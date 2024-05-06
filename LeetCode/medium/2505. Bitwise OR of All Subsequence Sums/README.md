# 2505. Bitwise OR of All Subsequence Sums

[링크](https://leetcode.com/problems/bitwise-or-of-all-subsequence-sums)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

각 subsequence의 합에서 비트가 필요하다. 따라서 각 수를 순회하며 가능한 비트들을 모두 계산한 뒤 이를 이용해 답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 비트를 저장할 공간이 필요하며 이에 O(1)의 공간 복잡도를 사용한다. 

### 비트 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      95      |    O(N)     |    O(1)     |

subsequence의 합에서 정답에 영향을 주는 값들은 각 자리에 존재하는 비트들이다.

이는 결과적으로 subsequence의 합을 OR 연산할 때 존재 여부만 영향을 준다.

따라서 각 수를 순회하며 각 자리의 비트들을 세고, 이를 이용해 답을 구할 수 있다.

이 때 subsequences의 합을 구할 때 carry가 발생할 수 있으므로 이를 고려해야 한다.

```cpp
long long subsequenceSumOr(vector<int>& nums) {
  long long bits[64] = {
      0,
  };

  for (int& num : nums) {
    for (int i = 0; i < 31; i++) {
      if (num & (1 << i)) {
        bits[i]++;
      }
    }
  }

  long long answer = 0;
  for (int i = 0; i < 63; ++i) {
    if (bits[i] > 0) {
      answer |= 1LL << i;
    }

    // carry count
    bits[i + 1] += bits[i] / 2;
  }

  return answer;
}
```

## 고생한 점
