#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long my_pow(long long a, int t) {
  long long res = 1;
  while (t--) res *= a;
  return res;
}

long long calc(long long num) {
  // cur number : AXXXX...
  string digits = to_string(num);
  int size = digits.size();

  int front = digits[0] - '0';

  long long ret = 0;

  // calc A0000... ~ AXXXX...
  for (int i = 1; i <= size; i++) {
    if (i == size) {
      ret++;
      break;
    }

    int cur = digits[i] - '0';

    long long curCase = min(front, cur);
    long long otherCase = my_pow(front, size - 1 - i);
    ret += curCase * otherCase;

    if (cur >= front) break;
  }

  // calc 0 ~ (A000... - 1)
  for (int i = 0; i < size; i++) {
    int limit = (i != 0 ? 9 : (front - 1));

    for (int digit = 1; digit <= limit; digit++) {
      ret += my_pow(digit, size - 1 - i);
    }
  }
  return ret;
}

long long solution(long long left, long long right) {
  long long answer = calc(right) - calc(left - 1);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long L, R;
  cin >> L >> R;

  long long answer = solution(L, R);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}