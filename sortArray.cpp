#include<iostream>
using namespace std;


// void sortArray(int arr[], int n) {
//     int count0 = 0; 
//     int count1=0;
//     int count2=0;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i]==0)
//         {
//        count0++;
//        } else if (arr[i]==1)
//        {
//         count1++;
//        }else{
//         count2++;
//        }
       
//     }
// int index= 0;
//         for (int i = 0; i < count0; i++)
//         arr[index++] = 0;

   
//     for (int i = 0; i < count1; i++)
//         arr[index++] = 1;


//     for (int i = 0; i < count2; i++)
//         arr[index++] = 2;

    
       
    
   
// }

void sortArray(int arr[], int n ){
    // int left =0;
    // int right = n-1;
    
    // while (left<right)
    // {
    //     while (arr[left]==0 && left<right)
    //     {
    //         left++;
    //     }

    //     while (arr[right]==1 && left<right)
    //     {
    //         right--;
    //     }

    //     swap(arr[left], arr[right]);
    //     left++;
    //     right--;

    // }

    int count0= 0;
    int count1=1;

    for (int i = 0; i <n; i++)
    {
        if (arr[i]==0)
        {
            count0++;
        } else{
            count1++;
        }
        
    }

    int index=0;

    for (int i = 0; i < count0; i++)
    {
        arr[index++] = 0;
    }

    for (int i = 0; i < count1; i++)
    {
       arr[index++]=1;
    }
    
    

}

    
        
        
        
  
    
    
void printingArray(int arr[], int n){

    for (int i = 0; i <n; i++)
    {
        cout <<" "<<arr[i]<<" ";
    }
    cout<<endl;
    
}



int main(){
    int arr[8]={1,1,0,1,1,0,1,0};

    sortArray(arr, 8);

    // sortArray(arr,8);

    printingArray(arr,8);
}