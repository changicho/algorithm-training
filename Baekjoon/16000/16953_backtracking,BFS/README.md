# 16953. A → B

[링크](https://www.acmicpc.net/problem/16953)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   43.081    |

## 설계

### 시간 복잡도

A, B (1 ≤ A < B ≤ 10^9) 가 주어진다.

하나의 수에서 두가지 경우의 탐색이 가능하다.

- 2를 곱한다.
- 1을 수의 가장 오른쪽에 추가한다.

이 때 이전에 탐색한 수를 다시 탐색하는 경우는 건너뛰어야 한다. (최소 연산의 수를 구해야 하므로 정답이 절대 아님)

따라서 백트래킹을 이용해 시간복잡도를 줄인다.

제한시간 2초

### 공간 복잡도

입력받는 A와 B는 10^9 이며 int형의 범위는 2,147,483,647 까지이다.

따라서 1을 수의 가장 오른쪽에 추가하는 연산의 경우 overflow가 발생한다.

그러므로 long long 형으로 관리한다.

### 탐색

이전에 방문한 수를 체크하기 위해서 int형 배열을 선언하는 경우 크기가 10^9 이므로 메모리를 초과한다.

모든 수가 필요하지 않으므로 map을 이용해 체크한다.

```cpp
while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.number == B) {
    answer = cur.depth;
    break;
  }
  if (counts[cur.number] != 0) continue;
  counts[cur.number] = cur.depth;

  if (cur.number * 2 <= B) {
    q.push({cur.number * 2, cur.depth + 1});
  }
  if (cur.number * 10 + 1 <= B) {
    q.push({cur.number * 10 + 1, cur.depth + 1});
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      16      |       0        |

## 고생한 점
