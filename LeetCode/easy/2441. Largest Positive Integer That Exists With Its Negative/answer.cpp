#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findMaxK(vector<int> &nums) {
    unordered_set<int> appears;

    int answer = -1;
    for (int &num : nums) {
      appears.insert(num);
    }

    for (int &num : nums) {
      if (num < 0) continue;

      if (appears.count(-num) > 0) {
        answer = max(answer, num);
      }
    }
    return answer;
  }
};

// use hash set & one pass
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findMaxK(vector<int> &nums) {
    unordered_set<int> us;

    int answer = -1;
    for (int &num : nums) {
      if (us.count(-num)) {
        answer = max(answer, abs(num));
      }
      us.insert(num);
    }
    return answer;
  }
};