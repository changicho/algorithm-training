#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool checkSorted(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] > nums[i + 1]) {
      return false;
    }
  }
  return true;
}

bool solution(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size - 1; i++) {
    swap(nums[i], nums[i + 1]);

    bool isSorted = checkSorted(nums);

    if (isSorted) {
      return true;
    }

    swap(nums[i], nums[i + 1]);
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<int> A(5);
  for (int i = 0; i < 5; i++) {
    cin >> A[i];
  }

  bool answer = solution(A);

  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}