#ifndef PLANEMANAGER_H
#define PLANEMANAGER_H

#include "plane.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class PlaneManager{
private:
  list<Plane> planes;
  list<Plane>::iterator iter;
public:
  PlaneManager();
  ~PlaneManager();

  void   AddPlane();
  void   AddPlane(Plane& plane);

  void   EditPlane(const string& tailNumber);

  void   DeletePlane(const string& tailNumber);

  bool   PlaneExists(const string& tailNumber);

  Plane& Find(const string& tailNumber);

  void   PrintPlanes();

  void   Print(const string& tailNumber);

  void   RunMenu();

  string toString() const;
};
#endif
