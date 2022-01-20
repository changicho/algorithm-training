#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use vector

class SparseVector {
 public:
  vector<int> nums;
  SparseVector(vector<int>& nums) { this->nums = nums; }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ret = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      ret += vec.nums[i] * nums[i];
    }

    return ret;
  }
};

// use trim zero

class SparseVector {
 public:
  unordered_map<int, int> nonZeros;
  SparseVector(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == 0) continue;
      nonZeros[i] = nums[i];
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int ret = 0;

    for (auto& it : nonZeros) {
      int key = it.first, value = it.second;

      if (vec.nonZeros.find(key) == vec.nonZeros.end()) continue;
      ret += vec.nonZeros[key] * value;
    }

    return ret;
  }
};