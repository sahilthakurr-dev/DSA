#include <iostream>
using namespace std;

// int power(int a, int b){
//     int ans = 1;
//         for (int i = 1; i <=b; i++)
//         {
//             ans = ans * a;
//         }

//         return ans;
        
// bool IsEven(int num){
//     if (num%2==0)
//     {
//        return true;
//     } else{
//         return false;
//     };
    
// };

// int factorial(int n){
//     int factorial = 1;
//     for (int i = 1; i <=n; i++)
//     {
//         factorial *=i;

//     }
//     return factorial;
// }
// int ncr(int n, int r){
//     int numerator = factorial(n);
//     int denominator = factorial(r)*factorial(n-r);

//     int ans = numerator/denominator;
//     return ans;

   
// }

// };

// bool isPrime(int n){
//     for (int i = 2; i < n; i++)
//     {
//        if (n%i==0)
//        {
//         return 0;  // 0-> false
//        } else{
//         return 1; // 1-> true
//        }
//     }
    
// }

// int AP(int n){
//  int ap = (3*n)+7;
//  return ap;
// }

// int countBit(int a, int b){
//     int count =0;

//    for (;a!=0;)
//    {
//      if (a&1)
//    {
//     count++;
//    };

//    a = a>>1;
  

//    }
//    for (; b!=0;)
//    {
//      if (b&1)
//    {
//     count++;
//    };
//     b= b>>1;

//    }

//      return count;
    
// }

int series(int num){
    int a=0;
    int b =1;
    // cout<<a<<endl;
    // cout<<b<<endl;
    int nextNumber =0;
  
    
if(num ==1 ) return a;
if (num ==2) return b;
     
     
    for (int i = 3; i <=num; i++)
    {
         nextNumber = a+b;
        a=b;
        b=nextNumber;
        // cout<<nextNumber<<endl;
        if (i==num)
        {
           return nextNumber;
          
        }
        
      
    }


    
}

int main(){

    int a;
    // int b;


    cin>>a;
    // cin>>b;

    int result =  series(a);


    cout<<"Number is  : "<<result;
    
    
    
//    int result =  isPrime(a);
//    if (isPrime(a))
//    {
//     cout<<"Is Prime number"<<endl;
//    } else{
//     cout<<"Not a Prime number"<<endl;
//    }
    

//    cout<<"Result is "<<result<<endl;



 

}

