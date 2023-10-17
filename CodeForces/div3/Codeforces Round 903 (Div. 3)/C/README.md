# C. Perfect Square

[링크](https://codeforces.com/contest/1881/problem/C)

## 설계

### 시간 복잡도

입력받은 변의 크기를 N이라 하자.

이동 할 수 있는 좌표들은 4개가 한 쌍이며 이 쌍들을 순회하는데 O(N^2)의 시간 복잡도를 사용한다.

이동 시에도 각 쌍이 같아져야 하는 경우는 모두 같은 문자인 경우이므로 각 쌍마다 같은 문자로 변환하는데 O(1)의 시간 복잡도를 사용한다.

따라서 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표만 순회할 경우 O(1)의 공간 복잡도를 사용한다.

### 좌표 계산

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(N^2)    |    O(1)     |

이동하는 4개의 좌표가 이동 후에도 같기 위해선 모두 같은 문자여야만 한다.

이 때 각 문자들은 증가시킬수만 있으므로 해당 4개의 문자중에서 가장 큰 값으로 통일한다.

이를 각 좌표 묶음들마다 반복한다.

```cpp
int solution(int size, vector<string> &board) {
  int answer = 0;

  for (int y = 0; y < size / 2; y++) {
    for (int x = 0; x < size / 2; x++) {
      // y x
      // x size-1-y
      // size-1-y size-1-x
      // size-1-x y
      vector<char> arr = {board[y][x], board[x][size - 1 - y],
                          board[size - y - 1][size - 1 - x],
                          board[size - x - 1][y]};
      char max = *max_element(arr.begin(), arr.end());

      int count = 0;
      for (char &c : arr) {
        count += max - c;
      }

      answer += count;
    }
  }

  return answer;
}
```

## 고생한 점
