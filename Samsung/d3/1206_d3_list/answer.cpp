#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer = 0;
  vector<int> buildings;
  int N;
  cin >> N;
  for (int i = 0; i < N; i += 1) {
    int building;
    cin >> building;
    buildings.push_back(building);
  }

  for (int i = 2; i < N - 2; i++) {
    int high = max(max(buildings[i - 2], buildings[i - 1]),
                   max(buildings[i + 1], buildings[i + 2]));
    int diff = buildings[i] - high;
    if (diff > 0) {
      answer += diff;
    }
  }

  cout << "#" << test_case << " ";
  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int test_case = 1; test_case <= 10; test_case++) {
    solution(test_case);
  }

  return 0;
}