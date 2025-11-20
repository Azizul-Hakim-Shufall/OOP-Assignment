#include <iostream>
#include <string>

using namespace std;
class Ticket{
protected:
    string ticketID;
    string source;
    string destination;
    float distance;
    float baseFare;
public:
    void setTicketInfo() {
        cout << "\nEnter Ticket Information" << endl;
        cout << "Enter Ticket ID: ";
        cin >> ticketID;
        cout << "Enter Source: ";
        cin >> source;
        cout << "Enter Destination: ";
        cin >> destination;
        cout << "Enter Distance (km): ";
        cin >> distance;
    }
    void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << fixed << " " << distance << " km" << endl;
    }
    virtual float calculateFare() {
        baseFare = distance * 1.0;
        return baseFare;
    }
};

class TrainTicket : private Ticket{
private:
    string coachType;
    float totalFare;

public:
    void setTrainTicketInfo() {
        setTicketInfo();
        cout << "Enter Coach Type (AC/Sleeper/General): ";
        cin >> coachType;
    }
    float calculateFare(){
        float fare = Ticket::calculateFare();
        if (coachType == "AC") {
            fare += 200.0;
        } else if (coachType == "Sleeper") {
            fare += 100.0;
        } else {}
        totalFare = fare;
        return totalFare;
    }
    void displayTrainTicket() {
        cout << "\n=== Train Ticket Details ===" << endl;
        displayTicketInfo();
        cout << "Coach Type: " << coachType << endl;
        calculateFare();
        cout << "Total Fare: " << fixed << " " << totalFare << " tk" << endl;
        cout << "\n" << endl;
    }
};

class FlightTicket : protected Ticket {
private:
    string seatClass;
    float luggageWeight;
    float totalFare;

public:
    void setFlightTicketInfo() {
        setTicketInfo();
        cout << "Enter Seat Class (Economy/Business): ";
        cin >> seatClass;
        cout << "Enter Luggage Weight (kg): ";
        cin >> luggageWeight;
    }
    float calculateFare(){
        float fare = distance * 25.0;
        if (seatClass == "Business") {
            fare += 20000.0;
        }
        if (luggageWeight > 20.0) {
            float extraWeight = luggageWeight - 20.0;
            fare += extraWeight * 5000.0;
        }

        totalFare = fare;
        return totalFare;
    }
    void displayFlightTicket() {
        cout << "\n=== Flight Ticket Details ===" << endl;
        displayTicketInfo();

        cout << "Seat Class: " << seatClass << endl;
        cout << "Luggage Weight: " << fixed << " " << luggageWeight << " kg" << endl;
        calculateFare();
        cout << "Total Fare: " << fixed << " " << totalFare << " tk" << endl;
        cout << "\n" << endl;
    }
};

int main() {
    TrainTicket myTrainTicket;
    FlightTicket myFlightTicket;
    myTrainTicket.setTrainTicketInfo();
    myFlightTicket.setFlightTicketInfo();
    myTrainTicket.displayTrainTicket();
    myFlightTicket.displayFlightTicket();

    return 0;
}
