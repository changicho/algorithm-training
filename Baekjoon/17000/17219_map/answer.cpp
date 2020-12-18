#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  // map<string, string> m;
  unordered_map<string, string> m;

  string id, password;

  id.reserve(20);
  password.reserve(20);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> id >> password;

    m[id] = password;
  }

  for (int i = 0; i < M; i++) {
    cin >> id;

    cout << m[id] << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}