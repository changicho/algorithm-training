# 1674. Minimum Moves to Make Array Complementary

[링크](https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 수를 N, 최대 변화값 범위를 M이라 하자.

각 index쌍 별로 특정 범위로 변화시키기 위한 연산의 수를 diff배열에 저장한다.

이후 모든 값들을 특정 값으로 변화하기 위한 연산의 수를 순회로 구하는데 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

diff배열에 O(M)의 공간 복잡도를 사용한다.

### diff count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N + M)   |    O(M)     |

각 index쌍에서 두 수중에서 작은값, 큰값을 각각 a, b라 하자.

두 값을 이용해 합의 범위를 생성하는데 구간을 다음과 같이 나눌 수 있다.

- 2 ~ (1+a) ~ (a+b) ~ (a+b+1) ~ (b+limit+1) ~ (2*limit)

각 구간에 맞춰 수를 변화하는데 필요한 연산의 수를 구할 수 있다.

이를 모든 쌍에 대해 구한 뒤, 실제 해당 값으로 변화시키기 위한 수를 diff array를 이용해 구한다.

```cpp
int minMoves(vector<int>& nums, int limit) {
  int size = nums.size();
  vector<int> diff(2 * limit + 2, 0);

  for (int i = 0; i < size / 2; ++i) {
    int a = min(nums[i], nums[size - 1 - i]);
    int b = max(nums[i], nums[size - 1 - i]);

    // 2 ~ (1+a) ~ (a+b) ~ (a+b+1) ~ (b+limit+1) ~ (2*limit)

    diff[2] += 2;
    diff[1 + a] -= 1;
    diff[a + b] -= 1;
    diff[a + b + 1] += 1;
    diff[b + limit + 1] += 1;
  }

  int answer = size;
  int cur = 0;

  for (int c = 2; c <= 2 * limit; ++c) {
    cur += diff[c];
    answer = min(answer, cur);
  }

  return answer;
}
```

## 고생한 점
