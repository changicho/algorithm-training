# 9019. DSLR

[링크](https://www.acmicpc.net/problem/9019)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   22.315    |

## 설계

### 시간 복잡도

가능한 경우들을 탐색하며, 가장 먼저 가능한 명령이 나오면 출력하면 되므로 BFS를 이용한다.

이 때 0000 ~ 9999 까지 가능하고 각 경우마다 4개의 연산을 수행할 수 있다.

탐색을 진행하며 이미 방문한 숫자는 건너뛰어야한다.

### 공간 복잡도

숫자의 절대값은 9999까지이다 따라서 int형으로 충분하다.

명령들은 string으로 관리한다.

### BFS

시간복잡도가 매우 높으므로, 문제를 시간안에 해결하기 위해 함수로 분리하지 않고 한번에 전부 계산한다.

```cpp
while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.number == target) {
    answer = cur.commands;
    break;
  }

  int first = cur.number / 1000;
  int second = (cur.number % 1000) / 100;
  int third = (cur.number % 100) / 10;
  int fourth = cur.number % 10;

  int Dnumber = (cur.number * 2) % 10000;
  int Snumber = (cur.number - 1 + 10000) % 10000;
  int Lnumber = second * 1000 + third * 100 + fourth * 10 + first;
  int Rnumber = fourth * 1000 + first * 100 + second * 10 + third;

  if (!visited[Dnumber]) {
    visited[Dnumber] = true;
    q.push({Dnumber, cur.commands + "D"});
  }
  if (!visited[Snumber]) {
    visited[Snumber] = true;
    q.push({Snumber, cur.commands + "S"});
  }
  if (!visited[Lnumber]) {
    visited[Lnumber] = true;
    q.push({Lnumber, cur.commands + "L"});
  }
  if (!visited[Rnumber]) {
    visited[Rnumber] = true;
    q.push({Rnumber, cur.commands + "R"});
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     3704     |      520       |

## 고생한 점
