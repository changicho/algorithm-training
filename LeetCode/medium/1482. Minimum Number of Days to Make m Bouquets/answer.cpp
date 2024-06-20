#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use binary search
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end()) + 1;

    function<int(int)> getCount = [&bloomDay, &k](int mid) {
      int ret = 0;
      int count = 0;
      for (int& day : bloomDay) {
        if (day <= mid) {
          count++;
        } else {
          count = 0;
        }

        if (count == k) {
          ret++;
          count = 0;
        }
      }
      return ret;
    };

    int answer = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (getCount(mid) >= m) {
        answer = mid;
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return answer;
  }
};

// use binary search (faster)
// time : O(N * log_2(M))
// space : O(1)
class Solution {
 private:
  int getCount(vector<int>& bloomDay, int mid, int k) {
    int ret = 0;
    int count = 0;
    for (int& day : bloomDay) {
      if (day <= mid) {
        count++;
      } else {
        count = 0;
      }

      if (count == k) {
        ret++;
        count = 0;
      }
    }
    return ret;
  }

 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end()) + 1;

    int answer = -1;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (getCount(bloomDay, mid, k) >= m) {
        answer = mid;
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return answer;
  }
};