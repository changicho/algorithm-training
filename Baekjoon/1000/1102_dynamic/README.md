# 1102. 발전소

[링크](https://www.acmicpc.net/problem/1102)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold I |   22.534    |

## 설계

### 시간 복잡도

N은 최대 16인 자연수이다.

모든 경우를 탐색할 경우 16! 정도 소요되므로 (각 발전소가 켜지는 상황까지 고려해야 하므로) 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 문제를 풀이한다.

동적 계획법에서 각 발전소의 켜짐 유무의 상태별로 탐색을 이어나가야 하므로 비트마스킹을 이용한다.

### 공간 복잡도

N은 최대 16까지인 자연수이다.

16^2 크기의 2차원 배열을 통해 발전에 들어가는 비용 table을 사용한다.

비트 마스킹을 사용하기 위해 2^16 크기의 숫자를 사용해야 한다. 이는 65535 까지 이므로 int형으로 충분하다.

각 발전소를 켜는 비용은 최대 50까지 이므로 최악의 경우의 비용은 800 이하이다.

### 비트마스킹

수를 2진수로 나타내어 해당 bit가 1인지 여부를 판단한다.

이 때 모든 비트를 포함하기 위한 수 (경우의 수)가 자료형으로 표현 가능한지를 판단해야한다.

비트마스킹은 & 연산과 | 연산을 이용해 사용한다 (AND, OR)

해당 bit가 1인지 판단은 다음과 같다.

```cpp
if (bits & (1 << index))
```

해당 비트를 1로 변경할 경우는 다음과 같다.

```cpp
int newBits = bits | (1 << index);
```

### 동적 계획법

재귀 함수를 이용한 Top-Down 방식으로 문제를 해결했다.

dp 배열의 의미는 다음과 같다.

```cpp
// 해당 비트마스킹에서의 최소값
dp[bitMasking] = lowestCostValue;
```

dp 배열의 초기값은 다음과 같다.

```cpp
memset(dp, -1, sizeof(dp));
```

dp의 일반식은 다음과 같다.

```cpp
dp[bits] = min(dp[bits], func(num + 1, bits | (1 << 고장난 발전기)) + cost[가동 발전기][고장 발전기]
```

cost의 계산은 해당 고장난 발전기를 켰을 때 들어가는 비용과 현재 비용 중 최소값을 선택한다.

dp 배열을 갱신하기 위해 이용한 재귀 함수의 형태는 다음과 같다.

```cpp
// count : 켜진 발전소 개수, bits : 비트마스킹 상태
int recursive(int count, int bits) {
  if (count == P) return 0;

  if (dp[bits] != -1) return dp[bits];
  dp[bits] = MAX;

  for (int from = 0; from < N; from++) {
    if (bits & (1 << from)) {
      for (int to = 0; to < N; to++) {
        if (from == to) continue;

        if ((bits & (1 << to)) == 0) {
          int newBits = bits | (1 << to);
          int newCost = recursive(count + 1, newBits) + table[from][to];

          dp[bits] = min(dp[bits], newCost);
        }
      }
    }
  }

  return dp[bits];
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       4        |

## 고생한 점
