#include<iostream>
using namespace std;

class Hero {
    //properties

    public:
    char name[100];
    int  health;

    int level;

    void print(){
        cout<<level<<endl;
    }

    int getHealth(){
        return health;
    }

    int getLevel (){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(int l){
        level = l;
    }

};        

int main(){
    //creation of object statically
    Hero ramesh;
   ramesh.setHealth(100);
   ramesh.setLevel(10);
    cout<<"Health is "<<ramesh.health<<endl;
    cout<<"Level is "<<ramesh.level<<endl;
//dynamically 
    Hero *raju = new Hero;
    raju->health = 80;
    raju->level = 5;

    cout<<"Health is "<<(*raju).health<<endl;
    cout<<"Level is "<<(*raju).level<<endl;


    //using setter
    // ramesh.setHealth(70);

    // //using getter
    // cout<<ramesh.getHealth()<<endl;

    // //accessing elements
    // // ramesh.health = 100;
    // ramesh.level = 2;
    
    // // cout<<"Health is "<<ramesh.health<<endl;
    // cout<<"Level is "<<ramesh.level<<endl;




}