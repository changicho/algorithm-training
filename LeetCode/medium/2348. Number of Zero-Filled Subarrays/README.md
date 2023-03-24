# 2348. Number of Zero-Filled Subarrays

[링크](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. (N <= 10^5)

모든 subArray에 대해 직접 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

연속된 0의 개수에 대해 구성 가능한 subArray의 경우의 수를 O(1)의 시간 복잡도로 구할 수 있다.

따라서 한번의 순회를 진행하며 각 경우마다 연속된 0의 갯수를 구하고 모든 경우의 수를 탐색한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 별도의 배열등의 공간을 사용하지 않는다.

따라서 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     167      |    O(N)     |    O(1)     |

왼쪽부터 오른쪽으로 순회하며, 현재 숫자를 끝으로 하는 연속된 0의 갯수를 센다.

이 때 연속된 0의 갯수들에 대해 각 길이로 만들 수 있는 경우의 수는 다음과 같다.

- 연속된 0의 갯수를 X라 하자.
- 길이가 1, 2, 3, ... , X인 모든 경우의 수를 더하는 식은 아래와 같다.
- X + (X-1) + (X-2) + ... + 1
- 따라서 이를 다음과 같이 구할 수 있다. (X \* (X + 1) / 2)

따라서 연속된 0의 갯수들에 대해 위 식을 이용해 경우의 수를 모두 구한다.

```cpp
long long zeroFilledSubarray(vector<int>& nums) {
  long long answer = 0;

  long long continuous = 0;
  for (int& num : nums) {
    if (num != 0) {
      // 1 + 2 + ... + X = X * (X + 1) / 2
      answer += (continuous + 1) * (continuous) / 2;
      continuous = 0;
    } else {
      continuous++;
    }
  }

  if (continuous > 0) {
    answer += (continuous + 1) * (continuous) / 2;
  }
  return answer;
}
```

## 고생한 점
