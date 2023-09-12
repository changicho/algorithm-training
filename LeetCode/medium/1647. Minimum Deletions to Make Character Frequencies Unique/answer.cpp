#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minDeletions(string s) {
    int counts[26] = {
        0,
    };
    for (char &c : s) {
      counts[c - 'a']++;
    }

    // key freq, val count
    unordered_map<int, int> um;
    vector<int> freqs;
    for (int i = 0; i < 26; i++) {
      um[counts[i]]++;
    }

    int answer = 0;
    for (int i = 0; i < 26; i++) {
      int count = counts[i];
      if (count == 0) continue;
      if (um[count] <= 1) continue;
      um[count]--;
      while (count > 0 && um[count] >= 1) {
        count--;
        answer++;
      }
      um[count]++;
    }

    return answer;
  }
};