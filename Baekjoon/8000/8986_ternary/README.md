# 8986. 전봇대

[링크](https://www.acmicpc.net/problem/8986)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   25.805    |

## 설계

### 시간 복잡도

전봇대의 개수는 최대 100,000, 각 전봇대의 x좌표는 최대 1,000,000,000까지이다.

첫번쨰 전봇대는 항상 0에 위치해있다. (첫번째 전봇대는 고정)

이 경우 각 전봇대들의 너비를 계산하고, 이를 토대로 이동할 위치를 계산할 수 있다.

너비를 탐색할 때 O(log_2(N)) 까지 시간을 줄일 수 있으므로,

이 경우 시간 복잡도는 O(log_2(1,000,000,000)) = 30 정도이다.

각 경우마다 비용을 계산하는데 O(N)이 소요되므로

최악의 경우 시간 복잡도는 대략 아래와 같다.

```cpp
O(100,000 * log_2(1,000,000,000)) = 3,000,000
```

이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

입력되는 좌표는 최대 1,000,000,000 까지이며, 좌표를 계산할 경우 이동되는 위치 까지 고려한다면 최악의 경우

100,000,000,000,000 까지 될 수 있다.

따라서 변수들은 long long 형태로 관리한다.

### cost 함수

f(x) = Σ|i \* x - x_i| 이다.

이를 코드로 나타낸 경우 아래와 같다.

```cpp
long long calculateCost(long long length) {
  long long ret = 0;

  for (int i = 0; i < arr.size(); i++) {
    ret += abs(i * length - arr[i]);
  }

  return ret;
}
```

각 항을 x에 대한 함수 g_i(x) = |i\*x - x_i| 로 나타내고 최솟값을 찾아보자.

이 함수는 x = x_i/i 인 지점에서 미분불가능하면서 최솟값을 가진다.

### 삼분 탐색 (Ternary Search)

삼분 탐색은 볼록함수에서 극값 혹은 최대/최솟값을 찾을 때 사용할 수 있는 테크닉이다.

이분 탐색은 함수가 항상 단조 증가/감소할 때만 쓸 수 있었지만, 삼분탐색의 경우 보다 더 복잡한 곳에도 사용이 가능하다.

메커니즘의 특성상, 최솟값이 아닌데 평탄한 구간이 존재할 경우 삼분 탐색을 쓸 수가 없으므로 이에 유의한다.

한쪽은 순감소, 반대쪽은 순증가라면 삼분 탐색을 사용할 수 있다. (최솟값 찾을 수 있을때)

삼분탐색의 구현에 필요한 변수들은 다음과 같다.

- 시작점 (range_start) : 삼분탐색 구간의 시작점
- 끝점 (range_end) : 삼분탐색 구간의 끝점
- left : 시작점에 가중치를 더 둔 점 ((2 \* range_start + range_end) / 3)
- right : 끝점에 가중치를 더 둔 점 ((range_start + 2 \* range_end) / 3)

삼분 탐색의 구현은 아래와 같다.

```cpp
long long range_start = 1, range_end = 1e9;

while (range_start + 3 <= range_end) {
  long long left = (2 * range_start + range_end) / 3;
  long long right = (range_start + 2 * range_end) / 3;

  long long costL = calculateCost(left);
  long long costR = calculateCost(right);

  if (costL < costR) {
    range_end = right;
  } else {
    range_start = left;
  }
}
```

위 로직을 실행한 결과, 최솟값을 가질 수 있는 위치는 start ~ end 사이에 있음이 보장된다.

최후에 이 구간을 이용해 정답을 구한다.

```cpp
for (long long cur = range_start; cur <= range_end; cur++) {
  answer = min(answer, calculateCost(cur));
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       8        |

## 고생한 점
