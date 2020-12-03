#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  string name;
  map<string, int> m;
  vector<string> answers;

  cin >> N >> M;

  for (int i = 0; i < N + M; i++) {
    cin >> name;
    m[name] += 1;
  }

  for (pair<string, int> p : m) {
    if (p.second >= 2) answers.push_back(p.first);
  }

  cout << answers.size() << "\n";

  for (string answer : answers) {
    cout << answer << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}