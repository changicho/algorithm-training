#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long answer = 0;

    sort(happiness.begin(), happiness.end(), greater<int>());

    for (int turn = 0; turn < k; turn++) {
      answer += max(0, happiness[turn] - turn);
    }
    return answer;
  }
};