#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canMove(vector<long long>& diffs) {
  int odd = 0, even = 0;
  for (long long diff : diffs) {
    if (diff % 2 == 1) {
      odd++;
    } else {
      even++;
    }
  }

  if (even == 0 || odd == 0) {
    return true;
  }
  return false;
}

void solution(int test_case) {
  int answer = 0, N;
  long long max_diff = 0;
  vector<long long> diffs;

  cin >> N;

  for (int i = 0; i < N; i++) {
    long long x, y;
    cin >> x >> y;
    long long diff = abs(0 - x) + abs(0 - y);

    diffs.push_back(diff);
    max_diff = max(max_diff, diff);
  }

  if (!canMove(diffs)) {
    answer = -1;
    cout << "#" << test_case << " " << answer << "\n";
    return;
  }

  for (answer = 0; answer < 100000; answer++) {
    max_diff -= answer;

    if (max_diff <= 0) {
      break;
    }
  }

  max_diff = -max_diff % 2;

  if (max_diff != 0) {
    if (max_diff == (answer + 1) % 2) {
      answer += 1;
    } else {
      answer += 2;
    }
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}