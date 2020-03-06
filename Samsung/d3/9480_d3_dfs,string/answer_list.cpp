#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> words;
int answer = 0;

bool checkAllAlpha(vector<bool> check) {
  for (int i = 0; i < 26; i++) {
    if (!check[i]) {
      return false;
    }
  }
  return true;
}

void dfs(int depth, vector<bool> board) {
  if (depth == words.size()) {
    if (checkAllAlpha(board)) {
      answer += 1;
    }
    return;
  }

  dfs(depth + 1, board);

  for (char c : words[depth]) {
    board[c - 'a'] = true;
  }
  dfs(depth + 1, board);
}

void solution(int test_case) {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    words.push_back(word);
  }

  vector<bool> board(26, false);

  dfs(0, board);

  cout << "#" << test_case << " " << answer << "\n";
}

void clear() {
  words.resize(0);
  answer = 0;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    clear();
    solution(test_case);
  }

  return 0;
}