#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverse(string &word){
    stack<char>s;
    int i = 0;
    //adding all values in stack
    while(i<word.length()){
        s.push(word[i]);
        i++;
    }
    //pushing back top elements into ans array and removing it also
    for(int i = 0 ; i<word.length();i++ ){
      word[i] = s.top();
        s.pop();
    }


}


int main(){

    string word = "sahil";
    reverse(word);
    cout<<word<<endl;
  


}