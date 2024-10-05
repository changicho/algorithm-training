#include <algorithm>
#include <climits>
#include <cmath>
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

// use hash map
// time : O(N)
// space : O(1)
class Solution {
 public:
  long long dividePlayers(vector<int> &skill) {
    int size = skill.size();
    unordered_map<int, int> counts;
    long long sum = 0;
    for (int &num : skill) {
      counts[num]++;
      sum += num;
    }

    if (sum % (size / 2) != 0) return -1;
    int target = sum / (size / 2);

    long long answer = 0;

    for (int &num : skill) {
      if (counts[num] == 0) continue;
      int needed = target - num;
      if (counts[needed] == 0) return -1;

      answer += num * needed;
      counts[num]--;
      counts[needed]--;
    }
    return answer;
  }
};