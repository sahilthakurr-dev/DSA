#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool IsSafe(int x, int y, int n, vector<vector<int>>& visited, int m[][4]) {
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(int m[][4], int n, vector<string>& ans, int srcX, int srcY, vector<vector<int>> visited, string path) {
    // base case 
    if (srcX == n - 1 && srcY == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[srcX][srcY] = 1;

    // Down
    int newX = srcX + 1;
    int newY = srcY;
    if (IsSafe(newX, newY, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Left
    newX = srcX;
    newY = srcY - 1;
    if (IsSafe(newX, newY, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Right
    newX = srcX;
    newY = srcY + 1;
    if (IsSafe(newX, newY, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    // Up
    newX = srcX - 1;
    newY = srcY;
    if (IsSafe(newX, newY, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newX, newY, visited, path);
        path.pop_back();
    }

    visited[srcX][srcY] = 0;
}

vector<string> mazeProblem(int maze[][4], int& m, int n) {
    vector<string> ans;
    int srcX = 0;
    int srcY = 0;
    vector<vector<int>> visited(m, vector<int>(n, 0));
    string path = "";

    if (maze[0][0] == 0) {
        return ans;
    }

    solve(maze, n, ans, srcX, srcY, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    cout << "Printing the maze array" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << " " << maze[i][j] << " ";
        }
        cout << endl;
    }

    int m = 4;
    int n = 4;
    vector<string> ans = mazeProblem(maze, m, n);

    cout << "\nAll paths from start to end:" << endl;
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
