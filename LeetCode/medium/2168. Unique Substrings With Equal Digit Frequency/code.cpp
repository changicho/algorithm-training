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

// use brute force with bitmask
// time : O(L^3)
// space : O(L^3)
class Solution {
 public:
  int equalDigitFrequency(string s) {
    unordered_set<string> us;

    int size = s.size();
    for (int i = 0; i < size; i++) {
      string temp = "";

      int pairs[1001] = {
          0,
      };
      for (int num = 0; num <= 9; num++) {
        pairs[0] |= (1 << num);
      }
      int counts[10] = {
          0,
      };

      for (int j = i; j < size; j++) {
        temp += s[j];

        int cur = s[j] - '0';
        int count = counts[cur];
        pairs[count] &= ~(1 << cur);
        pairs[count + 1] |= (1 << cur);
        counts[cur] = count + 1;

        if ((__builtin_popcount(pairs[count + 1]) * (count + 1)) ==
            temp.size()) {
          us.insert(temp);
        }
      }
    }

    return us.size();
  }
};

// use rolling hash
// time : O(L^2)
// space : O(L^2)
class Solution {
 public:
  int equalDigitFrequency(string s) {
    int size = s.size();
    int prime = 31;
    long long mod = 10e9;
    unordered_set<long long> us;

    for (int left = 0; left < size; left++) {
      vector<int> count(10, 0);
      int uniqueCount = 0;
      long long substringHash = 0;
      int maxCount = 0;

      for (int right = left; right < size; right++) {
        int cur = s[right] - '0';

        if (count[cur] == 0) {
          uniqueCount++;
        }

        count[cur]++;
        maxCount = max(maxCount, count[cur]);

        substringHash = (prime * substringHash + cur + 1) % mod;

        if (maxCount * uniqueCount == right - left + 1) {
          us.insert(substringHash);
        }
      }
    }

    return us.size();
  }
};

// use trie
// time : O(L^2)
// space : O(L^2)
class Solution {
 private:
  struct TrieNode {
    bool visited = false;
    TrieNode *children[10] = {NULL};
  };

 public:
  int equalDigitFrequency(string s) {
    int size = s.size();

    TrieNode *root = new TrieNode();
    int answer = 0;

    for (int left = 0; left < size; left++) {
      int count[10] = {
          0,
      };
      int uniqueCount = 0;
      int maxCount = 0;
      TrieNode *node = root;
      for (int right = left; right < size; right++) {
        int cur = s[right] - '0';

        if (count[cur] == 0) {
          uniqueCount++;
        }

        count[cur]++;
        maxCount = max(maxCount, count[cur]);

        if (!node->children[cur]) {
          node->children[cur] = new TrieNode();
        }
        node = node->children[cur];

        if (maxCount * uniqueCount == right - left + 1 && !node->visited) {
          answer++;
          node->visited = true;
        }
      }
    }

    return answer;
  }
};