#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int DIV = 1234567;
int memo[100001];

int fibo(int n) {
  if (n < 1) {
    return 0;
  }
  if (n == 1) {
    return n;
  }

  if (memo[n] != 0) {
    return memo[n];
  }

  return memo[n] = (fibo(n - 1) + fibo(n - 2)) % DIV;
}

int solution(int n) {
  int answer = fibo(n);

  return answer;
}

struct TestCase {
  int n;
  int result;
};

int main() {
  vector<TestCase> testCases = {{3, 2}, {5, 5}};

  for (TestCase testCase : testCases) {
    int myAnswer = solution(testCase.n);

    cout << "answer : " << testCase.result << ", myAnswer : " << myAnswer << "\n";
  }
}