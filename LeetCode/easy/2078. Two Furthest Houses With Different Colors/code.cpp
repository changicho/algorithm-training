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

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int size = colors.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = colors[i];
      if (colors[0] != cur) {
        answer = max(answer, i);
      }
      if (colors[size - 1] != cur) {
        answer = max(answer, size - 1 - i);
      }
    }
    return answer;
  }
};

// one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxDistance(vector<int>& colors) {
    int size = colors.size();

    int answer = 0;
    for (int i = 0; i < size; i++) {
      int cur = colors[i];
      if (colors[0] != cur) {
        answer = max(answer, i);
      }
      if (colors[size - 1] != cur) {
        answer = max(answer, size - 1 - i);
      }
    }
    return answer;
  }
};