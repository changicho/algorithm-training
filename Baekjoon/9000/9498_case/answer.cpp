#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  string answer;

  cin >> N;
  N /= 10;

  switch (N) {
    case 10: {
      answer = "A";
      break;
    }
    case 9: {
      answer = "A";
      break;
    }
    case 8: {
      answer = "B";
      break;
    }
    case 7: {
      answer = "C";
      break;
    }
    case 6: {
      answer = "D";
      break;
    }
    default: {
      answer = "F";
    }
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