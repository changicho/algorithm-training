#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use Longest Non-Decreasing Subsequence

class Solution {
 private:
  int getMinimumChange(vector<int> &list) {
    int size = list.size();
    vector<int> lis;

    for (int i = 0; i < size; i++) {
      int target = upper_bound(lis.begin(), lis.end(), list[i]) - lis.begin();

      if (target == lis.size()) {
        lis.push_back(list[i]);
      } else {
        lis[target] = list[i];
      }
    }

    return size - lis.size();
  }

 public:
  int kIncreasing(vector<int> &arr, int k) {
    vector<vector<int>> lists(k);
    int size = arr.size();

    for (int i = 0; i < size; i++) {
      lists[i % k].push_back(arr[i]);
    }

    int answer = 0;
    for (vector<int> &list : lists) {
      answer += getMinimumChange(list);
    }

    return answer;
  }
};