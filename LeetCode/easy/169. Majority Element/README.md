# 169. Majority Element

[링크](https://leetcode.com/problems/majority-element/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

hash_map을 이용할 경우 한번 순회로 문제를 해결할 수 있다. 따라서 O(N)의 시간 복잡도가 필요하다.

정렬을 이용해 문제를 풀이하는 경우 O(N \* log_2(N))의 시간 복잡도가 필요하다.

가반수 값을 찾는 알고리즘을 이용할 경우 한번의 순회로 충분하므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

hash_map을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

정렬을 이용할경우 별도의 공간이 필요하지 않다. 따라서 O(1)의 공간 복잡도가 필요하다.

가반수 값을 찾는 알고리즘을 이용할 경우 별도의 공간이 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(N \* log_2(N)) |    O(1)     |

배열에서 최빈수는 절반 이상을 차지한다.

따라서 정렬을 수행할 경우 중앙점에는 언제나 최빈수가 위치한다.

(N / 2)크기의 막대를 어느 위치에 놓아도 중점을 지나는 것을 이용한다.

```cpp
int majorityElement(vector<int>& nums) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  return nums[size / 2];
}
```

### 가반수 알고리즘 (Boyer-Moore)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

수를 순회하며 target 숫자와 같은 수가 나올경우 count를 증가, 다른수가 나올경우 count를 감소한다.

만약 count가 0인 경우 현재 숫자를 target으로 설정한다.

최빈수의 경우 target이 변경된다 하더라도 숫자가 절반 이상 존재하므로 최종적으로는 target으로 지정될 수 밖에 없다.

```cpp
int majorityElement(vector<int>& nums) {
  int count = 0;
  int candidate;

  for (int num : nums) {
    if (count == 0) {
      candidate = num;
    }
    count += (num == candidate) ? 1 : -1;
  }

  return candidate;
}
```

## 고생한 점
