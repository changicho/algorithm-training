#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int board[30][30];
Axis limit;

vector<Axis> detect() {
  vector<Axis> result;

  for (int y = 0; y < limit.y - 1; y++) {
    for (int x = 0; x < limit.x - 1; x++) {
      int target = board[y][x];
      if (target == 0) continue;

      if (board[y + 1][x] == target && board[y][x + 1] == target && board[y + 1][x + 1] == target) {
        result.push_back({y, x});
      }
    }
  }

  return result;
}

int destory(vector<Axis> destoryList) {
  int count = 0;
  for (Axis axis : destoryList) {
    for (int y = 0; y < 2; y++) {
      for (int x = 0; x < 2; x++) {
        if (board[axis.y + y][axis.x + x] != 0) {
          count += 1;
          board[axis.y + y][axis.x + x] = 0;
        }
      }
    }
  }

  return count;
}

void pull() {
  for (int x = 0; x < limit.x; x++) {
    for (int y = limit.y - 1; y >= 0; y--) {
      while (board[y][x] == 0) {
        int zeroCount = 0;

        for (int y2 = y - 1; y2 >= 0; y2--) {
          if (board[y2][x] != 0) zeroCount += 1;
          board[y2 + 1][x] = board[y2][x];
        }
        board[0][x] = 0;

        if (zeroCount == 0) break;
      }
    }
  }
}

int solution(int m, int n, vector<string> b) {
  memset(board, 0, sizeof(board));
  int answer = 0;
  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++) {
      board[y][x] = b[y][x];
    }
  }

  limit.y = m;
  limit.x = n;

  while (true) {
    vector<Axis> destoryList = detect();
    if (destoryList.size() == 0) break;

    answer += destory(destoryList);
    pull();
  }

  return answer;
}

struct TestCase {
  int m;
  int n;
  vector<string> board;
  int answer;
};

int main() {
  vector<TestCase> testCases = {
      {4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}, 14},
      {6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}, 15}};

  for (TestCase testCase : testCases) {
    int answer = solution(testCase.m, testCase.n, testCase.board);

    cout << "answer : " << answer << ", myAnswer : " << testCase.answer << "\n";
  }

  return 0;
}