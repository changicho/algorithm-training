#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct calender {
  int E, S, M;
};

bool compare(calender A, calender B) {
  if (A.E == B.E && A.S == B.S && A.M == B.M) {
    return true;
  }
  return false;
}

void solution() {
  int E, S, M;

  calender target;
  calender limit = {15, 28, 19};
  calender cur = {0, 0, 0};
  int answer = 1;

  cin >> target.E >> target.S >> target.M;

  target.E -= 1;
  target.S -= 1;
  target.M -= 1;

  while (!compare(target, cur)) {
    answer += 1;

    cur.E += 1;
    cur.S += 1;
    cur.M += 1;

    cur.E %= limit.E;
    cur.S %= limit.S;
    cur.M %= limit.M;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}