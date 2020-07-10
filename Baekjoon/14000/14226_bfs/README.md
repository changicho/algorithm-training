# 14226. 이모티콘

[링크](https://www.acmicpc.net/problem/14226)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   33.926    |

## 설계

### 시간 복잡도

이모티콘의 길이와 클립보드의 길이는 각각 0~1001 까지이다.

1001 까지인 경우는 1000을 만들기 위해 1001 - 1 을 수행할 수 있기 때문이다.

따라서 중복을 제외하고 가능한 최악의 경우는

```cpp
1001^2 = 1,002,001
```

이므로 제한시간 내에 충분하다.

### 공간 복잡도

중복을 제거하기 위해 2차원 bool 배열을 선언한다.

이 배열의 크기는 1,002,001 이다.

이모티콘의 크기와 클립보드는 전부 1001 이하의 수 이므로 int형으로 선언한다.

### BFS

이모티콘의 길이, 클립보드의 길이, 연산의 수를 기록하는 구조체를 만든다.

```cpp
struct Status {
  int screen, clip, count;
};
```

BFS를 수행하면서, screen과 clip이 범위를 넘어서는지 항상 checking 한다.

각 경우별로 q에 push한다.

- 클립보드를 이모티콘에 복사
- 이모티콘을 클립보드에 복사
- 하나 지우기

```cpp
while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.screen == S) {
    answer = cur.count;
    break;
  }

  if (cur.screen < 0 || cur.clip < 0) continue;
  if (cur.screen > 1001 || cur.clip > 1001) continue;
  if (visited[cur.screen][cur.clip]) continue;
  visited[cur.screen][cur.clip] = true;

  q.push({cur.screen, cur.screen, cur.count + 1});
  q.push({cur.screen + cur.clip, cur.clip, cur.count + 1});
  q.push({cur.screen - 1, cur.clip, cur.count + 1});
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
