//Recursion with Binary Search
#include<iostream>
#include<vector>
using namespace std;


//Simple brute force
// bool isSorted(int arr[], int size){
   

//     for (int i = 0; i < size-1; i++)
//     {
//     
//       if(arr[i]>arr[i+1]){
//         return false;
//       }
//      
//     }

//     return true;
    
// }
     
bool isSorted(int arr[], int size){
    if(size == 0 || size == 1) return true;

    if(arr[0]>arr[1]){
        return false;
    }else{
         bool ans = isSorted(arr + 1, size - 1);
         return ans;
         
    }

    

}

int arraySum(int arr[], int size){
    if(size == 0) {
        return 0;
    }
    return arr[0] + arraySum(arr + 1, size - 1);
}

// int arraySum(int arr[], int size){
//     if(size == 0){
//         return 0;
//     }
//     if(size == 1){
//         return arr[0]; 
//     }

//     int sum = arr[0] + arr[1];
//     return sum + arraySum(arr + 2, size - 2);
// }


// LINEAR SEARCH-->
bool linearSearch(int arr[], int size, int key){
    // base condition
    if(size == 0) return false;
    if(arr[0] == key){
        return true;
    } 
    // recursive relation
    return linearSearch(arr+1,size-1,key);

   
}

bool binarySearch(int arr[], int start, int end, int key){
    
    if(start>end) return false;
    
    int mid = start + (end-start)/2;
    
    if(arr[mid]== key){

        return true;

    } else if(arr[mid]>key){

        end = mid-1;
    } else{

        start = mid + 1;
    }
    
    return binarySearch(arr,start,end,key);
 }


int main(){

  int arr[5] ={1,2,3,8,9};
  int size = sizeof(arr)/ sizeof(arr[0]); 

//   if (isSorted(arr, size))
//   {
//    cout<<"Array is sorted"<<endl;
//   } else{
//     cout<<"Array is not sorted"<<endl;
//   }
  int total = arraySum(arr, size);
  cout<<"Sum is "<< total <<endl;
  bool ans1 = linearSearch(arr, size, 2);

  if(ans1){
    cout<<"Found"<<endl;
  }else{
    cout<<"Not found"<<endl;
  }
 
  bool ans2 = binarySearch(arr,0 ,size-1,2);
if(ans2){
    cout<<"Found"<<endl;
    } else{
        cout<<"Not Found"<<endl;
    }
}

    

    

