#include <iostream>
#include <memory>
using namespace std;
//2l ozzy
class building {//abstract class for all buildings
protected:
    //here we use dynamic allocation by using unique_ptr to prevent memory leaks
    unique_ptr<int> id;
    unique_ptr<string> name;
    unique_ptr<int> numOfLevels;
public:
    building(int id, const string& name,int numOfLevels) //constructor
            : id(make_unique<int>(id)), name(make_unique<string>(name)),numOfLevels(make_unique<int>(numOfLevels))
    {}//constructor body

    //setters
    void setId(int id){
        this->id = make_unique<int>(id);
    }
    void setName(const string& name){
        this->name = make_unique<string>(name);
    }
    void setNumOfLevels(int numOfLevels){
        this->numOfLevels = make_unique<int>(numOfLevels);
    }
    //getters
    int getId(){
        return *id;
    }
    string getName(){
        return *name;
    }
    int getNumOfLevels(){
        return *numOfLevels;
    }
    virtual void printData() = 0;
    friend class floor;
};
class floor{ //friend class floor to building abstract class
    static int count;
    unique_ptr<int> level;
    unique_ptr<int> squareArea;
    unique_ptr<string> access; //staff only,students,executives only ,etc
public:

    floor(int level,int squarArea,const string& access,building targetBuilding)
            : level((level > *targetBuilding.numOfLevels) ? make_unique<int>(level) : nullptr), squareArea(make_unique<int>(squarArea))
            , access(make_unique<string>(access))
    {
        count++;
    }
};
class adminBuilding:public building{

public:
  void printData()override{

  }
};
class facuiltyBuilding:public building{
    unique_ptr<int> numOfLabs;
public:
    facuiltyBuilding(int id, const string &name, int numOfLevels,int numOfLabs)
    : building(id, name, numOfLevels),numOfLabs(make_unique<int>(numOfLabs))
    {}
    void setNumOfLabs(int numOfLabs){
        this->numOfLabs = make_unique<int>(numOfLabs);
    }
    int getNumOfLabs(){
        return *numOfLabs;
    }
    void printData()override{
        cout<<"+++++++++++++++++++++\nName: "<<getName()<<"\n"<<
        "ID: "<<getId()<<"\n"<<
        "Number of Levels: "<<getNumOfLevels()<<"\n"<<"+++++++++++++++++++++\n";
    }
};
//boom

