#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];     
        int j = i - 1;

       
       while (j >= 0){
        if (arr[j] > temp) {   
        //  shift the elements
        arr[j + 1] = arr[j];
        j--;
    } else {
        break;
           }
      } 
             
    arr[j + 1] = temp;

    }
}
        
      

void bubbleSort(int arr[], int size){

    // we started i= 1 because its shows the number of rounds which goes like 1<n

    for (int i = 1; i < size; i++)
    {
       for (int j = 0; j < size-i; j++)
       {
        if (arr[j]>arr[j+1])
        {
           swap(arr[j], arr[j+1]);
        }
        
       }
       
    }
    

}

 void selectionSort(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;

        for (int j = i+1; j <size; j++)
        {
           if (arr[j]<arr[minIndex])
           {
            minIndex = j;
           }
           
        }
        swap(arr[minIndex],arr[i]);
    }
    
 }

 void printingArr(int arr[], int size){
    for (int i = 0; i <size; i++)
    {
      cout<<" "<<arr[i]<<" ";
    }
    
 }

int main(){
    int arr[5]= {3,5,7,1,2};
    int arr2[6]={1,7,6,10,9,14}; 

    // // selectionSort(arr,5);
    // bubbleSort(arr2,6);
    int arr3[5]= {2,4,5,1,7};
    insertionSort(arr3, 5);
    printingArr(arr3,5);
}