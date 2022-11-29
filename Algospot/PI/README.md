# 원주율 외우기

[링크](https://algospot.com/judge/problem/read/PI)

| 정답률 |
| :----: |
|  31%   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자. (N은 최대 10,000)

입력받은 문자열을 쪼개보며 모두 탐색할 경우 O(2^N) 미만의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전까지 계산 결과를 저장하고 이용한다.

이 경우 한번 순회에 O(N)의 시간 복잡도를 사용한다.

또한 각 경우마다 자를 수 있는 직전의 경우들을 탐색 하는 데 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|    268ms     |    O(N)     |    O(N)     |

dp를 다음과 같이 정의한다.

```cpp
dp[i]; // minimum cost until visit i
```

문자열은 3~5 자 단위로 분리할 수 있다.

따라서 초기값은 다음과 같다.

```cpp
dp[0] = dp[1] = MAXIMUM;
dp[2] = getCost(0, 2);
dp[3] = getCost(0, 3);
dp[4] = getCost(0, 4);
```

이제 index가 5인 경우부터 (이전 3 ~ 5글자의 값을 모두 계산한 경우) 값을 갱신하는 일반 식은 다음과 같다.

```cpp
// current is i
long cur = INT_MAX;
for (int length = 3; length <= 5; length++) {
  cur = min(cur, dp[i - length] + getCost(line, i - length + 1, i));
}
dp[i] = cur;
```

즉 현재 index를 i라고 할 때, 현재 나누려는 문자열의 길이가 3~5인 경우에 대해 cost를 계산하고, 이전에 방문한 dp값을 사용해 갱신한다.

이를 구현하면 다음과 같다.

```cpp
bool isAllSame(string &target) {
  for (int i = 0; i < target.size() - 1; i++) {
    if (target[i] != target[i + 1]) return false;
  }
  return true;
}

bool isPattern(string &target) {
  int size = target.size();
  for (int i = 0; i < size; i++) {
    if (target[i] != target[i % 2]) return false;
  }
  return true;
}

bool isMonotonic(string &target) {
  int diff = target[0] - target[1];
  for (int i = 0; i < target.size() - 1; i++) {
    if (target[i] - target[i + 1] != diff) return false;
  }
  return true;
}

bool isSequence(string &target) {
  int diff = target[0] - target[1];
  return isMonotonic(target) && (abs(diff) == 1);
}

int getCost(string &line, int left, int right) {
  string target = "";
  for (int i = left; i <= right; i++) {
    target += line[i];
  }

  if (isAllSame(target)) return 1;
  if (isSequence(target)) return 2;
  if (isPattern(target)) return 4;
  if (isMonotonic(target)) return 5;
  return 10;
}

int solution(string &line) {
  int size = line.size();
  vector<long> dp(size, INT_MAX);

  for (int i = 2; i <= 4; i++) {
    dp[i] = getCost(line, 0, i);
  }

  for (int i = 5; i < size; i++) {
    long cur = INT_MAX;
    for (int length = 3; length <= 5; length++) {
      cur = min(cur, dp[i - length] + getCost(line, i - length + 1, i));
    }
    dp[i] = cur;
  }

  return dp.back();
}
```

## 고생한 점
