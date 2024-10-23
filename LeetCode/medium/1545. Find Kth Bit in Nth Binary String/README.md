# 1545. Find Kth Bit in Nth Binary String

[링크](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수를 N, K라 하자.

직접 시뮬레이션을 사용할 경우 O(N \* K)의 시간 복잡도를 사용한다.

분할 정복을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

직접 시뮬레이션을 수행하는 데 O(K)의 공간 복잡도가 필요하다.

분할 정복을 사용할 경우 재귀 호출을 수행하는데 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |  O(N \* K)  |    O(K)     |

매 과정을 직접 시뮬레이션을 수행한다.

이 때 K 이후의 문자열은 필요가 없으므로 최대 길이가 K까지인 문자열을 생성한다.

```cpp
string convert(string &cur, int leftSize) {
  int size = cur.size();
  string ret = "";
  for (int i = size - 1; i >= 0; i--) {
    ret += cur[i] == '1' ? '0' : '1';
    if (ret.size() == leftSize) break;
  }
  return ret;
}

string getNext(string &cur, int k) {
  if (cur.size() > k) {
    return cur;
  }

  string ret = "1";
  int leftSize = k - ret.size();

  return ret + convert(cur, leftSize);
}

char findKthBit(int n, int k) {
  char ret = '0';

  string cur = "0";

  for (int i = 0; i < n; i++) {
    cur += getNext(cur, k);
  }
  return cur[k - 1];
}
```

### 분할 정복

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

2^N - 1 길이부터 탐색을 시작하며 K번째 문자를 생성하는 최초의 문자를 찾는다.

이 때 문자열의 구조는 A + 1 + A' 구조이므로 K가 A의 길이보다 크다면 K번째 문자를 만드는 것은 A에 존재하며 이는 뒤집힌 값이다.

반대로 K가 A의 길이보다 작다면 이 또한 A에 존재하며 이는 그대로의 값이다.

이를 반복하며 K번째 문자를 찾는다.

```cpp
char findKthBit(int n, int k) {
  bool isInverted = false;
  int length = (1 << n) - 1;

  while (k > 1) {
    if (k == length / 2 + 1) {
      return isInverted ? '0' : '1';
    }

    if (k > length / 2) {
      k = length + 1 - k;
      isInverted = !isInverted;
    }

    length /= 2;
  }
  return isInverted ? '1' : '0';
}
```

## 고생한 점
