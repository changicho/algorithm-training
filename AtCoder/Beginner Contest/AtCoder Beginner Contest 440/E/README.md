# E - Cookies

[링크](https://atcoder.jp/contests/abc440/tasks/abc440_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

배열의 원소의 수를 N, 정하는 수의 갯수를 K, 구해야 하는 합의 조합의 수를 X라 하자.

그리디 알고리즘을 사용해 매번 가장 큰 값을 선택해야 한다.

이를 위해 배열의 원소를 정렬 후 사용한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 우선순위 큐를 이용해 가장 큰 값을 선택하며 해당 수의 조합의 수는 N \* X개가 될 수 있다.

따라서 총 시간 복잡도는 O(NX \* log_2(NX))가 된다.

### 공간 복잡도

우선순위 큐에 O(NX)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      14      | O(NX \* log_2(NX)) |    O(NX)    |

배열의 원소를 내림차순 순으로 정렬한다.

가능한 가장 큰 조합은 가장 큰 배열의 원소를 K번 더한 값이다.

그 다음 작은 조합은 가장 큰 배열의 원소를 K-1번 더하고 두 번째로 큰 배열의 원소를 한 번 더한 값이다.

그 다음 작은 조합은 두 경우 중 하나이다.

- 가장 큰 배열의 원소를 K-2번 더하고 두 번째로 큰 배열의 원소를 한 번 더한 값
- 가장 큰 배열의 원소를 K-1번 더하고 세 번째로 큰 배열의 원소를 한 번 더한 값

즉 각 경우마다 현재 사용할 수 있는 가장 큰 원소의 index와 직전에 더한 원소를 수정 가능한지 여부를 함께 저장하며 우선순위 큐에 넣는다.

```cpp
struct Status {
  long long value;
  int index;
  int before;
  int current;

  bool operator<(const Status& other) const { return value < other.value; }
};

vector<long long> solution(int size, vector<long long>& nums, int k, int x) {
  vector<long long> answer;

  sort(nums.begin(), nums.end(), greater<long long>());

  priority_queue<Status> q;
  q.push({nums[0] * k, 0, 0, k});

  while (!q.empty() && answer.size() < x) {
    auto [value, index, before, current] = q.top();
    q.pop();

    answer.push_back(value);

    if (before) {
      q.push({value - nums[index - 1] + nums[index], index, before - 1,
              current + 1});
    }
    if (index != size - 1) {
      q.push(
          {value - nums[index] + nums[index + 1], index + 1, current - 1, 1});
    }
  }

  return answer;
}
```

## 고생한 점
