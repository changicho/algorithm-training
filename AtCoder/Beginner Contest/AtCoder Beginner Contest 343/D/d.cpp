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

vector<int> solution(int &n, vector<vector<int>> &ab) {
  vector<int> answer;

  vector<long long> arr(n + 1, 0);
  unordered_map<long long, int> um;

  um[0] = n;

  for (vector<int> &change : ab) {
    int from = change[0];
    long long diff = change[1];

    um[arr[from]]--;
    if (um[arr[from]] == 0) {
      um.erase(arr[from]);
    }

    arr[from] += diff;
    um[arr[from]]++;

    answer.push_back(um.size());
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, T;
  cin >> N >> T;

  vector<vector<int>> AB(T, vector<int>(2, 0));

  for (int i = 0; i < T; i++) {
    cin >> AB[i][0] >> AB[i][1];
  }

  vector<int> answer = solution(N, AB);

  for (int &a : answer) {
    cout << a << '\n';
  }

  return 0;
}