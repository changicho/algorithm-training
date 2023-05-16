#include <algorithm>
#include <climits>
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

string convert(long long k) {
  string ret = "";

  while (k > 0) {
    ret += to_string(k % 9);
    k /= 9;
  }

  reverse(ret.begin(), ret.end());

  return ret;
}

auto solution(long long k) {
  string converted = convert(k);

  int size = converted.size();
  for (int i = 0; i < size; i++) {
    if (converted[i] >= '4') {
      converted[i] = converted[i] + 1;
    }
  }

  return converted;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    long long K;
    cin >> K;

    auto answer = solution(K);

    cout << answer << "\n";
  }

  return 0;
}