#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

// simulation
// time : O(NM)
// space : O(N + M)
class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer;

    int count[101];
    for (int& num : nums) {
      count[num]++;
    }

    while (answer.size() < size) {
      for (int num = 0; num <= 100; num++) {
        if (count[num] > 0) {
          answer.push_back(num);
          count[num]--;
        }
      }
    }
    return answer;
  }
};

// queue
// time : O(N + M)
// space : O(N + M)
class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer;

    queue<int> keys;
    int count[101];
    for (int& num : nums) {
      count[num]++;
    }

    for (int num = 0; num <= 100; num++) {
      if (count[num] > 0) {
        keys.push(num);
      }
    }

    while (!keys.empty()) {
      int key = keys.front();
      keys.pop();

      answer.push_back(key);
      count[key]--;

      if (count[key] > 0) {
        keys.push(key);
      }
    }
    return answer;
  }
};