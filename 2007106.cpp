#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;


class Event {
protected:
    string name;
public:
    Event(const string& eventName) : name(eventName) {}
    virtual string getName() const {
        return name;
    }
    virtual void displayDetails() const = 0;
    virtual ~Event() {}
};


class Concert : public Event {
private:
    string date;
    string location;
public:
    Concert(const string& eventName, const string& eventDate, const string& eventLocation)
        : Event(eventName), date(eventDate), location(eventLocation) {}

    void displayDetails() const override {
        cout << "Concert Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "---------------------\n";
    }
};


class Conference : public Event {
private:
    string startDate;
    string endDate;
    string location;
public:
    Conference(const string& eventName, const string& eventStartDate, const string& eventEndDate, const string& eventLocation)
        : Event(eventName), startDate(eventStartDate), endDate(eventEndDate), location(eventLocation) {}

    void displayDetails() const override {
        cout << "Conference Name: " << name << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Location: " << location << endl;
        cout << "---------------------\n";
    }
};


class SportsEvent : public Event {
private:
    string date;
    string location;
    string sport;
public:
    SportsEvent(const string& eventName, const string& eventDate, const string& eventLocation, const string& eventSport)
        : Event(eventName), date(eventDate), location(eventLocation), sport(eventSport) {}

    void displayDetails() const override {
        cout << "Sports Event Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Sport: " << sport << endl;
        cout << "---------------------\n";
    }
};


class Exhibition : public Event {
private:
    string startDate;
    string endDate;
    string location;
    string theme;
public:
    Exhibition(const string& eventName, const string& eventStartDate, const string& eventEndDate, const string& eventLocation, const string& eventTheme)
        : Event(eventName), startDate(eventStartDate), endDate(eventEndDate), location(eventLocation), theme(eventTheme) {}

    void displayDetails() const override {
        cout << "Exhibition Name: " << name << endl;
        cout << "Start Date: " << startDate << endl;
        cout << "End Date: " << endDate << endl;
        cout << "Location: " << location << endl;
        cout << "Theme: " << theme << endl;
        cout << "---------------------\n";
    }
};


class TheatrePlay : public Event {
private:
    string date;
    string location;
    string playwright;
public:
    TheatrePlay(const string& eventName, const string& eventDate, const string& eventLocation, const string& eventPlaywright)
        : Event(eventName), date(eventDate), location(eventLocation), playwright(eventPlaywright) {}

    void displayDetails() const override {
        cout << "Theatre Play Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Playwright: " << playwright << endl;
        cout << "---------------------\n";
    }
};


class Workshop : public Event {
private:
    string date;
    string location;
    string facilitator;
public:
    Workshop(const string& eventName, const string& eventDate, const string& eventLocation, const string& eventFacilitator)
        : Event(eventName), date(eventDate), location(eventLocation), facilitator(eventFacilitator) {}

    void displayDetails() const override {
        cout << "Workshop Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Facilitator: " << facilitator << endl;
        cout << "---------------------\n";
    }
};



class SocialGathering : public Event {
private:
    string date;
    string location;
    int maxAttendees;
public:
    SocialGathering(const string& eventName, const string& eventDate, const string& eventLocation, int eventMaxAttendees)
        : Event(eventName), date(eventDate), location(eventLocation), maxAttendees(eventMaxAttendees) {}

    void displayDetails() const override {
        cout << "Social Gathering Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Maximum Attendees: " << maxAttendees << endl;
        cout << "---------------------\n";
    }
};

class GamingFiesta: public Event {
private:
    string date;
    string location;

    int prizemoney;
public:
    GamingFiesta(const string& eventName, const string& eventDate, const string& eventLocation,int eventprizemoney)
        :  Event(eventName), date(eventDate), location(eventLocation),  prizemoney(eventprizemoney) {}
     void displayDetails() const override {
        cout << "Gaming Fiesta Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Location: " << location << endl;
        cout << "Prize Money: " << prizemoney << endl;
        cout << "---------------------\n";
    }


};

vector<Event*> events;


