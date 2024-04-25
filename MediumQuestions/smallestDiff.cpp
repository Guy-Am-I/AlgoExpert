#include <vector>
#include <iostream>
using namespace std;

int absDiff(int num1, int num2) {
    return num1 < num2 ? abs(num2 - num1) : abs(num1 - num2);
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    // Write your code here.
    pair<int, int> res = {arrayOne[0],arrayTwo[0]};
    int resDiff = absDiff(res.first, res.second);
    /// Assume both non empty
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    vector<int>::iterator oneIter = arrayOne.begin(), twoIter = arrayTwo.begin();
    
    while(oneIter < arrayOne.end() && twoIter < arrayTwo.end()) {
        int first = *oneIter, second = *twoIter;
        ///check diff
        auto currDiff = absDiff(first, second);
        if ( currDiff < resDiff) {
            res.first = first;
            res.second = second;
            resDiff = currDiff;
        }
        ///advance smaller one
        if (first < second) {
            oneIter++;
        } else {
            twoIter++;
        }
    }
    
    return {res.first, res.second};
}

int main() {
    auto a1 = {-1, 5, 10, 20, 3};
    auto a2 = {26, 134, 135, 15, 17};
    auto res = smallestDifference(a1, a2);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
