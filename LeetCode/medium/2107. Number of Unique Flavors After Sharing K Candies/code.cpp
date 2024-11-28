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

// use sliding window
// time : O(N)
// space : O(N)
class Solution {
 public:
  int shareCandies(vector<int>& candies, int k) {
    int size = candies.size();

    unordered_map<int, int> um;
    for (int& c : candies) {
      um[c]++;
    }

    for (int i = 0; i < k; i++) {
      um[candies[i]]--;
      if (um[candies[i]] == 0) um.erase(candies[i]);
    }

    int answer = um.size();
    for (int right = k; right < size; right++) {
      int left = right - k;

      um[candies[right]]--;
      um[candies[left]]++;

      if (um[candies[right]] == 0) um.erase(candies[right]);

      answer = max(answer, (int)um.size());
    }

    return answer;
  }
};