#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use DFS with backtracking
// time : O(K)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  void recursive(int n, int index, unordered_set<int> &visited) {
    if (index == n) {
      answer++;
      return;
    }

    for (int num = 1; num <= n; num++) {
      if (visited.count(num)) continue;

      if (num % (index + 1) == 0 || (index + 1) % num == 0) {
        visited.insert(num);
        recursive(n, index + 1, visited);
        visited.erase(num);
      }
    }
  }

 public:
  int countArrangement(int n) {
    unordered_set<int> visited;

    recursive(n, 0, visited);

    return answer;
  }
};

// use bit masking DFS with backtracking
// time : O(K)
// space : O(N)
class Solution {
 private:
  int answer = 0;

  void recursive(int n, int index, int &visited) {
    if (index == n) {
      answer++;
      return;
    }

    for (int num = 1; num <= n; num++) {
      if (visited & (1 << num)) continue;

      if (num % (index + 1) == 0 || (index + 1) % num == 0) {
        visited ^= (1 << num);
        recursive(n, index + 1, visited);
        visited ^= (1 << num);
      }
    }
  }

 public:
  int countArrangement(int n) {
    int visited = 0;
    recursive(n, 0, visited);

    return answer;
  }
};