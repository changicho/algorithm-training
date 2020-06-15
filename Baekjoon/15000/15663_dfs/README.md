# 15663. N과 M (9)

[링크](https://www.acmicpc.net/problem/15663)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   48.629    |

## 설계

### 시간 복잡도

모든 정답의 경우를 생성하는 최악의 경우

N과 M이 최대이고 모든 수가 다를 때 8! 이므로 40320 이다.

이는 제한시간 내에 충분하다.

### 공간 복잡도

각 숫자의 크기는 10,000 이내이므로 int형으로 선언한다.

dfs 탐색을 위해 visited 배열을 선언한다.

### dfs 탐색

정답을 오름차순으로 정렬해 출력해야 한다.

따라서 입력받은 숫자들을 미리 오름차순으로 정렬하고 탐색한다.

이 때 각 자리수를 정할 때, 이전에 탐색한 수와 현재 탐새한 수가 중복되는 경우는 삭제해야 한다.

예를 들어 현재 9, 9, 9 를 고를 수 있을 때

세 수를 각각 골라도 모두 같은 수 이므로, 중복된 결과가 생성된다.

따라서 이를 제거해야함.

```cpp
void dfs(int index) {
  if (index == M) {
    for (int i : answer) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  int prev = -1;
  for (int i = 0; i < N; i++) {
    if (visited[i] || prev == arr[i]) continue;

    visited[i] = true;
    prev = arr[i];
    answer[index] = arr[i];

    dfs(index + 1);

    visited[i] = false;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       0        |

## 고생한 점

new line을 endl로 출력했더니 같은 알고리즘에서 시간이 700ms 이상 소요됨
