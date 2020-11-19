#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int L;
  string word;

  long long R = 1;
  long long M = 1234567891;
  long long summation = 0;

  cin >> L >> word;

  for (char c : word) {
    summation += (c - 'a' + 1) * R;
    summation %= M;
    R *= 31;
    R %= M;
  }

  cout << summation << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}