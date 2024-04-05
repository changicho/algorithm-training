# D - Popcount and XOR

[링크](https://atcoder.jp/contests/abc347/tasks/abc347_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 수를 A, B, C라 하자.

정답인 X, Y쌍을 구하기 위해 앞에 붙는 1의 갯수와 중간에 0을 만들기 위한 같은 1의 갯수에 대해 탐색을 진행한다.

이는 각각 0 ~ 60 까지 가능하므로 각 경우를 모두 순회했을 때 O(60^2)의 시간 복잡도를 사용하며 이는 O(1)이다.

이후 각 경우마다 가능한 X, Y를 구하기 위해 순회와 그리디 알고리즘을 사용한다.

이 경우 O(A + B)의 시간 복잡도를 사용하며 이는 O(60)이다.

따라서 총 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 문자열로 비트를 처리할 경우 최대 60자리의 문자열이 필요하다.

따라서 O(1)의 공간 복잡도를 사용한다.

정답 X, Y의 경우 2^60까지 표현해야 하므로 unsigned long long형으로 선언한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

정답으로 가능한 X, Y에 포함되는 비트수 A, B는 다음과 같이 이루어진다.

- 자리수를 맞추기 위한 맨 앞부터의 1의 갯수 (공통)
- 중간에 XOR연산으로 0을 만들기 위한 1의 갯수 (공통)
- C의 중간 비트 1을 만들기 위한 비트

따라서 X, Y의 공통으로 사용되는 두 가지 비트값에 대해 순회하며 각 경우마다 정답을 생성할 수 있는지 판단한다.

만약 현재 남은 비트수로 정답을 생성할 수 있는경우 정답을 생성한다.

이 때 X, Y에서 겹쳐야 하는 비트와 겹치면 안되는 비트를 구분해야 한다.

```cpp
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
```

## 고생한 점
