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

// brute force
// time : O(N^2)
// space : O(1)
class Solution {
 public:
  int countRotations(string s, int k) {
    int size = s.size();

    int answer = 0;

    for (int start = 0; start < size; start++) {
      int same = 0;

      for (int i = 0; i < size - 1; i++) {
        if (s[(start + i) % size] == s[(start + i + 1) % size]) {
          same++;
        }
      }

      if (same == k) answer++;
    }

    return answer;
  }
};

// shift move
// time : O(N)
// space : O(1)
class Solution {
 public:
  int countRotations(string s, int k) {
    int size = s.size();

    int answer = 0;
    int same = 0;
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == s[i + 1]) {
        same++;
      }
    }

    for (int start = 0; start < size; start++) {
      if (same == k) answer++;

      if (s[start] == s[start + 1]) {
        same--;
      }
      if (s[(start + size - 1) % size] == s[(start + size) % size]) {
        same++;
      }
    }

    return answer;
  }
};