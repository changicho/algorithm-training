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

// use brute force
// time : O(N^3)
// space : O(1)
class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int size = arr.size();
    int answer = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (abs(arr[i] - arr[j]) > a) continue;

        for (int k = j + 1; k < size; k++) {
          if (abs(arr[j] - arr[k]) > b) continue;
          if (abs(arr[k] - arr[i]) > c) continue;

          answer++;
        }
      }
    }
    return answer;
  }
};

// use sum count
// time : O(N * (N + M))
// space : O(M)
class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int size = arr.size();
    int sum[1001] = {0};

    int answer = 0;
    for (int j = 0; j < size; ++j) {
      for (int k = j + 1; k < size; ++k) {
        if (abs(arr[j] - arr[k]) > b) continue;

        int leftJ = arr[j] - a, rightJ = arr[j] + a;
        int leftK = arr[k] - c, rightK = arr[k] + c;

        int left = max({0, leftJ, leftK}), right = min({1000, rightJ, rightK});

        if (left <= right) {
          if (left == 0) {
            answer += sum[right];
          } else {
            answer += sum[right] - sum[left - 1];
          }
        }
      }

      for (int k = arr[j]; k <= 1000; ++k) {
        sum[k]++;
      }
    }
    return answer;
  }
};