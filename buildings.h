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


    building(int id, string name) //constructor
            : id(make_unique<int>(id)), name(make_unique<string>(name))
    {}//constructor body

    //setters
    void setId(int id){
        this->id = make_unique<int>(id);
    }
    void setName(string name){
        this->name = make_unique<string>(name);
    }
    //getters
    int getId(){
        return *id;
    }
    string getName(){
        return *name;
    }
    virtual void printData();
    friend class floor;
};
class floor{ //friend class floor
    static int count;
    unique_ptr<int> level;
    unique_ptr<int> squareArea;
    unique_ptr<string> access; //staff only,students,executives only ,etc
public:

    floor(int level,int squarArea,string access,building targetBuilding)
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
public:
    void printData()override{

    }
};
//boom
