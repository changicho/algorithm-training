#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  int distinctIntegers(int n) {
    queue<int> board;
    board.push(n);

    unordered_set<int> answer;
    answer.insert(n);

    while (!board.empty()) {
      for (int i = 1; i <= board.front(); i++) {
        if (board.front() % i == 1) {
          if (answer.count(i) > 0) continue;
          board.push(i);
          answer.insert(i);
        }
      }
      board.pop();
    }

    return answer.size();
  }
};

// use math
// time : O(1)
// space : O(1)
class Solution {
 public:
  int distinctIntegers(int n) {
    if (n == 1) return 1;
    return n - 1;
  }
};