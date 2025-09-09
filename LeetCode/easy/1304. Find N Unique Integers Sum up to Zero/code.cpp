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

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> answer = {};

    if (n % 2 == 1) {
      answer.push_back(0);
      n--;
    }

    for (int i = 0; i < n; i += 2) {
      answer.push_back(i + 1);
      answer.push_back(-(i + 1));
    }

    return answer;
  }
};