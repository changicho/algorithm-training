#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct axis {
  int y, x;
};

int map[9][9];

vector<axis> blanks;
bool is_answer = false;

bool check_row(axis current, int number) {
  bool check[10] = {
      0,
  };
  for (int x = 0; x < 9; x++) {
    if (map[current.y][x] == number) return false;
  }
  return true;
}

bool check_col(axis current, int number) {
  bool check[10] = {
      0,
  };
  for (int y = 0; y < 9; y++) {
    if (map[y][current.x] == number) return false;
  }
  return true;
}

bool check_square(axis current, int number) {
  int x_start = (current.x / 3) * 3, y_start = (current.y / 3) * 3;

  for (int y = y_start; y < y_start + 3; y++) {
    for (int x = x_start; x < x_start + 3; x++) {
      if (map[y][x] == number) return false;
    }
  }
  return true;
}

void print_answer() {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cout << map[y][x] << " ";
    }
    cout << "\n";
  }
}

void dfs(int depth) {
  if (is_answer) {
    return;
  }
  if (depth == blanks.size()) {
    is_answer = true;
    print_answer();
    return;
  }

  axis blank = blanks[depth];

  for (int i = 1; i <= 9; i++) {
    if (check_row(blank, i) && check_col(blank, i) && check_square(blank, i)) {
      map[blank.y][blank.x] = i;
      dfs(depth + 1);
      map[blank.y][blank.x] = 0;
    }
  }
}

void solution() {
  int answer;

  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cin >> map[y][x];
      if (map[y][x] == 0) {
        axis current = {y, x};
        blanks.push_back(current);
      }
    }
  }

  dfs(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}