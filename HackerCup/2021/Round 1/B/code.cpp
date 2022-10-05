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

// time : 40 min
vector<vector<int>> solution(int rows, int cols, int a, int b) {
  vector<vector<int>> answer(rows, vector<int>(cols, 1000));

  int minimumNeed = rows + cols - 1;
  if (a < minimumNeed || b < minimumNeed) {
    return {};
  }

  if (cols == 2) {
    int minimum = min(a - (rows - 1), b - (rows - 1));

    if (a > b) {
      for (int y = 0; y < rows; y++) {
        answer[y][1] = 1;
      }
      answer[rows - 1][0] = b - rows;
      answer[0][0] = a - rows;
    } else {
      for (int y = 0; y < rows; y++) {
        answer[y][0] = 1;
      }
      answer[rows - 1][1] = a - rows;
      answer[0][1] = b - rows;
    }

    return answer;
  }

  for (int y = 0; y < rows; y++) {
    answer[y][0] = answer[y][cols - 1] = 1;
  }

  // final row for both
  int minimum = min(a - (rows - 1), b - (rows - 1));
  for (int x = 0; x < cols; x++) {
    answer[rows - 1][x] = minimum / cols;
  }
  answer[rows - 1][cols - 1] += minimum % cols;

  int aLeft = a - minimum;
  int bLeft = b - minimum;

  if (aLeft > 0) {
    for (int y = 0; y < rows - 1; y++) {
      answer[y][0] = aLeft / (rows - 1);
    }
    answer[0][0] += aLeft % (rows - 1);
  }
  if (bLeft > 0) {
    for (int y = 0; y < rows - 1; y++) {
      answer[y][cols - 1] = bLeft / (rows - 1);
    }
    answer[0][cols - 1] += bLeft % (rows - 1);
  }

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
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    vector<vector<int>> answer = solution(N, M, A, B);

    cout << "Case #" << testCase << ": ";
    if (answer.size() == 0) {
      cout << "Impossible\n";
    } else {
      cout << "Possible\n";
      for (vector<int> &line : answer) {
        for (int &a : line) {
          cout << a << " ";
        }
        cout << "\n";
      }
    }
  }

  return 0;
}