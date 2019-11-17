#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0이면 소수, 1이면 소수가 아님
bool primes[1000001];

bool hasD(string number, int D) {
  for (char c : number) {
    if (c - '0' == D) {
      return true;
    }
  }
  return false;
}

void solution(int test_case) {
  int D, A, B, count = 0;

  cin >> D >> A >> B;

  for (int i = A; i <= B; i++) {
    if (!primes[i] && hasD(to_string(i), D)) {
      count++;
    }
  }
  cout << "#" << test_case << " " << count << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 처음 소수 테이블을 만듬
  primes[0] = 1;
  primes[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (!primes[i]) {
      for (int j = 2 * i; j <= 1000000; j += i) {
        primes[j] = 1;
      }
    }
  }

  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; test_case++) {
    solution(test_case);
  }

  return 0;
}