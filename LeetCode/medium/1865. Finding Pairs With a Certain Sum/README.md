# 1865. Finding Pairs With a Certain Sum

[링크](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 배열의 크기를 각각 N, M이라 하자.

hash map을 이용해 nums2의 원소의 갯수를 관리하며 이후 count연산에 순회할 경우 O(N)의 시간 복잡도를 사용한다.

nums2의 값이 변할 때 hash map을 업데이트 하는데 O(1)의 시간 복잡도를 사용한다.

총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

hash map을 사용하므로 O(N + M)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      84      |  O(N + M)   |  O(N + M)   |

nums2의 갯수를 hash map으로 관리하며 `add` 연산을 통해 nums2의 값을 변경할 때 hash map을 업데이트한다.

이후 `count` 연산을 통해 nums1의 원소를 순회하며 nums2에서 합이 tot가 되는 원소의 갯수를 구한다.

```cpp
class FindSumPairs {
 private:
  vector<int> nums1, nums2;
  unordered_map<int, int> um;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int& num : nums2) {
      um[num]++;
    }
  }

  void add(int index, int val) {
    int before = nums2[index];

    um[before]--;
    nums2[index] += val;
    um[before + val]++;
  }

  int count(int tot) {
    int ret = 0;
    for (int& num : nums1) {
      int rest = tot - num;

      if (um.count(rest)) {
        ret += um[rest];
      }
    }
    return ret;
  }
};
```

## 고생한 점
