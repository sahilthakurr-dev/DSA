#include<iostream>
#include<string>
using namespace std;

class Human{
    public:

    int heigt;
    int weight;

    protected:
    int age = 0;

    public:

   

    void setWeight(int weight){
        this->weight = weight;
    }
};

//syntax 
class Male:public Human{
    public:

    string color;
    
     int getAge(){
        return this->age;
    }

    

    void sleep(){

        cout<<"Male sleeping"<<endl;
    }
    
};



int main(){

    Male one;

   cout<< one.getAge()<<endl;

   

}
