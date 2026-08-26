# 3718. Smallest Missing Multiple of K

[링크](https://leetcode.com/problems/smallest-missing-multiple-of-k/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

각 값의 여부를 배열에 저장하는데 O(N + M)의 시간 복잡도를 사용한다.

이후 직접 탐색을 수행할 경우 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수의 여부를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(M)     |

각 수의 여부를 배열에 표시 후 가장 작은 값부터 순회하며 정답을 찾는다.

```cpp
int missingMultiple(vector<int>& nums, int k) {
  bool b[101] = {
      false,
  };
  for (int& num : nums) {
    b[num] = true;
  }

  int i = k;
  while (i <= 100) {
    if (b[i] == false) return i;
    i += k;
  }
  return i;
}
```

## 고생한 점
