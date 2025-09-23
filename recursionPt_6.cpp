#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string& digits, string& output, int index, vector<string>& ans, string mapping[]){
    int size = digits.length();
    
    //base condition
    
    if(index>=size){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
      output.push_back(value[i]);
      solve(digits,output,index+1, ans, mapping);
      output.pop_back();
    }
    


}

vector<string> letter(string& digits){
    vector<string> ans;
    if(digits.length() == 0){
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10]={"", "","abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits, output, index, ans,mapping);
    return ans;


}

int main(){
    string digits = "23";
    vector<string> ans = letter(digits);
    int size = ans.size();

    for (int i = 0; i < size ; i++)
    {
        cout<<"{"<<ans[i]<<"}"<<endl;
    }
    


}

