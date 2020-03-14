#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct counts {
  long long zero, one;
};

counts fibo[41];

counts fibonacci(int n) {
  if (n == 0) {
    return fibo[0];
  } else if (n == 1) {
    return fibo[1];
  } else {
    if (fibo[n].zero != 0 && fibo[n].one != 0) {
      return fibo[n];
    }

    counts first = fibonacci(n - 1);
    counts second = fibonacci(n - 2);

    fibo[n].one = first.one + second.one;
    fibo[n].zero = first.zero + second.zero;

    return fibo[n];
  }
}

void solution() {
  int N;

  cin >> N;
  cout << fibo[N].zero << " " << fibo[N].one << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  fibo[0] = {1, 0};
  fibo[1] = {0, 1};

  fibonacci(40);

  for (int testCase = 0; testCase < T; testCase++) {
    solution();
  }

  return 0;
}