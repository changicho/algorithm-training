# 912. Sort an Array

[링크](https://leetcode.com/problems/sort-an-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소의 갯수를 N, 원소의 범위를 M이라 하자.

카운팅 정렬을 사용할 경우 O(M)의 시간 복잡도를 사용한다.

머지소트를 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

카운팅 정렬을 사용할 경우 O(M)의 공간 복잡도를 사용한다.

머지소트를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     112      |  O(N + M)   |    O(M)     |

수의 범위가 작으므로 (최대 10^5가지 수) 카운팅 정렬을 이용한다.

```cpp
int DIFF = 5 * 1e4;

vector<int> sortArray(vector<int> &nums) {
  int counts[1000001] = {
      0,
  };
  for (int &num : nums) {
    counts[num + DIFF]++;
  }

  int index = 0;
  for (int num = 0; num <= 1e5; num++) {
    for (int j = 0; j < counts[num]; j++) {
      nums[index++] = num - DIFF;
    }
  }
  return nums;
}
```

### 머지소트

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     252      | O(N \* log_2(N)) |    O(M)     |

병합 정렬을 구현한다.

nums와 같은 크기의 배열을 선언 후 임시로 사용한다.

각 구간별로 나눈 뒤, 연이은 구간을 병합하며 정렬한다.

```cpp
class Solution {
 private:
  vector<int> temp;

  void merge(vector<int> &arr, int left, int mid, int right) {
    int size1 = mid - left + 1, size2 = right - mid;
    int start1 = left, start2 = mid + 1;

    for (int i = 0; i < size1; i++) {
      temp[start1 + i] = arr[start1 + i];
    }
    for (int i = 0; i < size2; i++) {
      temp[start2 + i] = arr[start2 + i];
    }

    int idx1 = 0, idx2 = 0, target = left;
    while (idx1 < size1 && idx2 < size2) {
      if (temp[start1 + idx1] <= temp[start2 + idx2]) {
        arr[target] = temp[start1 + idx1];
        idx1++;
      } else {
        arr[target] = temp[start2 + idx2];
        idx2++;
      }
      target++;
    }

    while (idx1 < size1) {
      arr[target] = temp[start1 + idx1];
      idx1 += 1;
      target += 1;
    }
    while (idx2 < size2) {
      arr[target] = temp[start2 + idx2];
      idx2 += 1;
      target += 1;
    }
  }

  void recursive(vector<int> &arr, int left, int right) {
    if (left >= right) {
      return;
    }
    int mid = (left + right) / 2;

    recursive(arr, left, mid);
    recursive(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }

 public:
  vector<int> sortArray(vector<int> &nums) {
    int size = nums.size();
    temp.resize(size);

    recursive(nums, 0, size - 1);

    return nums;
  }
};
```

## 고생한 점
