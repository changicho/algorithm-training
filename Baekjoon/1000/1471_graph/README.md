# 1471. 사탕 돌리기

[링크](https://www.acmicpc.net/problem/1471)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   46.429    |

## 설계

### 시간 복잡도

N은 200,000보다 작거나 같은 자연수이다.

브루트 포스 방법을 사용할 경우, 각 index마다 시뮬레이션을 돌려야 한다.

이 경우 시간 복잡도는 최악의 경우 N^2이며 이는 제한시간 2초 내에 불가능하다.

따라서 동적 계획법을 이용해 시간복잡도를 줄인다.

### 공간 복잡도

N은 최대 200,000 까지 이므로 정답 또한 이 이하의 자연수임이 보장된다.

따라서 int형으로 선언한다.

### 그래프 탐색

모든 공간을 시작점으로 두고 탐색을 이어나간다.

이 때 시작점을 1부터 두고 탐색했을 때, 앞으로 더 많은 칸을 방문할 수 있다.

(1부터 시작하는 경우가 다음 단계 index로 증가하는 값이 제일 작다)

이 때, 탐색을 진행하며 해당 칸에 이전에 사탕이 채워진 흔적이 있는 경우 더이상 탐색을 지속하지 않는다.

배열 arr과 dp는 다음을 의미한다.

```cpp
// steps[index] : 사탕 통에서 index번째에서 이동해야 하는 다음 칸의 개수
// counts[index] : 사탕 통에서 index 번째에서 들어있는 사탕의 개수
```

탐색을 진행하며 해당 칸을 방문했음을 체크한다. 그리고 이동할 다음 칸을 계산한다.

만약 이동할 다음 칸이 이전에 방문한 경우, counts 배열을 갱신한다.

이 때 counts 배열을 채울 때는 지금까지 거쳐온 index들을 역순으로 되돌아 가야 하기 때문에 steps 값을 이용한다.

그 후에 counts 배열의 값들을 전부 현재 index의 counts로 갱신한다.

이는 해당 counts를 통과하는 경로에서 놓을 수 있는 사탕의 개수는 모두 같기 때문이다.

```cpp
int count = next;
while (count != index) {
  counts[index]++;
  count = steps[count];
}

count = next;
while (count != index) {
  counts[count] = counts[index];
  count = steps[count];
}
```

만약 방문하지 않은 경우에는 재귀함수를 다음으로 이동할 index로 호출한다.

그 후에 현재 index에서 사탕의 개수가 갱신된 경우 현재 index의 counts를 갱신한다.

```cpp
int recursive(int index) {
  if (counts[index] != -1) return counts[index];

  visited[index] = true;
  int next = index;

  for (char c : to_string(index)) {
    next += c - '0';
  }

  if (next > N) next -= N;
  steps[index] = next;

  if (visited[next]) {
    if (counts[next] != -1) return counts[index] = counts[next] + 1;
    counts[index] = 1;

    int count = next;
    while (count != index) {
      counts[index]++;
      count = steps[count];
    }

    count = next;
    while (count != index) {
      counts[count] = counts[index];
      count = steps[count];
    }

    return counts[index];
  }

  recursive(next);

  if (counts[index] == -1) return counts[index] = recursive(next) + 1;

  return counts[index];
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      8       |       4        |

## 고생한 점
