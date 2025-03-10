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

// use one pass with prefix sum
// time : O(N)
// space : O(1)
class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int size = arr.size();

    int answer = 0;
    int prefixSum = 0;

    for (int i = 0; i < size; i++) {
      int num = arr[i];

      prefixSum += num;
      // sum of 0 to i
      int target = (i + 1) * i / 2;

      if (target == prefixSum) answer++;
    }
    return answer;
  }
};