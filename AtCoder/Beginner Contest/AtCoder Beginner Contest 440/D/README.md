# D - Forbidden List 2

[링크](https://atcoder.jp/contests/abc440/tasks/abc440_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열의 원소의 갯수를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 범위에 속하는 nums의 값을 찾아야 한다.

nums를 정렬 하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 각 쿼리마다 이분 탐색을 사용하여 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + Q) \* log_2(N))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     144      | O((N + Q) \* log_2(N)) |    O(N)     |

각 쿼리마다 구간 (X) ~ (X + Y - 1)에 속하는 nums의 원소의 개수를 구해야 한다.

만약 해당 구간에 속하는 값이 존재하는 경우, 해당 갯수만큼 구간을 변경하며 다시 구간에 속하는 nums의 원소의 개수를 구해야 한다.

이를 이분 탐색으로 구할 수 있다.

(구간에 속하는 원소의 수) - (구간이 변경되며 속하는 원소의 수)가 Y 이상이 되는 최초의 위치를 이분 탐색으로 찾으면 된다.

```cpp
struct Query {
  int x, y;
};

int calc(vector<int>& nums, int x, int y) {
  int size = nums.size();

  int s = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

  int left = s, right = size, target = size;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] - x - mid + s >= y) {
      target = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return target - s;
}

vector<int> solution(int size, vector<int>& nums, int qSize, vector<Query>& queries) {
  vector<int> answer;

  sort(nums.begin(), nums.end());

  for (Query& query : queries) {
    int x = query.x;
    int y = query.y;

    int buffer = calc(nums, x, y);
    int cur = x + y - 1 + buffer;

    answer.push_back(cur);
  }

  return answer;
}
```

## 고생한 점
