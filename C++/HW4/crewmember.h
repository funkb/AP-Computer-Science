#ifndef CREWMEMBER_H
#define CREWMEMBER_H

#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class CrewMember{
private:
  string name = "";
  int IDNum = 0;
  string type = "";
public:
  CrewMember();
  CrewMember(const string& name, const int& IDNum, const string& type);

  string GetName() const;
  void   SetName(const string& name);

  int    GetIDNum() const;
  void   SetIDNum(const int& IDNum);

  string GetType() const;
  void   SetType(const string& type);

  string toString() const;
};
#endif
