# 2337. Move Pieces to Obtain a String

[링크](https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 문자열 start, target의 길이를 각각 N, M이라 하자.

투 포인터를 사용할 경우 O(N + M)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

투 포인터를 사용해 비교할 경우 O(1)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(1)     |

start와 target의 두 index를 이용해 탐색하며 비교한다.

이 때 현재 start의 문자가 target의 문자와 다를 경우 아무리 이동해도 불가능하다.

그 외에 문자가 같아도 이동이 불가능한 경우 false를 반환한다.

```cpp
bool canChange(string start, string target) {
  int size = start.size();

  int sI = 0, tI = 0;
  while (tI < size && target[tI] == '_') {
    tI++;
  }
  for (; sI < size; sI++) {
    if (start[sI] == '_') continue;

    if (start[sI] != target[tI]) return false;
    if (start[sI] == 'L' && sI < tI) return false;
    if (start[sI] == 'R' && sI > tI) return false;

    tI++;
    while (tI < size && target[tI] == '_') {
      tI++;
    }
  }

  if (tI < size || sI < size) return false;
  return true;
}
```

## 고생한 점
