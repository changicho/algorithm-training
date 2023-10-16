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

bool canDivide(vector<int> &arr, int target) {
  int count = 0;
  vector<int> lefts;
  for (int &num : arr) {
    if (num < target) return false;
    if (num == target) continue;

    if (num % target != 0) return false;
    lefts.push_back(num);
  }

  for (int &left : lefts) {
    count += (left / target) - 1;
  }
  if (count > 3) return false;

  return true;
}

bool solution(int a, int b, int c) {
  vector<int> arr = {a, b, c};
  sort(arr.begin(), arr.end());

  // case fit to first
  if (canDivide(arr, arr.front())) {
    return true;
  }

  // case fit to first / 2
  if (arr.front() % 2 == 0 && canDivide(arr, arr.front() / 2)) {
    return true;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int A, B, C;
    cin >> A >> B >> C;

    double answer = solution(A, B, C);

    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}