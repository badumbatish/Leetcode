#include <vector>
#include <functional>
using namespace std;

class NumArray {
    vector<int> segTree;
    int n;

    // Build the segment tree
    void buildTree(vector<int>& nums, int treeIndex, int low, int high) {
        if (low == high) {
            segTree[treeIndex] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        buildTree(nums, leftChild, low, mid);
        buildTree(nums, rightChild, mid + 1, high);

        segTree[treeIndex] = segTree[leftChild] + segTree[rightChild];
    }

    // Update a value in the segment tree
    void updateTree(int treeIndex, int low, int high, int index, int val) {
        if (low == high) {
            segTree[treeIndex] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        if (index <= mid) {
            updateTree(leftChild, low, mid, index, val);
        } else {
            updateTree(rightChild, mid + 1, high, index, val);
        }

        segTree[treeIndex] = segTree[leftChild] + segTree[rightChild];
    }

    // Query the sum of a range
    int queryTree(int treeIndex, int low, int high, int left, int right) {
        if (low > right || high < left) {
            return 0; // Out of range
        }
        if (low >= left && high <= right) {
            return segTree[treeIndex]; // Fully within range
        }

        int mid = low + (high - low) / 2;
        int leftChild = 2 * treeIndex + 1;
        int rightChild = 2 * treeIndex + 2;

        return queryTree(leftChild, low, mid, left, right) +
               queryTree(rightChild, mid + 1, high, left, right);
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4 * n, 0); // Allocate memory for the segment tree
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};

/**
 * Example usage:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */
