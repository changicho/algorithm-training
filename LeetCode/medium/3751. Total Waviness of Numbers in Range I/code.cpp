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

// use brute force
// time : O(N * log_10(N))
// space : O(log_10(N))
class Solution {
 private:
  int count(int num) {
    int ret = 0;

    string s = to_string(num);
    int size = s.size();

    for (int i = 1; i < size - 1; i++) {
      if (s[i - 1] < s[i] && s[i] > s[i + 1]) {
        ret++;
      } else if (s[i - 1] > s[i] && s[i] < s[i + 1]) {
        ret++;
      }
    }
    return ret;
  }

 public:
  int totalWaviness(int num1, int num2) {
    int answer = 0;
    for (int num = num1; num <= num2; num++) {
      answer += count(num);
    }
    return answer;
  }
};