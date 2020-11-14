#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  bool answer = false;
  cin >> N;

  if ((N % 4 == 0 && N % 100 != 0) || N % 400 == 0) answer = true;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}