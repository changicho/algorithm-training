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

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  int minSwaps(vector<int>& data) {
    int size = data.size();
    int ones = accumulate(data.begin(), data.end(), 0);

    int answer = size;
    int temp = 0;
    for (int left = 0, right = 0; right < size; right++) {
      temp += data[right];

      if (right - left >= ones) {
        temp -= data[left];
        left++;
      }

      if (right - left == ones - 1) {
        answer = min(answer, ones - temp);
      }
    }
    return answer;
  }
};