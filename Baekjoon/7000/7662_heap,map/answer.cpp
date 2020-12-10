#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int K;
  char command;
  long long number;

  multiset<long long> ms;

  cin >> K;
  while (K--) {
    cin >> command >> number;

    switch (command) {
      case 'I': {
        ms.insert(number);

        break;
      }
      case 'D': {
        if (ms.empty()) break;

        if (number == 1) {
          ms.erase(--ms.end());
        } else {
          ms.erase(ms.begin());
        }
        break;
      }
    }
  }

  if (ms.empty()) {
    cout << "EMPTY\n";
    return;
  }
  cout << *(--ms.end()) << " " << *ms.begin() << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}