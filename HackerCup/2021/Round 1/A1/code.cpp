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

// time : 10min

int solution(int length, string t) {
  int index = 0;

  int answer = 0;
  bool isLeft = true;
  while (index < length) {
    if (t[index] == 'F') {
      index++;
      continue;
    }

    if (t[index] == 'O') {
      isLeft = false;
      break;
    }
    break;
  }

  while (index < length) {
    if (t[index] == 'O' && isLeft) {
      isLeft = false;
      answer++;
    } else if (t[index] == 'X' && !isLeft) {
      isLeft = true;
      answer++;
    }
    index++;
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
    string T;

    cin >> N >> T;

    int answer = solution(N, T);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}