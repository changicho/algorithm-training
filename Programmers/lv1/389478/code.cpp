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
// time : O(N)
// space : O(N)
int solution(int n, int w, int num) {
  int targetY = -1, targetX = -1;

  int board[101][101] = {
      0,
  };

  for (int y = 0, i = 1; y <= 100 && i <= n; y++) {
    for (int x = 0; x < w && i <= n; x++) {
      int xx = y % 2 ? x : w - 1 - x;

      board[y][xx] = i;
      if (i == num) {
        targetY = y;
        targetX = xx;
      }
      i++;
    }
  }

  int answer = 0;
  for (int y = targetY; y <= 100; y++) {
    if (board[y][targetX] > 0) {
      answer++;
    }
  }

  return answer;
}