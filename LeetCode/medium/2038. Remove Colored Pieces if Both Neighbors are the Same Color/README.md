# 2038. Remove Colored Pieces if Both Neighbors are the Same Color

[링크](https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 colors의 길이를 N이라 하자.

각 문자열을 순회하며 연속된 A, B의 갯수들을 각각 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자의 갯수를 세는데 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |    O(N)     |    O(1)     |

Alice, Bob이 A, B를 각각 지울 때 어떤 방법을 사용하던 최종적으로 지울 수 있는 갯수는 같다.

이는 3개 이상 연속된 문자열에서 최종적으로 2개의 문자열만 남기고 지울 수 있으며, 이 경우 문자를 지운 후 새로운 연속된 문자열이 생성되지 않기 때문이다.

따라서 각각 연속된 문자열의 수를 세고 이를 이용해 정답을 구한다.

```cpp
bool winnerOfGame(string colors) {
  int aCount = 0, bCount = 0;
  int aRemove = 0, bRemove = 0;

  for (char &c : colors) {
    if (c == 'A') {
      bRemove += max(bCount - 2, 0);
      bCount = 0;
      aCount++;
    } else {
      aRemove += max(aCount - 2, 0);
      aCount = 0;
      bCount++;
    }
  }
  aRemove += max(aCount - 2, 0);
  bRemove += max(bCount - 2, 0);

  if (aRemove > bRemove) return true;
  return false;
}
```

## 고생한 점
