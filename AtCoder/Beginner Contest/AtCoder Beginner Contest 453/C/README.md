# C - Sneaking Glances

[링크](https://atcoder.jp/contests/abc453/tasks/abc453_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS로 완전 탐색을 수행할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(2^N)    |    O(N)     |

시작 위치부터 각 값을 왼쪽, 오른쪽으로 이동하는 모든 경우를 탐색한다.

```cpp
int answer = 0;

bool isToggled(double a, double b) {
  if (a < 0 && b > 0) return true;
  if (a > 0 && b < 0) return true;
  return false;
}

void recursive(int i, vector<int>& nums, double cur, int count) {
  if (i == nums.size()) {
    answer = max(answer, count);
    return;
  }

  double length = nums[i];

  double left = cur - length;
  double right = cur + length;

  recursive(i + 1, nums, left, count + isToggled(cur, left));
  recursive(i + 1, nums, right, count + isToggled(cur, right));
}

int solution(int size, vector<int>& nums) {
  recursive(0, nums, 0.5, 0);

  return answer;
}
```

## 고생한 점
