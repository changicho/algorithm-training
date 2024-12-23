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

// use greedy with heap
// time : O(N * log_2(M))
// space : O(N + M)
class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    unordered_map<char, int> counts;
    for (char& c : s) {
      counts[c]++;
    }

    priority_queue<char> maxHeap;
    for (auto& [c, count] : counts) {
      maxHeap.push(c);
    }

    string answer;

    while (!maxHeap.empty()) {
      char c = maxHeap.top();
      maxHeap.pop();
      int count = counts[c];

      int use = min(count, repeatLimit);
      answer.append(use, c);

      counts[c] -= use;

      if (counts[c] > 0 && !maxHeap.empty()) {
        char next = maxHeap.top();
        maxHeap.pop();

        answer.push_back(next);
        counts[next]--;

        if (counts[next] > 0) {
          maxHeap.push(next);
        }

        maxHeap.push(c);
      }
    }

    return answer;
  }
};

// use greedy
// time : O(N * M)
// space : O(N + M)
class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    int counts[26] = {
        0,
    };
    for (char& c : s) {
      counts[c - 'a']++;
    }

    string answer = "";
    int index = 25;
    while (index >= 0) {
      if (counts[index] == 0) {
        index--;
        continue;
      }

      int use = min(counts[index], repeatLimit);
      answer.append(use, 'a' + index);
      counts[index] -= use;

      if (counts[index] > 0) {
        int sI = index - 1;
        while (sI >= 0 && counts[sI] == 0) {
          sI--;
        }

        if (sI < 0) break;

        answer.push_back('a' + sI);
        counts[sI]--;
      }
    }

    return answer;
  }
};