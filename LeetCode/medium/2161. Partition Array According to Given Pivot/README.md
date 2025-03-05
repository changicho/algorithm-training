# 2161. Partition Array According to Given Pivot

[링크](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

배열을 순회하며 별도의 배열에 pivot보다 작은 수, 큰 수, 같은 수를 나누어 저장해야 한다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

pivot보다 작은 수, 큰 수, 같은 수를 저장할 배열이 필요하다. 이에 O(N)의 공간 복잡도가 필요하다.

### 순회 & 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(N)     |

pivot보다 작은 수, 큰 수, 같은 수를 저장할 배열을 생성한다.

이후 왼쪽부터 순회하며 순서대로 각 배열에 저장 후 nums에 복사한다.

```cpp
vector<int> pivotArray(vector<int> &nums, int pivot) {
  int size = nums.size();
  vector<int> smaller, bigger, equals;

  for (int &num : nums) {
    if (num < pivot) {
      smaller.push_back(num);
    } else if (num > pivot) {
      bigger.push_back(num);
    } else {
      equals.push_back(num);
    }
  }

  int i = 0;
  for (int &num : smaller) {
    nums[i] = num;
    i++;
  }
  for (int &num : equals) {
    nums[i] = num;
    i++;
  }
  for (int &num : bigger) {
    nums[i] = num;
    i++;
  }
  return nums;
}
```

## 고생한 점
