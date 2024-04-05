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

typedef unsigned long long ULL;

using namespace std;

string convert(ULL num) {
  string result = "";
  while (num > 0) {
    result += '0' + (num % 2);
    num /= 2;
  }
  reverse(result.begin(), result.end());
  return result;
}

int count(string &bit) {
  int cnt = 0;
  for (int i = 0; i < bit.size(); i++) {
    if (bit[i] == '1') {
      cnt++;
    }
  }
  return cnt;
}

ULL convertToNum(string &bit) {
  ULL result = 0;
  for (int i = 0; i < bit.size(); i++) {
    result = result * 2 + (bit[i] - '0');
  }
  return result;
}

pair<ULL, ULL> solution(int a, int b, ULL c) {
  string result = convert(c);
  int length = result.size();

  int needToFill = count(result);
  int remainZeros = length - needToFill;

  for (int readingOne = 0; readingOne <= min(a, b); readingOne++) {
    for (int innerZero = 0; innerZero <= remainZeros; innerZero++) {
      int aLeft = a - readingOne - innerZero;
      int bLeft = b - readingOne - innerZero;

      if (aLeft < 0 || bLeft < 0) continue;
      if (aLeft + bLeft != needToFill) continue;

      if (length + readingOne > 60) continue;

      string aBit = string(length + readingOne, '0');
      string bBit = string(length + readingOne, '0');

      for (int i = 0; i < readingOne; i++) {
        aBit[i] = '1';
        bBit[i] = '1';
      }

      for (int i = readingOne, usedZero = 0; i < length + readingOne; i++) {
        char cur = result[i - readingOne];

        if (cur == '1') {
          // 1 case
          if (aLeft > 0) {
            aBit[i] = '1';
            aLeft--;
          } else {
            bBit[i] = '1';
            bLeft--;
          }
        } else {
          // 0 case
          if (usedZero < innerZero) {
            aBit[i] = '1';
            bBit[i] = '1';
            usedZero++;
          } else {
            aBit[i] = '0';
            bBit[i] = '0';
          }
        }
      }

      ULL x = convertToNum(aBit);
      ULL y = convertToNum(bBit);
      if ((x ^ y) != c) continue;

      return {x, y};
    }
  }

  return {-1, -1};
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int A, B;
  ULL C;

  cin >> A >> B >> C;

  pair<ULL, ULL> answer = solution(A, B, C);

  if (answer.first == -1) {
    cout << "-1" << endl;
  } else {
    cout << answer.first << " " << answer.second << endl;
  }

  return 0;
}