# 1140. Stone Game II

[링크](https://leetcode.com/problems/stone-game-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 piles의 크기를 N이라 하자.

현재 pile을 선택한 상황은 (bob 혹은 alice), index, m 이렇게 총 2 * N^2가지 경우이다.

따라서 해당 경우에 대한 메모이제이션을 진행한다.

각 경우마다 다음 값으로 갱신하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^3)이다.

### 공간 복잡도

메모이제이션을 사용하는데 O(N^2)의 공간 복잡도를 사용한다.

### 메모이제이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^3)    |   O(N^2)    |

재귀함수 호출을 통해 모든 경우를 탐색한다.

이 때 현재 상황에서 이전 상황으로 돌아갈 때마다 값이 갱신되므로 메모이제이션을 사용한다.

각 경우마다 현재 선택할 수 있는 2M개의 경우마다의 점수를 계산하고 이 중 제일 유리한 경우를 반환한다.

- 앨리스 : 선택한 경우중 앨리스의 점수의 합이 최대가 되는 경우
- 밥 : 선택한 경우들 중 앨리스의 점수의 합이 최소가 되는 경우

각 경우마다 앨리스가 얻는 점수를 반환하며 이를 통해 위 조건에 만족하는 경우를 찾는다.

```cpp
int size;
int dp[2][101][101];
vector<int> piles;

int recursive(bool isBob, int index, int m) {
  if (index == size) {
    return 0;
  }

  if (dp[isBob][index][m] != -1) {
    return dp[isBob][index][m];
  }

  int res = isBob ? INT_MAX : -1;
  int selected = 0;
  for (int next = index; next < size && (next - index + 1) <= 2 * m; next++) {
    selected += piles[next];

    int nextM = max(m, (next - index + 1));

    if (!isBob) {
      res = max(res, selected + recursive(true, next + 1, nextM));
    } else {
      res = min(res, recursive(false, next + 1, nextM));
    }
  }

  return dp[isBob][index][m] = res;
};

int stoneGameII(vector<int>& piles) {
  this->size = piles.size();
  this->piles = piles;

  memset(dp, -1, sizeof(dp));

  int answer = dp[false][0][1];
  return answer;
}
```

## 고생한 점
