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

// use BST set with linked list
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int minimumPairRemoval(vector<int>& nums) {
    int size = nums.size();

    vector<long long> arr(size);
    for (int i = 0; i < size; i++) {
      arr[i] = nums[i];
    }

    // {sum, index}
    set<pair<long long, int>> s;

    vector<int> nextI(size);
    vector<int> prevI(size);
    for (int i = 0; i < size; i++) {
      nextI[i] = i + 1;
      prevI[i] = i - 1;
    }

    int needToSum = 0;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        needToSum++;
      }

      s.insert({arr[i] + arr[i + 1], i});
    }

    int answer = 0;
    while (needToSum > 0) {
      // prev - i - j - next
      int i = s.begin()->second;
      int j = nextI[i];
      int prev = prevI[i];
      int next = nextI[j];

      if (arr[i] > arr[j]) {
        needToSum--;
      }
      long long sum = arr[i] + arr[j];

      if (prev >= 0) {
        if (arr[prev] > arr[i] && arr[prev] <= sum) {
          needToSum--;
        } else if (arr[prev] <= arr[i] && arr[prev] > sum) {
          needToSum++;
        }
      }

      if (next < size) {
        if (arr[next] >= arr[j] && arr[next] < sum) {
          needToSum++;
        } else if (arr[next] < arr[j] && arr[next] >= sum) {
          needToSum--;
        }
      }

      s.erase(s.begin());
      if (prev >= 0) {
        s.erase({arr[prev] + arr[i], prev});
        s.insert({arr[prev] + sum, prev});
      }
      if (next < size) {
        s.erase({arr[j] + arr[next], j});
        s.insert({sum + arr[next], i});
        prevI[next] = i;
      }
      nextI[i] = next;
      arr[i] = sum;
      answer++;
    }

    return answer;
  }
};