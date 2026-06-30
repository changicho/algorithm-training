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

// brute force & hash set
// time : O(N^2 + M)
// space : O(N^2)
class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    unordered_set<string> us;
    int size = word.size();
    for (int i = 0; i < size; i++) {
      string temp = "";
      for (int j = i; j < size; j++) {
        temp += word[j];

        us.insert(temp);
      }
    }

    int answer = 0;
    for (string& p : patterns) {
      answer += us.count(p);
    }
    return answer;
  }
};