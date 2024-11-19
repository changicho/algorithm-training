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
// time : O(N * K)
// space : O(N)
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int size = code.size();

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      int cur = 0;

      if (k > 0) {
        for (int j = 0; j < k; j++) {
          int next = (i + 1 + j) % size;
          cur += code[next];
        }
      } else if (k < 0) {
        for (int j = 0; j < abs(k); j++) {
          int prev = (i - 1 - j + size) % size;
          cur += code[prev];
        }
      }

      answer[i] = cur;
    }
    return answer;
  }
};

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int size = code.size();

    int sum = 0;
    vector<int> prefix(size + 1);

    for (int i = 0; i < size; i++) {
      prefix[i + 1] = prefix[i] + code[i];
    }

    vector<int> answer(size);
    for (int i = 0; i < size; i++) {
      int cur = 0;

      int left = 0, right = 0;
      if (k > 0) {
        // i+1 ~ i+k
        left = (i + 1) % size, right = (i + k) % size;
      } else if (k < 0) {
        // i-k ~ i-1
        left = (i - abs(k) + size) % size, right = (i - 1 + size) % size;
      } else {
        answer[i] = 0;
        continue;
      }

      if (left < right) {
        cur = prefix[right + 1] - prefix[left];
      } else if (left > right) {
        cur = prefix[right + 1] + prefix[size] - prefix[left];
      } else {
        cur = code[left];
      }

      answer[i] = cur;
    }
    return answer;
  }
};