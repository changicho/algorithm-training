# 1007. Minimum Domino Rotations For Equal Row

[링크](https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 tops, bottoms의 크기를 N이라 하자.

각 경우마다 도달 가능한지 모두 판단하는데 1~6까지 6가지 경우의 수를 확인한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

통일할 숫자를 1부터 6까지 모두 확인한다.

이 때 top에 맞추는 경우와 bottom에 맞추는 경우를 모두 확인한다.

불가능한 경우 탐색을 중지함에 유의한다.

```cpp
int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
  int size = tops.size();

  int answer = INT_MAX;
  for (int target = 1; target <= 6; target++) {
    int swapTop = 0;
    int swapBottom = 0;

    bool isPossible = true;
    for (int i = 0; i < size; i++) {
      if (tops[i] != target && bottoms[i] == target) {
        swapBottom++;
      }
      if (tops[i] == target && bottoms[i] != target) {
        swapTop++;
      }

      if (tops[i] != target && bottoms[i] != target) {
        isPossible = false;
        break;
      }
    }

    if (!isPossible) continue;

    answer = min({answer, swapTop, swapBottom});
  }

  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
