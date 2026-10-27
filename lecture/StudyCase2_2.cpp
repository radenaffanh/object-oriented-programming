#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <ctime>
#include <sstream>
using namespace std;
using chronoClock = chrono::system_clock;

/*struct RentalAgency{
    vector<unique_ptr<Vehicle>> vehicles;
    void addVehicle(unique_ptr<Vehicle> vehicle){
        vehicles.push_back(move(vehicle));
    }
    void rentVehicle(double id, int days){
        for(auto &vehicle : vehicles){
            if(vehicle->getID() == id){
                if(vehicle->getisRented()){
                    cout << "Vehicle is already rented." << endl;
                } else {
                    vehicle->setisRented(true);
                    cout << "Vehicle rented successfully. Rent cost: " << vehicle->rentCost(days) << endl;
                }
                return;
            }
        }
        cout << "Vehicle not found." << endl;
    }
    void returnVehicle(double id){
        for(auto &vehicle : vehicles){
            if(vehicle->getID() == id){
                if(vehicle->getisRented()){
                    vehicle->setisRented(false);
                    cout << "Vehicle returned successfully." << endl;
                } else {
                    cout << "Vehicle is not rented." << endl;
                }
                return;
            }
        }
        cout << "Vehicle not found." << endl;
    }
};*/

struct VehicleException : public runtime_error{
    explicit VehicleException(const string &message) : runtime_error(message) {}
};

struct VehicleNotAvailable : public VehicleException{
    VehicleNotAvailable() : VehicleException("Vehicle not available") {}
};

struct BatteryLowException : public VehicleException{
    BatteryLowException() : VehicleException("Battery too low to start") {}
};

struct OverloadException : public VehicleException{
    OverloadException() : VehicleException("Truck Overload") {}
};

struct InvalidReturnException : public VehicleException {
    InvalidReturnException(const string &msg) : VehicleException(msg) {}
};

class Logger{
    ofstream ofs;
    public:
    explicit Logger(const string &path){
        ofs.open(path, ios::app);
        if (!ofs.is_open()){
            throw runtime_error ("Unable to open log file: " + path);
        }
    }
    ~Logger() {
        if (ofs.is_open()) ofs.close();
    }

    void log(const string &message){
        auto now = chronoClock::to_time_t(chronoClock::now());
        ofs << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S")  << " - " << message << "\n";
    }
};



class Vehicle{
protected:
    double id;
    double model;
    double dailyRate = 0.0;
    bool isRented = false;

public:
    Vehicle() = default;
    Vehicle(double id, double model, double dailyRate) : id(id), model(model), dailyRate(dailyRate) {}


    void setID(double i){
        id = i;
    }
    void setModel(double m){
        model = m;
    }
    void setDailyRate(double dR){
        dailyRate = dR;
    }
    void setIsRented(bool isR){
        isRented = isR;
    }

    double getID(){
        return id;
    }
    double getModel(){
        return model;
    }
    double getDailyRate() const {
        return dailyRate;
    }
    bool getIsRented() const {
        return isRented;
    }

    virtual ~Vehicle(){};
    virtual double rentCost(int days) const = 0;
    virtual void start() = 0;

    virtual unique_ptr<Vehicle> clone() const = 0;
};

class Car : public Vehicle{
public:
    int passengerCapacity = 5;
    Car() = default;
    Car(const double id, const double model, const double dailyRate, const int passengerCapacity){
        setID(id);
        setModel(model);
        setDailyRate(dailyRate);
        this->passengerCapacity = passengerCapacity;
    }

    double rentCost(int days) const override{
        return getDailyRate() * days;
    }

    void start() override{
        cout << "Car " << id << " started successfully." << endl;
    }

    unique_ptr<Vehicle> clone() const override {
        return make_unique<Car>(*this);
    }
};

class Truck : public Vehicle{
public:
    int loadFee = 1000;
    double maxLoadKg = 0.0;
    Truck() = default;
    Truck(const double id, const double model, const double dailyRate, const double maxLoadKg, const int loadFee){
        setID(id);
        setModel(model);
        setDailyRate(dailyRate);
        this->maxLoadKg = maxLoadKg;
        this->loadFee = loadFee;
    }
    double rentCost(int days) const override{
        return getDailyRate() * days + loadFee;
    }
    double rentCost(int days, double loadKg) const {
        if(loadKg > maxLoadKg){
            throw OverloadException();
        }
        double perKgfee = 2.0;
        return getDailyRate() * days + loadFee + perKgfee * loadKg;
    }
    void start() override{
        cout << "Truck " << id << " started successfully." << endl;
    }

