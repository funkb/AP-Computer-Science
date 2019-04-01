#include <iostream>
/*
#include "date.h"
#include "crewmember.h"
#include "flight.h"
#include "plane.h"
*/
#include "crewmanager.h"
#include "planemanager.h"
#include "flightmanager.h"

using namespace std;

int main(){
  /*
  cout << "Date Class Testing" << endl << endl;

  Date date(25,3,2019,7+12,55);
  Date date2;

  cout << "Date1: " << date.toString() << endl;
  cout << "Date2: " << date2.toString() << endl;

  date2.SetYear(1970);
  date2.SetMonth(11);
  date2.SetDay(29);
  date2.SetMinute(55);
  date2.SetHour(11);

  cout << "Date2-revised: " << date2.toString() << endl;


  CrewMember cm1("Johnnyak Appleseed", 1234, "Pilot");
  CrewMember cm2;

  cm2.SetName("Jacob Little");
  cm2.SetIDNum(346423);
  cm2.SetType("Cabin Crew");


	int list1[5] = {26,3,2019,18,30};
	int list2[5] = {26,3,2019,20,45};
	Flight flight;
	Flight flight2("007325",2,15,"Bankok International","Hong Kong Airport",145,1,list1,list2);
	cout << "Flight: " << flight.toString() << endl;
	cout << "Flight2: " << flight2.toString() << endl;

	cout << endl << endl;
	cout << "Plane Testing: " << endl;

	Plane plane1;
	Plane plane2("Boeing","747","3543FD9",200,500,15);

	cout << "Plane1: " << plane1.toString() << endl;
	cout << "Plane2: " << plane2.toString() << endl;


	CrewManager cm;
	cm.AddMember();
	cm.AddMember(cm2);
	cm.PrintMembers();
	cm.Print(9998);
	cm.EditMember(cm2.GetName());
	cout << "New Members: " << endl;
	cm.PrintMembers();
  */
  //Intro Text
  cout << "============================" << endl;
  cout << "  CSCE 1040 | Brandon Funk  " << endl;
  cout << " Combined-NT752.1191.1.2821 " << endl;
  cout << "   brandonfunk@my.unt.edu   " << endl;
  cout << "============================" << endl << endl;

  PlaneManager pm;
  CrewManager cm;
  FlightManager fm;

  bool running = true;
  int option;
  while(running){
    cout << "\n=====Mean Green Airlines=====\n";
    printf("1. Manage Crew\n2. Manage Planes\n3. Manage Flights\n4. Exit\n>");
    cin >> option;
    switch(option){
      case 1:
        cm.RunMenu();
        break;
      case 2:
        pm.RunMenu();
        break;
      case 3:
        fm.RunMenu();
        break;
      case 4:
        running=false;
        break;
      default:
        cout << "\nPlease enter a valid option!\n";
    }
  }
	return 0;

}
