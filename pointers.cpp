#include <iostream>
#include <string.h>
using namespace std;

void print(int *p){
    cout<<*p<<endl;
}

void updatePointer(int *p){
    (*p)++;
    cout<<*p<<endl;
}

int main() {
    // int a = 10;
    // int* p = &a;

    // cout << "Address of a: " << &a << endl;
    // cout << "Address stored in p: " << p << endl;
    // cout << "Value pointed to by p: " << *p << endl;

    // *p = 20;
    // cout << "New value of a: " << a << endl;

    // double b = 4.2;
    // double* p2 = &b;

    //   cout << "Address of b: " << &b << endl;
    // cout << "Address stored in p2: " << p2 << endl;
    // cout << "Value pointed to by p2: " << *p2 << endl;

    // cout<<"Size of integer is "<<sizeof(b)<<endl;
    // cout<<"Size of poiner  is "<<sizeof(p2)<<endl;

    
    
    // pointer to int is created and pointing to some garbage value;;
    // int* p = 0 ;

    // cout<<*p<<endl;


//     int i = 5;
//     // int* p = &i;

//    int* p = 0;
//    p = &i;

//    cout<<p<<endl;
//    cout<<*p<<endl;

// int num = 5;
// int a= num;
// int *p = &num;
// (*p)++;
// a++;

// cout<<a<<endl;
// cout<<num<<endl;

// //copying a pointer

// int *q = p;
// cout<<p<<" - "<<q<<endl;
// cout<<*p<<" - "<<*q<<endl;

// int i = 3;
// int* t = &i;
// (*t)++;


// cout<<*t<<endl;
// cout<<&i<<endl;
// cout<<(*t)++<<endl;


// int arr[10] = {1,2,3,4};

// int *p = &arr[0];

// cout<<arr<<endl;
// cout<<p<<endl;
// cout<<*arr<<endl;
// cout<<(*arr)++<<endl;
// cout<<*arr<<endl;
// cout<<*(arr+1)<<endl;


// int i =2;
// cout<<i[arr]<<endl;

// cout<<p<<endl;
// cout<<&p<<endl;


// int arr[10];

// int *p = &arr[0];

// p= p+1;

// cout<<&arr[0]<<endl;
// cout<<p<<endl;


// int arr[5] = {1,2,3,4,5,};
// char ch[6] = "abcde";

// char *p = &ch[0];


// cout<<arr<<endl;
// cout<<p<<endl;
// cout<<ch<<endl;


// char temp = 'z';
// char *p2 = &temp;

// cout<<p2<<endl;

int value = 5;
int *p  = &value;

print(p);
updatePointer(p);
cout<<*p<<endl;






    return 0;
}
