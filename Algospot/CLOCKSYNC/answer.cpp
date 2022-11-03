#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> switches = {
    {0, 1, 2},         {3, 7, 9, 11},   {4, 10, 14, 15}, {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12}, {0, 2, 14, 15},  {3, 14, 15},     {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},   {3, 4, 5, 9, 13}};

bool isAllUpside(vector<int> &clocks) {
  for (int i = 0; i < 16; i++) {
    if (clocks[i] != 0) return false;
  }
  return true;
}

void recursive(int index, vector<int> clocks, int count, int &answer) {
  if (isAllUpside(clocks)) {
    if (answer == -1) {
      answer = count;
    }
    answer = min(count, answer);
  }

  if (index == 10) {
    return;
  }

  recursive(index + 1, clocks, count, answer);
  for (int i = 0; i < 3; i++) {
    for (int &target : switches[index]) {
      clocks[target] += 3;
      clocks[target] %= 12;
    }
    count++;

    recursive(index + 1, clocks, count, answer);
  }
}

int solution(vector<int> &clocks) {
  int answer = -1;

  recursive(0, clocks, 0, answer);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  while (C--) {
    vector<int> clocks(16, 0);
    for (int i = 0; i < 16; i++) {
      cin >> clocks[i];
      if (clocks[i] == 12) clocks[i] = 0;
    }

    int answer = solution(clocks);

    cout << answer << "\n";
  }

  return 0;
}