#include<iostream>
using namespace std;

int FirstOccuranceSearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid =  start + (end- start)/2;
    int ans = -1;

    while (start<=end)
    {
       if (arr[mid]== key)
       {
        ans = mid;
        end = mid-1;

       } else if (key>arr[mid])
       {
        start = mid +1;
       } else if (key<arr[mid])
       {
       end = mid-1;
       }

       mid = start + (end - start)/2;
       
       
       
    }
    
    return ans;

}


int LastOccuranceSearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid =  start + (end- start)/2;
    int ans = -1;

    while (start<=end)
    {
       if (arr[mid]== key)
       {
        ans = mid;
       start = mid+1;

       } else if (key>arr[mid])
       {
        start = mid +1;
       } else if (key<arr[mid])
       {
       end = mid-1;
       }

       mid = start + (end - start)/2;
       
       
       
    }
    
    return ans;

}

int binarySearch(int arr[], int size, int key){
    int start = 0;
    int end = size-1;

    int mid = (start + end)/2;

    while (start<=end)
    {
        if (arr[mid]== key)
        {
           return mid;
        }
        //  go to right part
        if (key>arr[mid])
        {
            start = mid+1;
        } 
        // else go to left part
        else {
            end = mid-1;
        }

        mid = (start + end)/2;

        
        
    }

    return -1;
   
}
    
    
int peviotElement(int arr[], int size){
    int start =0;
    int end = size-1;
    int mid = start +( end - start  )/2;

    while (start<end)
    {
       if (arr[mid]>=arr[0])
       {
       start = mid + 1;
       } else {
        end = mid;
       }

       mid = start + (end-start)/2;
       
    }

    return start;
    

}

int main(){
    int even[6]= {2,3,4,5,6,7};
    int odd[5] = {7,6,5,3,2};
    int arr[5] ={1,2,3,3,5};
    int rotSortArr[5]= {4,5,1,2,3};

    // int index = binarySearch(even, 6,8);
    // cout<<"index  is"<<" "<<index<<endl;
    // cout<< "first ouccurance of 3 is "<<FirstOccuranceSearch(arr, 5, 3)<<endl;
    // cout<< "last ouccurance of 3 is "<<LastOccuranceSearch(arr, 5, 3)<<endl;
    // int firstOccurance = FirstOccuranceSearch(arr, 5, 3);
    // int lastOccurance = LastOccuranceSearch(arr, 5, 3);
    // int totalOccurances = (lastOccurance -firstOccurance) + 1;

    // cout<< "total number of occurances is  "<<totalOccurances<<endl;
 int peviotIndex = peviotElement(rotSortArr, 5);
 
 cout<<"The peviot index is "<<peviotIndex<<endl;

 
}