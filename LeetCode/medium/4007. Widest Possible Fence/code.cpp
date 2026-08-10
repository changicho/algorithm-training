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

// hash map & frequency count
// time : O(N^2)
// space : O(N^2)
class Solution {
 public:
  int maximumWidth(vector<int>& planks) {
    unordered_map<int, int> count, twoCount;

    for (int& p : planks) {
      count[p]++;
      twoCount[p]++;
    }

    for (auto it1 : count) {
      for (auto& it2 : count) {
        int a = it1.first, b = it2.first;
        int countA = it1.second, countB = it2.second;

        if (a < b) {
          twoCount[a + b] += min(countA, countB);
        }
        if (a == b) {
          twoCount[a + b] += countA / 2;
        }
      }
    }

    int answer = 0;
    for (auto& [key, count] : twoCount) {
      answer = max(answer, count);
    }
    return answer;
  }
};