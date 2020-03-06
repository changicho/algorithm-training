#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ALLALPHA = 67108863;

int alpha[26] = {1,       2,       4,       8,        16,      32,     64,
                 128,     256,     512,     1024,     2048,    4096,   8192,
                 16384,   32768,   65536,   131072,   262144,  524288, 1048576,
                 2097152, 4194304, 8388608, 16777216, 33554432};
vector<int> words;
int answer = 0;

void dfs(int depth, int board) {
  if (depth == words.size()) {
    if (board == ALLALPHA) {
      answer += 1;
    }
    return;
  }

  dfs(depth + 1, board);

  board = board | words[depth];
  dfs(depth + 1, board);
}

void solution(int test_case) {
  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    int temp = 0;

    for (char c : word) {
      temp |= alpha[c - 'a'];
    }

    words.push_back(temp);
  }

  dfs(0, 0);

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

  // for (int i = 0; i < 26; i++) {
  //   alpha[i] = 1 << i;
  // }

  for (int test_case = 1; test_case <= T; test_case++) {
    clear();
    solution(test_case);
  }

  return 0;
}