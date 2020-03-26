#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int newNum(int n) {
  int first = n / 10 + n % 10;

  return (n % 10) * 10 + first % 10;
}

void solution() {
  int N, temp;
  int answer = 0;
  cin >> N;
  temp = N;

  temp = newNum(temp);
  answer += 1;

  while (temp != N) {
    temp = newNum(temp);
    answer += 1;
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}