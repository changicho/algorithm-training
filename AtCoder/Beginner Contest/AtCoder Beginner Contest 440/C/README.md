# C - Striped Horse

[링크](https://atcoder.jp/contests/abc440/tasks/abc440_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N, 색칠 가능한 칸의 주기를 W라 하자.

각 주기의 시작점마다 색칠 가능한 비용을 계산할 수 있다. 이를 슬라이딩 윈도우를 이용해 구현할 수 있다.

이 경우 O(W + N)의 시간 복잡도를 가진다.

### 공간 복잡도

각 주기별로 직전값을 업데이트해서 현재 값을 구할 경우 O(1)의 공간 복잡도를 가진다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |  O(W + N)   |    O(1)     |

각 케이스별로 색칠이 가능한 칸은 다음과 같다.

```cpp
// w = 2
// x = 1
// 1 3 5 7 9 11 ...
// x = 2
// 0 2 4 6 8 10 ...
// x = 3
// 1 3 5 7 9 ...

// w = 3
// x = 1
// 0 1 5 6 7 11 12 13 ...
// x = 2
// 0 4 5 6 10 11 12 ...
// x = 3
// 3 4 5 9 10 11 ...
```

즉 너비가 W인 구간이 반복되며 해당 구간을 색칠, 색칠하지 않는 경우 두가지가 반복되며 색칠된 cost를 전부 구한다.

패턴은 반복되므로 0 ~ (W - 1) 까지 index를 시작점으로 잡아 슬라이딩 윈도우를 이용해 총 cost를 구할 수 있다.

각 index를 계산할 때 반복문에서 방문하는 좌표의 수는 N / W개 이며 이를 총 W번 반복하므로 총 O(N + W)의 시간 복잡도를 사용하므로 제한시간 내에 해결할 수 있다.

이 때 현재 색칠된 부분과 색칠되지 않은 부분이 반전된 경우도 정답이 될 수 있으므로 둘 다 고려해 최솟값을 갱신한다.

```cpp
long long solution(int size, int w, vector<int> costs) {
  long long answer = LLONG_MAX;

  long long sum = accumulate(costs.begin(), costs.end(), 0LL);

  long long curSum = 0;
  for (int i = 0; i < size; i++) {
    if (i % (2 * w) < w) {
      curSum += costs[i];
    }
  }
  answer = min(answer, curSum);
  answer = min(answer, sum - curSum);

  for (int i = 0; i < w; i++) {
    long long prevSum = curSum;

    for (int j = i; j < size; j += 2 * w) {
      curSum -= costs[j];
      if (j + w < size) {
        curSum += costs[j + w];
      }
    }

    answer = min(answer, curSum);
    answer = min(answer, sum - curSum);
  }

  return answer;
}
```

## 고생한 점
