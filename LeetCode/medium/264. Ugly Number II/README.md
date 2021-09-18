# 264. Ugly Number II

[링크](https://leetcode.com/problems/ugly-number-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

어떤 숫자 x가 ugly number인지 구하는 데 들어가는 시간 복잡도는 O(log_2(X)) 이다.

(2, 3, 5중에서 2로만 나눴을 때 시간복잡도가 가장 오래 걸리므로)

N번째 ugly number를 구하기 위해 브루트 포스를 통해서 구할 경우

문제에서 구해야 하는 제일 큰 ugly number는 2,123,366,400 이며 이를 직접 구할경우 제한 시간 내에 불가능하다.

그리디 알고리즘을 이용할 경우 각 경우마다 제일 작은 값들을 저장하는데 O(log_2(N))의 시간 복잡도를 사용하고 탐색에 O(N)의 시간 복잡도를 소요한다.

따라서 시간 복잡도는 O(N \* log_2(N))이므로 제한시간 내에 충분하다.

혹은 동적 계획법을 이용할 경우 한번의 순회로 구할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그리디 알고리즘, 동적 계획법 모두 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

2를 곱하는 경우, 3을 곱하는 경우, 5를 곱하는 경우 3가지 경우에 대한 직전 값의 index를 저장한다.

이는 i번째 ugly number의 앞에는 현재 값보다 작은 값들이 존재하기 때문이다.

따라서 현재 i번째 ugly number가 각각 2, 3, 5를 곱했을 때 가장 작은 값들 중에서 셋 중 가장 작은 값을 선택한다면 현재 ugly number를 구할 수 있다.

이는 직전 값들에서 2, 3, 5를 곱했을 때 직전 dp값을 초과하는 가능한 가장 작은 값의 index를 지니고 있기 때문이다.

dp식을 다음과 같이 설정하자.

```cpp
dp[i]; // i번째 ugly number
```

일반식은 다음과 같다.

```cpp
int twoIdx = 0, threeIdx = 0, fiveIdx = 0;  // 각각 마지막에 2, 3, 5를 곱했을 때 dp[i-1]보다 큰 가장 작은 값의 index

dp[i] = min(dp[twoIdx] * 2, min(dp[threeIdx] * 3, dp[fiveIdx] * 5));

// 이후 선택한 index를 증가시킴
if (dp[i] == dp[twoIdx] * 2) twoIdx++;
if (dp[i] == dp[threeIdx] * 3) threeIdx++;
if (dp[i] == dp[fiveIdx] * 5) fiveIdx++;
```

초기값은 다음과 같다.

```cpp
dp[0] = 1;
```

이를 이용해 풀이할 경우 다음과 같다.

```cpp
int nthUglyNumber(int n) {
  int twoIdx = 0, threeIdx = 0, fiveIdx = 0;  // pointers for 2, 3, 5
  vector<int> dp(n);
  dp[0] = 1;

  for (int i = 1; i < n; i++) {
    dp[i] = min(dp[twoIdx] * 2, min(dp[threeIdx] * 3, dp[fiveIdx] * 5));

    if (dp[i] == dp[twoIdx] * 2) twoIdx++;
    if (dp[i] == dp[threeIdx] * 3) threeIdx++;
    if (dp[i] == dp[fiveIdx] * 5) fiveIdx++;
  }

  return dp.back();
}
```

### 그리디 알고리즘

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     108      | O(N \* log_2(N)) |    O(N)     |

매번 최소값에서 2, 3, 5를 곱한 값을 저장하고 다음 최소값을 찾을 수 있는경우

가장 작은 값에서 2, 3, 5를 곱한 값들을 저장하므로 i번째 ugly number를 구할 수 있다.

매번 가장 작은 값을 찾기 위해서 set 자료 구조를 이용한다.

(저장시에 O(log_2(N))의 시간 복잡도를 사용)

매번 set.begin()으로 가장 작은 값을 찾고 2, 3, 5를 곱한 값을 insert 한 뒤 set.begin()을 지운다.

이를 n번째 값이 저장될 때 까지 반복한다.

이 때 한번에 3개씩 값이 저장되므로 n번째보다 큰 값이 set에 저장될 수 있다.

따라서 overflow가 발생할 수도 있으므로 long long형으로 관리한다.

```cpp
int nthUglyNumber(int n) {
  set<long long> s;

  s.insert(1);
  int count = 0;
  int answer = 0;

  while (!s.empty()) {
    long long cur = *s.begin();
    s.erase(cur);

    answer = cur;
    count += 1;
    if (count == n) break;

    s.insert(cur * 2);
    s.insert(cur * 3);
    s.insert(cur * 5);
  }

  return answer;
}
```

## 고생한 점
