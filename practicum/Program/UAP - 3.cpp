#include <bits/stdc++.h>
using namespace std;

enum class VehicleType { CAR, MOTORCYCLE, EV };

class Vehicle {
protected:
    string plate, owner;
    VehicleType type;

public:
    Vehicle(string p, string o, VehicleType t)
        : plate(move(p)), owner(move(o)), type(t) {}

    virtual double calculateRate(int durationHours) const = 0;

    // method overloading
    virtual double calculateRate(int startHour, int endHour) const {
        return calculateRate(endHour - startHour);
    }

    VehicleType getType() const { return type; }
    string getPlate() const { return plate; }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    Car(string p, string o)
        : Vehicle(move(p), move(o), VehicleType::CAR) {}

    double calculateRate(int h) const override {
        double total = h * 5000;
        if (h > 24) total *= 0.9;
        return total;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string p, string o)
        : Vehicle(move(p), move(o), VehicleType::MOTORCYCLE) {}

    double calculateRate(int h) const override {
        return h * 2000;
    }
};

class EV : public Vehicle {
    bool chargingRequired;
public:
    EV(string p, string o, bool c)
        : Vehicle(move(p), move(o), VehicleType::EV),
          chargingRequired(c) {}

    double calculateRate(int h) const override {
        double total = h * 4000;
        if (chargingRequired) total += 3000;
        if (h > 24) total *= 0.9;
        return total;
    }
};

class ParkingSlot {
protected:
    string id;
    int level;
    bool occupied = false;

public:
    ParkingSlot(string i, int l)
        : id(move(i)), level(l) {}

    virtual bool canPark(const Vehicle& v) const = 0;

    bool isOccupied() const { return occupied; }
    void setOccupied(bool o) { occupied = o; }
    string getId() const { return id; }

    virtual ~ParkingSlot() = default;
};

class RegularSlot : public ParkingSlot {
public:
    RegularSlot(string i, int l)
        : ParkingSlot(move(i), l) {}

    bool canPark(const Vehicle& v) const override {
        return v.getType() != VehicleType::EV;
    }
};

class EVSlot : public ParkingSlot {
public:
    EVSlot(string i, int l)
        : ParkingSlot(move(i), l) {}

    bool canPark(const Vehicle& v) const override {
        return v.getType() == VehicleType::EV;
    }
};

class VIPSlot : public ParkingSlot {
    bool reserved = false;
public:
    VIPSlot(string i, int l)
        : ParkingSlot(move(i), l) {}

    bool canPark(const Vehicle&) const override {
        return !reserved;
    }

    void reserve() {
        if (reserved)
            throw ReservationException();
        reserved = true;
    }
};

class ParkingFloor {
    vector<unique_ptr<ParkingSlot>> slots;

public:
    void addSlot(unique_ptr<ParkingSlot> s) {
        slots.push_back(move(s));
    }

    ParkingSlot* findAvailableSlot(const Vehicle& v) {
        for (auto& s : slots) {
            if (!s->isOccupied() && s->canPark(v))
                return s.get();
        }
        throw NoAvailableSlotException();
    }
};

class ParkingGarage {
    vector<unique_ptr<ParkingFloor>> floors;
    map<string, double> revenue;

public:
    void addFloor(unique_ptr<ParkingFloor> f) {
        floors.push_back(move(f));
    }

    string park(unique_ptr<Vehicle> v) {
        for (auto& f : floors) {
            try {
                ParkingSlot* slot = f->findAvailableSlot(*v);
                slot->setOccupied(true);
                return "TICKET-" + v->getPlate();
            } catch (NoAvailableSlotException&) {
                continue;
            }
        }
        throw NoAvailableSlotException();
    }

    double unpark(const string& ticket, int hours, const Vehicle& v) {
        if (ticket.empty())
            throw InvalidTicketException();

        double fee = v.calculateRate(hours);
        revenue[v.getPlate()] += fee;
        return fee;
    }

    void report() const {
        cout << "\n--- DAILY REPORT ---\n";
        double total = 0;
        for (const auto& r : revenue)
            total += r.second;
        cout << "Total Revenue: Rp" << total << endl;
    }
};

class ParkingException : public exception {
protected:
    string msg;
public:
    ParkingException(const string& m) : msg(m) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class NoAvailableSlotException : public ParkingException {
public:
    NoAvailableSlotException()
        : ParkingException("No available parking slot!") {}
};

class InvalidTicketException : public ParkingException {
public:
    InvalidTicketException()
        : ParkingException("Invalid parking ticket!") {}
};

class ReservationException : public ParkingException {
public:
    ReservationException()
        : ParkingException("VIP slot is not available for reservation!") {}
};

class PaymentException : public ParkingException {
public:
    PaymentException()
        : ParkingException("Payment processing error!") {}
};


int main() {
    try {
        ParkingGarage garage;

        auto floor1 = make_unique<ParkingFloor>();
        floor1->addSlot(make_unique<RegularSlot>("R1", 1));
        floor1->addSlot(make_unique<EVSlot>("E1", 1));
        floor1->addSlot(make_unique<VIPSlot>("V1", 1));

        garage.addFloor(move(floor1));

        unique_ptr<Vehicle> v =
            make_unique<EV>("B1234EV", "Raden", true);

        string ticket = garage.park(move(v));
        cout << "Vehicle parked successfully\n";
        cout << "Ticket ID: " << ticket << endl;

        EV ev("B1234EV", "Raden", true);
        double payment = garage.unpark(ticket, 26, ev);

        cout << "Payment: Rp" << payment << endl;

        garage.report();

    } catch (const ParkingException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
