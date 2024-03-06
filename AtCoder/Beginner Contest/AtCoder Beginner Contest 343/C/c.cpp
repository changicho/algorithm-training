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

bool isPalindrome(unsigned long long num) {
  string s = to_string(num);
  int len = s.length();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - i - 1]) {
      return false;
    }
  }
  return true;
}

unsigned long long solution(unsigned long long &num) {
  unsigned long long answer = 0;

  long long limit = sqrt(num);
  for (unsigned long long i = 0; i <= limit; i++) {
    unsigned long long temp = i * i * i;

    if (temp > num) {
      break;
    }

    if (isPalindrome(temp)) {
      answer = max(answer, temp);
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

  unsigned long long N;
  cin >> N;

  unsigned long long answer = solution(N);

  cout << answer << endl;

  return 0;
}