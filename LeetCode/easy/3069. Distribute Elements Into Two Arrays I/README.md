# 3069. Distribute Elements Into Two Arrays I

[링크](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

시뮬레이션을 이용해 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

```cpp
vector<int> resultArray(vector<int>& nums) {
  vector<int> arr1, arr2;

  arr1.push_back(nums[0]);
  arr2.push_back(nums[1]);

  int size = nums.size();
  for (int i = 2; i < size; i++) {
    if (arr1.back() > arr2.back()) {
      arr1.push_back(nums[i]);
    } else {
      arr2.push_back(nums[i]);
    }
  }

  for (int& num : arr2) {
    arr1.push_back(num);
  }
  return arr1;
}
```

## 고생한 점
