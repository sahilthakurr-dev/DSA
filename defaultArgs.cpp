#include<iostream>
using namespace std;

void printArr(int arr[], int size, int start = 0){
    for (int  i = 0; i < size; i++)
    {
     cout<<" "<<arr[i]<<" "<<endl;
    }
    
}


int main(){
    
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    printArr(arr, size);



}