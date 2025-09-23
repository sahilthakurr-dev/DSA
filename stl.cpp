#include<iostream>
#include<array>
#include<vector>
using namespace std;

int main (){
// 1. ARRAYS
    // array<int,4> a = {1,2,3,4};

    // int size = a.size();

    // for (int i = 0; i < size; i++)
    // {
    //     cout<<a[i]<<endl;
    // }
    // // returns the element of the index
    // cout<<"Element at 2nd index"<< a.at(2)<<endl;

    // //empty returns boolean
    // a.empty();
    // // returns the first and last element of an array
    // a.back();


// 2. VECTORS 
   
   vector<int> v;
   int size = v.size();

    

    for(int i =0;i<10;i++){
        v.push_back(i);
 }

    for(auto i :v){
        cout<<i<<endl;
    }

    

}



