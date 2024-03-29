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

bool solution(int &w, int &b) {
  string piano = "wbwbwwbwbwbw";

  int size = piano.size();

  int length = w + b;
  for (int index = 0; index < size; index++) {
    int wCount = 0, bCount = 0;
    for (int i = 0; i < length; i++) {
      char cur = piano[(index + i) % size];
      if (cur == 'b') {
        bCount++;
      } else if (cur == 'w') {
        wCount++;
      }
    }
    if (wCount == w && bCount == b) return true;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int W, B;
  cin >> W >> B;

  bool answer = solution(W, B);

  cout << (answer ? "Yes" : "No") << "\n";

  return 0;
}