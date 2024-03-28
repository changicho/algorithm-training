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

vector<int> solution(vector<int> &arr) {
  int size = arr.size();

  vector<int> ret;
  for (int i = 0; i < size - 1; i++) {
    ret.push_back(arr[i] * arr[i + 1]);
  }
  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> answer = solution(A);

  for (int &a : answer) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}