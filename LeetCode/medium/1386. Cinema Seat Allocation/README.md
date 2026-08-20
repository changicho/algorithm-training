# 1386. Cinema Seat Allocation

[링크](https://leetcode.com/problems/cinema-seat-allocation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N, 배열의 크기를 M이라 하자.

N은 10^9까지 이므로 N개의 열을 모두 순회하면 제한시간 내에 불가능하다.

각 배열의 좌표를 순회하며 해당 열마다 좌표들을 저장한다.

이후 좌표가 존재하는 열만 순회하며 정답을 갱신한다.

이에 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표를 열별로 저장하는데 O(M)의 공간 복잡도를 사용한다.

### bitmask

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |    O(M)     |    O(M)     |

각 좌표들을 존재하는 열마다 묶어 저장한다.

이후 좌표가 존재하는 열만 순회하며 해당 열에 최대 몇 그룹을 배치 가능한지 판단한다.

이를 위해 비트마스킹으로 판단하며, 양 끝부터 가능한지 우선적으로 판단한다.

주어진 N에 대해서 가능한 최대 정답쌍은 N \* 2개 이다.

여기에서 배치 불가능한 열의 그룹의 수를 뺀 값을 반환한다.

```cpp
int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
  long long answer = (long long)n * 2;

  unordered_map<int, vector<int>> um;

  // 01111000000, 0001111000, 0000011110
  vector<int> mask = {30, 120, 480};

  for (vector<int>& r : reservedSeats) {
    int y = r[0] - 1, x = r[1] - 1;

    um[y].push_back(x);
  }

  for (auto [key, val] : um) {
    int board = 0;

    for (int x : val) {
      board |= (1 << x);
    }

    int curCase = 0;
    for (int& bit : mask) {
      if ((board & bit) == 0) {
        curCase++;
        board += bit;
      }
    }

    answer -= 2 - curCase;
  }

  return answer;
}
```

## 고생한 점
