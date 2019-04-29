#include "flightmanager.h"

using namespace std;

FlightManager::FlightManager() { }

FlightManager::~FlightManager() { }

void FlightManager::AddFlight(){
  string planeID;
  int numPilots;
  int numCabinCrew;
  list<int> pilotIDs;
  list<int> cabinCrewIDs;
  string startAirport;
  string endAirport;
  int numPassengers;
  int status=-1;
  int flightID;
  enum status_options{Active=1, Complete=2, Canceled=3};
  Date startDate;
  Date endDate;
  int day,month,year,hour,minute;

  printf("\n=====Add Flight=====\n");
  printf("Plane ID >");
  cin >> planeID;
  printf("Number of pilots >");
  cin >> numPilots;
  printf("Number of cabin crew >");
  cin >> numCabinCrew;
  printf("Starting Airport >");
  cin >> startAirport;
  printf("Ending Airport >");
  cin >> endAirport;
  printf("Number of passengers >");
  cin >> numPassengers;
  while(status>3 && status<1){
    printf("Status:\n1. Active\n2. Complete\n3. Canceled\n>");
    cin >> status;
  }
  printf("Unique Flight ID >");
  cin >> flightID;
  printf("\n====Start Date====\n");
  printf("Format date as example below:\nDay Month Year Hour Minute\n(Time is in 24 Hour format)\n>");
  cin >> day >> month >> year >> hour >> minute;
  startDate = Date(day,month,year,hour,minute);
  printf("\n=====End Date=====\n");
  printf("Format date as example below:\nDay Month Year Hour Minute\n(Time is in 24 Hour format)\n>");
  cin >> day >> month >> year >> hour >> minute;
  endDate = Date(day,month,year,hour,minute);

  flights.push_back(Flight(planeID,numPilots,numCabinCrew,startAirport,endAirport, numPassengers,status,flightID,startDate,endDate));
}

void FlightManager::AddFlight(Flight& flight){
  flights.push_back(flight);
}

void FlightManager::EditFlight(const int& flightID){
  if(FlightExists(flightID)){
    cout << "Editing " << Find(flightID).GetPlaneID() << ":" << endl;
    enum options{PLANEID=1, NUMPILOTS=2, NUMCABINCREW=3,
    PILOTID=4,CABINCREWID=5,STARTAIRPORT=6,ENDAIRPORT=7,
    NUMPASS=8,STATUS=9,FLIGHTID=10,STARTDATE=11,ENDDATE=12,
    EXIT=13};
    int sel;
    bool running=true;
    while(running){
      cout << "Select the option to change: " << endl;
      cout << "1.  Plane ID\n"
           << "2.  Number of Pilots\n"
           << "3.  Number of Cabin Crew\n"
           << "4.  Modify Pilot ID\'s\n"
           << "5.  Modify Cabin Crew ID\'s\n"
           << "6.  Starting Airport\n"
           << "7.  Ending Airport\n"
           << "8.  Number of Passengers\n"
           << "9.  Flight Status\n"
           << "10. Flight ID\n"
           << "11. Start Date/Time\n"
           << "12. End Date/Time\n"
           << "13. Exit\n"
           << ">";
      cin >> sel;
      switch(sel){
        case PLANEID:{
          string planeID;
          cout << "New PlaneID >";
          cin.ignore();
          getline(cin,planeID);
          Find(flightID).SetPlaneID(planeID);
          cout << "Changed Plane ID to " << planeID << endl;
        }break;
        case NUMPILOTS:{
          int numPilots;
          cout << "New Number of Pilots >";
          cin >> numPilots;
          Find(flightID).SetNumPilots(numPilots);
          cout << "Changed # of Pilots to " << numPilots << endl;
        }break;
        case NUMCABINCREW:{
          int numCabinCrew;
          cout << "New Number of Cabin Crew >";
          cin >> numCabinCrew;
          Find(flightID).SetNumCabinCrew(numCabinCrew);
          cout << "Changed # of Cabin Crew to " << numCabinCrew << endl;
        }break;
        case PILOTID:{
          //Not Implemented Yet
        }break;
        case CABINCREWID:{
          //Not Implemented yet/
        }break;
        case STARTAIRPORT:{
          string start;
          cout << "New Starting Airport >";
          cin.ignore();
          getline(cin,start);
          Find(flightID).SetStartAirport(start);
          cout << "Changed start airport to " << start << endl;
        }break;
        case ENDAIRPORT:{
          string end;
          cout << "New Ending Airport >";
          cin.ignore();
          getline(cin,end);
          Find(flightID).SetEndAirport(end);
          cout << "Changed end airport to " << end << endl;
        }break;
        case NUMPASS:{
          int numPass;
          cout << "New # of Passengers >";
          cin >> numPass;
          Find(flightID).SetNumPassengers(numPass);
          cout << "Changed # of Passengers to " << numPass << endl;
        }break;
        case STATUS:{
          int option=-1;
          while(option < 1 && option > 3){
            cout << "New flight status:\n1. Active\n2. Complete\n3. Canceled\n>";
            cin >> option;
          }
          Find(flightID).SetStatus(option);
          cout << "Changed status to " << Find(flightID).GetStatus() << endl;
        }break;
        case FLIGHTID:{
          int id;
          cout << "New Flight ID >";
          cin >> id;
          Find(flightID).SetFlightID(id);
          cout << "Changed Flight ID to " << id << endl;
        }break;
        case STARTDATE:{

        }break;
        case ENDDATE:{

        }break;
        case EXIT:{
          running=false;
        }break;
        default:{
          cout << "Please enter a valid option!" << endl;
        }break;
      }
    }
  }else{
    cout << "That flight cannot be found." << endl;
  }
}

