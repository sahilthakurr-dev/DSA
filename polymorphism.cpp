#include<iostream>
#include<string>
using namespace std;

// class A{
//   public:
//   void sayHello(){
//     cout<<"Hello Sahil"<<endl;
//   };

//   void sayHello(string name){
//     cout<<"Hello "<<name<<endl;
//   }

//   int sayHello(string name, int n){
//     cout<<"Hello "<<name<<endl;
//     return n;
//   }
// };

// class B{
//     public:
//     int a;
//     int b;

//     int add(){
//        return a+b;
//     }

//     int operator + (B &obj){

//         return this->a * obj.a;

//     }

//     void operator () (){
//         cout<<"Bracket call hua h bhai"<<this->a;

//     }
// };

//  int main(){

// //function overloading
//     A obj4;
//     obj4.sayHello();
//     obj4.sayHello("sahil");




// //operator overloading
//    B obj;
//    obj.a = 3;
//    obj.b = 4;

//    cout<<obj.add()<<endl;

//    B obj1, obj2;

//    obj1.a = 3;
//    obj2.a = 4;

//   cout<<obj1 + obj2<<endl;
//   obj1();
  

//  }


class Animal{
    public:

    void speak(){
        cout<<"Speaking"<<endl;
    }
};


class Dog:public Animal{
    public:

    void speak(){
        cout<<"Barking"<<endl;
    }

};



int main(){
    Dog obj;
    obj.speak();

}
