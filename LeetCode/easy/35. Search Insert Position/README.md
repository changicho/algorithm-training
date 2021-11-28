# 35. Search Insert Position

[링크](https://leetcode.com/problems/search-insert-position/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 길이는 최대 10^4이다.

브루트 포스 방법을 수행할 경우 시간 복잡도는 O(N) 이다.

분할 정복 (lower_bound)를 이용하면 시간 복잡도는 O(log_2(N)) 이다.

### 공간 복잡도

배열안의 값은 -10^4 ~ 10^4 인 정수이다. 또한 return해야 하는 값은 index이며 이는 10^4 이하이다.

### lower_bound

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

> STL사용 : 0ms, 직접 구현 : 4ms

이분 탐색을 이용해 시간 복잡도를 최적화 할 수 있다.

검색하고자 하는 값이 현재 값보다 크면 start를 증가시키고 그 외의 경우는 end값을 감소한다.

```cpp
int my_lower_bound(vector<int>& nums, int key) {
  int start = 0;
  int end = nums.size();
  int mid;

  while (start < end) {
    mid = (start + end) / 2;

    if (nums[mid] < key) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return end;
}
```

실제 lower_bound는 다음과 같다.

```cpp
template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val) {
  ForwardIterator it;
  iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first, last);
  while (count > 0) {
    it = first;
    step = count / 2;
    advance(it, step);
    if (*it < val) {  // or: if (comp(*it,val)), for version (2)
      first = ++it;
      count -= step + 1;
    } else
      count = step;
  }
  return first;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(log_2(N)) |    O(1)     |

lower bound와 동일한 방법을 이분탐색으로 구현해 사용한다.

```cpp
int searchInsert(vector<int>& nums, int target) {
  int size = nums.size();
  // first we set the range of part
  int left = 0, right = size;
  // we will set left is the answer.
  // so we set the right is the limit + 1 of the range (cannot be answer)

  // while left is lower than right
  while (left < right) {
    int mid = (left + right) / 2;

    // if mid < target
    if (nums[mid] < target) {
      // target will be in right part
      left = mid + 1;
    } else {  // else
      // target will be in left part
      right = mid;
    }
  }

  // left is the answer
  return left;
}
```

## 고생한 점
