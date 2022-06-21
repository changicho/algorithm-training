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

int solution(vector<int> &nums) {
  int size = nums.size();

  int length = size;
  int dupCount = 0;
  unordered_map<int, int> counts;
  for (int &n : nums) {
    counts[n]++;
  }

  for (auto it : counts) {
    int val = it.second;
    dupCount += val - 1;
  }

  if (dupCount % 2 == 0) {
    length -= dupCount;
  } else {
    length -= dupCount + 1;
  }

  return length;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> array(N);

    for (int i = 0; i < N; i++) {
      cin >> array[i];
    }

    int ret = solution(array);

    cout << ret;
    cout << "\n";
  }

  return 0;
}