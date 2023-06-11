# 1502. Can Make Arithmetic Progression From Sequence

[링크](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

주어진 배열 arr의 크기를 N이라 하자.

원소들을 정렬 후 순회하며 차이를 구할 경우 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

정렬에 따라 필요한 공간 복잡도에 차이가 존재한다.

퀵정렬을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬 & 비교

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(1)     |

원소들을 정렬한 뒤, 연속된 두 값의 차이가 모두 같은지 비교한다.

```cpp
bool canMakeArithmeticProgression(vector<int>& arr) {
  sort(arr.begin(), arr.end());
  int diff = arr[1] - arr[0];
  for (int i = 1; i < arr.size(); i++) {
    int curDiff = arr[i] - arr[i - 1];

    if (curDiff != diff) return false;
  }
  return true;
}
```

## 고생한 점
