#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string number;

  cin >> number;
  int sum = 0;

  for (char c : number) {
    sum += c - '0';
  }

  sort(number.begin(), number.end());

  if (sum % 3 != 0 || number[0] != '0') {
    cout << "-1\n";
    return;
  }

  reverse(number.begin(), number.end());

  cout << number << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}