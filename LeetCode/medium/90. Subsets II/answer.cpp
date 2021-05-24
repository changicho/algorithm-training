#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// use set

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    vector<int> array;
    recursive(s, array, nums, 0);

    vector<vector<int>> answer;
    for (vector<int> v : s) {
      answer.push_back(v);
    }
    return answer;
  }

  void recursive(set<vector<int>> &s, vector<int> &array, vector<int> &nums, int index) {
    int size = nums.size();
    s.insert(array);

    for (int i = index; i < size; i++) {
      array.push_back(nums[i]);
      recursive(s, array, nums, i + 1);
      array.pop_back();
    }
  }
};

// use sort and backtracking

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    set<vector<int>> s;
    sort(nums.begin(), nums.end());
    vector<int> array;
    vector<vector<int>> answer;

    recursive(answer, array, nums, 0);

    return answer;
  }

  void recursive(vector<vector<int>> &answer, vector<int> &array, vector<int> &nums, int index) {
    int size = nums.size();
    answer.push_back(array);

    for (int i = index; i < size; i++) {
      array.push_back(nums[i]);
      recursive(answer, array, nums, i + 1);
      array.pop_back();

      while (i + 1 < size && nums[i] == nums[i + 1]) i++;
    }
  }
};