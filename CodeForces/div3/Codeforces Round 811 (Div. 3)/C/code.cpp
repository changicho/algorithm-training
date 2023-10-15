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

// time : 20min
string table[46] = {
    "",
};

void recursive(int num, int sum, string val) {
  if (num > 10) return;

  if (table[sum] == "") {
    table[sum] = val;
  } else {
    if (val != "" && stoi(val) < stoi(table[sum])) {
      table[sum] = val;
    }
  }

  string next = val;
  next += (num + '0');
  recursive(num + 1, sum + num, next);
  recursive(num + 1, sum, val);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  recursive(1, 0, "");

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int S;
    cin >> S;

    cout << table[S] << "\n";
  }

  return 0;
}