    unique_ptr<Vehicle> clone() const override {
        return make_unique<Truck>(*this);
    }
};

class ElectricCar : public Vehicle{
public:
    int batterySurchargeIfNeeded = 1000;
    double batteryCapacityKWh = 0.0;
    double currentChargeKWh = 0.0;

    ElectricCar() = default;
    ElectricCar(const double id, const double model, const double dailyRate, const double batteryCapacityKWh, const double currentChargeKWh, const int batterySurchargeIfNeeded){
        setID(id);
        setModel(model);
        setDailyRate(dailyRate);
        this->batteryCapacityKWh = batteryCapacityKWh;
        this->currentChargeKWh = currentChargeKWh;
        this->batterySurchargeIfNeeded = batterySurchargeIfNeeded;
    }
    double rentCost(int days) const override{
        if (batteryCapacityKWh > 0 && currentChargeKWh < 0.2 * batteryCapacityKWh) {
            return getDailyRate() * days + batterySurchargeIfNeeded;
        }
        return getDailyRate() * days;
    }
    void start() override{
         if (currentChargeKWh <= 0.0) {
            throw BatteryLowException();
        }
        cout << "Electric car " << id << " started. Charge: " << currentChargeKWh << " kWh\n";
    }
    void charge(double kWh){
        currentChargeKWh += kWh;
        if(currentChargeKWh > batteryCapacityKWh){
            currentChargeKWh = batteryCapacityKWh;
        }
    }

    unique_ptr<Vehicle> clone() const override {
        return make_unique<ElectricCar>(*this);
    }

};

class RentalManager {
    vector<unique_ptr<Vehicle>> fleet;

    struct rentalRecord{
        double memberId;
        double VehicleId;
        chrono::system_clock::time_point rentalDate;
        int reservedDays;
    };

    unordered_map<double, rentalRecord> rentals;
    Logger logger;

public:
    explicit RentalManager(const string &logPath) : logger(logPath) {}

    void addVehicle(unique_ptr<Vehicle> vehicle) {
        fleet.push_back(move(vehicle));
    }
    
    Vehicle* findVehicleById(double const id) {
        for (const auto &vehicle : fleet) {
            if (vehicle->getID() == id) {
                return vehicle.get();
            }
        }
        return nullptr;
    }

    double rentVehicle(const double memberId, double vehicleId, int days, double loadKg = -1.0) {
        auto *v = findVehicleById(vehicleId);
        if (!v) {
            logger.log("rent vehicle failed : vehicle not found id " + to_string(vehicleId));
            //throw invalid_argument("Vehicle not found");
            throw VehicleNotAvailable();
        }
        if (v->getIsRented()) {
            logger.log("rent vehicle failed : already rented id " + to_string(vehicleId));
            throw VehicleNotAvailable();
        }
        
        double cost = 0.0;

        if (Truck *t = dynamic_cast<Truck*>(v)){
            if (loadKg >= 0.0){
                cost = t ->rentCost(days, loadKg);
            } else {
                cost = t-> rentCost(days);
            }
        } else {
            cost = v->rentCost(days);
        }

        v->setIsRented(true);
        rentalRecord rec;
        rec.memberId = memberId;
        rec.VehicleId = vehicleId;
        rec.reservedDays = days;
        rec.rentalDate = chrono::system_clock::now() + chrono::hours(24*days);
        rentals[vehicleId] = move(rec);

        logger.log("rented: member=" + to_string(memberId) + " vehicle=" + to_string(vehicleId) + " days=" + to_string(days) + " cost=" + to_string(cost));
        return cost;
    }

