#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> &v){
   int  start = 0;
   int end = v.size()-1;

    while(start<=0){
         swap(v[start], v[end]);
         start++;
         end--;

    }
    return v;
}

vector<int> indexReverse(vector<int>& v, int key){
    int start = key + 1;
    int end = v.size() - 1;
    

    while (start<=end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }

    return v;
    
}

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // vector<int> ans = reverse(v);
    // vector<int> ans2 = indexReverse(v, 1);
    
    // for ( auto num : ans2)
    // {
    //    cout<<" "<<num<<" ";
    // }
    
}