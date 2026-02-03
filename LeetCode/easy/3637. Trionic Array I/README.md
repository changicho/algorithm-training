# 3637. Trionic Array I

[링크](https://leetcode.com/problems/trionic-array-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 이용할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

왼쪽부터 순회하며 증가 구간과 감소 구간의 개수를 센다.

이후 시작하는 구간이 증가 구간이며, 증가 구간이 2개, 감소 구간이 1개일 경우에만 true를 반환한다.

```cpp
bool isTrionic(vector<int>& nums) {
  int size = nums.size();
  int desc = 0;
  int inc = 0;

  bool isInc = false;
  for (int i = 1; i < size; i++) {
    if (nums[i - 1] < nums[i]) {
      if (!isInc) {
        inc++;
        isInc = true;
      }
    } else if (nums[i - 1] > nums[i]) {
      if (isInc) {
        desc++;
        isInc = false;
      }
      if (inc == 0) return false;
    } else {
      return false;
    }
  }

  if (inc == 2 && desc == 1) return true;
  return false;
}
```

## 고생한 점
