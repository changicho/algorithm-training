# 4011. Count Subarrays With Even Odd Ratio I

[링크](https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 sub array의 짝,홀수의 갯수를 세는데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      45      |   O(N^2)    |    O(1)     |

완전 탐색을 수행하며 각 경우마다 odd, even의 갯수를 센다.

이 때 `even / odd <= a / b`을 구할 때 오차가 생길 수 있으므로 곱 연산으로 변경해 판단한다.

```cpp
int countRatioSubarrays(vector<int>& nums, int a, int b) {
  int size = nums.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int odd = 0, even = 0;

    for (int j = i; j < size; j++) {
      if (nums[j] % 2 == 0) {
        even++;
      } else {
        odd++;
      }

      if (even * b <= a * odd) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
