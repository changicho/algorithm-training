# 2333. Minimum Sum of Squared Difference

[링크](https://leetcode.com/problems/minimum-sum-of-squared-difference/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 숫자의 범위를 M이라 하자.

배열을 순회하며 차이를 구해 카운팅한다. 이에 O(N)의 시간 복잡도를 사용한다.

이후 차이를 큰 순서대로 순회하며 정답을 구한다. 이에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 차이를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 그리디 & 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N + M)   |    O(M)     |

차이들이 존재할 때, 차이의 제곱을 정답에 더하므로 큰 차이값 부터 줄이는 편이 유리하다.

따라서 각경우마다 가장 큰 차이값을줄이는 횟수를 k1 + k2번 반복하면 된다.

이를 위해 각 차이를 배열을 이용해 저장하며, 각 차이값을 큰 순서대로 순회하며 현재 남은 K의 수만큼 최대한 감소시킨다.

```cpp
long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
  int size = nums1.size();
  int count[100001] = {
      0,
  };

  int maximum = 0;
  for (int i = 0; i < size; i++) {
    int diff = abs(nums1[i] - nums2[i]);
    maximum = max(maximum, diff);
    count[diff]++;
  }

  long long answer = 0;
  int k = k1 + k2;
  for (int num = maximum; num >= 1; num--) {
    if (count[num] == 0) continue;

    int minus = min(k, count[num]);

    k -= minus;
    count[num] -= minus;
    count[num - 1] += minus;

    answer += (long long)num * num * count[num];
  }

  return answer;
}
```

## 고생한 점
