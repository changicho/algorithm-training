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

bool isPrime[1000001] = {
    false,
};
vector<int> primes;

void factorization(int num, unordered_map<int, int> &counts) {
  for (int &prime : primes) {
    if (num == 1) return;
    if (isPrime[num]) {
      counts[num]++;
      return;
    }

    while (num % prime == 0) {
      counts[prime]++;
      num /= prime;
    }
  }
}

bool solution(vector<int> &arr) {
  int size = arr.size();

  unordered_map<int, int> counts;
  for (int &num : arr) {
    factorization(num, counts);
  }

  for (auto &it : counts) {
    int count = it.second;

    if (count % size != 0) return false;
  }

  return true;
}

void init() {
  for (int i = 2; i <= 1000000; i++) {
    isPrime[i] = true;
  }

  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i]) {
      primes.push_back(i);

      for (int j = i * 2; j <= 1000000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);
  init();

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    bool answer = solution(arr);

    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}