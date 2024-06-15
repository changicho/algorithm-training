#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(N + M + K)
// space : O(N + K)
class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int counts[1001];

    for (int& num : arr1) {
      counts[num]++;
    }

    vector<int> answer;
    for (int& num : arr2) {
      while (counts[num] > 0) {
        answer.push_back(num);
        counts[num]--;
      }
    }

    for (int num = 0; num <= 1000; num++) {
      while (counts[num] > 0) {
        answer.push_back(num);
        counts[num]--;
      }
    }

    return answer;
  }
};