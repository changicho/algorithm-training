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

vector<int> solution(int n, int q, vector<int> &a) {
  vector<bool> colors(n + 2, false);

  int count = 0;

  vector<int> answer;

  for (int &x : a) {
    if (colors[x] == true) {
      // black
      if (colors[x - 1] == true && colors[x + 1] == true) {
        count++;
      } else if (colors[x - 1] == false && colors[x + 1] == false) {
        count--;
      }

      colors[x] = false;
    } else {
      // white
      if (colors[x - 1] == true && colors[x + 1] == true) {
        count--;
      } else if (colors[x - 1] == false && colors[x + 1] == false) {
        count++;
      }

      colors[x] = true;
    }

    answer.push_back(count);
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
  vector<int> A(Q);

  for (int i = 0; i < Q; i++) {
    cin >> A[i];
  }

  vector<int> answer = solution(N, Q, A);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}