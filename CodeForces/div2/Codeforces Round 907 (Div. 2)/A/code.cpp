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

bool solution(vector<int> &nums) {
  int size = nums.size();
  int windowSize = 1;

  for (int i = 0; i < size - 1; i++) {
    if (i == windowSize - 1) {
      windowSize *= 2;
      continue;
    }
    if (nums[i] > nums[i + 1]) return false;
  }
  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);
  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    bool answer = solution(A);

    cout << (answer ? "YES" : "NO") << endl;
  }

  return 0;
}