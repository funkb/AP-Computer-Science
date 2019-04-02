#include "flight.h"

Flight::Flight(){
  planeID = "";
  numPilots = 0;
  numCabinCrew = 0;
  startAirport = "";
  endAirport = "";
  numPassengers = 0;
  status = 0;
  flightID = 0;
  list<int> * pilotIDs = new list<int>;
  list<int> * cabinCrewIDs = new list<int>;
}

Flight::Flight(const string& planeID, const int& numPilots, const int& numCabinCrew,
    const string& startAirport, const string& endAirport, const int& numPassengers,
    const int& status,const int& flightID, int startTime[5], int endTime[5] ) : planeID(planeID),
    numPilots(numPilots), numCabinCrew(numCabinCrew), startAirport(startAirport),
    endAirport(endAirport), numPassengers(numPassengers), status(status), flightID(flightID) {
      SetStartDate(startTime[0],startTime[1],startTime[2],startTime[3],startTime[4]);
      SetEndDate(endTime[0],endTime[1],endTime[2],endTime[3],endTime[4]);
}

Flight::~Flight(){ }

string Flight::GetPlaneID() const{
  return planeID;
}
void Flight::SetPlaneID(const string& planeID){
  this->planeID = planeID;
}

int Flight::GetNumPilots() const{
  return numPilots;
}
void Flight::SetNumPilots(const int& numPilots){
  this->numPilots = numPilots;
}

int Flight::GetNumCabinCrew() const{
  return numCabinCrew;
}
void Flight::SetNumCabinCrew(const int& numCabinCrew){
  this->numCabinCrew = numCabinCrew;
}

void Flight::AddPilotID(const int& ID){
  pilotIDs.push_back(ID);
}
void Flight::RemovePilotID(const int& ID){
  pilotIDs.remove(ID);
}

void Flight::AddCabinCrewID(const int& ID){
  cabinCrewIDs.push_back(ID);
}
void Flight::RemoveCabinCrewID(const int& ID){
  cabinCrewIDs.remove(ID);
}

string Flight::GetStartAirport() const{
  return startAirport;
}
void Flight::SetStartAirport(const string& startAirport){
  this->startAirport = startAirport;
}

string Flight::GetEndAirport() const{
  return endAirport;
}
void Flight::SetEndAirport(const string& endAirport){
  this->endAirport = endAirport;
}

int Flight::GetNumPassengers() const{
  return numPassengers;
}
void Flight::SetNumPassengers(const int& numPassengers){
  this->numPassengers = numPassengers;
}

const string Flight::GetStartDate() const{
  return this->startDate.toString();
}
void Flight::SetStartDate(const int& day,const int& month,const int& year,const int& hour,const int& minute){
  this->startDate = Date(day,month,year,hour,minute);
}

const string Flight::GetEndDate() const{
  return this->endDate.toString();
}
void Flight::SetEndDate(const int& day,const int& month,const int& year,const int& hour,const int& minute){
  this->endDate = Date(day,month,year,hour,minute);
}

int Flight::GetFlightID() const{
  return this->flightID;
}

void Flight::SetFlightID(const int& flightID){
  this->flightID = flightID;
}

string Flight::GetStatus() const{
  string statusSTR;
  switch(status){
    case Active:
      statusSTR = "Active";
      break;
    case Complete:
      statusSTR = "Complete";
      break;
    case Canceled:
      statusSTR = "Cancelled";
      break;
  }
  return statusSTR;
}

void Flight::PrintStatus() const{

  cout << "Flight is " + GetStatus();
}

string Flight::toString() const{
  return "PlaneID: " + planeID + "\n"
       + "Number of Pilots: " + to_string(numPilots) + "\n"
       + "Number of Cabin Crew: " + to_string(numCabinCrew) + "\n"
       + "Starting Airport: " + startAirport + "\n"
       + "Ending Airport: " + endAirport + "\n"
       + "Starting Date/Time: " + GetStartDate() + "\n"
       + "Ending Date/Time: " + GetEndDate() + "\n"
       + "Number of Passengers: " + to_string(numPassengers) + "\n"
       + "Status: " + GetStatus() + "\n"
       + "Flight ID: " + to_string(GetFlightID()) + "\n";
}
