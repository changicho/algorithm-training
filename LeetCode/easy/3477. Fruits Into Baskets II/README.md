# 3477. Fruits Into Baskets II

[링크](https://leetcode.com/problems/fruits-into-baskets-ii/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 fruits, baskets의 크기를 N이라 하자.

직접 모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도가 필요하다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(1)     |

각 과일마다 적절한 바구니를 매번 탐색한다.

```cpp
int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
  int size = fruits.size();

  int answer = size;

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (fruits[i] <= baskets[j]) {
        answer--;
        baskets[j] = 0;
        break;
      }
    }
  }

  return answer;
}
```

## 고생한 점
