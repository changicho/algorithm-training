#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use recursive

class Solution {
  vector<vector<int>> answer;

  void recursive(vector<int> &array, int n) {
    if (n == 1) {
      if (array.size() >= 2) answer.emplace_back(array);
      return;
    }

    int left = array.empty() ? 2 : array.back();
    for (int num = left; num <= n; num++) {
      if (n % num == 0) {
        array.emplace_back(num);
        recursive(array, n / num);
        array.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    vector<int> array;
    recursive(array, n);
    return answer;
  }
};

// use backtracking push answer first

class Solution {
 private:
  vector<vector<int>> answer;

  void recursive(vector<int> &array, int n) {
    int left = array.empty() ? 2 : array.back();
    int right = sqrt(n);

    for (int num = left; num <= right; num++) {
      if (n % num == 0) {
        array.emplace_back(num);
        array.emplace_back(n / num);

        answer.emplace_back(array);

        array.pop_back();
        recursive(array, n / num);
        array.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    vector<int> array;
    recursive(array, n);
    return answer;
  }
};

// use backtracking push answer last

class Solution {
 private:
  vector<vector<int>> answer;

  void recursive(vector<int> &array, int n) {
    int left = array.empty() ? 2 : array.back();
    int right = sqrt(n);

    for (int num = left; num <= right; num++) {
      if (n % num == 0) {
        array.push_back(num);
        recursive(array, n / num);
        array.push_back(n / num);

        answer.push_back(array);

        array.pop_back();
        array.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> getFactors(int n) {
    vector<int> array;
    recursive(array, n);
    return answer;
  }
};