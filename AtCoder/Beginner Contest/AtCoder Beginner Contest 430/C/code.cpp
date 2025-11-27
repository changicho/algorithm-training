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

auto solution(int size, int a, int b, string& s) {
  long long answer = 0;

  int left = -1, rightA = -1, rightB = -1;
  int aCount = 0;
  int bCount = 0;

  for (; left < size; left++) {
    if (left >= 0) {
      if (s[left] == 'a') {
        aCount--;
      } else {
        bCount--;
      }
    }

    while (rightA < size && aCount < a) {
      if (s[rightA + 1] == 'a') {
        aCount++;
      }
      rightA++;
    }
    while (rightB < size && bCount < b) {
      if (s[rightB + 1] == 'b') {
        bCount++;
      }
      rightB++;
    }

    if (rightB > rightA) {
      answer += rightB - rightA;
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

  int N, A, B;
  cin >> N >> A >> B;

  string S;
  cin >> S;

  auto answer = solution(N, A, B, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}