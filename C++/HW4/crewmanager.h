#ifndef CREWMANAGER_H
#define CREWMANAGER_H

#include "crewmember.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class CrewManager{
private:
  list<CrewMember> crew;
  list<CrewMember>::iterator iter;
public:
  CrewManager();
  ~CrewManager();

  void AddMember();
  void AddMember(CrewMember& member);

  void EditMember(const int& ID);

  void DeleteMember(const int& ID);

  bool MemberExists(const int& ID);

  CrewMember& Find(const int& ID);

  void PrintMembers();

  void Print(const int& ID);

  void RunMenu();

  string toString() const;
};
#endif
