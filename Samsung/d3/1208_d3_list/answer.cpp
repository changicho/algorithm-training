#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int dumps, MAX_index = 0, MIN_index = 0, buildings[100];
  cin >> dumps;

  for (int i = 0; i < 100; i += 1) {
    cin >> buildings[i];
    if (buildings[i] > buildings[MAX_index]) MAX_index = i;
    if (buildings[i] < buildings[MIN_index]) MIN_index = i;
  }

  for (int dump = 0; dump < dumps; dump += 1) {
    buildings[MAX_index] -= 1;
    buildings[MIN_index] += 1;

    for (int i = 0; i < 100; i += 1) {
      if (buildings[i] > buildings[MAX_index]) MAX_index = i;
      if (buildings[i] < buildings[MIN_index]) MIN_index = i;
    }
  }

  cout << "#" << test_case << " " << buildings[MAX_index] - buildings[MIN_index]
       << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 10;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}