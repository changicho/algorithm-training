#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b) {
  if (a.length() > b.length()) {
    return false;
  }

  if (a.length() == b.length()) {
    return a < b;
  }
  return true;
}

void solution() {
  int N;
  cin >> N;

  vector<string> words(N);

  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }
  // 요구조건에 맞춰 정렬
  sort(words.begin(), words.end(), compare);
  // 중복 원소 제거
  words.erase(unique(words.begin(), words.end()), words.end());

  for (string word : words) {
    cout << word << "\n";
  }

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}