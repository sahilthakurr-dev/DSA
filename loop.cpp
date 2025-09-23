#include <iostream>
#include <string>
using namespace std;

int main(){
//     int a;
//     cin>>a;
//    if(a>0){
//     cout<<"A is positive"<<endl;
//    }else{
//     cout<<"A is negative"<<endl;
// }

//  int a,b;
//  cout<<"Enter the value of A:";
//  cin>>a;
//  cout<<"Enter the value of B:";
//  cin>>b;

//  if(a>b){
//     cout<<"A is greater than B"<< endl;
//  } else{
//     cout<<"B is greater than A"<< endl;
//  }

// int a;
// cout<<"Please enter the number:";
// cin>>a;
// if(a>0){
//     cout<<"Number is positive"<< endl;
// } else if (a<0)
// {
//    cout<<"Number is negative"<< endl;
// } else{
//     cout<<"Number is zero"<< endl;
// }

// char ch;
// cout<<"Enter the character:";
// cin>>ch;
// if(ch >= 'a' && ch <= 'z'){
// 	cout<< "Alphabet is lowercase"<< endl;
// } else if(ch>='A' && ch<='Z'){
//     cout<<"Alphabet is uppercase"<< endl;
// } else{
//     cout<<"Unknown"<< endl;
// }

// PROGRAM FOR KNOWING THE ASCII VALUE OF THE CHARACTER;

// char ch;
// cout<<"Enter the Alphaet:";
// cin>>ch;
// cout<<"The ASCII value of the Alphabet is "<<(int)ch<<endl;

// int n;
// cout<<"Enter the number";
// cin>>n;
// int a = 0;
// int sum=0;
// while( a<=n){
//     sum+=a;
   
//     a++;
// }
//  cout <<sum << endl;
// }

// for (int i = 1; i <= 1000000; i++) {
//     cout << i << " ";
// }

// int a;
// cout<<"Enter the number:";
// cin>>a;
// int i =0;
// int sum= 0;
// while (i<=a)
// {
// //  sum+=i;
// //  i=i+2;
// if(i%2==0){
//     sum+=i;

// }
// i++;
// }
// cout<<"Sum is:"<<" "<<sum<<endl;

// int a;
// cout<<"Enter the number";
// cin>>a;
// int i=1;
// while(i<=a){
//     if(i>1 && i<5){
//         if(a%i!=0){
//             cout<<a<<" "<<"is a Prime number";
//         } else{
//              cout<<a<<" "<<"is  not a Prime number";
//         }
//     }
//     i++;
// }

// int a;
// cin>>a;
// int sum=0;
//  for (int i = 0; i <=a; i++)
//  {
//  sum+=i;
//  }
 
// cout<<sum<<endl;

// int n = 10;
// int a = 0;
// int b = 1;

// cout << a << endl;  // Print first term
// cout << b << endl;  // Print second term

// for (int i = 2; i <= n; i++) {
//     int nextNumber = a + b;
//     cout << nextNumber << endl;

//     a = b;
//     b = nextNumber;
// }


// int a;
// cin>>a;
// bool isPrime = true;

// for (int i = 2; i <a; i++)
// {
//    if(a%i==0){

//     isPrime=false;
//     // break;
//    } 

// }
//    if(isPrime==false){
//     cout<<"Not a prime number"<< endl;
//    }  else{
//     cout<<"Is a prime number"<<endl;
//    }

   
// int x = 123;
// int c = 0;
// while (x!=0)
// {
//     x+=1;
//    cout<<c<<endl;
//    c++;
   
// }

int a;
cout<<"Enter the first number:"<< endl;
cin>>a;

int b;
cout<<"Enter the second number:"<< endl;
cin>>b;

char ch;
cout<<"What you want to perform?"<<endl;
cin>>ch;

switch (ch)
{
    case '+':
       cout<<"Sum of"<<a<<"and"<<b<<"is"<<"="<<a+b<<endl;
        break;
    case '-':
        cout<<"Substraction of "<<a<<" and "<<b<<" is "<< " = " <<a-b<<endl;
        break;
    case '*':
       cout<<"Multiplicaion of "<<a<<" and "<<b<<" is "<<" = " <<a*b<<endl;
       
        break;
    case '%':
       cout<<"Modulous of "<<a<<" and "<<b<<" is "<<" = "<<a%b<<endl;
       
        break;
    case '/':
       cout<<"Divison of "<<a<<" and "<<b<<" is "<<" =" <<a/b<<endl;
       
        break;
    
    default:
    cout<<"Sorry this operation is not available right now.. :-("<<endl;
    break;
}



}

    