# 384. Shuffle an Array

[링크](https://leetcode.com/problems/shuffle-an-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 숫자의 개수를 N이라 하자.

shuffle을 수행할 때 배열을 무작위로 섞어야 한다.

이 shuffle연산을 위해 피셔 예이츠 셔플을 사용한다.

이 경우 시간 복잡도는 O(N)이다.

그 외에 reset연산을 수행할 때 기존 값을 미리 저장하는 경우 O(N)의 시간 복잡도만 사용해 구현할 수 있다.

### 공간 복잡도

원본 배열과 셔플 배열을 저장해야 한다.

이는 O(N)의 공간 복잡도를 사용한다.

### 피셔 예이츠 셔플 (Fisher-Yates Shuffle)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     104      |    O(N)     |    O(N)     |

피셔 예이츠 셔플은 배열 순서를 무작위로 섞는 방법이다.

배열이 가진 요소를 무작위로 하나씩 이동하면서 새로운 순서를 정의한다.

1. 1 ~ N 번째 값 중에 임의의 값을 취한 후 1번째 값과 교환 한다.
2. 2 ~ N 번째 값 중에 임의의 값을 취한 후 2번째 값과 교환 한다.
3. 이런 식으로 계속 진행하면 n까지의 모든 수를 shuffle할 수 한다.

이를 이용해 shuffle을 구현한다.

```cpp
class Solution {
  vector<int> array;

 public:
  Solution(vector<int> nums) { this->array = nums; }

  vector<int> reset() { return array; }

  vector<int> shuffle() {
    int size = array.size();
    vector<int> result(array);

    for (int i = 0; i < size; i++) {
      int pos = rand() % (size - i);
      swap(result[i + pos], result[i]);
    }
    return result;
  }
};
```

## 고생한 점
