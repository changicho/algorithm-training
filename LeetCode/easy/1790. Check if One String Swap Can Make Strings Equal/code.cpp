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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    int size = s1.size();
    vector<int> counts1(26, 0), counts2(26, 0);

    int diff = 0;
    for (int i = 0; i < size; i++) {
      char c1 = s1[i], c2 = s2[i];

      counts1[c1 - 'a']++;
      counts2[c2 - 'a']++;

      if (c1 != c2) diff++;
    }

    return (diff == 2 || diff == 0) && counts1 == counts2;
  }
};