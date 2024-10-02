#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    unordered_map<int, int> ranks;

    vector<int> answer = arr;

    sort(arr.begin(), arr.end());

    for (int& num : arr) {
      if (ranks.count(num)) continue;
      ranks[num] = ranks.size() + 1;
    }

    for (int i = 0; i < answer.size(); i++) {
      answer[i] = ranks[answer[i]];
    }
    return answer;
  }
};