#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int U, D, T;
  int answer = 0;

  cin >> U >> D >> T;

  int high = T - U;

  answer = high / (U - D);

  if ((U - D) * answer != high) {
    answer += 1;
  }

  answer += 1;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}