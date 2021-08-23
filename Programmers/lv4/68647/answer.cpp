#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 10000019

using namespace std;

void calculateCombination(vector<vector<long long>> &combination, int limit) {
  combination[0][0] = 1;
  for (int n = 1; n <= limit; n++) {
    for (int r = 0; r <= limit; r++) {
      if (r == 0 || n == r) {
        combination[n][r] = 1;
        continue;
      }

      combination[n][r] = (combination[n - 1][r - 1] + combination[n - 1][r]) % MOD;
    }
  }
}

int solution(vector<vector<int>> board) {
  int rows = board.size();
  int cols = board.front().size();

  vector<vector<long long>> combination(rows + 1, vector<long long>(rows + 1, 0));
  vector<int> ones(cols + 1, 0);
  vector<vector<long long>> dp(cols + 1, vector<long long>(rows + 1, 0));

  calculateCombination(combination, rows);

  // count one of columns
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      ones[col] += board[row][col];
    }
  }

  dp[1][rows - ones.front()] = combination[rows][rows - ones.front()];

  for (int col = 1; col < cols; col++) {
    int curOnes = ones[col];

    for (int row = 0; row <= rows; row++) {
      // 짝수행을 가진 배열이 존재하지 않는 경우 계산 X
      if (dp[col][row] == 0) continue;

      for (int one = 0; one <= curOnes; one++) {
        // 기존 짝수행에서 1의 선택을 받지 못한 경우 + 기존 홀수행에 추가되는 나머지 1의 개수
        int nextEvenRows = (row - one) + (curOnes - one);
        if (row < one || nextEvenRows > rows) continue;

        // 짝수행이 만들어 질 수 있는 경우의 수
        // 기존 짝수행에서 k를 선택하는 경우의 수 x 홀수행에서 나머지 1을 선택하는 경우의 수
        long long result = (combination[row][one] * combination[rows - row][curOnes - one]) % MOD;

        // 다음 열까지 짝수행의 개수 += (현재 열까지 짝수행의 개수 x 짝수행이 만들어질 수 있는 경우의 수)
        // dp[col + 1][nextEvenRows]에 해당하는 값이 여러번 등장할 수 있으므로 기존값과 함께 더해줌
        dp[col + 1][nextEvenRows] = (dp[col + 1][nextEvenRows] + dp[col][row] * result) % MOD;
      }
    }
  }

  return dp.back().back();
}