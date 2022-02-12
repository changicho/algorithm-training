#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector<long long> factorials(5001, 0);

long long solution(int n, vector<int> hate) {
  unordered_map<int, int> hateCount;
  for (int &target : hate) {
    // ignore useless case
    if (target > n) continue;
    hateCount[target]++;
  }

  // edge case
  if (hateCount.size() == 0) return factorials[n];

  vector<long long> uniqueHate;
  for (auto &it : hateCount) {
    uniqueHate.push_back(it.second);
  }

  // nC1, nC2, ... , nCn
  vector<long long> pascalTriangle = {1};
  for (long long count : uniqueHate) {
    vector<long long> currentLine;

    long long prev = 0;
    for (long long number : pascalTriangle) {
      // fill weight of current nCr
      long long cur = (prev * count) % MOD;

      cur += number;
      cur %= MOD;

      currentLine.push_back(cur);
      prev = number;
    }

    currentLine.push_back((prev * count) % MOD);

    pascalTriangle = currentLine;
  }

  long long answer = 0;
  for (int i = 0; i < pascalTriangle.size(); i++) {
    long long cur = pascalTriangle[i];
    cur *= factorials[n - i];
    cur %= MOD;

    if (i % 2 == 0) {
      answer += cur;
    } else {
      answer -= cur;
    }
  }

  answer %= MOD;
  if (answer < 0) answer += MOD;

  return answer;
}

// initialize

void fillFactorial() {
  factorials[0] = 1;
  factorials[1] = 1;
  for (int num = 2; num <= 5000; num++) {
    factorials[num] = (factorials[num - 1] * num) % MOD;
  }
}

void runCurrentTest(int testNumber) {
  int N;
  cin >> N;

  vector<int> hates(N);
  for (int i = 0; i < N; i++) {
    cin >> hates[i];
  }

  long long answer = solution(N, hates);

  cout << "#" << testNumber << " " << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fillFactorial();

  int T;
  cin >> T;

  for (int testNumber = 1; testNumber <= T; testNumber++) {
    runCurrentTest(testNumber);
  }

  return 0;
}