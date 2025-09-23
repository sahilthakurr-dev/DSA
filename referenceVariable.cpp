#include<iostream>
using namespace std;

void update(int n ){
    n++;
    cout<<"Function n "<<n<<endl;
}
void update2(int& n ){
    n++;
}

int getSum(int arr[], int n){

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += arr[i];
    }
    
    return sum;
}
int main(){

    // int i = 5;
    // //create a refernce
    // int& ref = i;
    // ref++;
    // i++;

    // cout<<ref<<endl;

    // int n  = 5;
    // cout<<"Before "<<n<<endl;
    // update2(n);
    // cout<<"After"<<n<<endl;

   




}

