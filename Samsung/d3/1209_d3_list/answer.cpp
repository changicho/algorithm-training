#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX_SIZE 100

using namespace std;

void solution(int test_case) {
  cin >> test_case;
  int answer = 0, sum1, sum2;
  int arr[100][100];

  for (int y = 0; y < MAX_SIZE; y += 1) {
    for (int x = 0; x < MAX_SIZE; x += 1) {
      cin >> arr[y][x];
    }
  }

  for (int i = 0; i < MAX_SIZE; i += 1) {
    sum1 = 0, sum2 = 0;
    for (int j = 0; j < MAX_SIZE; j += 1) {
      sum1 += arr[j][i];
      sum2 += arr[i][j];
    }
    answer = max(answer, sum1);
    answer = max(answer, sum2);
  }

  sum2 = 0, sum1 = 0;
  for (int i = 0; i < MAX_SIZE; i += 1) {
    sum1 += arr[i][i];
    sum2 += arr[i][MAX_SIZE - 1 - i];
  }
  answer = max(sum1, answer);
  answer = max(sum2, answer);

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}