#include<iostream>
#include <algorithm>
using namespace std;


void reverse(int arr[], int size){
    int start = 0;
    int end = size-1;
    while (start<=end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }


    
}
bool search(int arr[], int size, int key){

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
        
    }
    return 0;
    

}

void alternateSwap(int arr[], int size){
    int start=0;
    int end=1;
    while (end<=size-1)
    {
        swap(arr[start],arr[end]);
        start = start+2;
        end=start+1;
    }
    
}

int printingArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
       cout<< arr[i];
    }
    
}

int main(){
    int arr[10]= {5,7,-3,1,5,6,7,8,9,2};
    
    // WHEATHER 1 IS PRESENT OR NOT??
    // int key;
    // cout<<"Enter the value you want to find :"<<endl;
    // cin>>key;

    // int found = search(arr, 10,key);

    // if (found)
    // {
    //     cout<<key<<" found"<<endl;
    // } else {
        
    //     cout<<key<<" not found "<<endl;
    // }

    // REVERSING THE ARRAY

    
    int incr[6]= {1,2,3,4,5,6};
    int decr[5]= {6,5,4,3,2};

    // AFTER REVERSING INCR BECOMES DECR AND DECR WILL BECOME INCR;

// reverse(incr,6);

// reverse(decr,5);


// PRINTTING THE ARRAY

// SWAPING ALTERNATE NUMBER

alternateSwap(incr,6);

printingArray(incr,6);


    
}