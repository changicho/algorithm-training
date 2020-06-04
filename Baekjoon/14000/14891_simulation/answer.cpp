#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Gear {
  int score;
  vector<bool> gear;

  Gear() { gear.resize(8, false); }

  int getScore() { return gear[0] ? score : 0; }

  bool getLeft() { return gear[6]; }
  bool getRight() { return gear[2]; }

  void turnClock() {
    gear.insert(gear.begin(), gear.back());
    gear.pop_back();
  }
  void turnCounterClock() {
    gear.push_back(gear.front());
    gear.erase(gear.begin());
  }
};

Gear gears[4];

void solution() {
  int K;
  int answer = 0;

  for (int i = 0; i < 4; i++) {
    string line;
    cin >> line;

    for (int c = 0; c < 8; c++) {
      gears[i].gear[c] = line[c] == '0' ? false : true;
    }
    gears[i].score = 1 << i;
  }

  cin >> K;

  for (int command = 0; command < K; command++) {
    int dirs[4] = {
        0,
    };
    int index_gear, dir;

    cin >> index_gear >> dir;
    index_gear -= 1;

    dirs[index_gear] = dir;

    // check left
    int curDir = dir;
    for (int i = index_gear; i >= 1; i--) {
      if (gears[i].getLeft() == gears[i - 1].getRight()) {
        break;
      }

      curDir = -curDir;
      dirs[i - 1] = curDir;
    }

    // check right
    curDir = dir;
    for (int i = index_gear; i < 3; i++) {
      if (gears[i].getRight() == gears[i + 1].getLeft()) {
        break;
      }

      curDir = -curDir;
      dirs[i + 1] = curDir;
    }

    for (int i = 0; i < 4; i++) {
      if (dirs[i] == -1) {
        gears[i].turnCounterClock();
      }
      if (dirs[i] == 1) {
        gears[i].turnClock();
      }
    }
  }

  for (Gear g : gears) {
    answer += g.getScore();
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