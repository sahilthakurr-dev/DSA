#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // int n;
    // cin >> n;
    // string binary;  

    // while (n != 0) {
    //     int remainder = n % 2;
    //     binary = to_string(remainder) +  binary ; 
    //     cout << "Remainder: " << remainder << endl;
    //     n = n / 2;
    //     cout << "Division: " << n << endl;
    // }
    
    // cout << "Binary: " << binary << endl;


// BINARY TO DECIMAL;

    int n ;
    cin>>n;
    int ans =0;
    int i =0;

    while (n!=0)
    {
      int digit = n%10;

      if (digit ==1)
      {
       ans = ans + pow(2,i);
      }
      i++;
      n=n/10;
      
    }
    cout<<ans<<endl;
    
    
}
