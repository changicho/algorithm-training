#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int towers[500000];
int answers[500000];

struct tower {
  int index, level;
};

void solution() {
  int N;
  stack<tower> s;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> towers[i];

    if (s.empty()) {
      answers[i] = 0;
      s.push({i, towers[i]});

      continue;
    }

    if (towers[i] > s.top().level) {
      while (!s.empty() && s.top().level < towers[i]) {
        s.pop();
      }

      if (s.empty()) {
        answers[i] = 0;
      } else {
        answers[i] = s.top().index + 1;
      }
    } else {
      answers[i] = s.top().index + 1;
    }
    s.push({i, towers[i]});
  }

  for (int i = 0; i < N; i++) {
    cout << answers[i] << " ";
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