void addEvent() {
    string eventType;
    cout << "Enter event type (Concert/Conference/Sports/Exhibition/TheatrePlay/Workshop/SocialGathering/GamingFiesta): ";
    getline(cin >> ws, eventType);

    string eventName, eventDate, eventLocation;
    cout << "Enter event name: ";
    getline(cin >> ws, eventName);
    cout << "Enter event date: ";
    getline(cin >> ws, eventDate);
    cout << "Enter event location: ";
    getline(cin >> ws, eventLocation);

    if (eventType == "Concert") {
        events.push_back(new Concert(eventName, eventDate, eventLocation));
    } else if (eventType == "Conference") {
        string eventStartDate, eventEndDate;
        cout << "Enter conference start date: ";
        getline(cin >> ws, eventStartDate);
        cout << "Enter conference end date: ";
        getline(cin >> ws, eventEndDate);
        events.push_back(new Conference(eventName, eventStartDate, eventEndDate, eventLocation));
    } else if (eventType == "Sports") {
        string eventSport;
        cout << "Enter sport: ";
        getline(cin >> ws, eventSport);
        events.push_back(new SportsEvent(eventName, eventDate, eventLocation, eventSport));
    } else if (eventType == "Exhibition") {
        string eventStartDate, eventEndDate, eventTheme;
        cout << "Enter exhibition start date: ";
        getline(cin >> ws, eventStartDate);
        cout << "Enter exhibition end date: ";
        getline(cin >> ws, eventEndDate);
        cout << "Enter exhibition theme: ";
        getline(cin >> ws, eventTheme);
        events.push_back(new Exhibition(eventName, eventStartDate, eventEndDate, eventLocation, eventTheme));
    } else if (eventType == "TheatrePlay") {
        string eventPlaywright;
        cout << "Enter playwright: ";
        getline(cin >> ws, eventPlaywright);
        events.push_back(new TheatrePlay(eventName, eventDate, eventLocation, eventPlaywright));
    } else if (eventType == "Workshop") {
        string eventFacilitator;
        cout << "Enter facilitator: ";
        getline(cin >> ws, eventFacilitator);
        events.push_back(new Workshop(eventName, eventDate, eventLocation, eventFacilitator));
    }
      else if (eventType == "Social Gathering") {
        int eventMaxAttendees;
        cout << "Enter Maximum Attendees: ";
        cin>>eventMaxAttendees;
        events.push_back(new SocialGathering(eventName, eventDate, eventLocation, eventMaxAttendees));
    }
      else if(eventType=="GamingFiesta"){
        int eventprizemoney;
        cout<<"Enter PrizeMoney: ";
        cin>>eventprizemoney;
        events.push_back(new GamingFiesta(eventName, eventDate, eventLocation, eventprizemoney));
      }

      else {
        cout << "Invalid event type.\n";
    }

    cout << "Event added successfully!\n";
}


void viewEvents() {
    if (events.empty()) {
        cout << "No events found.\n";
        return;
    }

    cout << "Events:\n";
    for (const auto& event : events) {
        event->displayDetails();
    }
}

void deleteEventByName() {
    string eventName;
    cout << "Enter event name to delete: ";
    getline(cin >> ws, eventName);

    int deletedCount = 0;

    for (auto it = events.begin(); it != events.end(); ) {
        Event* event = *it;

        if (event->getName() == eventName) {

            if (dynamic_cast<Concert*>(event)) {
                cout << "Deleting Concert: " << eventName << endl;
            } else if (dynamic_cast<Conference*>(event)) {
                cout << "Deleting Conference: " << eventName << endl;
            } else if (dynamic_cast<SportsEvent*>(event)) {
                cout << "Deleting Sports Event: " << eventName << endl;
            } else if (dynamic_cast<Exhibition*>(event)) {
                cout << "Deleting Exhibition: " << eventName << endl;
            } else if (dynamic_cast<TheatrePlay*>(event)) {
                cout << "Deleting Theatre Play: " << eventName << endl;
            } else if (dynamic_cast<Workshop*>(event)) {
                cout << "Deleting Workshop: " << eventName << endl;
            } else if (dynamic_cast<SocialGathering*>(event)) {
                cout << "Deleting Social Gathering: " << eventName << endl;
            } else if (dynamic_cast<GamingFiesta*>(event)) {
                cout << "Deleting Gaming Fiesta: " << eventName << endl;
            }

            delete event;
            it = events.erase(it);
            ++deletedCount;
        } else {
            ++it;
        }
    }

    if (deletedCount > 0) {
        cout << "Event(s) deleted successfully!\n";
    } else {
        cout << "No events found with the given name.\n";
    }
}





void getEventCount() {
    int count = events.size();
    cout << "Total number of events: " << count << endl;
}


inline void displayMenu() {
    cout << "\nEvent Management System\n";
    cout << "-----------------------\n";
    cout << "1. Add Event\n";
    cout << "2. View Events\n";
    cout << "3. Delete Event by Name\n";
    cout << "4. Get Total Number of Events\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

int main(){
    cout<<"\t\t\t\t\t EVENT MANAGEMENT SYSTEM\n";
    cout<<"\t\t\t\t\t Project By:Asif Akbar\n";
    cout<<"\t\t\t\t\t Roll:2007106\n";
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        cin.ignore();

        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                viewEvents();
                break;
            case 3:
                deleteEventByName();
                break;
            case 4:
                getEventCount();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }


    for (const auto& event : events) {
        delete event;
    }

    return 0;
}

