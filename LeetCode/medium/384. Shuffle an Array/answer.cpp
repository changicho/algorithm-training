#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> array;
  vector<int> origin;

  int randRange(int min, int max) { return (int)rand() % (max - min) + min; }

 public:
  Solution(vector<int>& nums) {
    array = nums;
    origin = nums;
  }

  vector<int> reset() {
    array = origin;

    return array;
  }

  vector<int> shuffle() {
    int size = array.size();
    for (int i = 0; i < size; i++) {
      int from = i, to = randRange(i, size);
      swap(array[from], array[to]);
    }
    return array;
  }
};

// use short version

class Solution {
  vector<int> array;

 public:
  Solution(vector<int> nums) { this->array = nums; }

  vector<int> reset() { return array; }

  vector<int> shuffle() {
    int size = array.size();
    vector<int> result(array);

    for (int i = 0; i < size; i++) {
      int pos = rand() % (size - i);
      swap(result[i + pos], result[i]);
    }
    return result;
  }
};