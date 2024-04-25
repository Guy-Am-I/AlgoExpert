#include <vector>
using namespace std;

bool isMonotonic(vector<int> array) {
    if (array.size() <= 2) {
        return true;
    }
    bool nonDecreasing = true;
    bool nonIncreasing = true;
    for (int i = 1; i < array.size(); ++i) {
        if (array[i] > array[i - 1]) {
            nonIncreasing = false;
        }
        if (array[i] < array[i - 1]) {
            nonDecreasing = false;
        }
    }
    return nonIncreasing || nonDecreasing;
}