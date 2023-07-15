#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use dynamic programming with hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int size = arr.size();
    unordered_map<int, int> counts;

    int answer = 1;

    for (int i = 0; i < size; i++) {
      int num = arr[i];

      if (counts.count(num - difference) > 0) {
        counts[num] = counts[num - difference] + 1;
      }

      counts[num] = max(counts[num], 1);
      answer = max(answer, counts[num]);
    }
    return answer;
  }
};