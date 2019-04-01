#ifndef PLANE_H
#define PLANE_H

#include <string>

using namespace std;

class Plane{
private:
  string   make;
  string   model;
  string   tailNumber;
  int      numSeats;
  int      range;
  int      minCrew;
public:
  Plane();
  Plane(string make, string model, string tailNumber, int numSeats, int range, int minCrew);

  string    GetMake() const;
  void      SetMake(const string& make);

  string    GetModel() const;
  void      SetModel(const string& model);

  string    GetTailNumber() const;
  void      SetTailNumber(const string& tailNumber);

  int       GetNumSeats() const;
  void      SetNumSeats(const int& numSeats);

  int       GetRange() const;
  void      SetRange(const int& range);

  int       GetMinCrew() const;
  void      SetMinCrew(const int& minCrew);

  string    toString() const;
};
#endif
