# 1752. Check if Array Is Sorted and Rotated

[링크](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 직접 탐색할 경우 시간 복잡도는 O(N^2)이다.

배열의 정렬 순서가 뒤집힌 수를 순회로 판단하는데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

직접 탐색하는데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열은 특정 index부터 오름차순으로 유지되어야 한다.

따라서 정렬 순서가 어긋나는 경우는 1번 이하만 발생해야 한다.

```cpp
bool check(vector<int>& nums) {
  int size = nums.size();
  int inverted = 0;

  for (int i = 0; i < size; i++) {
    int nI = (i + 1) % size;

    if (nums[nI] < nums[i]) inverted++;
  }

  return inverted <= 1;
}
```

## 고생한 점
