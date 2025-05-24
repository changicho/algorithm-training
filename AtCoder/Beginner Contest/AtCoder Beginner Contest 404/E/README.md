# E - Bowls and Beans

[링크](https://atcoder.jp/contests/abc404/tasks/abc404_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

맨 뒤에 있는 콩 부터 시작해 앞으로 옮긴다.

이 때 탐욕 알고리즘을 사용해 선택 가능한 가장 최선의 방법을 선택할 수 있다.

각 index마다 다음 위치를 최대 N번 탐색할 수 있다.

따라서 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

콩이 존재하는 위치를 저장하는 배열에 O(N)의 공간 복잡도를 가진다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |    O(N)     |

맨 뒤의 콩부터 이동시키며 콩을 모아 한번에 이동시킬 수 있다.

콩을 이동시키는 갯수는 제한이 없으며, 한번에 하나의 위치로 이동할 수 있기 때문이다.

이 때 현재 콩이 이동할 수 있는 다음 왼쪽 위치 중 콩이 존재할 경우 해당 위치에 콩을 이동한다.

해당 콩들을 모아 한꺼번에 이동하는 편이 더 유리하다.

콩이 없는 경우 다음 이동에서 가장 왼쪽으로 이동할 수 있는 위치로 이동한다.

```cpp
int solution(int size, vector<int> &dist, vector<int> &arr) {
  int answer = 0;

  for (int i = size - 1; i >= 1; i--) {
    if (arr[i] == 0) continue;

    int c = dist[i];
    int target = max(i - c, 0);
    for (int j = i - 1; j >= max(i - c, 0); j--) {
      int next = j - dist[j];

      if (arr[j] > 0) {
        target = j;
        break;
      }

      if (next < target - dist[target]) {
        target = j;
      }
    }

    answer++;
    arr[target] += arr[i];
  }

  return answer;
}
```

## 고생한 점
