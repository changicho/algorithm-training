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

vector<long long> solution(int size, vector<int> &queries) {
  vector<long long> answer(size, 0);
  unordered_set<int> s;
  unordered_map<int, long long> startSums;

  long long sum = 0;

  for (int &query : queries) {
    int target = query - 1;

    if (s.count(target) == 0) {
      startSums[target] = sum;
      s.insert(target);
    } else {
      s.erase(target);
      answer[target] += sum - startSums[target];
      startSums.erase(target);
    }
    sum += s.size();
  }

  for (int target : s) {
    answer[target] += sum - startSums[target];
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<int> X(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i];
  }

  vector<long long> answer = solution(N, X);

  for (int i = 0; i < N; i++) {
    cout << answer[i] << ' ';
  }
  cout << endl;

  return 0;
}