#include "crewmanager.h"

CrewManager::CrewManager(){ }
CrewManager::~CrewManager() { }

void CrewManager::AddMember(){
  string name;
  int ID;
  string type;
  cout << "Crew Member\'s Name: ";
  cin.ignore();
  getline(cin,name);
  cout << name << "\'s ID#: ";
  cin >> ID;
  cin.ignore();
  cout << name << "\'s Role (Pilot/Cabin Crew): ";
  getline(cin,type);
  crew.push_back(CrewMember(name,ID,type));
}
void CrewManager::AddMember(CrewMember& member){
  crew.push_back(member);
}

void CrewManager::EditMember(const int& ID){
  if(MemberExists(ID)){
    cout << "Editing " << Find(ID).GetName() << ":" << endl;
    enum options{NAME=1,IDNUM=2,TYPE=3,EXIT=4};
    int sel;
    bool exit = false;
    while(!exit){
      cout << "Select the option to change: " << endl;
      cout << "1. Name" << endl << "2. ID Number" << endl << "3. Role" << endl << "4. Exit" << endl;
      cout << ">";
      cin >> sel;
      switch(sel){
        case NAME:{
          string nameNew;
          cout << "New name >";
          cin.ignore();
          getline(cin,nameNew);
          Find(ID).SetName(nameNew);
        }break;
        case IDNUM:{
          int id;
          cout << "New id >";
          cin >> id;
          cin.ignore();
          Find(ID).SetIDNum(id);
        }break;
        case TYPE:{
          string role;
          cout << "New role >";
          cin.ignore();
          getline(cin,role);
          Find(ID).SetType(role);

        }break;
        case EXIT:
        default:
          exit=true;
          break;
      }
    }
  }else{
    cout << "Couldn\'t find that employee." << endl;
  }
}

void CrewManager::DeleteMember(const int& ID){
  if(MemberExists(ID)){
    for (iter = crew.begin(); iter != crew.end();++iter){
      if(iter->GetIDNum() == ID){
        iter = crew.erase(iter);
        return;
      }

    }
  }else
    cout << "Couldn\'t find that employee." << endl;

}

bool CrewManager::MemberExists(const int& ID){
  for (auto const& i : crew){
    if(i.GetIDNum() == ID)
      return true;
  }
  return false;
}

CrewMember& CrewManager::Find(const int& ID){
  if(MemberExists(ID)){
    for (auto& i : crew){
      if(i.GetIDNum() == ID)
        return i;
    }
  }else
    cout << "Couldn\'t find that employee." << endl;
}

void CrewManager::PrintMembers(){
  cout << "\nCrew Member's: " << endl;
  for (auto const& i : crew){
    cout << i.toString() << endl;
  }
}

void CrewManager::Print(const int& ID){
  if(MemberExists(ID))
    cout << Find(ID).toString() << endl;
  else
    cout << "Could\'t find an employee with ID#:" <<to_string(ID) << endl;
}

void CrewManager::RunMenu(){
  bool running = true;

  while (running){
    int option;
    cout << "=====Crew Menu=====" << endl;
    printf("1. Add Crew Member\n2. Edit Crew Member\n3. Delete Crew Member\n4. Print Crew Member\n5. Print All Crew\n6. Exit\n>");
    cin >> option;
    switch(option){
      case 1:{
        AddMember();
      }break;
      case 2:{
        int id;
        printf("\n=====Edit Menu=====\n");
        printf("Enter ID# >");
        cin >> id;
        EditMember(id);
      }break;
      case 3:{
        int id;
        printf("\n=====Delete Menu=====\n");
        printf("Enter ID# >");
        cin >> id;
        DeleteMember(id);
      }break;
      case 4:{
        int id;
        printf("\n=====Print Menu=====\n");
        printf("Enter ID# >");
        cin >> id;
        Print(id);
      }break;
      case 5:{
        PrintMembers();
      }break;
      case 6:{
        running=false;
        break;
      }
      default:
        cout << "Enter a valid option!" << endl;
    }
  }
}


string CrewManager::toString() const{
  return "";
}
