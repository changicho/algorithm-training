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

bool solution(vector<int> &a, vector<int> &b) {
  unordered_set<int> us(a.begin(), a.end());

  vector<int> c;
  for (int &num : a) {
    c.push_back(num);
  }
  for (int &num : b) {
    c.push_back(num);
  }
  sort(c.begin(), c.end());

  for (int i = 0; i < c.size() - 1; i++) {
    if (us.count(c[i]) && us.count(c[i + 1])) {
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

  int N, M;
  cin >> N >> M;

  vector<int> A(N), B(M);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  bool answer = solution(A, B);

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}