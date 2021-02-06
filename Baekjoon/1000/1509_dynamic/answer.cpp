#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  string line;
  cin >> line;
  int N = line.length();

  bool isPalindrome[2500][2500] = {
      false,
  };

  isPalindrome[0][0] = true;
  for (int i = 1; i < N; i++) {
    isPalindrome[i][i] = true;
    isPalindrome[i - 1][i] = (line[i - 1] == line[i]);
  }

  for (int length = 2; length < N; length++) {
    for (int from = 0; from < N - length; from += 1) {
      int to = from + length;

      isPalindrome[from][to] = isPalindrome[from + 1][to - 1] && (line[from] == line[to]);
    }
  }

  int count[2500] = {
      1,
  };

  for (int index = 1; index < N; index++) {
    count[index] = count[index - 1] + 1;

    if (isPalindrome[0][index]) {
      count[index] = 1;
    }

    for (int cur = 1; cur <= index; cur++) {
      if (isPalindrome[cur][index]) {
        count[index] = min(count[index], count[cur - 1] + 1);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << count[i] << " ";
  }
  cout << endl;

  cout << count[N - 1] << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}