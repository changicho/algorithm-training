# 3746. Minimum String Length After Balanced Removals

[링크](https://leetcode.com/problems/minimum-string-length-after-balanced-removals/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

문자열에서 a, b의 길이를 세는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자의 수를 세는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

a 와 b의 갯수가 같은 가장 긴 문자열을 만들기 위해 제거해야 하는 문자의 수는 abs(a의 갯수 - b의 갯수) 와 같다.

즉 둘 중 갯수가 적은 쪽에 맞춰 제거하면 된다.

```cpp
int minLengthAfterRemovals(string s) {
  int aCount = 0;
  for (char& c : s) {
    if (c == 'a') aCount++;
  }
  int bCount = s.size() - aCount;

  return abs(aCount - bCount);
}
```

## 고생한 점
