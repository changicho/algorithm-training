#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

auto solution(int size, string &number, int digit) {
  for (int i = 0; i < size; i++) {
    int cur = number[i] - '0';

    if (cur < digit) {
      number.insert(i, to_string(digit));
      break;
    }
  }
  if (number.size() == size) {
    number += to_string(digit);
  }

  return number;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, D;
    cin >> N >> D;

    string number;
    cin >> number;

    auto answer = solution(N, number, D);

    cout << answer << endl;
  }

  return 0;
}