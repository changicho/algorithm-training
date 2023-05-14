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

auto solution(int size, int x1, int y1, int x2, int y2) {
  int firstX = min(x1, size + 1 - x1);
  int firstY = min(y1, size + 1 - y1);
  int secondX = min(x2, size + 1 - x2);
  int secondY = min(y2, size + 1 - y2);

  int firstLoop = min(firstX, firstY);
  int secondLoop = min(secondX, secondY);

  if (firstLoop == secondLoop) return 0;

  int answer = abs(firstLoop - secondLoop);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, X1, Y1, X2, Y2;
    cin >> N >> X1 >> Y1 >> X2 >> Y2;

    auto answer = solution(N, X1, Y1, X2, Y2);

    cout << answer << "\n";
  }
  cout << endl;

  return 0;
}