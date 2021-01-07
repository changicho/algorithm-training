#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N;
int scores[50][9];
int answer = 0;
int max_score = 0;
int order_index = 0;

void game(vector<int> order, int inning) {
  int out = 0;
  int get_score = 0;

  queue<int> field;
  field.push(0);
  field.push(0);
  field.push(0);

  while (out < 3) {
    get_score = 0;

    int current = scores[inning][order[order_index] - 1];

    order_index++;
    order_index %= 9;

    if (current == 0) {
      out++;
      continue;
    } else {
      bool isFisrt = true;
      for (int i = 0; i < current; i++) {
        if (field.front() != 0) {
          get_score++;
        }
        field.pop();
        if (isFisrt) {
          field.push(1);
          isFisrt = false;
        } else {
          field.push(0);
        }
      }
    }
    answer += get_score;
  }

  // 한 이닝이 끝남
}

void solution() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> scores[i][j];
    }
  }

  vector<int> order;
  for (int i = 0; i < 8; i++) {
    order.push_back(i + 2);
  }

  do {
    order_index = 0;
    answer = 0;
    vector<int> cur_order = {order[0], order[1], order[2], 1,       order[3],
                             order[4], order[5], order[6], order[7]};

    for (int inning = 0; inning < N; inning++) {
      game(cur_order, inning);
    }

    max_score = max(answer, max_score);
  } while (next_permutation(order.begin(), order.end()));
  // 모든 경우의 수를 돌려봄

  cout << max_score << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}