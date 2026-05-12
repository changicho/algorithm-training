# D - Raise Minimum

[링크](https://atcoder.jp/contests/abc457/tasks/abc457_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열의 크기를 N, 연산 횟수를 K라 하자.

K가 매우 크므로 우선순위 큐를 이용해 직접 시뮬레이션 할 경우 제한시간 내에 불가능하다.

이분 탐색을 이용해 정답을 구할 경우 O(N \* log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색에 별도의 공간 복잡도를 사용하지 않는다.

각 숫자가 매우 크므로 long long형을 사용한다.

ceil연산에서 초과가 발생할 수 있으므로 이를 보정해서 연산한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      59      | O(N \* log_2(K)) |    O(1)     |

현재 배열과 K를 이용해 최소값이 target이상이 가능한지 판단하는 함수를 생성한다.

이후 target을 이분탐색을 수행하며 최대값을 검색한다.

```cpp
bool check(vector<ll>& nums, ll k, ll target) {
  int size = nums.size();
  ll count = 0;

  for (int i = 0; i < size; i++) {
    ll num = nums[i];

    if (num > target) continue;
    ll diff = target - num;

    ll curCount = (diff + i) / (i + 1);
    count += curCount;
    if (count > k) return false;
  }
  return true;
}

ll solution(int size, ll k, vector<ll>& nums) {
  if (size == 1) {
    return nums[0] + k;
  }

  ll answer = 0;
  ll left = 0, right = LLONG_MAX;

  while (left < right) {
    ll mid = (left) + (right - left) / 2;

    if (check(nums, k, mid)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
