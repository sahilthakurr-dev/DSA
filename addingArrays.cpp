#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> add(vector<int> &arr1, vector<int> &arr2){
    vector<int> ansArr;
    int index1 = 0;
    int index2 = 0;
    int carry = 0;

    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());

    while (index1 < arr1.size() && index2 < arr2.size()) {
        int sum = carry + arr1[index1++] + arr2[index2++]; 
        int digit = sum % 10;
        ansArr.push_back(digit);
        carry = sum / 10;
    }

    while (index1 < arr1.size()) {
        int sum = carry + arr1[index1++];
        int digit = sum % 10;
        ansArr.push_back(digit);
        carry = sum / 10;
    }

    while (index2 < arr2.size()) {
        int sum = carry + arr2[index2++];
        int digit = sum % 10;
        ansArr.push_back(digit);
        carry = sum / 10;
    }

    while (carry != 0) {
        int digit = carry % 10;
        ansArr.push_back(digit);
        carry /= 10;
    }

    reverse(ansArr.begin(), ansArr.end());
    return ansArr;
}

int main() {
    vector<int> arr1 = {4, 6, 7}; 
    vector<int> arr2 = {8, 4, 3};  

    vector<int> ans = add(arr1, arr2); 

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
