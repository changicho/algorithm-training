# 1007. 벡터 매칭

[링크](https://www.acmicpc.net/problem/1007)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold II |   36.528    |

## 설계

### 시간 복잡도

점의 개수는 최대 20개이다.

문제에서 정답을 찾기 위해선 모든 점들을 두 그룹으로 나눠 비교해봐야한다.

모든 경우를 비교해본다고 할 때 시간 복잡도는 두 그룹으로 나누는 경우의 수 이므로 184,756 번 이다.

테스트 케이스의 수는 정해지지 않았으므로 넘어간다고 했을 때, 제한시간 2초내에 충분하다고 가정한다.

### 공간 복잡도

정답은 소수점을 가질 수 있으므로 double형으로 선언한다.

### 벡터 매칭

문제에서 요구하는 사항은 결국 점들을 N/2 개의 점을 가진 두 집합으로 나눴을 때,

각 집합의 벡터를 구하고 그 크가를 구하는것이다.

하나의 그룹은 벡터를 더하고, 하나의 그룹은 벡터를 뺀다.

그룹으로 나누는 경우의 수는 next_permutation을 이용해 구현한다.

```cpp
vector<bool> checks(N, false);

for (int i = 0; i < N / 2; i++) {
  checks[i] = true;
}
sort(checks.begin(), checks.end());

do {
  double sumX = 0, sumY = 0;

  for (int i = 0; i < N; i++) {
    if (checks[i]) {
      sumX += points[i].x;
      sumY += points[i].y;
    } else {
      sumX -= points[i].x;
      sumY -= points[i].y;
    }
  }

  double curAnswer = sqrt(sumY * sumY + sumX * sumX);
  answer = min(answer, curAnswer);
} while (next_permutation(checks.begin(), checks.end()));
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     260      |       8        |

## 고생한 점
