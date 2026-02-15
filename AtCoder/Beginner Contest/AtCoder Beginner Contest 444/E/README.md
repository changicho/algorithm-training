# E - Sparse Range

[링크](https://atcoder.jp/contests/abc444/tasks/abc444_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

슬라이딩 윈도우를 이용해 조건을 만족하는 구간을 찾는다.

이 때 각 원소를 추가했을 때 해당 값과 차이가 가장 작은 값들을 찾고 조건을 만족하는지 판단해야 한다.

이를 위해 multiset을 사용할 수 있다.

이 경우 각 원소에 대해 판단하는데 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 전체 시간 복잡도는 O(N \* log_2(N))이 된다.

### 공간 복잡도

multiset에 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우 & multiset

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     323      | O(N \* log_2(N)) |    O(N)     |

문제 조건을 만족하는 경우를 슬라이딩 윈도우를 이용해 관리한다.

이 이유는 이미 현재 윈도우가 정답을 만족하지 못하는 경우 해당 윈도우를 오른쪽으로 증가시켜도 정답을 만족하지 못하기 때문이다.

조건을 만족하는 현재 윈도우에 새로운 값이 추가되었을 때 새로운 값과 차이가 가장 작은 값의 차이가 limit 이상인지 판단해야 한다.

이를 위해 multiset을 이용해 윈도우 내의 값을 정렬된 상태로 관리한다.

이후 이분 탐색을 사용해 새로운 값과 차이가 가장 작은 값을 찾는다. (작은값, 큰값 중)

조건을 만족하는 경우 현재 새로운 값을 윈도우에 추가한다. (윈도우를 오른쪽으로 증가)

그렇지 않은 경우 윈도우의 왼쪽을 삭제해 크기를 감소시켜 다시 판단한다.

현재 윈도우가 정답을 만족하는 경우 정답에 현재 윈도우의 크기를 더한다.

이는 현재 윈도우에서 현재 원소(맨 오른쪽)를 포함하는 모든 구간이 정답을 만족한다는 의미이기 때문이다.

```cpp
long long solution(int size, const vector<long long>& nums, long long limit) {
  long long answer = 0;

  multiset<long long> window;

  auto check = [&](long long newVal) -> bool {
    if (window.empty()) return true;
    if (window.count(newVal) > 0) return false;

    auto nextEl = window.upper_bound(newVal);
    if (nextEl != window.end()) {
      if (abs(*nextEl - newVal) < limit) {
        return false;
      }
    }

    if (nextEl == window.begin()) {
      return true;
    }
    // Check previous element
    auto prevEl = prev(nextEl);

    if (abs(*prevEl - newVal) < limit) {
      return false;
    }

    return true;
  };

  for (int left = 0, right = 0; right < size; right++) {
    while (left < right && check(nums[right]) == false) {
      window.erase(window.find(nums[left]));
      left++;
    }
    window.insert(nums[right]);

    answer += right - left + 1;
  }

  return answer;
}
```

## 고생한 점
