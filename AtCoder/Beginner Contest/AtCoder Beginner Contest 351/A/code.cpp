#include <algorithm>
#include <cmath>
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

int solution(vector<int> &a, vector<int> &b) {
  int aSum = accumulate(a.begin(), a.end(), 0),
      bSum = accumulate(b.begin(), b.end(), 0);

  if (bSum > aSum) return 0;
  return aSum - bSum + 1;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<int> A(9), B(8);

  for (int i = 0; i < 9; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < 8; i++) {
    cin >> B[i];
  }

  int answer = solution(A, B);

  cout << answer << "\n";

  return 0;
}