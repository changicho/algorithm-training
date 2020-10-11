# 15686. 치킨 배달

[링크](https://www.acmicpc.net/problem/15686)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   40.949    |

## 설계

### 시간 복잡도

모든 경우를 체크해야한다.

이 떄 치킨집을 고르는 경우의 수는 최악의 경우 2^13 이다.

각 경우의 수 마다 모든 집에서 거리를 구해야 하므로, 집의 개수는 최대 100개 이므로

총 시간 복잡도는

```cpp
2^13 * 100 = 819,200
```

으로 제한시간 내에 충분하다.

### 공간 복잡도

최악의 경우 정답은 모든 집이 2N만큼의 거리를 가지는 경우이다.

```cpp
13 * 50 * 2
```

이므로 이는 int형으로 충분하다.

### 치킨집 선택

next_permutation을 이용해 조합을 구현한다.

남길 치킨집의 수는 총 치킨집의 수 이하임이 보장되므로 bool형식의 vector를 만들고

M개 만큼만 true를 선언한 뒤, 나머지는 false로 할당한다.

이후 next_permutation을 통해 모든 경우를 탐색한다.

```cpp
do {
  int totalDistance = 0;
  for (Axis home : homes) {
    int count = 50 * 50;

    for (int i = 0; i < visited.size(); i++) {
      if (!visited[i]) continue;

      count = min(count, getDistance(home, chickens[i]));
    }
    totalDistance += count;
  }

  answer = min(answer, totalDistance);
} while (next_permutation(visited.begin(), visited.end()));
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
