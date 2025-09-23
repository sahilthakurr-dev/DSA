#include<iostream>
using namespace std;

void printingArray(int arr[], int size){
    cout<<"Printing the array"<<endl;

    for (int i = 0; i <size; i++)
    {
        cout<<"Printing the function array"<<arr[i]<<endl;
    }
    
}

int main(){

//    declare array

int number[15] = {1,3,5};

// for (int i = 0; i <15; i++)
// {
//    cout<<number[i];
// }

int score[4]= {80,50,60,99};
int size = sizeof(score)/sizeof(int);

printingArray(score,4);





    
}