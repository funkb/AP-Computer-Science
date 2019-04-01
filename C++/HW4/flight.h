#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <list>
#include <iostream>
#include "date.h"

using namespace std;

class Flight{
private:
  string planeID;
  int numPilots;
  int numCabinCrew;
  list<int> * pilotIDs = new list<int>;
  list<int> * cabinCrewIDs = new list<int>;
  string startAirport;
  string endAirport;
  int numPassengers;
  int status;
  int flightID;
  enum status_options{Active, Complete, Canceled};
  Date startDate;
  Date endDate;
public:


  Flight();
  Flight(const string& planeID, const int& numPilots, const int& GetNumCabinCrew,
      const string& startAirport, const string& endAirport, const int& numPassengers,
      const int& status,const int& flightID, int startTime[5], int endTime[5] );
  ~Flight(); //Delete Lists

  string GetPlaneID() const;
  void SetPlaneID(const string& planeID);

  int GetNumPilots() const;
  void SetNumPilots(const int& numPilots);

  int GetNumCabinCrew() const;
  void SetNumCabinCrew(const int& numCabinCrew);

  void AddPilotID(const int& ID);
  void RemovePilotID(const int& ID);

  void AddCabinCrewID(const int& ID);
  void RemoveCabinCrewID(const int& ID);

  string GetStartAirport() const;
  void SetStartAirport(const string& startAirport);

  string GetEndAirport() const;
  void SetEndAirport(const string& endAirport);

  int GetNumPassengers() const;
  void SetNumPassengers(const int& numPassengers);

  const string GetStartDate() const;
  void SetStartDate(const int& day,const int& month,const int& year,const int& hour,const int& minute);

  const string GetEndDate() const;
  void SetEndDate(const int& day,const int& month,const int& year,const int& hour,const int& minute);

  int GetFlightID() const;
  void SetFlightID(const int& flightID);

  string GetStatus() const;
  void PrintStatus() const;
  string toString() const;
};
#endif
