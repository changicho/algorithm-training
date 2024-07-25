#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & two pointer
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    sort(worker.begin(), worker.end());

    int size = profit.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < size; i++) {
      arr.push_back({difficulty[i], profit[i]});
    }
    sort(arr.begin(), arr.end());

    int index = 0;
    int curMaxProfit = 0;

    int answer = 0;
    for (int& work : worker) {
      while (index < size && arr[index].first <= work) {
        curMaxProfit = max(curMaxProfit, arr[index].second);
        index++;
      }

      answer += curMaxProfit;
    }
    return answer;
  }
};