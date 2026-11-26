# 3411. Maximum Subarray With Equal Products

[링크](https://leetcode.com/problems/maximum-subarray-with-equal-products/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

완전 탐색을 통해 O(N^2)의 시간 복잡도로 풀이 가능하다.

각 과정마다 gcd, lcm을 구하는 데 O(log_2(M))의 시간 복잡도를 사용한다.

따라서 O(N^2 \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      2       | O(N^2 \* log_2(M)) |    O(1)     |

현재 i부터 시작하는 가능한 모든 subArray에 대해 gcd, lcm을 구해 정답을 만족하는지 판단한다.

이 때 값의 product가 gcd, lcm의 곱보다 커지는 경우는 이후 탐색에 정답이 없으므로 탐색을 중지한다.

```cpp
int maxLength(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;
  for (int i = 0; i < size; i++) {
    long long p = nums[i];
    long long g = nums[i];
    long long l = nums[i];

    for (int j = i + 1; j < size; j++) {
      p = p * nums[j];
      g = gcd(g, nums[j]);
      l = lcm(l, nums[j]);

      if (p > g * l) break;
      if (p == g * l) {
        answer = max(answer, j - i + 1);
      }
    }
  }

  return answer;
}
```

## 고생한 점
