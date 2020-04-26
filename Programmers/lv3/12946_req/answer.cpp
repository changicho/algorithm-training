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

vector<vector<int>> solution(int n) {
  vector<vector<int>> answer;

  hanoi(n, 1, 2, 3);

  cout << changes.size() << endl;

  for (change c : changes) {
    vector<int> a(2);
    a[0] = c.from;
    a[1] = c.to;
    answer.push_back(a);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  vector<vector<int>> answer = solution(N);

  for (vector<int> a : answer) {
    cout << a[0] << " " << a[1] << "\n";
  }

  return 0;
}