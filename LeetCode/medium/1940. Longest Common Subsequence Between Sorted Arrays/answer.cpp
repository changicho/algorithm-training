#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  vector<int> longestCommonSubsequence(vector<vector<int>> &arrays) {
    int size = arrays.size();
    vector<int> answer;

    int counts[101] = {
        0,
    };

    for (vector<int> &arr : arrays) {
      for (int &num : arr) {
        counts[num]++;
      }
    }

    for (int num = 0; num <= 100; num++) {
      if (counts[num] == size) answer.push_back(num);
    }
    return answer;
  }
};