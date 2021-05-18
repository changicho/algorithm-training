#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;

    vector<int> array;
    recursive(array, ret, n, k);

    return ret;
  }

  void recursive(vector<int> &arr, vector<vector<int>> &answer, int n, int k) {
    if (arr.size() == k) {
      answer.push_back(arr);
      return;
    }

    for (int i = arr.empty() ? 1 : arr.back() + 1; i <= n; i++) {
      arr.push_back(i);
      recursive(arr, answer, n, k);
      arr.pop_back();
    }
  }
};

// use iterate

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    int index = 0;

    vector<int> array(k, 0);
    while (index >= 0) {
      array[index]++;
      if (array[index] > n) {
        index--;
      } else if (index == k - 1) {
        ret.push_back(array);
      } else {
        index++;
        array[index] = array[index - 1];
      }
    }
    return ret;
  }
};