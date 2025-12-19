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

vector<long long> solution(int n, vector<int>& nums) {
  sort(nums.begin(), nums.end());

  vector<int> odds;
  vector<int> evens;
  for (int& num : nums) {
    if (num % 2 == 0) {
      evens.push_back(num);
    } else {
      odds.push_back(num);
    }
  }

  if (odds.size() == 0) {
    return vector<long long>(n, 0);
  }

  vector<long long> evenUseMaxs(n + 1);
  evenUseMaxs[0] = 0;

  for (int i = 1; i <= evens.size(); i++) {
    evenUseMaxs[i] = evenUseMaxs[i - 1] + evens[evens.size() - i];
  }

  vector<long long> answer(n);
  int oddUsed = 1;
  int evenUsed = 0;
  answer[0] = odds.back();
  for (int i = 1; i < n; i++) {
    if (evenUsed < evens.size()) {
      evenUsed++;
    } else {
      if (oddUsed + 2 <= odds.size() && evenUsed > 0) {
        oddUsed += 2;
        evenUsed--;
      } else {
        oddUsed++;
      }
    }

    if (oddUsed % 2 == 1) {
      answer[i] = odds.back() + evenUseMaxs[evenUsed];
    } else {
      answer[i] = 0;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    auto answer = solution(N, A);

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    for (auto& line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}