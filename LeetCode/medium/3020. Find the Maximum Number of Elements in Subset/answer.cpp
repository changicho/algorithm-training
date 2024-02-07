#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort & hash map
// time: O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumLength(vector<int> &nums) {
    unordered_set<int> visited;
    unordered_map<long long, int> um;

    for (int &num : nums) {
      um[num]++;
    }
    sort(nums.begin(), nums.end());

    int answer = 0;
    for (int &start : nums) {
      if (start == 1) continue;
      if (visited.count(start)) continue;

      long long cur = start;
      long long next = cur * cur;
      int length = 1;

      visited.insert(cur);
      while (um[next] >= 1 && um[cur] >= 2) {
        length++;

        visited.insert(cur);
        visited.insert(next);

        cur = next;
        next = cur * cur;

        if (next > nums.back()) break;
      }

      answer = max(answer, length * 2 - 1);
    }

    int oneCount = um[1];
    answer = max(answer, oneCount - (oneCount % 2 == 0));

    return answer;
  }
};

// use BST map
// time: O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maximumLength(vector<int> &nums) {
    int maximum = 0;

    map<int, int> counts;
    for (int &num : nums) {
      counts[num]++;
      maximum = max(num, maximum);
    }

    int answer = 0;
    if (counts[1] > 0) {
      answer = counts[1] - (counts[1] % 2 == 0);
    }
    counts[1] = 0;

    for (auto &[key, count] : counts) {
      long long cur = key;
      int length = 0;

      while (cur <= maximum && counts[cur] > 0) {
        length += 2;
        if (counts[cur] == 1) break;
        counts[cur] = 0;
        cur *= cur;
      }

      length--;
      answer = max(answer, length);
    }
    return answer;
  }
};