#include <vector>
#include <iostream>
using namespace std;


vector<int> spiralTraverse(vector<vector<int>> array) {
    // Write your code here.
    /// row: 0 > max => col: 0 > max => row: max -> 0; col: max -> 0
    int leftCol = 0;
    int rightCol = array[0].size() - 1;
    int top = 0;
    int bottom = array.size() - 1;

    vector<int> ans;

    while (leftCol <= rightCol && top <= bottom) {
        for (int c = leftCol; c <= rightCol; ++c) { //Right
            ans.push_back(array[top][c]);
        }
        for (int r = top + 1; r <= bottom; r++) { //Down
            ans.push_back(array[r][rightCol]);
        }

        if (top == bottom || leftCol == rightCol) break;

        for (int c = rightCol - 1; c >= leftCol; c--) {  //Left
            ans.push_back(array[bottom][c]);
        }

        for (int r = bottom - 1; r > top; r--) { //Up
            ans.push_back(array[r][leftCol]);
        }

        top++;
        rightCol--;
        bottom--;
        leftCol++;
    }

    return ans;
}

int main() {
    vector<vector<int>> test =  {{1, 2, 3, 4},
    {12, 13, 14, 5},
    {11, 16, 15, 6},
    {10, 9, 8, 7}};

    auto res = spiralTraverse(test);

    for (const auto& val : res) {
        cout << val << ", ";
    }
    return 0;
}