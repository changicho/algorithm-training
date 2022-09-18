# Problem B1: Watering Well - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/B1)

| 난이도 |
| :----: |
| 12 pt  |

## 설계

### 시간 복잡도

나무와 연못의 크기를 각각 N, Q라 하자.

이를 모두 순회할 경우 시간 복잡도는 O(N \* Q)이며 이는 N과 Q의 범위가 500,000 까지 이므로 제한시간 내에 불가능하다.

각 좌표의 길이는 최대 3,000 까지이다. 이를 L이라 하자.

좌표를 모두 순회하며 판단할 경우 O(L^4)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

x, y좌표에 대한 유클리드 길이를 각각 판단해 구할 수 있다.

이 경우 O(L^2)의 시간 복잡도로 풀이 가능하다.

### 공간 복잡도

y, x좌표에 대한 갯수를 미리 저장하고 구할 경우 O(L)의 공간 복잡도를 사용한다.

### 좌표 counting

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|   O(L^2)    |    O(L)     |

나무 A와 연못 B의 길이의 합은 다음과 같이 구한다.

- |Ax - Bx|^2 + |Ay - By|^2

이는 x좌표와 y좌표에 대해 분리해 생각할 수 있음을 의미한다.

따라서 이를 분리하고, 좌표의 범위가 적으므로 이를 각각 count한다.

이후 나무의 좌표, 연못의 좌표를 서로 순회하며 만약 두 좌표에 나무와 연못이 존재하는 경우 정답에 더한다.

이를 구현하면 다음과 같다.

```cpp
int getLength(Axis &a, Axis &b) {
  long long yDiff = abs(a.y - b.y);
  long long xDiff = abs(a.x - b.x);

  long long ret = (yDiff * yDiff) % MOD + (xDiff * xDiff) % MOD;
  ret %= MOD;
  return (int)ret;
}

int solution(int n, int q, vector<Axis> &trees, vector<Axis> &waters) {
  long long answer = 0;

  vector<int> treeXs(3001, 0), treeYs(3001, 0), waterXs(3001, 0),
      waterYs(3001, 0);

  for (Axis &tree : trees) {
    treeXs[tree.x]++;
    treeYs[tree.y]++;
  }

  for (Axis &water : waters) {
    waterXs[water.x]++;
    waterYs[water.y]++;
  }

  for (int wy = 0; wy <= 3000; wy++) {
    if (waterYs[wy] == 0) continue;

    for (int ty = 0; ty <= 3000; ty++) {
      if (treeYs[ty] == 0) continue;

      long long diff = abs(wy - ty);
      long long length = (diff * diff) % MOD;
      long long diffSum = (length * waterYs[wy] * treeYs[ty]) % MOD;

      answer += diffSum;
      answer %= MOD;
    }
  }

  for (int wx = 0; wx <= 3000; wx++) {
    if (waterXs[wx] == 0) continue;

    for (int tx = 0; tx <= 3000; tx++) {
      if (treeXs[tx] == 0) continue;

      long long diff = abs(wx - tx);
      long long length = (diff * diff) % MOD;
      long long diffSum = (length * waterXs[wx] * treeXs[tx]) % MOD;

      answer += diffSum;
      answer %= MOD;
    }
  }

  return answer % MOD;
}
```

## 고생한 점
