# 239. Sliding Window Maximum

[링크](https://leetcode.com/problems/sliding-window-maximum/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N, 입력받은 숫자를 K라 하자.

N개의 원소를 순회해야 하므로 O(N)의 시간 복잡도 이내로 풀이할 수 없다.

BST기반의 map을 이용해 매번 최대값을 구할 수 있다. 이 경우 각 window마다 O(log_2(K))의 시간 복잡도로 최대값을 구할 수 있으며 갱신할 수 있다.

이 경우 시간 복잡도는 O(N \* log_2(K))가 된다.

모노토닉 큐를 이용해 모든 순회동안 O(K)의 시간 복잡도로 매번 최대값을 구할 수 있다.

이 경우 시간 복잡도는 O(N + K)이다.

### 공간 복잡도

window를 저장할 공간이 필요하며 O(K)의 공간 복잡도를 사용한다.

### 모노토닉 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     244      |  O(N + K)   |    O(K)     |

Monotone Queue는 Monotone 과 Queue의 합성어이다. 즉 단조로운 큐라는 의미다.

어떠한 알고리즘을 토대로 큐를 단조롭게 관리하는 알고리즘이다.

모노토닉큐를 이용해 각 구간에서 최적의 값(우선순위가 높은 값)을 알 수 있다.

1. 현재 위치까지 영향력을 줄 수 없는 모든 원소들을 앞에서부터 제거한다. (pop_front)
2. 현재 값이 맨 뒤에 있는 원소보다 우선하면 이를 제거한다. (pop_back)
3. 큐가 비거나 2번이 만족하지 않을 때까지 2번의 과정을 반복한다.
4. 현재 위치의 값을 넣는다. (push back)
5. 큐는 단조 증가하는 형태이므로 구간내의 우선순위가 가장 높은 값은 맨 앞에 있다.

모노토닉 큐를 이용하기 위해 다음과 같은 데이터를 이용한다.

```cpp
struct Data {
  int value, index;
};
```

여기서 index를 사용하는 이유는 현재 index에서 deque를 trim할때 이전 데이터의 index를 사용하기 때문이다.

이를 이용해 nums를 순회하며 각 index마다의 최적의 상태를 deque로 구현한다.

이후 window의 크기가 k를 넘어서부터 우선순위가 가장 높은 값(큰 값)을 정답 배열에 삽입한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int size = nums.size();
  deque<Data> dq;

  vector<int> answer;
  for (int i = 0; i < size; i++) {
    while (!dq.empty() && dq.front().index < i - k + 1) {
      dq.pop_front();
    }

    while (!dq.empty() && dq.back().value < nums[i]) {
      dq.pop_back();
    }

    dq.push_back({nums[i], i});
    if (i >= k - 1) {
      answer.push_back(dq.front().value);
    }
  }

  return answer;
}
```

### BST map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     596      | O(N \* log_2(K)) |    O(K)     |

K크기의 sliding window를 BST기반의 map으로 만들 수 있다.

슬라이딩 윈도우에서 left, right구간을 이동시키며 값을 없애고, 증가시킨다.

이 때 map구조는 다음과 같다.

- key: number
- value: count

이를 이용해 count가 0이된 경우는 map에서 제거하며 window의 count의 합을 K로 유지할 수 있다.

제일 큰 값은 항상 맨뒤에 있는 값이다.

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int size = nums.size();
  map<int, int> slide;

  for (int i = 0; i < k; i++) {
    slide[nums[i]] += 1;
  }

  vector<int> answer;
  int left = 0, right = k - 1;
  auto it = slide.end();
  it--;
  answer.push_back(it->first);

  for (int left = 0; left < size - k; left++) {
    int right = left + k;

    slide[nums[left]] -= 1;
    if (slide[nums[left]] == 0) {
      slide.erase(nums[left]);
    }
    slide[nums[right]] += 1;

    auto it = slide.end();
    it--;
    answer.push_back(it->first);
  }

  return answer;
}
```

## 고생한 점
