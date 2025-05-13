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
// time : O(N * log_2(N) + N^3)
// space : O(N)
class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    int size = digits.size();
    sort(digits.begin(), digits.end());

    vector<int> answer;

    vector<bool> visited(size, false);
    function<void(int, int)> recursive = [&](int cur, int count) {
      if (count == 3) {
        if (cur % 2 == 0) {
          answer.push_back(cur);
        }
        return;
      }

      int before = -1;
      for (int i = 0; i < size; i++) {
        if (digits[i] == before) continue;
        if (cur == 0 && digits[i] == 0) continue;
        if (visited[i]) continue;

        visited[i] = true;
        recursive(cur * 10 + digits[i], count + 1);
        visited[i] = false;
        before = digits[i];
      }
    };
    recursive(0, 0);

    return answer;
  }
};

// use brute force
// time : O(N)
// space : O(1000)
class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    int size = digits.size();

    int counts[10] = {
        0,
    };
    for (int& d : digits) {
      counts[d]++;
    }
    vector<int> answer;

    for (int i = 1; i <= 9; i++) {
      if (counts[i] - 1 < 0) continue;
      counts[i]--;

      for (int j = 0; j <= 9; j++) {
        if (counts[j] - 1 < 0) continue;
        counts[j]--;

        for (int k = 0; k <= 9; k += 2) {
          if (counts[k] - 1 < 0) continue;
          counts[k]--;

          int cur = i * 100 + j * 10 + k;
          answer.push_back(cur);

          counts[k]++;
        }
        counts[j]++;
      }
      counts[i]++;
    }

    return answer;
  }
};