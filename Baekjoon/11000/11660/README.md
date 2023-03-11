# 11660. 구간 합 구하기 5

[링크](https://www.acmicpc.net/problem/11660)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| 실버 I |   45.556    |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 크기를 N^2, 쿼리의 갯수를 M 이라 하자.

각 쿼리마다 직접 구간의 합을 구할 경우 O(M \* N^2)의 시간 복잡도를 사용한다.

각 구역의 합을 미리 구해놓고 쿼리마다 수행할 경우 O(N^2 + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 구간의 합을 미리 구해놓기 위해서 O(N^2)의 공간 복잡도를 사용한다.

## 구간 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     132      | O(N^2 + M)  |   O(N^2)    |

각 구간까지의 합을 구하기 위해 다음과 같은 배열을 생성한다.

```cpp
int memo[y][x]; // (0,0)~(y,x) 까지의 합을 나타낸다.
```

이를 이용해 (y1,x1) ~ (y2,x2)까지의 구간의 합은 다음과 같이 구할 수 있다.

(y2 >= y1 && x2 >= x1)

```cpp
memo[y2][x2] - memo[y2][x1] - memo[y1][x2] + memo[y1][x1]
```

이는 0,0에서부터 각 구역에서 구하고자 하는 영역에 포함되는 부분과 포함되지 않는 부분을 미리 구해놓기 때문이다.

이를 이용해 구현하면 다음과 같다.

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[1026][1026];
int memo[1026][1026];

void solution() {
  int N, M;
  cin >> N >> M;

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= N; x++) {
      cin >> arr[y][x];

      memo[y][x] = arr[y][x] + memo[y][x - 1] + memo[y - 1][x] - memo[y-1][x-1];
    }
  }

  for (int i = 0; i < M; i++) {
    int x1, x2, y1, y2; // n1 < n2
    cin >> x1 >> y1 >> x2 >> y2;

    int answer = memo[x2][y2] - memo[x1 - 1][y2] - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1];

    cout << answer << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}
```

## 고생한 점

문제에서 주어지는 x와 y의 순서가 일반적으로 생각하는 arr의 y,x와 반대이다
