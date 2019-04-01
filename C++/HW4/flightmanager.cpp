#include "flightmanager.h"

using namespace std;

FlightManager::FlightManager() { }

FlightManager::~FlightManager() {
  delete flights;
  delete iter;
}

void FlightManager::AddFlight(){

}

void FlightManager::AddFlight(Flight& flight){
  flights->push_back(flight);
}

void FlightManager::EditFlight(const int& flightID){

}

void FlightManager::DeleteFlight(const int& flightID){

}

bool FlightManager::FlightExists(const int& flightID){
  for(auto& i : *flights){
    if(i.GetFlightID() == flightID){
      return true;
    }
  }
  return false;
}

Flight& FlightManager::Find(const int& flightID){
  if(FlightExists(flightID)){
    for(auto& i : *flights){
      if(i.GetFlightID() == flightID){
        return i;
      }
    }
  }else
    cout << "Couldn\'t find that flight." << endl;
}

void FlightManager::PrintFlights(){

}

void FlightManager::Print(const int& flightID){

}
void FlightManager::RunMenu(){

}

string FlightManager::toString() const{
  return "";
}
