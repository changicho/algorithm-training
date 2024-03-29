# 319. Bulb Switcher

[링크](https://leetcode.com/problems/bulb-switcher/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 1e9)

1부터 N까지 순회할 경우 O(N)의 시간 복잡도가 사용되며 이는 제한시간 내에 불가능하다.

따라서 각 경우마다 토글을 직접 실행할 경우 O(N^2)의 시간 복잡도를 사용하므로 이 또한 불가능하다.

각 전구가 토글되는 횟수는 해당 순서의 약수의 갯수와 관련이 있다.

따라서 약수의 갯수가 홀수인 제곱수들만 찾아 계산하면 된다.

이 경우 sqrt(N)까지만 순회하면 되므로 O(sqrt(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

매번 제곱수를 직접 셀 경우 O(1)의 공간 복잡도를 사용한다.

### 제곱수 세기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(sqrt(N))  |    O(1)     |

1 ~ N 까지의 숫자들 중에서 매번 루프의 배수들을 토글시켰을 때 마지막에 켜져있는 전구들의 수를 구하는 문제이다.

여기서 토글되는 횟수는 배수와 관련있기 때문에, 결국 해당 숫자의 약수의 갯수와 관련이 있다.

따라서 약수가 홀수개인 수의 갯수를 찾으면 된다.

N=10이라 가정할 경우 다음과 같은 결과를 얻을 수 있다.

- 1 : 1 = 1
- 2 : 1,2 = 2
- 3 : 1,3 = 2
- 4 : 1,2,4 = 3
- 5 : 1,5 = 2
- 6 : 1,2,3,6 = 4
- 7 : 1,7 = 2
- 8 : 1,2,4,8 = 4
- 9 : 1,3,9 = 3
- 10 : 1,2,5,10 = 4

여기서 약수의 수가 홀수개인 경우는 특정 수 X의 제곱수인 경우이다.

따라서 1부터 N까지 X^2의 형태인 수들의 갯수를 찾으면 된다.

```cpp
int bulbSwitch(int n) {
  int count = 0;
  for (int num = 1; num * num <= n; num++) {
    count++;
  }
  return count;
}
```

### 제곱수 세기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

위 방법에서 sqrt까지 직접 순회하지 않고, 가능한 sqrt값을 직접 반환해도 된다.

이는 어차피 1부터 sqrt(N) 까지 순회하기 때문이다.

```cpp
int bulbSwitch(int n) { return sqrt(n); }
```

## 고생한 점
