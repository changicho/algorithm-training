#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

vector<int> solution(int n) {
  vector<int> answer;
  int board[1000][1000] = {
      0,
  };

  Axis axis = {0, 0};
  int number = 1;
  int limit = n * (n + 1) / 2;

  while (number <= limit) {
    while (board[axis.y][axis.x] == 0 && axis.y < n) {
      board[axis.y][axis.x] = number;
      number += 1;
      axis.y += 1;
    }

    axis.y -= 1;
    axis.x += 1;

    while (board[axis.y][axis.x] == 0 && axis.x < n) {
      board[axis.y][axis.x] = number;
      number += 1;
      axis.x += 1;
    }

    axis.y -= 1;
    axis.x -= 2;

    for (int i = 0; i < n - 1; i++) {
      if (board[axis.y][axis.x] != 0) break;
      board[axis.y][axis.x] = number;
      axis.y -= 1;
      axis.x -= 1;
      number += 1;
    }

    axis.y += 2;
    axis.x += 1;
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x <= y; x++) {
      answer.push_back(board[y][x]);
    }
  }

  return answer;
}

struct TestCase {
  int n;
  vector<int> result;
};

string vectorToString(vector<int> v) {
  string ret = "(";
  for (int i : v) {
    ret += to_string(i) + ", ";
  }
  ret.erase(ret.length() - 2, 2);
  return ret + ")";
}

int main() {
  vector<TestCase> tcs = {
      {4, {1, 2, 9, 3, 10, 8, 4, 5, 6, 7}},
      {5, {1, 2, 12, 3, 13, 11, 4, 14, 15, 10, 5, 6, 7, 8, 9}},
      {6, {1, 2, 15, 3, 16, 14, 4, 17, 21, 13, 5, 18, 19, 20, 12, 6, 7, 8, 9, 10, 11}}

  };

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.n);

    bool isCorrect = vectorToString(answer) == vectorToString(tc.result);

    cout << "answer : " << vectorToString(tc.result) << ", myAnswer : " << vectorToString(answer) << "\n";
  }

  return 0;
}