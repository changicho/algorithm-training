#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;

  vector<int> arr;
  vector<int> arr_x;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
    arr_x.push_back(temp);
  }

  sort(arr_x.begin(), arr_x.end());
  arr_x.erase(unique(arr_x.begin(), arr_x.end()), arr_x.end());

  for (int n : arr) {
    cout << lower_bound(arr_x.begin(), arr_x.end(), n) - arr_x.begin() << " ";
  }

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}