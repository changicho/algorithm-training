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

long long solution(vector<int> &nums, long long k) {
  long long sum = k * (k + 1) / 2;

  unordered_set<int> us;
  for (int &num : nums) {
    if (us.count(num)) continue;
    if (num > k) continue;
    us.insert(num);
    sum -= num;
  }
  return sum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  long long K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long answer = solution(A, K);

  cout << answer << endl;
  return 0;
}