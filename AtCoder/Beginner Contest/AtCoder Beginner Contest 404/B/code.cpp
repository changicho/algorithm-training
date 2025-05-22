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

vector<string> rotate(vector<string> &s) {
  int size = s.size();
  vector<string> rotated(size, string(size, '.'));

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      rotated[x][size - 1 - y] = s[y][x];
    }
  }

  return rotated;
}

int findDiff(vector<string> &s, vector<string> &t) {
  int size = s.size();
  int diff = 0;

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (s[y][x] != t[y][x]) {
        diff++;
      }
    }
  }

  return diff;
}

int solution(int size, vector<string> &s, vector<string> &t) {
  int answer = size * size;

  for (int i = 0; i < 4; i++) {
    int diff = findDiff(s, t);
    answer = min(answer, diff + i);
    s = rotate(s);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<string> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }

  int answer = solution(N, S, T);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}