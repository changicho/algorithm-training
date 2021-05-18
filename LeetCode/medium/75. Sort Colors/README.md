# 75. Sort Colors

[링크](https://leetcode.com/problems/sort-colors/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

one pass로 문제를 해결해야 한다.

배열의 길이를 N이라고 했을 때 시간 복잡도는 O(N)으로 문제를 풀이한다.

카운팅 정렬을 이용할 경우 O(N)번에 문제를 풀이할 수 있다.

원 패스 알고리즘을 이용할 경우 O(N)번에 문제를 풀이할 수 있다.

### 공간 복잡도

공간 복잡도 상수로 문제를 풀이할 수 있다.

카운팅 정렬의 경우 0,1,2 세가지 경우만 세 주면 된다. 따라서 O(1)의 공간 복잡도가 필요하다.

one pass의 경우 swap만 이용하므로 O(1)의 공간 복잡도가 필요하다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

배열을 순회하며 0,1,2의 개수를 센다.

이후 배열에 0부터 채운다.

```cpp
void sortColors(vector<int>& nums) {
  int counts[3] = {
      0,
  };
  for (int num : nums) {
    counts[num] += 1;
  }

  int index = 0;
  for (int num = 0; num <= 2; num++) {
    while (counts[num] > 0) {
      nums[index] = num;
      counts[num] -= 1;
      index++;
    }
  }
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

0,1,2 세가지 숫자밖에 없다.

순회를 지속하며 0은 앞으로 2는 뒤로 보낼 경우 자연스럽게 0,1,2가 정렬이 된다.

이를 이용해 정렬을 수행한다.

```cpp
void sortColors(vector<int>& nums) {
  int size = nums.size();
  int zeroIdx = 0, twoIdx = size - 1;

  for (int i = 0; i <= twoIdx; ++i) {
    if (nums[i] == 0 && i != zeroIdx) {
      swap(nums[i], nums[zeroIdx]);
      i--;
      zeroIdx++;
    } else if (nums[i] == 2 && i != twoIdx) {
      swap(nums[i], nums[twoIdx]);
      i--;
      twoIdx--;
    }
  }
}
```

## 고생한 점
