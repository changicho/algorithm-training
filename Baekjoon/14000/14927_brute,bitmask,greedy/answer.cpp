#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis {
  int y, x;
};

int N;
long long board[18];
long long temp_board[18];

void toggle(Axis axis) {
  int y = axis.y, x = axis.x;
  temp_board[y] ^= (1 << (N - x - 1));

  if (y > 0) {
    temp_board[y - 1] ^= (1 << (N - x - 1));
  }
  if (y < N - 1) {
    temp_board[y + 1] ^= (1 << (N - x - 1));
  }
  if (x > 0) {
    temp_board[y] ^= (1 << (N - x));
  }
  if (x < N - 1) {
    temp_board[y] ^= (1 << (N - x - 2));
  }
}

void solution() {
  cin >> N;

  bool isOn;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> isOn;
      if (isOn) {
        board[y] |= (1 << (N - x - 1));
      }
    }
  }

  int answer = -1;

  for (long long bitMask = (1 << N) - 1; bitMask >= 0; bitMask--) {
    int count = 0;

    for (int y = 0; y < N; y++) {
      temp_board[y] = board[y];
    }

    for (int x = 0; x < N; x++) {
      if (bitMask & (1 << (N - x - 1))) {
        toggle({0, x});

        count++;
      }
    }

    for (int y = 1; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (temp_board[y - 1] & (1 << (N - x - 1))) {
          toggle({y, x});

          count++;
        }
      }
    }

    if (temp_board[N - 1] == 0) {
      if (answer == -1) {
        answer = count;
      } else {
        answer = min(answer, count);
      }
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}