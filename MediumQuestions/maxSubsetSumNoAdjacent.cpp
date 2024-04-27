#pragma once
#include <iostream>
#include <vector>
using namespace std;

int getMaxSubsetSum(const vector<int>& array, int startIdx, vector<int>& subsetSumsMemo) {
    int nextIdx = startIdx + 1;
    int currVal = array[startIdx];
    if (startIdx >= array.size()) return 0;
    if (nextIdx == array.size()) { /// last elem
        subsetSumsMemo[startIdx] = currVal;
        return currVal;
    }

    if (subsetSumsMemo[nextIdx] == 0) {
        subsetSumsMemo[nextIdx] =  getMaxSubsetSum(array, nextIdx, subsetSumsMemo);
    }

    subsetSumsMemo[startIdx] = max(subsetSumsMemo[nextIdx], currVal + getMaxSubsetSum(array, startIdx + 2, subsetSumsMemo));
    return subsetSumsMemo[startIdx];

}

int maxSubsetSumNoAdjacent(vector<int> array) {
    if (array.size() == 0) return 0;
    vector<int> subsetSumsMemo(array.size(), 0);
    return getMaxSubsetSum(array, 0, subsetSumsMemo);
}

int main() {
    // cout << maxSubsetSumNoAdjacent({10, 5, 20, 25, 15, 5, 5, 15, 3, 15, 5, 5, 15});
    cout << maxSubsetSumNoAdjacent({}) << endl;
    return 0;
}
