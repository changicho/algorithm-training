# 3375. Minimum Operations to Make Array Values Equal to K

[링크](https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

K보다 큰 수들의 유니크한 종류를 세야한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

K보다 큰 수들의 유니크한 종류를 세기 위해 hash set을 사용한다. 이 경우 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

nums의 원소 중 하나라도 k보다 작은 경우 문제 조건을 만족시킬 수 없다.

또한 k보다 큰 수들의 경우 특정 숫자 A를 모두 B로 바꿀 수 있으므로 결과적으로 k보다 큰 수들의 유니크한 종류를 세면 된다.

```cpp
int minOperations(vector<int>& nums, int k) {
  unordered_set<int> us;
  for (int& num : nums) {
    if (num < k)
      return -1;
    else if (num > k)
      us.insert(num);
  }

  return us.size();
}
```

## 고생한 점