    double returnVehicle(const double &memberId, const double &vehicleId, int actualDays, bool damageFlag){
        auto it = rentals.find(vehicleId);
        if (it == rentals.end() || it->second.memberId != memberId){
            logger.log("return vehicle failed : no rental record for id " + to_string(vehicleId));
            throw InvalidReturnException("Invalid return attempt");
        }
        rentalRecord rec = it->second;

        if (rec.memberId != memberId) {
            logger.log("return vehicle failed : member id mismatch for vehicle id " + to_string(vehicleId));
            throw InvalidReturnException("Member ID does not match rental record");
        }

        Vehicle *v = findVehicleById(vehicleId);
        if (!v || !v->getIsRented()){
            logger.log("return vehicle failed : vehicle not rented id " + to_string(vehicleId));
            throw InvalidReturnException("Vehicle not rented");
        }

        double baseCost;
        if (Truck *t = dynamic_cast<Truck*>(v)){
            baseCost = t->rentCost(rec.reservedDays);
        } else {
            baseCost = v->rentCost(rec.reservedDays);
        }

        double penalty = 0.0;
        if (actualDays > rec.reservedDays){
            int lateDays = actualDays - rec.reservedDays;
            double lateFeePerDay = 1.2 * (baseCost / rec.reservedDays);
            penalty += lateDays * lateFeePerDay;
        }

        if (damageFlag){
            bool severe = false;
            if (severe) {
                logger.log("returnVehicle: severe damage, incident logged for vehicle=" + to_string(vehicleId));
                rentals.erase(it);
                v->setIsRented(false);
                throw InvalidReturnException("Severe damage reported - incident escalated");
            } else {
                double damageFee = 0.2 * baseCost;
                penalty += damageFee;
                logger.log("returnVehicle: minor damage fee applied for vehicle id " + to_string(vehicleId));
            }
        }

        v->setIsRented(false);
        rentals.erase(it);

        logger.log("returned: member =" + to_string(memberId) + " vehicle =" + to_string(vehicleId));
        return baseCost + penalty; 
    }  

    void chargeBattery(double vehicleId, double kwh){
        Vehicle *v = findVehicleById(vehicleId);
        if (!v){
            logger.log("charge battery failed : vehicle not found id " + to_string(vehicleId));
            throw invalid_argument("Vehicle not found");
        }
        ElectricCar *ec = dynamic_cast<ElectricCar*>(v);
        if (!ec){
            logger.log("charge battery failed : vehicle is not electric id " + to_string(vehicleId));
            throw invalid_argument("Vehicle is not electric");
        }
        ec->charge(kwh);
        logger.log("charged battery: vehicle=" + to_string(vehicleId) + " kWh=" + to_string(kwh));
    }

};

int main(){
    try{
        RentalManager manager ("rental_log.txt");

        manager.addVehicle(make_unique<Car>(1, 1, 300, 7));
        manager.addVehicle(make_unique<Truck>(2, 4, 500, 2000, 1500));
        manager.addVehicle(make_unique<ElectricCar>(3, 2, 400, 75, 20, 1000));
        
        double cost1 = manager.rentVehicle(1, 1, 3);
        cout << "Rented C001 cost: " << cost1 << "\n";

      
        double cost2 = manager.rentVehicle(2, 2, 2, 1500.0);
        cout << "Rented T001 cost (with load): " << cost2 << "\n";
        
     
        try {
            Vehicle* ev = manager.findVehicleById(3);
            if (ev) ev->start();
        } catch (const VehicleException &ve) {
            cout << "Start failed: " << ve.what() << "\n";
            // charge and retry
            manager.chargeBattery(3, 30.0);
            Vehicle* ev = manager.findVehicleById(3);
            if (ev) {
                ev->start();
            }
        }

        try {
            double total = manager.returnVehicle(2, 2, 4, true); 
            cout << "Return T001 total charge: " << total << "\n";
        } catch (const VehicleException &e) {
            cout << "Return error: " << e.what() << "\n";
        }

        try {
            manager.rentVehicle(3, 2, 1, 3000.0); 
        } catch (const OverloadException &oe) {
            cout << "Overload: " << oe.what() << "\n";
        }

        double finalCost = manager.returnVehicle(1, 1, 3, false);
        cout << "Return C001 final cost: " << finalCost << "\n";

    } catch (const exception &e) {
        cerr << "Fatal error: " << e.what() << "\n";
        return 1;
    
    }
    return 0;
}