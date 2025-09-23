#include<iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col){

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

void PrintSum(int arr[][4], int row , int col){
    int sum = 0;
    int maxi = arr[0][0];
    int largestRow = 0;
    for(int i =0; i<row; i++){
        for (int j = 0; j < col;j++)
        {
           sum += arr[i][j];
           if(maxi<sum)
           {
            maxi = sum;
            largestRow = row;
           }
        }
        cout<<"Sum of the "<<i<<" row is "<<sum<<endl;
        
    }

    cout<<"Largest sum of the element is "<<maxi<< " in row "<<largestRow<<endl;

}

void Transpose(int arr[][3], int row, int col){

    for (int i = 0; i < row; i++)
    {
        for (int j = i+1; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        
    }
    

}
int main(){

    // creation of 2D array

    int arr[3][3];
    cout<<"Enter the elements"<<endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>> arr[i][j];
        }
        
    }
    
    Transpose(arr, 3,3);
    // printing 

    for(int i =0; i<3;i++){
        for (int j = 0; j < 3; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        
    }

    // PrintSum(arr, 3, 4);
    // cout<<"Enter the element to search"<<endl;
    // int search;
    // cin>>search;
    // if(isPresent(arr, search , 3,4)){
    //     cout<<"Element found"<<endl;
    // } else{
    //     cout<<"Not found"<<endl;
    // }


}