#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  bool isPossible(vector<int> &candies, long long &k, int &pile) {
    long long count = 0;

    for (int &candy : candies) {
      count += candy / pile;

      if (count >= k) return true;
    }

    return false;
  }

 public:
  int maximumCandies(vector<int> &candies, long long k) {
    int left = 1, right = 1e7 + 1;
    int answer = 0;

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (isPossible(candies, k, mid)) {
        answer = mid;
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return answer;
  }
};