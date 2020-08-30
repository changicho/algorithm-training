#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }

  int temp;

  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

long long solution(int w, int h) {
  long long answer = 1;
  long long total = (long long)w * (long long)h;

  int div = gcd(w, h);

  double w_d = w / (long long)div;
  double h_d = h / (long long)div;

  double rate = (double)h_d / (double)w_d;
  double before = 0;
  int count = 0;

  for (int i = 1; i <= w_d; i++) {
    double height = rate * (double)i;

    count += ceil(height) - floor(before);
    before = height;
  }

  answer = total - count * div;

  return answer;
}

struct TestCase {
  int W, H;
  long long result;
};

int main() {
  vector<TestCase> testCases = {
      {8, 12, 80},
      {1, 100, 0},
      {5, 5, 20}};

  for (TestCase testCase : testCases) {
    auto answer = solution(testCase.W, testCase.H);

    cout << "answer : " << testCase.result << ", myAnswer : " << answer << "\n";
  }

  return 0;
}