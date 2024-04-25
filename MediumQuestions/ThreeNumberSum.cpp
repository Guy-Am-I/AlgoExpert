#include <vector>
#include <iostream>
using namespace std;

void printVector2D(vector<vector<int>> matrix) {
    cout << "[ ";
    for (const auto& row : matrix) {
        cout << "[ ";
        for (const auto& val: row) {
            cout << val << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

using vecIter = vector<int>::iterator;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int>> res = {};
    ///SORT (in-place)
    sort(array.begin(), array.end());
    /// can stop shy of end iter
    for (vecIter currValIter = array.begin(); currValIter < array.end() - 1; currValIter++) {
        vecIter smallestIter = currValIter + 1;
        auto largestIter = array.rbegin();
        /// Array is unique so we can compare values instead of iterators
        while (*smallestIter != *largestIter) {
            int current = *currValIter, small = *smallestIter, large = *largestIter;
            int currSum = current + small + large;

            if (currSum < targetSum) {
                smallestIter++;
            } else if (currSum > targetSum) {
                largestIter++; ///reverse iterator
            } else {
                ///Add to result
                res.push_back({current, small, large});
                smallestIter++; //increase one for potential multiple triplets with same CURR
            }
        }
    }

    return res;
}

int main() {
    //printVector2D(threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0));
    printVector2D(threeNumberSum({1,2,3}, 6));
    return 0;
}