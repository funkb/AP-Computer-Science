#ifndef CREWMANAGER_H
#define CREWMANAGER_H

#include "crewmember.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

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

  void EditMember(const string& name);
  void EditMember(const int& ID);

  void DeleteMember(const string& name);
  void DeleteMember(const int& ID);

  bool MemberExists(const string& name);
  bool MemberExists(const int& ID);

  CrewMember& Find(const int& ID);
  CrewMember& Find(const string& name);

  void PrintMembers();

  void Print(const int& ID);
  void Print(const string& name);

  void RunMenu();

  string toString() const;
};
#endif
