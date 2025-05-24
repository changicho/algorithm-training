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

string add(string &a, string &b) {
  int size = a.size();
  string result(size, '0');
  for (int i = 0; i < size; i++) {
    int sum = (a[i] - '0') + (b[i] - '0');
    if (sum >= 2) {
      result[i] = '2';
    } else {
      result[i] = '0' + sum;
    }
  }
  return result;
}

long long solution(int n, int m, vector<long long> &costs,
                   vector<vector<int>> &animals) {
  vector<string> zoos(n, string(m, '0'));
  for (int animal = 0; animal < m; animal++) {
    string mask = string(m, '0');
    mask[animal] = '1';

    for (int &zoo : animals[animal]) {
      zoos[zoo - 1] = add(zoos[zoo - 1], mask);
    }
  }

  string END_CONDITION = string(m, '2');

  long long answer = LLONG_MAX;

  function<void(int, string, long long)> dfs = [&](int index, string mask,
                                                   long long cost) {
    if (index == n) {
      if (mask == END_CONDITION) {
        answer = min(answer, cost);
      }

      return;
    }

    dfs(index + 1, mask, cost);

    string new_mask = mask;
    long long new_cost = cost;
    for (int i = 1; i <= 2; i++) {
      new_mask = add(new_mask, zoos[index]);
      new_cost += costs[index];

      dfs(index + 1, new_mask, new_cost);
    }
  };

  dfs(0, string(m, '0'), 0);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<long long> costs(N);

  for (int i = 0; i < N; i++) {
    cin >> costs[i];
  }

  vector<vector<int>> animals(M);
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;

    for (int j = 0; j < K; j++) {
      int a;
      cin >> a;
      animals[i].push_back(a);
    }
  }

  long long answer = solution(N, M, costs, animals);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}