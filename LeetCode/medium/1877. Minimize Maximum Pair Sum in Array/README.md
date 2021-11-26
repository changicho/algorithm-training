# 1877. Minimize Maximum Pair Sum in Array

[링크](https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

정렬을 이용한 후 pair들을 가장 작은 값들로 생성할 수 있다.

이후 한번의 순회로 pair들을 만들고 이 합들의 최대값을 구할 수 있으므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬과 pair의 합을 갱신하는 데 상수 공간 복잡도를 사용하므로 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     224      | O(N \* log_2(N)) |    O(1)     |

we can use sort to make minimized pair

we divide sorted array two part

small's part (0 <= index < n/2)

big's part (n/s <= index < n)

center = n/2 and iterate i = 0 ~ n/2

make pair {center - 1 - i, cetner + i}

then we can make minimized pairs

so we can find the maximum of minimized pairs (one pass)

```cpp
class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int answer = nums.front() + nums.back();

    int center = size / 2;
    for (int i = 0; i < size / 2; i++) {
      // current pair is {nums[center - 1 - i], nums[cetner + i]}
      answer = max(nums[center - 1 - i] + nums[center + i], answer);
    }

    return answer;
  }
};
```

## 고생한 점
