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

vector<long long> solution(vector<long long> &arr, vector<int> &queries) {
  unordered_set<long long> us;
  stack<long long> stk;

  for (int &q : queries) {
    long long cur = 1 << q;

    if (!stk.empty() && stk.top() <= cur) {
      continue;
    }
    stk.push(cur);
  }

  while (!stk.empty()) {
    us.insert(stk.top());
    stk.pop();
  }

  int size = arr.size();
  for (int i = 0; i < size; i++) {
    long long cur = arr[i];
    long long sum = 0;

    for (int j = 1; j <= 30; j++) {
      int divisor = 1 << j;

      if (cur % divisor == 0 && us.count(divisor) > 0) {
        sum += divisor / 2;
      }
    }

    arr[i] += sum;
  }
  return arr;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    vector<int> X(Q);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < Q; i++) {
      cin >> X[i];
    }

    vector<long long> answer = solution(A, X);

    for (long long &cur : answer) {
      cout << cur << " ";
    }
    cout << "\n";
  }

  return 0;
}