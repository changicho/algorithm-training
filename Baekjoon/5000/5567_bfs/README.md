# 5567. 결혼식

[링크](https://www.acmicpc.net/problem/5567)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   42.612    |

## 설계

### 시간 복잡도

결국 모든 사람을 방문하는 경우가 최악이므로, 최악의 시간 복잡도는

```cpp
N = 500
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

사람의 번호는 500까지 이므로 int형으로 충분하다

### BFS

각 사람마다 1번과 촌수를 표시하기 위해 struct를 사용한다.

```cpp
struct Status {
  int index, count;
};
```

bfs에서 탐색을 건너 뛰는 경우는 다음과 같다

```cpp
if (visited[cur.index]) continue;
if (cur.count > 2) continue;
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
