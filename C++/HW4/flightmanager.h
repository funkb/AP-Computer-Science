#ifndef FLIGHTMANAGER_H
#define FLIGHTMANAGER_H

#include "flight.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class FlightManager{
private:
  list<Flight> flights;
  list<Flight>::iterator iter;
public:
  FlightManager();
  ~FlightManager();

  void AddFlight();
  void AddFlight(Flight& flight);

  void EditFlight(const int& flightID);

  void DeleteFlight(const int& flightID);

  bool FlightExists(const int& flightID);

  Flight& Find(const int& flightID);

  void PrintFlights();

  void Print(const int& flightID);

  void RunMenu();

  string toString() const;
};
#endif
