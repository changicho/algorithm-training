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

long long solution(vector<int> &nums) {
  const int PRIME_SIZE = 500;
  bool isNotPrime[PRIME_SIZE] = {false};

  for (int i = 2; i < PRIME_SIZE; i++) {
    if (isNotPrime[i]) continue;
    for (int j = i * 2; j < PRIME_SIZE; j += i) {
      isNotPrime[j] = true;
    }
  }

  vector<int> primes;
  for (int i = 2; i < PRIME_SIZE; i++) {
    if (!isNotPrime[i]) {
      primes.push_back(i);
    }
  }

  long long answer = 0;
  unordered_map<int, int> counts;

  int zeroCount = 0;

  for (int &num : nums) {
    if (num == 0) {
      answer += (nums.size() - 1 - zeroCount);

      zeroCount++;
      continue;
    }

    // trim num;
    unordered_map<int, int> factors;
    for (int &prime : primes) {
      if (prime > num) break;
      while (num % prime == 0) {
        factors[prime]++;
        num /= prime;
      }
    }

    int converted = num;
    for (auto &factor : factors) {
      if (factor.second % 2 == 0) {
        continue;
      }
      converted *= factor.first;
    }

    if (converted == 1) {
      converted = 0;
    }

    answer += counts[converted];
    counts[converted]++;
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
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long answer = solution(A);

  cout << answer << "\n";

  return 0;
}