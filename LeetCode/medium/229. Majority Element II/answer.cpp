#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
    int size = nums.size();

    int limit = size / 3;
    unordered_map<int, int> um;

    for (int &num : nums) {
      um[num]++;
    }

    vector<int> answer;
    for (auto &[key, val] : um) {
      if (val > limit) {
        answer.push_back(key);
      }
    }
    return answer;
  }
};

// use boyer-moore voting algorithm
// time : O(N)
// space : O(1)
class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
    int size = nums.size();
    int first(-1), second(-1), countFirst(0), countSecond(0);

    for (const int &num : nums) {
      if (num == first) {
        countFirst++;
      } else if (num == second) {
        countSecond++;
      } else if (!countFirst) {
        first = num;
        countFirst = 1;
      } else if (!countSecond) {
        second = num;
        countSecond = 1;
      } else {
        countFirst--, countSecond--;
      }
    }

    countFirst = countSecond = 0;
    for (const int &x : nums) {
      if (x == first) {
        countFirst++;
      } else if (x == second) {
        countSecond++;
      }
    }

    vector<int> result;
    if (countFirst > size / 3) result.push_back(first);
    if (countSecond > size / 3) result.push_back(second);
    return result;
  }
};