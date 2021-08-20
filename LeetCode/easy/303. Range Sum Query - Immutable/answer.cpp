#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use subsum array

class NumArray {
 private:
  vector<int> sums;

 public:
  NumArray(vector<int>& nums) {
    sums.push_back(0);
    for (int num : nums) {
      sums.push_back(sums.back() + num);
    }
  }

  int sumRange(int left, int right) {
    return sums[right + 1] - sums[left];
  }
};

// use segment tree

class NumArray {
 private:
  template <typename T>
  struct SegmentTree {
    int size;
    vector<T> arr;
    vector<T> tree;

    void init(vector<T> array) {
      size = array.size();

      arr = array;
      tree.resize(size * 4);

      init(1, 0, size - 1);
    }

    T operation(T x, T y) {
      return x + y;
    }

    int init(int node, int start, int end) {
      if (start == end) return tree[node] = arr[start];
      int mid = (start + end) / 2;

      return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
    }

    T query(int node, int start, int end, int left, int right) {
      if (right < start || end < left) return 0;
      if (left <= start && end <= right) return tree[node];

      int mid = (start + end) / 2;
      return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }

    T query(int left, int right) {
      return query(1, 0, size - 1, left, right);
    }
  };

  SegmentTree<int> segmentTree;

 public:
  NumArray(vector<int>& nums) {
    segmentTree.init(nums);
  }

  int sumRange(int left, int right) {
    return segmentTree.query(left, right);
  }
};