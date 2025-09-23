#include<iostream>
using namespace std;


int addValue(int num[],int size){
    int sum=0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + num[i];
    }

    return sum;
    
}

int main(){
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    cout<<"Enter the value"<<endl;
    int num[50];

    for (int i = 0; i <size; i++)
    {
       cin>>num[i];
       
    }

    int result = addValue(num, size);
    cout<<"Sum of the array is: "<<result<<endl;
}