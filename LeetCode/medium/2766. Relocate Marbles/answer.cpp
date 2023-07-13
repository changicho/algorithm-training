#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N * log_2(N) + M)
// space : O(N)
class Solution {
 public:
  vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom,
                              vector<int>& moveTo) {
    unordered_set<int> us;

    for (int& num : nums) {
      us.insert(num);
    }

    int size = moveFrom.size();
    for (int i = 0; i < size; i++) {
      int from = moveFrom[i], to = moveTo[i];

      if (us.count(from) == 0) continue;

      us.erase(from);
      us.insert(to);
    }

    vector<int> answer(us.begin(), us.end());
    sort(answer.begin(), answer.end());
    return answer;
  }
};