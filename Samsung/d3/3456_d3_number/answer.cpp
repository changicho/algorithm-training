#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int answer;
  vector<int> arr(3);

  for (int i = 0; i < 3; i += 1) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  if (arr[0] == arr[1]) {
    answer = arr[2];
  } else {
    answer = arr[0];
  }

  cout << "#" << test_case << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}