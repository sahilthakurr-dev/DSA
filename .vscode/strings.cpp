#include<iostream>
#include<string>
#include<vector>
#include <cstring>
using namespace std;


int getLength(char name[]){
    int count = 0;
    for (int i = 0; name[i] !='\0'; i++)
    {
      count ++;

    }
    
    return count;
}

void reverseString(char name[]){
    int start = 0;
    int len = strlen(name);
    int end = len - 1;

   while (start<=end)
   {
    swap(name[start++], name[end--]);
   }


   
    
}

char GetMaxOccuringCharacter(string s){
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch>= 'a' && ch<='z')
        {
            number = ch-'a';
        } else{
            number = ch-'A';
        }
        arr[number]++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int maxi = arr[0];
       if (maxi < arr[i])
       {
        ans = i;
        maxi = arr[i];
       }
       
    }
    
    char finalAnswer = 'a' + ans;
    return finalAnswer;
    
}

string removeSpace(string& s){
    string temp;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i]== ' ')
      {
       temp.push_back('@');
       temp.push_back('4');
       temp.push_back('0');
      } else{
        temp.push_back(s[i]);
      }
      
    }

    return temp;
    

}

int main(){
//     char name[20];
//     cout<<"Enter your name"<<endl;
//     cin>>name;

//     int count = getLength(name);
//     reverseString(name);
//     cout<<"Your name is "<<name<<endl;
//     cout<<"Length of the array is "<< count<< endl; 
//     cout<<"Reversed array is "<< name<<endl;
    

// string s;
// cin>>s;
// cout<<GetMaxOccuringCharacter(s);

string s;
getline(cin, s);

 string newString = removeSpace(s);
cout<<" "<<newString<<" "<<endl;





}