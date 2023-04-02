# 2588. Count the Number of Beautiful Subarrays

[링크](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. N <= 10^5

num은 최대 10^6 이하의 자연수이다.

각 연산마다 2개의 숫자의 같은 위치의 비트를 하나 삭제할 수 있다.

따라서 각 구간의 비트들의 갯수가 모두 짝수인 경우에 정답에 추가가 가능하다.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2) 이므로 제한시간 내에 불가능하다.

prefix를 이용해 각 상황마다의 비트의 갯수의 짝수, 홀수 여부를 구하고 현재 비트와 이전 비트를 이용해 정답을 구할 수 있다.

이 경우 순회에 O(N), 비트 계산에 O(20)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 비트들을 저장할 공간에 O(2^20)의 공간 복잡도를 사용한다.

### bit count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     256      |    O(N)     |   O(2^20)   |

각 sub array의 각 비트들의 갯수가 모두 짝수인 경우 정답의 경우에 추가할 수 있다.

모든 sub array의 경우의 수를 판단하는데 O(N^2)의 시간 복잡도가 필요하며 이는 불가능하다.

현재 비트의 상황과, 이전의 비트의 상황을 비교해 만약 짝수인 비트의 종류와 홀수인 비트의 종류가 같은 경우 정답에 추가할 수 있다.

따라서 nums을 순회하며 각 비트의 상황을 count한다.

이 때 각 비트의 상황에서 갯수가 아닌, 홀짝 여부만 판단하면 된다.

따라서 현재 num까지 순회하며 이를 sub array의 마지막으로 두고 이전에 같은 비트가 존재하는 경우 해당 수만큼 정답에 더한다.

```cpp
long long beautifulSubarrays(vector<int>& nums) {
  // bit count and can make answer if all bit count is even

  long long answer = 0;
  int dp[1 << 20] = {
      0,
  };

  int bitMask = 0;
  int allPass = 0;

  for (int num : nums) {
    for (int i = 0; i < 20; i++) {
      int bit = (1 << i);

      if ((num & bit) > 0) {
        // toggle bit on bitMask
        if ((bitMask & bit) > 0) {
          bitMask -= bit;
        } else {
          bitMask += bit;
        }
      }
    }

    if (bitMask == allPass) answer++;

    answer += dp[bitMask];
    dp[bitMask]++;
  }
  return answer;
}
```

## 고생한 점
