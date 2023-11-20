# 2929. Distribute Candies Among Children II


[링크](https://leetcode.com/problems/distribute-candies-among-children-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N, 개인이 가질 수 있는 최대값을 L이라 하자.

3명에게 사탕을 나누기 위해 각 인원을 다음과 같이 그룹으로 묶어 생각할 수 있다. (1,2), (3)

이 경우 두 그룹에 나누는 사탕의 합이 N이 되도록 순회하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열을 사용하지 않아도 되므로 O(1)의 공간 복잡도를 사용한다.

### 분할

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(1)     |

3명에게 사탕을 나누기 위해 각 인원을 다음과 같이 그룹으로 묶어 생각할 수 있다. (1,2), (3)

이 때 두명이 속한 그룹에 존재하는 사탕의 수가 X라고 할 때 해당 그룹에 사탕을 나누는 경우는 다음과 같다.

- X, 0
- (X-1), 1
- (X-2), 2
- ...
- 0, X

이는 X+1가지 경우이므로 X를 알 수 있다면 경우의 수를 바로 구할 수 있다.

여기서 사탕을 가질 수 있는 최대 갯수는 제한되므로 한명에게 주어질 수 있는 사탕의 범위는 다음과 같다.

- max(0, n - 2 * limit) ~ min(limit, n)

두병에게 나눌 수 있는 사탕의 범위는 다음과 같다.

- max(0, n - x' - limit) ~ min(limit, n - x')

이를 이용해 x'에 대해 순회하며 정답을 구한다.

```cpp
long long distributeCandies(int n, int limit) {
  long long answer = 0;
  int firstMin = max(0, n - 2 * limit);
  int firstMax = min(limit, n);

  for (int i = firstMin; i <= firstMax; ++i) {
    int secondMin = max(0, n - i - limit);
    int secondMax = min(limit, n - i);

    answer += secondMax - secondMin + 1;
  }
  return answer;
}
```

## 고생한 점
