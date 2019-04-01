#include "plane.h"

Plane::Plane(){
  make="";
  model="";
  tailNumber="";
  numSeats=0;
  range=0;
  minCrew=0;
}
Plane::Plane(string make, string model, string tailNumber, int numSeats,
  int range, int minCrew): make(make), model(model), tailNumber(tailNumber),
  numSeats(numSeats),range(range), minCrew(minCrew){ }

string Plane::GetMake() const{
  return make;
}
void Plane::SetMake(const string& make){
  this->make = make;
}

string Plane::GetModel() const{
  return model;
}
void Plane::SetModel(const string& model){
  this->model = model;
}

string Plane::GetTailNumber() const{
  return tailNumber;
}
void Plane::SetTailNumber(const string& tailNumber){
  this->tailNumber = tailNumber;
}

int Plane::GetNumSeats() const{
  return numSeats;
}
void Plane::SetNumSeats(const int& numSeats){
  this->numSeats = numSeats;
}

int Plane::GetRange() const{
  return range;
}
void Plane::SetRange(const int& range){
  this->range = range;
}

int Plane::GetMinCrew() const{
  return minCrew;
}
void Plane::SetMinCrew(const int& minCrew){
  this->minCrew = minCrew;
}


string Plane::toString() const{
  return make + " " + model + " " + tailNumber + "\n"
    + "Flies " + to_string(numSeats) + " passengers a max of " + to_string(range) + " miles, with a minimum crew of " + to_string(minCrew) + ".";
}
