#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct change {
  int from, to;
};

vector<change> changes;

void hanoi(int n, int from, int by, int to) {
  if (n == 1) {
    changes.push_back({from, to});
  } else {
    hanoi(n - 1, from, to, by);
    changes.push_back({from, to});
    hanoi(n - 1, by, from, to);
  }
}

void solution() {
  int N;
  cin >> N;

  hanoi(N, 1, 2, 3);

  cout << changes.size() << "\n";

  for (change c : changes) {
    cout << c.from << " " << c.to << "\n";
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