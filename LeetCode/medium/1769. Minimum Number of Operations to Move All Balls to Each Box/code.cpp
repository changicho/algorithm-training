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
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int size = boxes.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; i++) {
      int left = i - 1, right = i + 1;

      int count = 0;
      for (int j = 0; j < size; j++) {
        if (j == i) continue;
        if (boxes[j] == '0') continue;
        count += abs(j - i);
      }
      answer[i] = count;
    }
    return answer;
  }
};

// use prefix sum
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int size = boxes.size();
    vector<int> answer(size, 0);

    vector<pair<int, int>> prefixes(size + 1);
    // count, index sum
    pair<int, int> cur;
    for (int i = 0; i < size; i++) {
      if (boxes[i] == '1') {
        cur.first++;
        cur.second += i;
      }
      prefixes[i + 1] = cur;
    }

    for (int i = 0; i < size; i++) {
      pair<int, int> left = prefixes[i];
      pair<int, int> right = prefixes[size];
      right.first -= prefixes[i + 1].first;
      right.second -= prefixes[i + 1].second;

      int cur = abs(left.second - i * left.first) +
                abs(right.second - i * right.first);

      answer[i] = cur;
    }
    return answer;
  }
};