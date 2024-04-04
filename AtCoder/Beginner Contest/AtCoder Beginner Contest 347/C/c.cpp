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

bool solution(int a, int b, vector<int> &days) {
  int allDays = a + b;

  unordered_set<int> us;
  for (int &day : days) {
    int cur = day % allDays;
    us.insert(cur);
  }

  vector<int> remainders(us.begin(), us.end());
  sort(remainders.begin(), remainders.end());

  int size = remainders.size();

  for (int i = 0; i < size; i++) {
    remainders.push_back(remainders[i] + allDays);
  }

  for (int i = 0; i < size; i++) {
    int start = remainders[i];
    int end = remainders[i + size - 1];

    if (end - start + 1 <= a) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, A, B;
  cin >> N >> A >> B;
  vector<int> D(N);

  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }

  bool answer = solution(A, B, D);

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}