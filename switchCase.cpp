#include <iostream>
using namespace std;

int main(){
    
// A SIMPLE CALCULATOR TO UNDERSTAND THE BASICS OF SWTICH CASE;

// int a;
// cout<<"Enter the first number:"<< endl;
// cin>>a;

// int b;
// cout<<"Enter the second number:"<< endl;
// cin>>b;

// char ch;
// cout<<"What you want to perform?"<<endl;
// cin>>ch;

// switch (ch)
// {
//     case '+':
//        cout<<"Sum of"<<a<<"and"<<b<<"is"<<"="<<a+b<<endl;
//         break;
//     case '-':
//         cout<<"Substraction of "<<a<<" and "<<b<<" is "<< " = " <<a-b<<endl;
//         break;
//     case '*':
//        cout<<"Multiplicaion of "<<a<<" and "<<b<<" is "<<" = " <<a*b<<endl;
       
//         break;
//     case '%':
//        cout<<"Modulous of "<<a<<" and "<<b<<" is "<<" = "<<a%b<<endl;
       
//         break;
//     case '/':
//        cout<<"Divison of "<<a<<" and "<<b<<" is "<<" =" <<a/b<<endl;
       
//         break;
    
//     default:
//     cout<<"Sorry this operation is not available right now.. :-("<<endl;
//     break;
// }


// MONEY TELLER PROGRAM;



    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int choice = 1;

    while (choice <= 4 && amount > 0) {
        switch (choice) {
            case 1: 
                if (amount >= 100) {
                    cout << "You need " << amount / 100 << " notes of 100" << endl;
                    amount = amount % 100;
                }
                break;
            case 2:
                if (amount >= 50) {
                    cout << "You need " << amount / 50 << " notes of 50" << endl;
                    amount = amount % 50;
                }
                break;
            case 3: 
                if (amount >= 20) {
                    cout << "You need " << amount / 20 << " notes of 20" << endl;
                    amount = amount % 20;
                }
                break;
            case 4:
                if (amount >= 10) {
                    cout << "You need " << amount / 10 << " notes of 10" << endl;
                    amount = amount % 10;
                }
                break;
        }
        choice++;
    }

    if (amount > 0) {
        cout << "Remaining amount that cannot be broken: " << amount << endl;
    }

  
}


