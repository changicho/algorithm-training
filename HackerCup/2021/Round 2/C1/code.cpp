#include <algorithm>
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

int getMinimumChange(vector<string> &board, int k) {
  const int rows = board.size(), cols = board.front().size();

  vector<int> upperCount(cols, 0);

  int answer = 0;
  for (int x = 0; x < cols; x++) {
    if (board[k][x] == 'X') answer++;
  }

  if (answer == 0) return 0;

  // up case
  for (int y = 0; y <= k; y++) {
    for (int x = 0; x < cols; x++) {
      if (board[y][x] == 'X') {
        upperCount[x]++;
      }
    }
  }

  for (int i = 0; i < rows; i++) {
    int target = (k + 1) + i;
    int curAnswer = i + 1;

    if (curAnswer >= answer) break;
    for (int x = 0; x < cols && target < rows; x++) {
      if (board[target][x] == 'X') {
        upperCount[x]++;
      }
    }

    for (int x = 0; x < cols; x++) {
      if (upperCount[x] >= (k + 1) ||
          target < rows && board[target][x] == 'X') {
        curAnswer++;
      }
    }

    answer = min(curAnswer, answer);
  }

  return answer;
}

int solution(int rows, int cols, int k, vector<string> &board) {
  vector<string> reversed = board;
  for (int y = 0; y < rows / 2; y++) {
    int rI = (rows - 1) - y;

    swap(reversed[y], reversed[rI]);
  }

  int minCount = getMinimumChange(board, k);
  int reverseMinCount = getMinimumChange(reversed, (rows - 1) - k);

  int answer = min(minCount, reverseMinCount);

  // fill
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./valet_parking_chapter_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int R, C, K;
    cin >> R >> C >> K;

    vector<string> G(R);
    for (int i = 0; i < R; i++) {
      cin >> G[i];
    }

    int answer = solution(R, C, K - 1, G);

    cout << "Case #" << testCase << ": ";
    // cout << (answer ? "YES" : "NO") << "\n";
    cout << answer << "\n";
  }

  return 0;
}