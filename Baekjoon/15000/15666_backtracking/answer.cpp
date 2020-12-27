#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

void recursive(vector<int> numbers, int index) {
  if (numbers.size() == M) {
    for (int number : numbers) {
      cout << number << " ";
    }
    cout << "\n";

    return;
  }

  numbers.push_back(-1);

  int size = numbers.size();
  int before = size > 1 ? numbers[size - 2] : -1;

  for (int i = index; i < arr.size(); i++) {
    int number = arr[i];

    numbers[size - 1] = number;
    recursive(numbers, i);
  }
}

void solution() {
  cin >> N >> M;
  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());

  recursive({}, 0);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}