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

int solution(int size, vector<string> &board) {
  int answer = 0;

  for (int y = 0; y < size / 2; y++) {
    for (int x = 0; x < size / 2; x++) {
      // y x
      // x size-1-y
      // size-1-y size-1-x
      // size-1-x y
      vector<char> arr = {board[y][x], board[x][size - 1 - y],
                          board[size - y - 1][size - 1 - x],
                          board[size - x - 1][y]};
      char max = *max_element(arr.begin(), arr.end());

      int count = 0;
      for (char &c : arr) {
        count += max - c;
      }

      answer += count;
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

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
      cin >> board[i];
    }

    int answer = solution(N, board);

    cout << answer << "\n";
  }

  return 0;
}