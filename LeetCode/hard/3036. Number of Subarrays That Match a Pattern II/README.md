# 3036. Number of Subarrays That Match a Pattern II

[링크](https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, pattern의 크기를 M이라 하자.

nums에서 pattern을 만족하는 subarray의 개수를 구해야 한다.

이를 위해 모든 subarray를 탐색할 경우 시간 복잡도는 O(N \* M)이며 이는 제한시간 내에 불가능하다.

KMP 알고리즘을 사용해 풀이할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

KMP 알고리즘에 O(N + M)의 공간 복잡도가 필요하다.

### KMP 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     178      |  O(N + M)   |  O(N + M)   |

nums의 각 원소를 직전값과 대소비교한 배열 line을 생성한다.

이후 line에 pattern이 몇번 나타나는지를 탐색한다.

KMP알고리즘을 사용해 몇번 나타나는지 탐색한다.

```cpp
int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
  for (int i = 0; i < nums.size() - 1; i++) {
    int cur = 0;
    if (nums[i] < nums[i + 1]) {
      cur = 1;
    } else if (nums[i] > nums[i + 1]) {
      cur = -1;
    }
    nums[i] = cur;
  }

  nums.pop_back();
  int size = nums.size(), pSize = pattern.size();
  vector<int> pIndexes(pSize, 0);

  int ret = 0;

  for (int i = 1, pI = 0; i < pSize; i++) {
    while (pI > 0 && pattern[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }
    if (pattern[i] == pattern[pI]) {
      pI++;
      pIndexes[i] = pI;
    }
  }

  for (int i = 0, pI = 0; i < size; i++) {
    while (pI > 0 && nums[i] != pattern[pI]) {
      pI = pIndexes[pI - 1];
    }

    if (nums[i] == pattern[pI]) {
      if (pI == pSize - 1) {
        ret++;

        pI = pIndexes[pI];
      } else {
        pI++;
      }
    }
  }

  return ret;
}
```

## 고생한 점
