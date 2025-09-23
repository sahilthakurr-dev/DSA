#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans){
    int size = nums.size();

    if(index >= size){
        ans.push_back(output);
        cout<<"base case hit"<<endl;
        return;
    }

    // Exclude
    solve(nums, output, index + 1, ans);

    // Include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);

    // Backtrack
    output.pop_back();
}


vector<vector<int>> subsets(vector<int>& nums){
 
    vector<vector<int>> ansArr;
    vector<int> output;
    int index = 0;
    solve(nums,output,index,ansArr);
    return ansArr;


  
    


}

void solve2(vector<string>& str, int index, vector<string> & output, vector<vector<string>>& ans){
    //base case
    int size = str.size();

    if(index >= size){
        if(output.size()>0){
         ans.push_back(output);
        }
        return;
    }

    //exculde
    solve2(str, index+1, output, ans);

    //include 
    string ch = str[index];
    output.push_back(ch);
    solve2(str,index+1, output, ans);

    output.pop_back();

    
}

vector<vector<string>> subsequence(vector<string>& str){
    int index = 0;
    vector<string> output;
    vector<vector<string>> ans;
    solve2(str,index,output,ans);
    return ans;

}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<string> str ={"a", "b", "c"};
    vector<vector<int>> ans = subsets(nums);
    vector<vector<string>> ans2 = subsequence(str);
    int size = ans2.size();


    // Print the subsets

    for(int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;

    }

    cout<<endl;

    // Print the subsequences

    // for (int  i = 0; i <size ; i++)
    // {
    //    cout<<"{ ";
    //    for (int  j= 0; j < ans2[i].size(); j++)
    //    {
    //        cout<<ans2[i][j]<<" ";
    //    }

    //    cout<<"}"<<endl;
       
    // }
    

    return 0;
}
