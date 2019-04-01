#include "crewmember.h"

CrewMember::CrewMember(){
  this->name = "";
  this->IDNum = 0;
  this->type = "";
}

CrewMember::CrewMember(const string& name, const int& IDNum, const string& type) :
 name(name), IDNum(IDNum), type(type){ }

string CrewMember::GetName() const{
  return name;
}
void CrewMember::SetName(const string& name){
  this->name = name;
}

int CrewMember::GetIDNum() const{
  return IDNum;
}
void CrewMember::SetIDNum(const int& IDNum){
  this->IDNum = IDNum;
}

string CrewMember::GetType() const{
  return type;
}
void CrewMember::SetType(const string& type){
  this->type = type;
}

string CrewMember::toString() const{
  stringstream ss;
  ss << setw(20) << left << name << "  ID: " << setw(6) << to_string(IDNum) << "  " << type;
  //return name + "  ID:" + to_string(IDNum) + " " + type;
  return ss.str();
}
