#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(int num) {
  // do something
  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int A;
  vector<int> arr;
  while (cin >> A) {
    arr.push_back(A);
  }

  reverse(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << '\n';
  }

  return 0;
}