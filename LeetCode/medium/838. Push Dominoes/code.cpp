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

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  void change(string &line, int left, int right) {
    if (line[left] == 'L' && line[right] == '.') return;
    if (line[left] == '.' && line[right] == 'R') return;
    if (line[left] == 'L' && line[right] == 'R') return;

    if (line[left] == line[right] || line[left] == '.' || line[right] == '.') {
      char target = line[left] == '.' ? line[right] : line[left];

      for (int i = left; i <= right; i++) {
        line[i] = target;
      }
      return;
    }

    int centerR = (right + left + 1) / 2;
    int centerL = (right + left) / 2;

    for (int i = left; i <= centerR - 1; i++) {
      line[i] = 'R';
    }
    for (int i = centerL + 1; i <= right; i++) {
      line[i] = 'L';
    }
  }

 public:
  string pushDominoes(string dominoes) {
    int size = dominoes.size();

    int left = 0;
    for (int i = 0; i < size; i++) {
      char c = dominoes[i];

      if (c == '.') continue;

      change(dominoes, left, i);
      left = i;
    }
    change(dominoes, left, size - 1);

    return dominoes;
  }
};