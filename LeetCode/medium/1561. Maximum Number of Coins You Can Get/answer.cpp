#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & deque
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());

    deque<int> queue(piles.begin(), piles.end());

    int answer = 0;
    while (!queue.empty()) {
      queue.pop_back();        // alice
      answer += queue.back();  // us
      queue.pop_back();
      queue.pop_front();  // bob
    }

    return answer;
  }
};