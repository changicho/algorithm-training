# B - Tombola

[링크](https://atcoder.jp/contests/abc437/tasks/abc437_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 H, 열의 갯수를 W, nums 배열의 길이를 N이라고 하자.

각 행마다 배열에 있는 원소의 수를 세야 한다. hash set을 이용할 경우 O(H \* W + N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      1       | O(H \* W + N) |    O(N)     |

행의 숫자들 중 nums 배열에 포함된 숫자의 개수를 세야 한다.

nums의 원소를 hash set에 저장한 뒤, 각 행을 순회하며 hash set에 포함된 숫자의 개수를 센다.

```cpp
int solution(vector<vector<int>>& board, vector<int>& nums) {
  int height = board.size();
  int width = board[0].size();

  unordered_set<int> numSet(nums.begin(), nums.end());
  int answer = 0;

  for (int y = 0; y < height; y++) {
    int count = 0;
    for (int x = 0; x < width; x++) {
      if (numSet.count(board[y][x]) > 0) {
        count++;
      }
    }

    answer = max(answer, count);
  }

  return answer;
}
```

## 고생한 점
