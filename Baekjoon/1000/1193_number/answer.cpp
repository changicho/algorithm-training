#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  int depth = 1;
  long long sum = 0;

  while (sum < N) {
    sum += depth;
    depth += 1;
  }

  depth -= 1;
  sum -= depth;

  int count = N - sum;

  int big = depth - (count - 1), small = 1 + (count - 1);

  if (depth % 2 == 1) {
    cout << big << "/" << small;
  } else {
    cout << small << "/" << big;
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