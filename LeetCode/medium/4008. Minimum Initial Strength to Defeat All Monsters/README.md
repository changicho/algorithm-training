# 4008. Minimum Initial Strength to Defeat All Monsters

[링크](https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

몬스터 배열의 크기를 N, 부스트 배열의 크기를 M, 가능한 정답의 최대값을 K라 하자.

범위에 대한 부스트를 diff array로 관리할 경우 O(N + M)의 시간 복잡도를 사용한다.

각 시작점마다 가능한지 판단하는데 O(N)의 시간 복잡도를 사용한다.

이를 이분 탐색으로 구할 경우 O(N \* log_2(K) + M)의 시간 복잡도를 사용한다.

혹은 역순회로 시작점을 복구할 수 있다. 이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

diff array에 O(N)의 공간 복잡도를 사용한다.

### diff array & 이분 탐색

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     147      | O(N \* log_2(K) + M) |    O(N)     |

각 index마다 버프의 증감을 미리 배열에 저장 후 특정 점수에 따른 가능 여부를 체크한다.

이를 가능한 범위에 대해 이분 탐색을 통해 탐색한다.

```cpp
bool check(vector<int>& monsters, vector<long long> diffs, long long start) {
  int size = monsters.size();
  long long cur = start;
  long long diff = 0;
  for (int i = 0; i < size; i++) {
    diff += diffs[i];

    if (monsters[i] > cur + diff) return false;
    cur -= monsters[i];
    cur = max(cur, 0LL);
  }
  return true;
}

long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
  int size = monsters.size();

  long long left = 0, right = 50000000000001;

  vector<long long> diffs(size + 2, 0);
  for (vector<int>& b : boosts) {
    diffs[b[0]] += b[2];
    diffs[b[1] + 1] -= b[2];
  }

  long long answer = -1;
  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (check(monsters, diffs, mid)) {
      // pick left

      answer = mid;
      right = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }

  return answer;
}
```

### diff array & 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(N + M)   |    O(N)     |

조건에 따라 역순회로 가능한 최소의 시작점을 복구한다.

```cpp
long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
  int size = monsters.size();

  vector<long long> diffs(size + 2, 0);
  for (vector<int>& b : boosts) {
    diffs[b[1]] += b[2];
    if (b[0] - 1 >= 0) {
      diffs[b[0] - 1] -= b[2];
    }
  }

  long long answer = 0;
  long long diff = 0;
  for (int i = size - 1; i >= 0; i--) {
    diff += diffs[i];

    if (answer > 0) {
      answer += monsters[i];
    } else {
      answer = max(0LL, (long long)monsters[i] - diff);
    }
  }

  return answer;
}
```

## 고생한 점
