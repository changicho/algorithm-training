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
// time : O(N)
// space : O(N)
class Solution {
 public:
  int findLucky(vector<int>& arr) {
    int count[501] = {
        0,
    };

    for (int& num : arr) {
      count[num]++;
    }

    int answer = -1;
    for (int i = 1; i <= 500; i++) {
      if (count[i] == i) answer = i;
    }
    return answer;
  }
};