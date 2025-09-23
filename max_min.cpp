#include<iostream>
#include <climits>
using namespace std;

int MaxValue(int num[], int n){
    int max = INT_MIN;

    for (int i = 0; i <n; i++)
    {
     if (num[i]>max)
     {
       max = num[i];
     }
     
    }
    
    return max;
}

int MinValue(int num[],int n ){
    int min = INT_MAX;
    for (int i = 0; i < i; i++)
    {
      if (num[i]<min)
      {
        min = num[i];
      }
      
    }
     return min;
}

int main(){
    int size;
    cin>>size;

    int num[100];

    for (int i = 0; i <size; i++)
    {
        cin>>num[i];
    }

    cout<<"Maximum values is "<<MaxValue(num,size)<<endl;
    cout<<"Minimum values is "<<MinValue(num,size);


    
}