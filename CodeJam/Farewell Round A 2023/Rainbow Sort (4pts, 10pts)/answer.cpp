#include <algorithm>
#include <climits>
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

vector<int> solution(vector<int> &colors) {
  int size = colors.size();

  unordered_set<int> used;
  vector<int> answer;
  used.insert(colors[0]);
  answer.push_back(colors[0]);
  for (int i = 1; i < size; i++) {
    if (colors[i] == colors[i - 1]) continue;

    if (used.count(colors[i])) return {};
    used.insert(colors[i]);
    answer.push_back(colors[i]);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> colors(N);
    for (int i = 0; i < N; i++) {
      cin >> colors[i];
    }

    vector<int> answer = solution(colors);
    cout << "Case #" << testCase << ": ";
    if (answer.size() == 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      for (int &num : answer) {
        cout << num << " ";
      }
      cout << endl;
    }
  }

  return 0;
}