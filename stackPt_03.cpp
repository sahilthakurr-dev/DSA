#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int count, int size){
    // base case
    if (count == size / 2) {
        s.pop();  // remove middle element
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s, count + 1, size);

    s.push(num);  // restore stack
}

int main(){
    int arr[5] = {3, 5, 9, 2, 4};
    int size = 5;
    stack<int> s;

    for (int i = 0; i < size; i++) {
        s.push(arr[i]);
    }

    int count = 0;
    solve(s, count, size);  

    int i = s.size() - 1;
    while (!s.empty()) {
        arr[i--] = s.top();
        s.pop();
    }

    for (int i = 0; i < size - 1; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
