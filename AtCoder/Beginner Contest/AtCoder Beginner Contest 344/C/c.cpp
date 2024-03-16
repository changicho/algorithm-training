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

vector<bool> solution(vector<int> &a, vector<int> &b, vector<int> &c,
                      vector<long long> &queries) {
  int size1 = a.size(), size2 = b.size(), size3 = c.size();

  vector<bool> answer;

  unordered_set<long long> us;

  for (int i1 = 0; i1 < size1; i1++) {
    for (int i2 = 0; i2 < size2; i2++) {
      for (int i3 = 0; i3 < size3; i3++) {
        long long sum = (long long)a[i1] + b[i2] + c[i3];

        us.insert(sum);
      }
    }
  }

  for (long long &q : queries) {
    if (us.find(q) != us.end()) {
      answer.push_back(true);
    } else {
      answer.push_back(false);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M, L, Q;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  cin >> L;
  vector<int> C(L);
  for (int i = 0; i < L; i++) {
    cin >> C[i];
  }
  cin >> Q;
  vector<long long> X(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i];
  }

  vector<bool> answer = solution(A, B, C, X);

  for (bool a : answer) {
    if (a == true) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
  }

  return 0;
}