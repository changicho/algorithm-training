# 1524. Number of Sub-arrays With Odd Sum

[링크](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

prefix sum을 이용해 풀이할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 경우마다 홀수, 짝수의 경우의 수를 저장한다. 이 경우 O(1)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

prefix sum을 구하며 현재까지 지나온 합이 짝수인 경우의 수와 홀수인 경우의 수를 구한다.

현재 prefix sum이 짝수인 경우, 이전까지의 홀수인 경우의 수를 더한다.

이는 현재 prefix sum에서 이전까지 합이 홀수인 경우를 빼는 경우 odd sum들이 되기 때문이다.

반대의 경우도 마찬가지다.

```cpp
int numOfSubarrays(vector<int>& arr) {
  const int MOD = 1e9 + 7;

  int count = 0, prefixSum = 0;
  int oddCount = 0, evenCount = 1;

  for (int num : arr) {
    prefixSum += num;

    if (prefixSum % 2 == 0) {
      count += oddCount;
      evenCount++;
    } else {
      count += evenCount;
      oddCount++;
    }

    count %= MOD;
  }

  return count;
}
```

## 고생한 점
