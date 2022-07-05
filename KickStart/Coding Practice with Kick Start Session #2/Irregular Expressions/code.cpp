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

int getCount(string &word) {
  int vowelCount = 0;
  for (char &c : word) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowelCount += 1;
    }
  }
  return vowelCount;
}

// The start word is always the same as the end word and consists of at least
// two syllables. A syllable consists of any number of letters, including
// exactly one vowel.
bool search(string &s, int index) {
  int length = s.length();
  string prefix = "";
  for (int i = index; i < length; i++) {
    prefix += s[i];

    int left = i + 1;
    int prefixCount = getCount(prefix);

    if (prefixCount <= 1) continue;
    int right = left;
    while (s.find(prefix, right) != string::npos) {
      if (right + prefix.length() - 1 >= length) {
        right += 1;
        continue;
      }
      string middle = "";
      for (int j = left; j < right; j++) {
        middle += s[j];
      }
      if (getCount(middle) == 1 && middle.length() > 0) {
        return true;
      }
      right += 1;
    }
  }
  return false;
}

bool isSpell(string &s) {
  int length = s.length();

  for (int i = 0; i < length; i++) {
    bool cur = search(s, i);

    if (cur) return true;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    string S;
    cin >> S;

    bool answer = isSpell(S);

    cout << "Case #" << testCase << ": " << (answer ? "Spell!" : "Nothing.")
         << "\n";
  }

  return 0;
}