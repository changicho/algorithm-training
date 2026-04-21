#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

vector<bool> solution(int size, int m, vector<int>& clothes) {
  vector<bool> answer;

  unordered_set<int> us;
  for (int& c : clothes) {
    us.insert(c);
  }

  answer.push_back(us.size() == size);
  answer.push_back(us.size() == m);

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

  vector<int> F(N);

  for (int i = 0; i < N; i++) {
    cin >> F[i];
  }

  auto answer = solution(N, M, F);

  // cout << answer << endl;
  for (auto line : answer) {
    cout << (line ? "Yes" : "No") << endl;
    // cout << line << "\n";
  }
  // cout << endl;

  return 0;
}