# 43238. 입국 심사

[링크](https://programmers.co.kr/learn/courses/30/lessons/43238)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv3   |   1678   |

## 설계

### 시간 복잡도

최악의 경우 걸리는 시간은, 임국 심사관이 1명, 손님이 1,000,000,000명, 입국에 걸리는 시간이 1,000,000,000분 일 때 이다.

따라서 이 경우에 최악의 시간은 1,000,000,000,000,000,000 이다.

시뮬레이션으로 풀 경우 시간 초과가 발생하므로, 위 시간을 이분 탐색해 풀이한다.

이 경우 시간 복잡도는

```cpp
M * log(TIME) =  100,000 * 60 = 6,000,000
```

이므로 제한 시간 내에 충분하다.

### 공간 복잡도

정답의 범위는 long long 형이다. 따라서 long long 을 사용하며, 입국 심사관 마다 걸리는 시간은 int형 이므로 casting 해준다.

### 이분 탐색

총 시간 time을 변수로 두고, 입국 심사관들이 각 시간별로 처리 했을 때 모든 손님을 심사할 수 있는지를 검사한다.

총 시간 / 처리 시간 = 처리하는 명 수

이 때 나머지는 무시한다. (예를 들어 5초가 걸리는 심사관이 9초 동안 처리할 수 있는 손님은 1명이다.)

```cpp
long long calculPeople(long long totalTime, vector<int> &times) {
  long long sum = 0;

  for (int t : times) {
    sum += totalTime / (long long)t;
  }

  return sum;
}
```

현재 시간에서 처리할 수 있는 손님의 수가 실제 손님보다 적으면 time을 증가하고, 그 외의 경우는 time을 감소한다.

```cpp
while (start <= end) {
  mid = (start + end) / 2;

  long long peoples = calculPeople(mid, times);

  // 대기 인원보다 현재 시간에서 검사할 수 있는 인원이 더 많으면
  if (n > peoples) {
    start = mid + 1;
  } else {
    answer = min(mid, answer);
    end = mid - 1;
  }
}
```

## 고생한 점
