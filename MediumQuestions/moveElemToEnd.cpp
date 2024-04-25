#include <vector>
#include <iostream>
using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
    ///pointer to end, pointer to beg
    ///go to first occurence of end that isn't toMove
    ///from first -> end
    ///swap if first is toMove -> move toEnd one 'back'
    if (array.empty()) {
        return array;
    }

    auto begin = array.begin();
    auto endIter = array.rbegin();
    while (begin < endIter.base()) {
        if (*endIter == toMove) {
            ++endIter;
            continue;
        }
        if (*begin == toMove) {
            auto temp = *endIter;
            *endIter = *begin;
            *begin = temp; 
            endIter++;
        }
        begin++;
    }

    return array;
}

int main() {
    vector<int> arr = {5,1,2,5,5,3,4,6,7,5,8,9,10,11,5,5,12};
    auto vec = moveElementToEnd(arr, 5);
    for_each(vec.begin(), vec.end(), [](const auto& val){
        cout << val << ", ";
    });
    return 0;
}