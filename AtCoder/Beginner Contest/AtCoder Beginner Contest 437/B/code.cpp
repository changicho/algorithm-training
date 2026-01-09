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

int solution(vector<vector<int>>& board, vector<int>& nums) {
  int height = board.size();
  int width = board[0].size();

  unordered_set<int> numSet(nums.begin(), nums.end());
  int answer = 0;

  for (int y = 0; y < height; y++) {
    int count = 0;
    for (int x = 0; x < width; x++) {
      if (numSet.count(board[y][x]) > 0) {
        count++;
      }
    }

    answer = max(answer, count);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int H, W, N;
  cin >> H >> W >> N;

  vector<vector<int>> A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A[y][x];
    }
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  auto answer = solution(A, B);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}