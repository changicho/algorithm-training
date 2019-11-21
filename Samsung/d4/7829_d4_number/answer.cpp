#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int test_case) {
  int size;
  cin >> size;

  vector<int> arr;

  for (int i = 0; i < size; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  int max_child, min_child;
  max_child = arr[0];
  min_child = arr[0];

  for (int i : arr) {
    max_child = max(max_child, i);
    min_child = min(min_child, i);
  }

  cout << "#" << test_case << " " << (max_child * min_child) << "\n";
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