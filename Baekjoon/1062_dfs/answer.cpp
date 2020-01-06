#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> words;
bool visited['z' - 'a' + 1];
int N, K, answer;

int count_can_memory() {
  bool flag;
  int count = 0;
  for (string word : words) {
    flag = true;
    for (char c : word) {
      if (!visited[c - 'a']) {
        flag = false;
        break;
      }
    }
    if (flag) count += 1;
  }
  return count;
}

void dfs(int depth, int index) {
  if (depth == K) {
    int count = count_can_memory();
    answer = max(count, answer);
    return;
  }

  for (int i = index; i <= 'z' - 'a'; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(depth + 1, i);
      visited[i] = false;
    }
  }
}

void clear() {
  answer = 0;
  words.resize(0);
  for (int i = 0; i < 'z' - 'a'; i++) {
    visited[i] = 0;
  }
  visited['a' - 'a'] = 1;
  visited['c' - 'a'] = 1;
  visited['i' - 'a'] = 1;
  visited['n' - 'a'] = 1;
  visited['t' - 'a'] = 1;
}

void solution() {
  clear();
  string word;

  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> word;
    words.push_back(word);
  }

  if (K - 5 >= 0) {
    dfs(5, 0);
  }

  cout << answer << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}