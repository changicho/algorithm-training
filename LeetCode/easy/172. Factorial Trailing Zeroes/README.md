# 172. Factorial Trailing Zeroes

[링크](https://leetcode.com/problems/factorial-trailing-zeroes/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

팩토리얼을 직접 구하고 0의 개수를 셀 경우 시간 복잡도와 공간 복잡도를 초과한다.

따라서 수학적 성질을 이용해 문제를 풀이해야 한다.

이 경우 5의 배수의 수를 세면 되며 이는 모두 탐색할 경우 O(N)의 시간 복잡도가 소요된다.

만약 나눗셈을 이용할 경우 O(log_5(N))의 시간 복잡도 이내로 해결 가능하다.

### 공간 복잡도

직접 팩토리얼을 구하는 경우 수가 매우 크므로 공간복잡도를 초과한다.

따라서 5의 배수의 수를 센다. 이 경우 O(1)의 공간 복잡도가 필요하다.

### 5의 갯수 세기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_5(N)) |    O(1)     |

팩토리얼에서 끝자리가 0이 나오는 경우는 다음과 같다.

- 2 \* 5가 한번씩 나타날 때마다 0의 자리가 1씩 증가한다.

따라서 팩토리얼 곱을 약수로 나타냈을 때 2의 갯수와 5의 갯수를 모두 센뒤 두 수 중에서 적은 쪽을 count한다.

이 때, 2는 5보다 수가 무조건 많을 수 밖에 없으므로 5의 수를 센다.

5, 25, 125등과 같이 5로 나누어 떨어지는 수에 대한 예외 처리를 추가해 문제를 풀이할 수 있다.

```cpp
int trailingZeroes(int n) {
  int answer = 0;

  vector<int> fives;
  for (int five = 5; five <= 10000; five *= 5) {
    fives.push_back(five);
  }

  for (int num = 1; num <= n; num++) {
    for (int five : fives) {
      if (num % five == 0) answer += 1;
    }
  }

  return answer;
}
```

아니면 5의 배수의 갯수를 count하면 되므로 나누기를 이용해 더 빠르게 계산할 수 있다.

```cpp
// use for
int trailingZeroes(int n) {
  int answer = 0;
  for (long long five = 5; n / five > 0; five *= 5) {
    answer += (n / five);
  }
  return answer;
}

// use while
int trailingZeroes(int n) {
  int answer = 0;
  while (n / 5 > 0) {
    int tmp = n / 5;
    answer += tmp;
    n = tmp;
  }
  return answer;
}
```

## 고생한 점
