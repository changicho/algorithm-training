#include <algorithm>
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

long long solution(long long num) {
  if (num < 0) {
    long long ret = num / 10;
    return ret;
  }
  long long ret = num / 10;
  if (num % 10 != 0) ret++;

  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long X;
  cin >> X;

  long long answer = solution(X);

  cout << answer << endl;

  return 0;
}