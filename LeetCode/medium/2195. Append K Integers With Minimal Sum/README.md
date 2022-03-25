# 2195. Append K Integers With Minimal Sum

[링크](https://leetcode.com/problems/append-k-integers-with-minimal-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, 입력받은 k를 K라고 하자.

브루트 포스 & 해시 셋을 이용할 경우 O(N + K)의 시간 복잡도를 사용하며 이 경우 K가 매우 크므로 제한시간 내에 불가능하다.

BST기반의 set, heap을 이용해 불가능한 경우만 정답에서 제거하고 O(N \* log_2(N))의 시간 복잡도로 풀이 가능하다.

혹은 BST set을 이용해 구간별 값만을 이용해 O(N \* log_2(N))의 시간 복잡도를 사용해 구현 가능하다.

### 공간 복잡도

heap, BST set에 O(N)의 공간 복잡도를 사용한다.

### BST set 구간 sum

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     399      | O(N \* log_2(N)) |    O(N)     |

nums의 원소를 정렬하고 unique한 값만 뽑는다. (set을 구현)

가장 작은 sum을 구하기 위해서 1부터 시작하는 값들 중 가능한 값 (nums에 없는 값)을 정답에 더한다.

이 때 매번 더할 경우 시간 복잡도가 매우 커지므로 구간별로 더한다.

set의 각 원소를 순회하면서 다음 구간의 값을 정답에 더한다.

- (직전 값 + 1) ~ (현재 값 - 1) 까지의 합
- 여기서 숫자는 최대 K개를 더한다.
- 직전 값을 현재 값으로 갱신하고 다음 루프에 도입한다.

이 방법으로 각 구간들의 합을 바로 구하고 정답을 갱신할 수 있다.

구간 합은 다음 함수를 이용한다.

```cpp
long long getSums(long long to) {
  if (to <= 0) return 0;
  return (to * (to + 1)) / 2;
}

long long getSums(long long from, long long to) {
  return getSums(to) - getSums(from - 1);
}
```

순회가 끝나고 K개를 채우지 못한 경우는 맨 마지막 수 + 1 부터 K개의 숫자를 정답에 더한다.

이를 구현하면 다음과 같다.

```cpp
long long minimalKSum(vector<int>& nums, int k) {
  int count = k;
  set<int> numSets(nums.begin(), nums.end());

  long long answer = 0;
  int before = 0;
  auto it = numSets.begin();
  while (it != numSets.end() && count > 0) {
    int cur = *it;

    if (before + 1 < cur) {
      int diff = (cur - 1) - (before + 1) + 1;

      long long from = before + 1;
      long long to = diff <= count ? cur - 1 : from + count - 1;

      count -= (to - from + 1);

      answer += getSums(from, to);
    }

    before = cur;
    it++;
  }

  if (count > 0) {
    long long from = before + 1;
    long long to = from + count - 1;

    answer += getSums(from, to);
  }
  return answer;
}
```

### BST set 가능한 경우만 더하기

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     284      | O(N \* log_2(N)) |    O(N)     |

위 방법을 반대로 생각하면 다음과 같이 정답을 구할 수 있다.

nums의 unique한 값을 오름차순으로 정렬한 set을 만든다.

- 1부터 K까지의 합을 미리 구한다.
- 이후 set을 순회하며 해당 숫자를 합에서 빼고, K를 증가시키고 해당 값을 더한다.

즉 미리 1 ~ K의 합을 구한 뒤 set에 존재하는 수를 빼는 방법이다. (뺀 수만큼 가능한 가장 작은 다음 수를 더함)

이를 구현하면 다음과 같다.

```cpp
long long minimalKSum(vector<int>& nums, int k) {
  long long answer = (long long)k * (k + 1) / 2;
  set<int> numSets(nums.begin(), nums.end());

  long long nextK = k;
  for (int num : numSets) {
    if (num <= nextK) {
      nextK++;
      answer += nextK - num;
    }
  }

  return answer;
}
```

heap을 이용할 경우 다음과 같이 구할 수 있다.

```cpp
long long minimalKSum(vector<int>& nums, int k) {
  long long answer = (long long)k * (k + 1) / 2;
  priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

  int last = 0;
  long long nextK = k;
  while (!pq.empty() && pq.top() <= nextK) {
    int num = pq.top();
    pq.pop();

    if (num != last) {
      nextK++;
      answer += nextK - num;
    }
    last = num;
  }

  return answer;
}
```

## 고생한 점
