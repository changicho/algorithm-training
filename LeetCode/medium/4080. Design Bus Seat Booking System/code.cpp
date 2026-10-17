#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// simulation with count array
// time : O(N)
// space : O(N)
class BusBooking {
 private:
  pair<int, int> parse(string& s) {
    int x = s[0] - 'A';
    int y = stoi(s.substr(1));

    return {y, x};
  }

  vector<vector<int>> board;
  int count = 0;
  int totalTime = 0;

 public:
  BusBooking(int n) { board.resize(n + 1, vector<int>(4, 0)); }

  void toggle(string seat) {
    auto [y, x] = parse(seat);

    if (board[y][x]) {
      count--;

      totalTime -= board[y][x];
      board[y][x] = 0;
    } else {
      count++;

      bool needCross = (x == 0 && board[y][1]) || (x == 3 && board[y][2]);
      int cost = 1 + (needCross ? 2 : 0);
      totalTime += cost;
      board[y][x] = cost;
    }
  }

  int getTotalTime() { return totalTime; }

  int getMinTime() { return count; }
};
