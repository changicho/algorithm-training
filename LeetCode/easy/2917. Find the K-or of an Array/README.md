# 2917. Find the K-or of an Array

[링크](https://leetcode.com/problems/find-the-k-or-of-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 nums의 배열의 크기를 N이라 하자.

총 32개의 비트의 수를 세면 되며 이는 상수이므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 배열등을 사용할 필요가 없으므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

각 비트별로 숫자에 포함된 갯수를 센다. 이 갯수가 k개 이상인 경우 정답에 더한다.

```cpp
int findKOr(vector<int>& nums, int k) {
  int answer = 0;

  for (int i = 0; i < 31; i++) {
    int digit = 1 << i;
    int count = 0;
    for (int& num : nums) {
      count += (num & digit) > 0;
    }

    if (count >= k) {
      answer += digit;
    }
  }
  return answer;
}
```

## 고생한 점
