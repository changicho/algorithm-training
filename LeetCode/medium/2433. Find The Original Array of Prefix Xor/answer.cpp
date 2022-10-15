#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit operation
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> findArray(vector<int>& pref) {
    int size = pref.size();
    vector<int> answer;

    answer.push_back(pref.front());
    for (int i = 1; i < size; i++) {
      int cur = pref[i];
      int before = pref[i - 1];

      answer.push_back(cur ^ before);
    }

    return answer;
  }
};