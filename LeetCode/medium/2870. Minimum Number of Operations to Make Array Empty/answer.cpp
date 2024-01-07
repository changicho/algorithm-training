#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use count
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minOperations(vector<int> &nums) {
    unordered_map<int, int> um;
    for (int &num : nums) {
      um[num]++;
    }

    int answer = 0;
    for (auto &[_num, count] : um) {
      if (count == 1) return -1;

      answer += count / 3;
      if (count % 3 != 0) answer++;
    }
    return answer;
  }
};

// use count (array)
// time : O(1e6)
// space : O(1e6)
class Solution {
 public:
  int minOperations(vector<int> &nums) {
    int um[1000001] = {
        0,
    };
    for (int &num : nums) {
      um[num]++;
    }

    int answer = 0;
    for (int i = 0; i < 1000001; i++) {
      if (um[i] == 1) return -1;

      answer += um[i] / 3;
      if (um[i] % 3 != 0) answer++;
    }
    return answer;
  }
};