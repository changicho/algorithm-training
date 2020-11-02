# 10819. 차이를 최대로

[링크](https://www.acmicpc.net/problem/10819)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   62.215    |

## 설계

### 시간 복잡도

N은 최대 8이다.

각 경우를 모두 시도해 봤을 경우 시간 복잡도는

```cpp
8! = 40,320
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

N은 최대 8이고, 각 수의 절대값의 최대치는 100까지이다.

최악의 경우 합은 200이 7번 반복되는것이므로 1,400정도이다.

이는 int형으로 충분하다.

### next_permutation

next_permutation을 이용해 모든 경우의 조합을 빠르게 계산할 수 있다.

```cpp
sort(arr.begin(), arr.end());

do {
  int summation = 0;

  for (int i = 0; i < N - 1; i++) {
    summation += abs(arr[i] - arr[i + 1]);
  }

  answer = max(summation, answer);
} while (next_permutation(arr.begin(), arr.end()));
```

직접 구현하는 경우는 방문배열과 재귀를 이용해 풀이할 수 있다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
