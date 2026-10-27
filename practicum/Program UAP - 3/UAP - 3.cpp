#include <bits/stdc++.h>
#include "Vehicle.h"
#include "ParkingFloor.h"
#include "ParkingSlot.h"
#include "ParkingGarage.h"
#include "ParkingException.h"
using namespace std;


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
