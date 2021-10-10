# 365. Water and Jug Problem

[링크](https://leetcode.com/problems/water-and-jug-problem/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

jug1의 크기를 N, jug2의 크기를 M이라 하자.

jug 두 값의 합이 변화하는 값을 탐색할 경우는 (N + M) 가지밖에 없다.

각 경우마다 jug1, jug2 하나의 물이 변화한다 하더라도 결국 그 총합이 변화하게 되기 때문이다.

따라서 BFS로 모든 경우를 탐색할 경우 경우의 수는 O(N + M)만큼 소요된다.

이 때 각 경우마다 6번씩 다음 경우로 나갈 수 있으므로 미리 중복 체크를 수행해야 한다.

혹은 수학적 방법을 이용할 수 도 있다.

GCD를 이용할 경우 시간 복잡도는 O(log_2(N))이 된다. (N > M 이라고 할 때)

### 공간 복잡도

BFS 탐색시 중복 경우를 제거하기 위해 visited를 사용할 경우 O(N + M) 크기의 공간 복잡도를 사용한다.

그 외의 경우 별도의 배열이 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### BFS & backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1196     |  O(N + M)   |  O(N + M)   |

현재 경우에서 다음 경우로 갈 수 있는 6가지 경우는 다음과 같다.

(1 : jug1Capacity, 2 : jug2Capacity)

- 2 to 1
- 1 to 2
- fill 1
- fill 2
- pour 1
- pour 2

각 경우마다 다음 6가지 경우에 대해 탐색을 진행한다.

이 때 이전에 방문한 경우는 무시한다.

hash set을 사용하기 위해 first와 second 값을 변환해 hash set에 저장한다.

```cpp
long long convert(pair<int, int> cur) {
  return (long long)cur.first * 1000000 + cur.second;
}

bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
  if (jug1Capacity + jug2Capacity < targetCapacity) return false;

  queue<pair<int, int>> q;
  unordered_set<long long> s;

  s.insert(convert({jug1Capacity, jug2Capacity}));
  q.push({jug1Capacity, jug2Capacity});

  bool answer = false;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int jug1 = cur.first, jug2 = cur.second;

    if (jug1 + jug2 == targetCapacity) {
      answer = true;
      break;
    }

    vector<pair<int, int>> cases = {{jug1 - min(jug1, jug2Capacity - jug2),
                                      jug2 + min(jug1, jug2Capacity - jug2)},
                                    {jug1 + min(jug2, jug1Capacity - jug1),
                                      jug2 - min(jug2, jug1Capacity - jug1)},
                                    {jug1Capacity, jug2},
                                    {jug1, jug2Capacity},
                                    {0, jug2},
                                    {jug1, 0}};

    for (pair<int, int> next : cases) {
      if (s.count(convert(next)) > 0) continue;

      s.insert(convert(next));
      q.push(next);
    }
  }
  return answer;
}
```

### GCD

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

gcd의 경우 다음과 같이 구현되어있다.

```cpp
int gcd(int a, int b) {
  if (b == 0) return a;
  gcd(b, a%b);
}
```

두 수 a, b를 jug1, jug2라고 생각하자.

결국 우리는 jug1, jug2에 물을 넣고, 이동하고, 버리는 작업을 통해서 두 수의 gcd값을 최소단위로 얻을 수 있다.

이를 응용해서 gcd를 한번 구할 수 있으면, 해당 gcd의 배수를 구하는것도 가능하다.

따라서 target을 gcd값으로 만들 수 있는지 (나누어 떨어지는 지) 판단한다.

```cpp
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
  int gcdVal = gcd(jug1Capacity, jug2Capacity);

  if (targetCapacity % gcdVal == 0 &&
      jug1Capacity + jug2Capacity >= targetCapacity) {
    return true;
  }
  return false;
}
```

### ax-by=z

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

두 수 a, b를 jug1, jug2라고 생각하자.

결국 우리는 jug1, jug2에 물을 넣고, 이동하고, 버리는 작업을 while문으로 진행한다.

만약 작업을 진행하며 target에 도달한 경우 정답을 만들 수 있는 경우이다.

만약 물이 모두 비워진 경우는 시작점과 동일하므로 이는 무시한다.

jug2보다 jug1이 더 큰 용량을 가지고 있다고 가정했을 때 다음과 같은 순서로 진행한다.

- jug1보다 현재 물이 적으면 jug2를 더한다
- 그 외의 경우 jug1만큼 뺀다
- 정답을 만들 수 있는지 검사한다.

```cpp
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
  if (jug1Capacity + jug2Capacity == targetCapacity) return true;
  if (jug1Capacity + jug2Capacity < targetCapacity) return false;

  if (jug1Capacity > jug2Capacity) swap(jug1Capacity, jug2Capacity);

  int volume = 0;
  bool answer = false;

  while (true) {
    if (volume < jug1Capacity) {
      volume += jug2Capacity;
    } else {
      volume -= jug1Capacity;
    }

    if (volume == targetCapacity) {
      answer = true;
      break;
    }

    if (volume == 0) break;
  }

  return answer;
}
```

## 고생한 점
