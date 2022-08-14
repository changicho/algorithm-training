# 480. Sliding Window Median

[링크](https://leetcode.com/problems/sliding-window-median/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

중앙값을 계산하기 위해서 두개의 multiset을 사용한다.

이 경우 K개의 원소들이 multiset에 저장되고 이전것은 삭자되며 이는 O(log_2(K))의 시간 복잡도를 사용한다.

이를 N개의 원소에 대해 순회하며 저장하고 중앙값을 찾으므로 O(N \* log_2(K))의 시간 복잡도를 사용한다.

### 공간 복잡도

두개의 multiset을 사용할 경우 O(K)의 공간 복잡도를 사용한다.

이후 정답 배열에 O(N - K)의 공간 복잡도를 사용하므로 공간 복잡도는 O(N)이다.

### two multiset

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      75      | O(N \* log_2(K)) |    O(N)     |

두개의 힙을 이용해 중앙값을 찾는 방법을 응용한다.

힙 대신 정렬가능하고 중복된 원소들을 저장 가능한 multiset을 이용한다.

두 개의 multiset중 하나는 내림차순 (높은값 저장), 오른차순 (낮은값 저장)으로 설정해 top에는 중앙값의 후보가 위치하도록 한다. (실제로는 맨 앞과 맨 뒤로 볼 수 있도록 구성)

N개의 원소를 순회하며 원소를 저장하고, 두개의 multiset에 원소를 삽입할 때 정리하고 삽입한다.

이 때 저장된 원소의 갯수가 홀수일 경우 작은쪽이 1개 더 많이 가져가도록 구성한다.

이 과정에서 중앙값은 K가 홀수일 경우 작은 힙의 top, 짝수일 경우 각 top의 평균이 된다.

여기서 중복된 값들이 존재할 수 있고, 현재 윈도우에서 벗어나는 값들도 존재하므로 이는 multiset에서 제거해준다.

이를 이용해 구현하면 다음과 같다.

```cpp
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
  int size = nums.size();

  vector<double> medians;
  multiset<int> lower, higher;

  for (int i = 0; i < size; i++) {
    if (i >= k) {
      if (nums[i - k] <= *lower.rbegin()) {
        lower.erase(lower.find(nums[i - k]));
      } else {
        higher.erase(higher.find(nums[i - k]));
      }
    }

    lower.insert(nums[i]);

    higher.insert(*lower.rbegin());
    lower.erase(prev(lower.end()));

    if (lower.size() < higher.size()) {
      lower.insert(*higher.begin());
      higher.erase(higher.begin());
    }

    if (i >= k - 1) {
      double median;
      if (k % 2 == 1) {
        median = *lower.rbegin();
      } else {
        median = ((double)(*lower.rbegin()) + (*higher.begin())) / 2;
      }
      medians.push_back(median);
    }
  }

  return medians;
}
```

## 고생한 점
