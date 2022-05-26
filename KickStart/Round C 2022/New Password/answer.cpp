#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<char> specialChar = {'#', '@', '*', '&'};

// At least 7 characters.
// At least one uppercase English alphabet letter.
// At least one lowercase English alphabet letter.
// At least one digit.
// At least one special character. There are four special characters: #, @, *,
// and &.
string getNewPassword(string before) {
  bool hasUpperCase = false;
  bool hasLowerCase = false;
  bool hasDigit = false;
  bool hasSpecialChar = false;

  for (char &c : before) {
    if (islower(c)) hasLowerCase = true;
    if (isupper(c)) hasUpperCase = true;
    if (isdigit(c)) hasDigit = true;
    if (specialChar.count(c) > 0) hasSpecialChar = true;
  }

  if (!hasUpperCase) before += 'A';
  if (!hasLowerCase) before += 'a';
  if (!hasDigit) before += '0';
  if (!hasSpecialChar) before += '#';

  while (before.length() < 7) {
    before += '0';
  }

  return before;
}

void init() {}

int main() {
  std::ios_base::sync_with_stdio(false);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  init();

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    string before;

    cin >> N >> before;

    string res = getNewPassword(before);

    cout << "Case #" << testCase << ": " << res << "\n";
  }

  return 0;
}