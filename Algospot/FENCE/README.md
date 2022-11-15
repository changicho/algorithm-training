# 알고스팟. 울타리 잘라내기

[링크](https://www.algospot.com/judge/problem/read/FENCE)

| 정답률 |
| :----: |
|  32%   |

## 설계

### 시간 복잡도

입력받은 울타리의 길이를 N이라 하자.

가능한 최대 정사각형의 크기를 계산하기 위해 분할 정복을 사용할 수 있다.

이 경우 각 범위마다의 중점을 기준으로 탐색을 이어간다.

이 경우 분할하는 횟수에 O(log_2(N))의 시간 복잡도를, 각 분할의 단계마다 탐색에 총 O(N)의 시간 복잡도를 사용한다.

이는 머지소트와 유사하게 분할한다.

따라서 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

울타리정보를 저장하는데 O(N)의 공간 복잡도를 사용한다.

재귀 호출의 call stack에 O(log_2(N))의 공간 복잡도를 사용한다.

따라서 총 O(N)의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      72      | O(N \* log_2(N)) |    O(N)     |

현재 검사하고자 하는 범위를 left ~ right 라고 하자.

현재 범위에 대해서 정답은 다음 3가지중 한군데에 걸쳐있다.

- left ~ right
- left ~ mid
- (mid + 1) ~ right

현재 범위에 대해서 정답을 찾는 경우를 생각해보자.

우선 중앙에 위치한 값을 탐색할 투 포인터로 각각 설정한다.

각 중앙에 위치한 두 점을 현재 범위에 대해 탐색을 진행해 나간다.

이 때 왼쪽과 오른쪽에 위치한 값 중에서 더 큰 높이를 선택하며 탐색을 진행한다.

각 과정마다 높이를 방문한 높이들 중 가장 작은 높이로 갱신한다. (각 울타리에서 현재 width에 대해 면적은 가장 낮은 높이에 대해서만 구할 수 있음)

갱신한 높이와 width를 이용해 넓이를 갱신한다.

```cpp
int recursive(int left, int right, vector<int> &trees) {
  if (left == right) return trees[left];
  int mid = left + (right - left) / 2;

  int ret = max(recursive(left, mid, trees), recursive(mid + 1, right, trees));
  int lo = mid, hi = mid;
  int height = trees[mid];
  ret = max(ret, height);

  while (left < lo || hi < right) {
    if (hi < right && (lo == left || trees[lo - 1] < trees[hi + 1])) {
      hi++;
      height = min(height, trees[hi]);
    } else {
      lo--;
      height = min(height, trees[lo]);
    }
    ret = max(ret, height * (hi - lo + 1));
  }
  return ret;
}

int solution(vector<int> &trees) {
  int size = trees.size();

  return recursive(0, size - 1, trees);
}
```

## 고생한 점
