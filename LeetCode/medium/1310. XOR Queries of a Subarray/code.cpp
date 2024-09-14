#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use prefix sum
// time : O(N + Q)
// space : O(N)
class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int size = arr.size();

    vector<int> prefixes(size + 1, 0);

    for (int i = 0; i < size; i++) {
      prefixes[i + 1] = prefixes[i];

      prefixes[i + 1] ^= arr[i];
    }

    vector<int> answer;
    for (vector<int>& query : queries) {
      int left = query[0] + 1, right = query[1] + 1;

      int ret = prefixes[right] ^ prefixes[left - 1];

      answer.push_back(ret);
    }
    return answer;
  }
};

// use prefix sum (bit count)
// time : O(N + Q)
// space : O(N)
class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int size = arr.size();

    vector<int> subArraySum(size + 1, 0);

    for (int i = 0; i < size; i++) {
      subArraySum[i + 1] = subArraySum[i];

      int cur = arr[i];
      for (int j = 0; j < 31; j++) {
        int bit = (1 << j);

        if ((cur & bit) > 0) {
          subArraySum[i + 1] ^= bit;
        }
      }
    }

    vector<int> answer;
    for (vector<int>& query : queries) {
      int left = query[0] + 1, right = query[1] + 1;

      int ret = subArraySum[right] ^ subArraySum[left - 1];

      answer.push_back(ret);
    }
    return answer;
  }
};