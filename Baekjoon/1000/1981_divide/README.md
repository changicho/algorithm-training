# 1981. 배열에서 이동

[링크](https://www.acmicpc.net/problem/1981)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold I |   22.660    |

## 설계

### 시간 복잡도

각 지도를 탐색해야 한다. BFS로 탐색한다고 했을 때, 100^2 개의 좌표를 탐색하므로 100,000 번의 연산이 소요된다.

배열의 각 수는 200 이하의 자연수이다. 범위를 0 ~ 200 으로 완전탐색 하는 경우 200^2 번의 연산이 소요되며,

각 경우 지도를 탐색 할 때 완전 탐색을 하면

```cpp
100^2 * 200^2 = 400,000,000
```

400,000,000 번의 연산이 소요되므로 제한시간 내에 불가능하다.

따라서 범위의 탐색을 완전 탐색이 아닌, 다음 방법을 이용한다.

- 이분 탐색 (max - min 값)
- 투 포인터 (range의 시작점과 끝점)

변화시킬 값은 max - min 값 이며, 이를 이분 탐색 하는 경우 log(200) 만큼 소요된다.

max - min 값을 각 경우에 대입하기 위해 지도의 제일 작은 값부터 큰 값 까지 탐색하며 시작점으로 둔다.

(시작점) ~ (시작점 + max - min) 만큼 탐색해야 하므로 최악의 경우 200번이 소요된다.

따라서 시간 복잡도를 전부 계산하면

```cpp
// (max-min) * range탐색 * BFS
log(200) * 200 * 100,000 = 1,600 * 100,000 = 160,000,000
```

이며 이는 제한 시간에 아슬아슬 하다 (160 ms)

시간을 최적화 하기 위해선 range 의 시작점과 끝 점을 투 포인터로 설정한다.

이 경우 start와 end가 이동하는 데 2N 의 시간 복잡도가 소요된다.

범위가 0~200 까지 이므로, 시간 복잡도는

```cpp
// range탐색 * BFS
(200*2) * 100,000 = 40,000,000
```

이며 이는 제한시간 내에 충분하다.

### 공간 복잡도

모든 값은 200 이하의 양수이므로 int형으로 선언한다.

### BFS로 탐색

BFS로 탐색 전, 시작점 (0, 0) 이 유효한 범위인지 검사해줘야 한다.

만약 유효하지 않은 경우에는 탐색을 시작하기 전에 false를 return 한다.

BFS로 탐색할 때, 인자로 받은 range (from ~ to) 에 속해있는 수인지를 비교해 탐색한다.

```cpp
// 범위에 속한 수 인지를 검사
if (map[next.y][next.x] < from || map[next.y][next.x] > to) continue;
```

### limit을 이분 탐색

범위의 차이의 절대값을 이분 탐색 하는 경우 다음과 같다.

이 때 모든 범위를 탐색하지 않고, 입력받은 값 중 최소 ~ 최대 의 범위만 탐색한다.

```cpp
while (start <= end) {
  mid = (start + end) / 2;

  bool isPossible = checkRange(mid, minValue, maxValue);
  if (isPossible) {
    answer = min(answer, mid);
    end = mid - 1;
  } else {
    start = mid + 1;
  }
}
```

mid는 최소값과 최대 값의 차이의 절대값을 의미한다.

### range를 탐색

range의 경우 인자로 받은 범위의 차의 절대값을 기준 탐색한다.

```cpp
bool checkRange(int limit, int minVal, int maxVal) {
  for (int val = minVal; val <= maxVal; val++) {
    if (canVisit(val, val + limit)) {
      return true;
    }
  }
  return false;
}
```

### 시작점과 끝점 투 포인터

만약 limit을 이분탐색 하는 것이 아닌, 시작점과 끝 점을 투 포인터로 탐색하는 경우 다음과 같이 구현할 수 있다.

```cpp
start = 0;
end = 0;

while (start <= end) {
  bool isPossible = canVisit(start, end);
  if (isPossible) {
    answer = min(answer, end - start);
    start++;
  } else if (end < 201) {
    end++;
  } else {
    break;
  }
}
```

이 경우 시간 복잡도는 start의 이동 횟수, end의 이동 횟수 를 더한 400이다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      48      |       8        |

## 고생한 점
