#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    int height;
    int age;

    public:
// constructor
    Student(string name, int age , int height){
        this->age = age;
        this->height = height;
        this->name = name;

    }

    int getAge(){
      return this->age;
    }

    void print(){
        cout<<"Name is "<<this->name<<endl;
        cout<<"Age is "<<this->age<<endl;
        cout<<"Height is "<<this->height<<" cm "<<endl;
    }
};

int main(){
    string name = "sahil";
    int age = 21;
    int height = 160;
    Student first(name,age,height);
    first.print();

}

    

