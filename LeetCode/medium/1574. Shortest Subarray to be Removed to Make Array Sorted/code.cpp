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

// use two pointer
// time : O(N)
// space : O(1)
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int size = arr.size();
    int left = 0, right = size - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
      right--;
    }

    int answer = right;
    while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
      while (right < size && arr[left] > arr[right]) {
        right++;
      }

      answer = min(answer, right - left - 1);
      left++;
    }

    return answer;
  }
};