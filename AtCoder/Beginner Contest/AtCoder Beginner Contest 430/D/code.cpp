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

auto solution(int size, vector<long long> nums) {
  vector<long long> answer;

  map<long long, long long> prevs;
  map<long long, long long> nexts;

  long long sum = 0;

  prevs[0] = INT_MIN;
  prevs[nums[0]] = 0;
  nexts[0] = nums[0];
  nexts[nums[0]] = INT_MAX;

  answer.push_back(nums[0] * 2);
  sum += nums[0] * 2;

  for (int i = 1; i < size; i++) {
    long long num = nums[i];

    auto it = prevs.lower_bound(num);

    if (it == prevs.end()) {
      long long last = prevs.rbegin()->first;

      nexts[last] = num;
      prevs[num] = last;
      nexts[num] = INT_MAX;

      sum += (num - last);

      if (last - prevs[last] > (num - last)) {
        sum -= (last - prevs[last]);
        sum += (num - last);
      }
    } else {
      long long next = it->first;
      long long prev = it->second;

      long long prevCost = min(nexts[prev] - prev, prev - prevs[prev]);
      long long nextCost = min(nexts[next] - next, next - prevs[next]);

      long long newPrevCost = (num - prev);
      long long newNextCost = (next - num);

      if (prevCost > newPrevCost) {
        sum -= prevCost;
        sum += newPrevCost;
      }

      if (nextCost > newNextCost) {
        sum -= nextCost;
        sum += newNextCost;
      }

      sum += min(newPrevCost, newNextCost);

      prevs[num] = prev;
      nexts[prev] = num;
      nexts[num] = next;
      prevs[next] = num;
    }

    answer.push_back(sum);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }

  auto answer = solution(N, X);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}