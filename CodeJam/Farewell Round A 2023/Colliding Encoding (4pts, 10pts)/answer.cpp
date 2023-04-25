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

bool hasCollision(vector<int> &table, vector<string> &words) {
  unordered_set<string> converted;

  for (auto &word : words) {
    string temp = "";

    for (auto &c : word) {
      temp += table[c - 'A'] + '0';
    }

    if (converted.count(temp)) {
      return true;
    }

    converted.insert(temp);
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    vector<int> D(26);
    for (int i = 0; i < 26; i++) {
      cin >> D[i];
    }

    int N;

    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++) {
      cin >> words[i];
    }

    bool answer = hasCollision(D, words);

    cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << endl;
  }

  return 0;
}