#include<iostream>
using namespace std;

int factorial(int n) {
    if (n < 0) return -1; // error case
    if (n == 0) return 1; // base case
    return n * factorial(n - 1);
}

int power(int n ){
    // base case
    if (n==0) return 1; 
   //recursive case
    return 2 * power(n-1);
    
}

// head recursion -->
void count(int n ){
    if (n==0)
    {
        return;
    }
    count(n-1);
    
    cout<<n<<endl;
    
    
}

int fibonnaciNumberPosition(int n ){
    if(n==0) return 0;
    if(n==1) return 1;
    int ans = fibonnaciNumberPosition(n-1) + fibonnaciNumberPosition(n-2);
    return ans;
}

void sayDigit(int n , string arr[]){
    if(n==0){
        return;
    }

    int digit = n%10;
    n = n/10;
    sayDigit(n , arr);
    cout<<""<<arr[digit-1]<<" ";
}
int main(){
    int n ;
    cin>> n;
    // int ans = factorial(n);
    // int ans = power(n);
    // count(n);

    // int ans = fibonnaciNumberPosition(n);
    string arr[10] = {"one", "two","three", "four", "five","six","seven","eight","nine","ten"};
    sayDigit(n, arr);
 

    

    // cout<<ans<<endl;
}

// #include<iostream>
// using namespace std;

// void numberToDigits(int& digit, string mapping[]){
//     //base condtion
//     if (digit == 0)
//     {
//        return;
//     }
    
//     int singleDigit = digit % 10;
//     digit = digit/10;
//     //recursive relation
//     numberToDigits(digit, mapping);
    
//     cout<<mapping[singleDigit]<<endl;

    
// }

// int main(){

//     int digit = 123;
//     string mapping[11] = {"zero","one", "two","three","four","five","six","seven","eight","nine","ten"};
//     numberToDigits(digit, mapping);
// }