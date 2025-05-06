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

// use count
// time : O(N + M)
// space : O(M)
class Solution {
 private:
  int convert(vector<int> &d) {
    int first = min(d[0], d[1]);
    int second = max(d[0], d[1]);

    return first * 10 + second;
  }

 public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    int count[100] = {
        0,
    };

    for (vector<int> &d : dominoes) {
      int key = convert(d);

      count[key]++;
    }

    int answer = 0;
    for (int &val : count) {
      answer += (val) * (val - 1) / 2;
    }
    return answer;
  }
};