#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// use map
// time : O(N * log_2(N * M))
// space : O(N)
class Solution {
 private:
  int convert(int num) {
    if (num % 2 == 1) return num;

    while (num % 2 == 0) {
      num /= 2;
    }
    return num;
  }

 public:
  int minimumDeviation(vector<int>& nums) {
    map<int, int> uniqueNums;
    for (int& num : nums) {
      int converted = convert(num);

      int limit = num % 2 == 0 ? num : num * 2;
      if (uniqueNums.count(converted) == 0) {
        uniqueNums[converted] = limit;
      } else {
        uniqueNums[converted] = min(limit, uniqueNums[converted]);
      }
    }

    if (uniqueNums.size() == 1) return 0;

    // maximum - minimum
    int answer = abs(uniqueNums.begin()->first - uniqueNums.rbegin()->first);
    while (true) {
      auto lowest = *uniqueNums.begin();

      if (lowest.first == lowest.second) break;
      uniqueNums.erase(lowest.first);

      uniqueNums[lowest.first * 2] = lowest.second;

      // maximum - minimum
      int curDiff = abs(uniqueNums.begin()->first - uniqueNums.rbegin()->first);
      answer = min(answer, curDiff);
    }
    return answer;
  }
};