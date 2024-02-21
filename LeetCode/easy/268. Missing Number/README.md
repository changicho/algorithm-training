# 268. Missing Number

[링크](https://leetcode.com/problems/missing-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 원소의 개수를 N 이라 하자.

0부터 N까지 순회하며 나타나지 않은 수를 찾을 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

0부터 N까지의 방문 배열을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

XOR연산을 이용할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### XOR

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

0부터 N까지 수를 모두 xor 연산한 bit를 만든다.

이 bit에 nums의 모든 수를 xor연산한다.

이는 xor은 다음 법칙이 만족하기 때문이다.

```cpp
x^x = 0;
0^x = x;
```

따라서 missing number의 경우 한번만 나타나므로 bit는 해당 숫자가 된다.

```cpp
int missingNumber(vector<int>& nums) {
  int size = nums.size();

  int bit = 0;
  for (int num : nums) {
    bit ^= num;
  }

  for (int i = 0; i <= size; i++) {
    bit ^= i;
  }
  return bit;
}
```

### 자리 뒤집기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

배열에 존재하는 수의 범위는 0 ~ N 이다.

따라서 각 수를 순회하며 해당 수에 해당하는 index에 해당하는 수를 음수로 바꿔 후에 양수인 숫자가 존재하는 index를 이용해 정답을 구할 수 있다.

이 때 음수 index는 존재하지 않으므로 절대값을 사용한다.

이 때 배열 안에 0, N이 존재하는 경우를 처리하기 위해 두 방법중 한가지를 사용한다.

- X - 1에 해당하는 index를 음수로 변경, 0을 별도로 처리
- X에 해당하는 수를 음수로 변경, N을 별도로 처리
- 배열을 N+1 크기로 증가시킴

이 때 방문한 0을 처리하기 위해 nums의 값의 범위를 넘어서는 수를 더하고 나머지들을 이용해 값을 구한다.

```cpp
const int MOD = 1e6;

int missingNumber(vector<int>& nums) {
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    int cur = abs(nums[i] % MOD);
    if (cur == 0) continue;

    if (nums[cur - 1] == 0) nums[cur - 1] += MOD;
    nums[cur - 1] *= -1;
  }

  for (int i = 0; i < size; i++) {
    if (nums[i] >= 0) return i + 1;
  }
  return 0;
}
```

## 고생한 점
