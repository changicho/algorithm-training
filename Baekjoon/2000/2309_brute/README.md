# 2309. 일곱 난쟁이

[링크](https://www.acmicpc.net/problem/2309)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Bronze II |   44.615    |

## 설계

### 시간 복잡도

입력되는 숫자의 수는 9개이다. 모든 경우를 탐색했을 때 경우의 수는 2^9 이다.

이는 제한시간 내에 충분하다.

### 공간 복잡도

입력받는 모든 수는 100 이하이다. 따라서 int형으로 선언해도 충분하다.

### 완전 탐색

next_permutation을 이용해 가능한 조합을 탐색한다.

```cpp
vector<bool> visited = {0, 0, 1, 1, 1, 1, 1, 1, 1};
sort(visited.begin(), visited.end());

do {
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    if (!visited[i]) continue;
    sum += arr[i];
  }

  if (sum == 100) {
    for (int i = 0; i < 9; i++) {
      if (!visited[i]) continue;
      cout << arr[i] << "\n";
    }
    break;
  }
} while (next_permutation(visited.begin(), visited.end()));

```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
