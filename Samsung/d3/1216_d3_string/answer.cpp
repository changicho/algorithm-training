#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 100

using namespace std;

bool isPalin(string s) {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }
  return true;
}

void solution(int test_case) {
  int answer = 100;
  bool flag = true;
  char map[MAX_SIZE][MAX_SIZE];
  string word;

  cin >> test_case;

  for (int y = 0; y < MAX_SIZE; y += 1) {
    for (int x = 0; x < MAX_SIZE; x += 1) {
      cin >> map[y][x];
    }
  }

  while (flag) {
    for (int y = 0; y < MAX_SIZE; y += 1) {
      for (int x = 0; x < MAX_SIZE - answer + 1; x += 1) {
        word = "";
        for (int i = 0; i < answer; i += 1) {
          word += map[y][x + i];
        }
        if (isPalin(word)) flag = false;
      }
    }

    for (int y = 0; y < MAX_SIZE - answer + 1; y += 1) {
      for (int x = 0; x < MAX_SIZE; x += 1) {
        word = "";
        for (int i = 0; i < answer; i += 1) {
          word += map[y + i][x];
        }
        if (isPalin(word)) flag = false;
      }
    }

    if (flag) answer -= 1;
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}