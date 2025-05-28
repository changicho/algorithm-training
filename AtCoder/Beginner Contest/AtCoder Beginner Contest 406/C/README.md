# C - ~

[링크](https://atcoder.jp/contests/abc406/tasks/abc406_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

배열 P의 크기를 N이라 하자.

각 수를 순회하며 이전 수와의 증감 여부를 구하는 데 O(N)의 시간 복잡도를 사용한다.

이를 순회하며 정답을 구하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

경우의 수가 최대 N^2까지 증가할 수 있다. 따라서 long long형을 사용한다.

각 과정마다 증감 여부를 이용해 정답을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |    O(N)     |    O(1)     |

현재 숫자가 다음 숫자보다 작은 경우와 큰 경우 2가지로 나누어 생각한다.

정답의 경우는 상승-하강-상승 순서가 되어야 한다.

따라서 상승인 경우 연속 상승인 경우의 count를 증가시킨다.

만약 하강인 경우 (이전 연속 상승) \* (현재 연속 상승) 의 경우의 수를 정답에 더할 수 있다.

이는 상승-하강-상승 부에서 상승 부분으로 만들 수 있는 경우의 수를 구하는 것이다.

```javascript
// +1 : 상승
// -1 : 하강
[+1, +1, +1, -1, -1, +1, +1]

// 위 경우 왼쪽 부분에 3가지 경우의 수,
// 오른쪽 부분에 2가지 경우의 수가 존재한다.

// 따라서 3 * 2 = 6가지 경우의 수가 존재한다.
```

이후 이전 연속 상승을 현재 연속 상승으로 바꿔준 뒤 현재 연속 상승을 0으로 초기화한다.

```cpp
long long solution(int size, vector<int> &nums) {
  long long answer = 0;

  long long beforeCount = 0;
  long long curCount = 0;
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] < nums[i + 1]) {
      curCount++;
    } else if (nums[i] > nums[i + 1]) {
      answer += curCount * beforeCount;

      if (curCount > 0) {
        beforeCount = curCount;
      }
      curCount = 0;
    }
  }

  answer += curCount * beforeCount;

  return answer;
}
```

## 고생한 점
