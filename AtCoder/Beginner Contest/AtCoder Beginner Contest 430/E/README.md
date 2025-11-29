# E - Shift String

[링크](https://atcoder.jp/contests/abc430/tasks/abc430_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

모든 경우를 직접 확인할 경우 O(N^2)의 시간 복잡도를 가지게 된다. 이는 제한시간 내에 불가능하다.

KMP 알고리즘을 사용할 경우 O(N)의 시간 복잡도로 문제를 해결할 수 있다.

### 공간 복잡도

KMP알고리즘에 O(N)의 공간 복잡도를 사용한다.

### KMP 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      21      |    O(N)     |    O(N)     |

문자열 A를 회전하며 B로 만들 수 있는지 판별해야 한다.

A를 복제한 문자열 A`를 만들고, 여기에 B가 존재하는지 확인하면 된다.

이를 KMP 알고리즘을 사용해 빠르게 찾는다.

```cpp
int kmp(string& line, string& pattern) {
  int size = line.size(), pSize = pattern.size();
  vector<int> pIndexes(pSize, 0);

  for (int i = 1, pI = 0; i < pSize; i++) {
    while (pI > 0 && pattern[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }
    if (pattern[i] == pattern[pI]) {
      pI++;
      pIndexes[i] = pI;
    }
  }

  for (int i = 0, pI = 0; i < size; i++) {
    while (pI > 0 && line[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }

    if (line[i] == pattern[pI]) {
      if (pI == pSize - 1) {
        return i - pSize + 1;

        pI = pIndexes[pI];
      } else {
        pI++;
      }
    }
  }

  return -1;
}

auto solution(string& a, string& b) {
  a += a;

  int answer = kmp(a, b);

  return answer;
}
```

## 고생한 점
