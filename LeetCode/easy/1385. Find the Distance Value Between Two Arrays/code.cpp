#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// sort & binary search
// time : O((N + M) * log_2(M))
// space : O(M)
class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int answer = 0;

    sort(arr2.begin(), arr2.end());

    for (int& num1 : arr1) {
      int left = num1 - d;
      int right = num1 + d;

      int count = upper_bound(arr2.begin(), arr2.end(), right) -
                  lower_bound(arr2.begin(), arr2.end(), left);

      if (count == 0) answer++;
    }
    return answer;
  }
};

// brute force
// time : O(NM)
// space : O(1)
class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int answer = 0;

    for (int& num1 : arr1) {
      bool check = true;
      for (int& num2 : arr2) {
        if (abs(num1 - num2) <= d) check = false;
      }
      if (check) answer++;
    }
    return answer;
  }
};