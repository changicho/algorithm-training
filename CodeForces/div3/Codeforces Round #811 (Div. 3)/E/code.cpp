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

// time : 40min
bool solution(int n, vector<int> &arr) {
  if (n == 1) return true;

  sort(arr.begin(), arr.end());
  vector<int> zeros;
  vector<int> fives;
  vector<int> twos;

  for (int &n : arr) {
    if (n % 10 == 0) {
      zeros.push_back(n);
    } else if (n % 10 == 5) {
      fives.push_back(n);
    } else {
      twos.push_back(n);
    }
  }

  if (!zeros.empty() || !fives.empty()) {
    if (!twos.empty()) return false;

    set<int> nums;
    for (int &zero : zeros) {
      nums.insert(zero);
    }
    for (int &five : fives) {
      nums.insert(five + 5);
    }

    return nums.size() == 1;
  }

  set<int> group;
  for (int &two : twos) {
    int key = (two / 10) % 2;

    if (two % 10 == 7 || two % 10 == 9 || two % 10 == 6 || two % 10 == 3) {
      key++;
      key %= 2;
    }
    group.insert(key);
  }

  if (group.size() == 2) return false;

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

    bool answer = solution(N, A);
    cout << (answer ? "Yes" : "No") << "\n";
  }

  return 0;
}