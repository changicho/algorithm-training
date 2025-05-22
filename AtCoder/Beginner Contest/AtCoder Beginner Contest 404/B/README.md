# B - Grid Rotation

[링크](https://atcoder.jp/contests/abc404/tasks/abc404_b)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 2차원 정방 배열의 한 변의 크기를 N이라 하자.

각 회전에 대해서 다른 부분을 비교할 수 있다.

이 경우 회전에 O(N^2)의 시간 복잡도를 사용한다.

각 좌표별로 모두 비교하는 데 O(N^2)의 시간 복잡도를 사용한다.

각 경우마다 비교, 회전을 4번 수행하므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

회전 배열에 O(N^2)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |   O(N^2)    |

특정 좌표들을 변환 후 회전을 반복하는 경우보다 우선 회전한 뒤 좌표들을 변환하는 방법이 더 유리하다.

따라서 각 회전마다 s와 t의 다른 좌표들을 세 정답을 구한다.

```cpp
vector<string> rotate(vector<string> &s) {
  int size = s.size();
  vector<string> rotated(size, string(size, '.'));

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      rotated[x][size - 1 - y] = s[y][x];
    }
  }

  return rotated;
}

int findDiff(vector<string> &s, vector<string> &t) {
  int size = s.size();
  int diff = 0;

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (s[y][x] != t[y][x]) {
        diff++;
      }
    }
  }

  return diff;
}

int solution(int size, vector<string> &s, vector<string> &t) {
  int answer = size * size;

  for (int i = 0; i < 4; i++) {
    int diff = findDiff(s, t);
    answer = min(answer, diff + i);
    s = rotate(s);
  }

  return answer;
}
```

## 고생한 점
