#include <iostream>
using namespace std;

// int main(){
//     cout << "Namaste Duniya!!" << endl;
// }

int main(){
    // int a = 3;
    // cout<< a << endl;
    // char v = 'V';
    // cout<< v << endl;

    // bool bl = true;
    // cout<< bl<< endl;

    // float f = 1.2;
    // cout<< f<< endl;

    //  int size = sizeof(a);
    //  cout<< "Size of a is "<<  size << endl;

    int a;
    cin>>a;
    int ans =1;

    for (int i = 0; i <=30; i++)

    {
        ans = ans*2;
        cout<<ans<<endl;
        if (ans==a)
        {
            cout<<"true"<<endl;
            break;
        }
    }
    
        if (ans!=a)
        {
            cout<<"false"<<endl;
        }
        
   
    
}