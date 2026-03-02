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

// sliding window & bitset
// time : O(N)
// space : O(2^K)
class Solution {
 public:
  bool hasAllCodes(string s, int k) {
    int size = s.size();
    if (size < k) return false;

    int limit = 1 << k;
    bool visited[1048576] = {false};
    int visitCount = 0;

    int temp = 0;
    for (int i = 0; i < k - 1; i++) {
      temp = temp * 2 + (s[i] - '0');
    }
    for (int i = k - 1; i < size; i++) {
      temp = temp * 2 + (s[i] - '0');

      temp %= limit;
      if (visited[temp] == false) visitCount++;
      visited[temp] = true;
    }

    return visitCount == limit;
  }
};