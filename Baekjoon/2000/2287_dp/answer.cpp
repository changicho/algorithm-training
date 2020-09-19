#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, K;
  set<int> s[9];

  cin >> K >> N;

  string temp = "";

  for (int i = 1; i <= 8; i++) {
    temp += to_string(K);
    s[i].insert(stoi(temp));
  }

  for (int i = 1; i <= 8; i++) {
    for (int j = 0; j < i; j++) {
      for (int first : s[i - j]) {
        for (int second : s[j]) {
          s[i].insert(first + second);
          s[i].insert(first - second);
          s[i].insert(first * second);

          if (second != 0) {
            s[i].insert(first / second);
          }
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    int cur;
    int answer = -1;
    cin >> cur;

    for (int index = 1; index <= 8; index++) {
      if (s[index].find(cur) != s[index].end()) {
        answer = index;
        break;
      }
    }

    if (answer == -1) {
      cout << "NO\n";
      continue;
    }
    cout << answer << "\n";
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