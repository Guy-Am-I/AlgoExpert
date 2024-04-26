#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    void insert(int value)
    {
        if (value < this->value)
        {
            if (left == nullptr)
            {
                left = new BST(value);
            }
            else
            {
                left->insert(value);
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = new BST(value);
            }
            else
            {
                right->insert(value);
            }
        }
    }
};

BST* minHeightBstHelper(vector<int> arr, BST* node, int lowIdx, int highIdx) {
    if (highIdx < lowIdx) return nullptr;
    int midIdx = (lowIdx + highIdx) / 2;
    int valToAdd = arr[midIdx];
    if (node == nullptr) {
        node = new BST(valToAdd);
    } else {
        node->insert(valToAdd);
    }
    minHeightBstHelper(arr, node, lowIdx, midIdx - 1);
    minHeightBstHelper(arr, node, midIdx + 1, highIdx);
    return node;
}

BST *minHeightBst(vector<int> array)
{
    return minHeightBstHelper(array, nullptr, 0, array.size() - 1);
}
