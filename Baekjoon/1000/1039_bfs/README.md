# 1039. 교환

[링크](https://www.acmicpc.net/problem/1039)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |   20.191    |

## 설계

### 시간 복잡도

각 자리 숫자를 K번 바꿀 수 있다. 이는 최대 10번이다.

N은 1,000,000 이하의 자연수이다. 자리수는 최대 7 이다.

각 자리를 바꿀 수 있는 경우는 (7X6)/2 = 21번 이다.

완전 탐색을 수행하는 경우 21^7 번을 수행해야 하며 이는 제한시간 내에 불가능하다.

따라서 BFS로 탐색을 진행하며, backtracking 하며 탐색을 수행한다.

- 중복되는 경우 제거
- 불가능한 경우 제거

### 공간 복잡도

각 자리의 교환을 편하게 하기 위해 문자열로 숫자를 입력받는다.

K번 교환할 수 있으므로, 현재 몇 번째 교환인지 체크하기 위한 count_K를 선언한다.

현재 숫자에서 교환을 수행했을 때 이전에 만든 수 (중복) 체크를 위한 배열을 선언한다.

1,000,000 까지 만들 수 있으므로 bool visited[1000001] 과 같이 선언한다

### 불가능한 경우

N이 한 자리 수 이거나, 두 자리이며 10의 배수인 경우 교환이 불가능하다.

또한 K번 교환을 수행하지 못하고 탐색이 끝난 경우도 교환이 불가능한 경우이다.

### BFS

현재 K번 숫자를 교환한다고 했을 때, 이 때 만들 수 있는 숫자들이 중복된 경우는 예외 처리를 해야한다.

이 때 K가 갱신될 때마다 중복을 초기화 해야 함에 유의한다.

따라서 BFS는 다음과 같다.

```cpp
int count_K = 0
while(!q.empty()){
  count_K++;

  for(int q_size = q.size(); q_size > 0; q_size--){
    string cur = q.front();
    q.pop();

    // 탐색
  }
}
```

탐색의 경우 다음과 같다.

```cpp
// 교환할 두 수를 찾는다
for (int from = 0; from < length; from++) {
  for (int to = from + 1; to < length; to++) {
    // 불가능한 경우 제외
    if (from == 0 && cur[to] == '0') continue;

    swap(cur[from], cur[to]);

    // 이미 방문한 수이면 제외
    if (visited[stoi(cur)]) {
      swap(cur[from], cur[to]);
      continue;
    }

    // K번 교환한 수 이면 정답 갱신
    if (count_K == K) {
      answer = max(answer, stoi(cur));
    }

    q.push(cur);
    visited[stoi(cur)] = true;

    swap(cur[from], cur[to]);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점

greedy한 방법으로 풀이하려 했으나 포기함
