# 880. Decoded String at Index

[링크](https://leetcode.com/problems/decoded-string-at-index/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N (N <= 100) 입력받은 수를 K라 하자.

시뮬레이션을 직접 수행할 경우 최악의 경우 9^99의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

최종적으로 생성되는 문자열의 길이를 미리 구한 뒤, 문자열을 역순으로 순회하며 K번째 문자열을 찾는다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

직접 문자열을 생성하지 않고 index를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

s를 순회하며 최종 문자열의 길이를 미리 구할 수 있다.

왼쪽부터 순회하며 숫자가 나오면 해당 숫자만큼 길이를 곱하고, 문자가 나오면 길이를 1 증가시킨다.

이를 반대로 말하면 오른쪽 부터 순회하면 길이를 감소시키는 과정을 진행할 수 있다.

따라서 미리 최종 변환 문자열의 길이를 구하고 역순으로 순회하며 K번째 문자열을 찾는다.

이 때 K를 감소시키며 0이 되는 순간의 문자를 반환한다. 매 경우마다 K를 현재 변환된 문자열의 길이로 나눈 나머지로 갱신한다.

```cpp
string decodeAtIndex(string s, int k) {
  long length = 0;
  int size = s.size();

  for (char &c : s) {
    if (isdigit(c)) {
      length *= c - '0';
    } else {
      length++;
    }
  }

  for (int i = size - 1; i >= 0; --i) {
    char c = s[i];
    k %= length;
    if (k == 0 && isalpha(c)) return (string) "" + c;

    if (isdigit(c)) {
      length /= c - '0';
    } else {
      length--;
    }
  }
  return "";
}
```

## 고생한 점
