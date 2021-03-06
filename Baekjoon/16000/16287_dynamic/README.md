# 16287. Parcel

[링크](https://www.acmicpc.net/problem/16287)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   21.365    |       1       |

## 설계

### 시간 복잡도

원소의 개수 N은 최대 5,000개 까지이다.

모든 경우를 탐색하는 경우 (5,000 \* 4,999 \* 4,998 \* 4,997) 번 수행해야하므로 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 풀이한다.

### 공간 복잡도

4개의 모든 원소의 합은 800,000 이내이다.

따라서 int형을 사용한다.

### 탐색 최적화

4개의 무게의 조합의 일반식은 one + two + three + four = W이다.

이 방식대로 one, two, three, four를 변경하며 수행할 경우 제한시간 내에 불가능하므로 아래와 같이 탐색을 진행한다.

one + two = W - (three + four)

index를 증가시키며 one + two를 미리 계산하는 방법을 이용한다.

index를 순회하며 (index + 1) ~ N 까지인 right를 이용해 index + right 를 탐색한다.

이때 W - (index + right) 번째가 이전에 이미 만들어진 경우 one + two = W - (three + four)를 만족한다.

이후 0 ~ (index - 1) 까지인 left를 이용해 left + index 를 탐색한다.

이는 one + two를 구하는 과정이다.

```cpp
for (int index = 0; index < N; index++) {
  for (int right = index + 1; right < N; right++) {
    int newWeight = weights[index] + weights[right];
    if (newWeight > W) continue;

    if (dp[W - newWeight]) {
      answer = true;
    }
  }
  for (int left = 0; left < index; left++) {
    int newWeight = weights[left] + weights[index];
    if (newWeight < W) {
      dp[newWeight] = true;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      68      |       0        |

## 고생한 점
