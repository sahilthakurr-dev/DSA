#include<iostream>
#include <cstring>
using namespace std;

class Hero{
    int health;
    int level;
    public:
    char *name;
    static int timeToComplete;
    
    //creting simple constructor
    Hero(){
        cout<<endl;
        cout<<"Simple constructor called"<<endl;
        name =  new char[100];
    }
    //creating  prameterize constructor
    Hero(int health, int level){
        cout<<"constructor 1 called"<<endl;
        this-> health = health;
        this-> level = level;
    }

    //creating copying constructor

    Hero(Hero& temp){
        cout<<"Copy constructor called"<<endl;
        //deep copy
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->health = temp.health;
        this->level = temp.level;
        this->name = ch;
    }

    void setHealth(int health){
        this-> health = health;

    }

    void setLevel(int level){
        this-> level = level;
    }

    int getHealth(){
        return health;
    }

    int getLevel(){
        return level;
    }

    void setName(char name[]){
         strcpy(this->name, name);
        
    }

    void print(){
        cout<<endl;
        cout<<"[ ";
        cout<<"Name is "<<this->name<<", ";
        cout<<"Level is "<<this->level<<", ";
        cout<<"Health is "<<this->health;
        cout<<" ]"<<endl;
        

    }

    // static function

    static int random(){
      return Hero::timeToComplete;
    }
//destructor used to deallocate
    ~Hero() {
    cout << "Destructor called" << endl;
    delete[] name;
}
        

};

int Hero::timeToComplete = 5;

int main(){
    Hero raju(100,10);
    //copying the object
    Hero ramesh(raju);

    cout<<ramesh.getHealth()<<endl;
    cout<<ramesh.getLevel()<<endl;
  
    Hero hero1;
    char name[6] = "Sahil";
    hero1.setName(name);
    hero1.setHealth(100);
    hero1.setLevel(10);
    hero1.print();
    

 
    Hero hero2(hero1);
    hero2.print();
  
   hero1.setName("Rohan");

   hero1.print();

   hero2.print();

   hero1 = hero2;

   hero1.print();
   hero2.print();

   Hero *hero3 = new Hero;
   hero3->setName("Rahul");
   hero3->setHealth(60);
   hero3->setLevel(05);
   hero3->print();

   delete hero3;

cout<<Hero::timeToComplete<<endl;
cout<<Hero::random()<<endl;
    
    
}


    

    
   
