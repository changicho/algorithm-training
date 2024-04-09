# B - Farthest Point

[링크](https://atcoder.jp/contests/abc348/tasks/abc348_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 점의 수를 N이라 하자.

각 점마다 가장 멀리 떨어진 점을 직접 탐색해 계산할 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |    O(N)     |

각 점마다 가장 멀리 떨어진 다른 점을 구한다.

```cpp
struct Axis {
  int y, x;
};

long long getDist(Axis &a, Axis &b) {
  return (long long)(a.x - b.x) * (a.x - b.x) +
         (long long)(a.y - b.y) * (a.y - b.y);
}

vector<int> solution(int size, vector<Axis> &axises) {
  vector<int> ret;

  for (int i = 0; i < size; i++) {
    long long dist = 0;
    int target = -1;

    for (int j = 0; j < size; j++) {
      if (i == j) continue;

      long long temp = getDist(axises[i], axises[j]);

      if (temp > dist) {
        dist = temp;
        target = j;
      }
    }

    ret.push_back(target + 1);
  }

  return ret;
}
```

## 고생한 점
