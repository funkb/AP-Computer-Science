#include "planemanager.h"

using namespace std;

PlaneManager::PlaneManager(){ }

PlaneManager::~PlaneManager(){ }

void PlaneManager::AddPlane(){
  string make;
  string model;
  string tailNumber;
  int numSeats;
  int range;
  int minCrew;
  cin.ignore();
  cout << "Plane Make: ";
  getline(cin,make);
  //cin.ignore();
  cout << "Plane Model: ";
  getline(cin,model);
  //cin.ignore();
  cout << "Unique Tail Number: ";
  getline(cin,tailNumber);
  cout << "Number of seats: ";
  cin >> numSeats;
  cout << "Maximum flight range: ";
  cin >> range;
  cout << "Minimum flight crew: ";
  cin >> minCrew;
  planes->push_back(Plane(make,model,tailNumber,numSeats,range,minCrew));
}

void PlaneManager::AddPlane(Plane& plane){
  planes->push_back(plane);
}

void PlaneManager::EditPlane(const string& tailNumber){

}

void PlaneManager::DeletePlane(const string& tailNumber){
  if(PlaneExists(tailNumber)){
    for (iter = planes.begin(); iter != planes.end();++iter){
      if(iter->GetTailNumber() == tailNumber)
        iter = planes.erase(iter);
    }
  }else
    cout << "Couldn\'t find that plane." << endl;
}

bool PlaneManager::PlaneExists(const string& tailNumber){
  for(auto& plane : *planes){
    if(plane.GetTailNumber() == tailNumber){
      return true;
    }
  }
  return false;
}

Plane& PlaneManager::Find(const string& tailNumber){
  if(PlaneExists(tailNumber)){
    for(auto& plane: *planes){
      if(plane.GetTailNumber() == tailNumber){
        return plane;
      }
    }
  }else{
    cout << "Plane cannot be found." << endl;
  }
}

void PlaneManager::PrintPlanes(){
  cout << "All planes: " << endl;
  int count=1;
  for(auto& plane : *planes){
    cout << "Plane #" << count << endl;
    cout << plane.toString() << endl;
    count++;
  }
}
void PlaneManager::Print(const string& tailNumber){
  if(PlaneExists(tailNumber)){
    cout << Find(tailNumber).toString() << endl;
  }else{
    cout << "Couldn\'t find that plane." << endl;
  }
}

void PlaneManager::RunMenu(){
  bool running = true;

  while (running){
    int option;
    cout << "=====Plane Menu=====" << endl;
    printf("1. Add Plane\n2. Edit Plane\n3. Delete Plane\n4. Print Plane\'s Information\n5. Print All Plane Info\n6. Exit\n>");
    cin >> option;
    switch(option){
      case 1:{
        AddPlane();
      }break;
      case 2:{
        string tail;
        cout << "Unique Tail Number >";
        getline(cin,tail);
        EditPlane(tail);
      }break;
      case 3:{
        string tail;
        cin.ignore();
        cout << "Unique Tail Number >";
        getline(cin,tail);
        DeletePlane(tail);
      }break;
      case 4:{
        string tail;
        cin.ignore();
        cout << "Unique Tail Number >";
        getline(cin,tail);
        Print(tail);
      }break;
      case 5:{
        PrintPlanes();
      }break;
      default:
      case 6:{
        running=false;
        break;
      }
    }
  }
}

string PlaneManager::toString() const{
  return "";
}
