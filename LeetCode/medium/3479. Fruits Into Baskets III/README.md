# 3479. Fruits Into Baskets III

[링크](https://leetcode.com/problems/fruits-into-baskets-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열 fruits와 baskets의 크기를 N이라 하자.

루트 분해를 사용할 경우 O(N \* sqrt(N))의 시간 복잡도를 갖는다.

### 공간 복잡도

루트 분해에 O(sqrt(N))의 공간 복잡도를 사용한다.

### 루트 분해

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     457      | O(N * sqrt(N)) | O(sqrt(N))  |

```cpp
int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
  int size = baskets.size();
  int sizeSqrt = sqrt(size);
  int sections = (size + sizeSqrt - 1) / sizeSqrt;
  vector<int> maxV(sections);

  for (int i = 0; i < size; i++) {
    maxV[i / sizeSqrt] = max(maxV[i / sizeSqrt], baskets[i]);
  }

  int answer = 0;
  for (int& fruit : fruits) {
    int unset = 1;
    for (int sI = 0; sI < sections; sI++) {
      if (maxV[sI] < fruit) {
        continue;
      }
      bool isChosen = 0;
      maxV[sI] = 0;

      for (int i = 0; i < sizeSqrt; i++) {
        int pos = sI * sizeSqrt + i;
        if (pos < size && baskets[pos] >= fruit && !isChosen) {
          baskets[pos] = 0;
          isChosen = 1;
        }
        if (pos < size) {
          maxV[sI] = max(maxV[sI], baskets[pos]);
        }
      }
      unset = 0;
      break;
    }
    answer += unset;
  }
  return answer;
}
```

## 고생한 점