void FlightManager::DeleteFlight(const int& flightID){
  if(FlightExists(flightID)){
    for(iter = flights.begin(); iter != flights.end(); ++iter){
      if(iter->GetFlightID() == flightID){
        iter = flights.erase(iter);
        return;
      }
    }
  }else{
    cout << "Couldn\'t find that flight." << endl;
  }
}

bool FlightManager::FlightExists(const int& flightID){
  for(auto& i : flights){
    if(i.GetFlightID() == flightID){
      return true;
    }
  }
  return false;
}

Flight& FlightManager::Find(const int& flightID){
  if(FlightExists(flightID)){
    for(auto& i : flights){
      if(i.GetFlightID() == flightID){
        return i;
      }
    }
  }else
    cout << "Couldn\'t find that flight." << endl;
}

void FlightManager::PrintFlights(){
  cout << "\nAll Flights: " << endl;
  for(auto const& i : flights){
    cout << i.toString() << endl;
  }
}

void FlightManager::Print(const int& flightID){
  if(FlightExists(flightID)){
    cout << Find(flightID).toString() << endl;
  }else{
    cout << "Couldn\'t find that flight." << endl;
  }
}
void FlightManager::RunMenu(){
  bool running=true;

  while(running){
    int option;
    cout << "=====Flight Menu=====" << endl;
    printf("1. Add Flight\n2. Edit Flight\n3. Delete Flight\n4. Print Single Flight\n5. Print All Flights\n6. Exit\n>");
    cin >> option;
    switch(option){
      case 1:{
        AddFlight();
      }break;
      case 2:{
        int flightID;
        printf("\n=====Edit Menu=====\n");
        printf("Enter Flight ID# >");
        cin >> flightID;
        EditFlight(flightID);
      }break;
      case 3:{
        int id;
        printf("\n=====Delete Menu=====\n");
        printf("Enter Flight ID# >");
        cin >> id;
        DeleteFlight(id);
      }break;
      case 4:{
        int id;
        printf("\n=====Print Menu=====\n");
        printf("Enter Flight ID# >");
        cin >> id;
        Print(id);
      }break;
      case 5:{
        PrintFlights();
      }break;
      case 6:{
        running=false;
      }break;
      default: {
        cout << "Enter a valid option!" << endl;
      }break;
    }
  }
}

string FlightManager::toString() const{
  return "";
}
