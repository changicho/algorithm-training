# 3034. Number of Subarrays That Match a Pattern I

[링크](https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자 nums의 크기를 N, pattern의 크기를 M이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* M)이다.

KMP 알고리즘을 사용할 경우 O(N + M)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

직접 모든 경우를 탐색할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

KMP 알고리즘을 사용할 경우 O(N + M)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |  O(N \* M)  |    O(1)     |

직접 각 시작 index마다 pattern을 만족하는지 검사한다.

```cpp
bool check(int cur, int before, int p) {
  if (p == 1 && cur > before) return true;
  if (p == 0 && cur == before) return true;
  if (p == -1 && cur < before) return true;

  return false;
}

int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
  int size = nums.size();
  int pSize = pattern.size();

  int answer = 0;
  for (int i = 0; i < size - pSize; i++) {
    int before = nums[i];
    bool isFine = true;

    for (int pI = 0; pI < pSize; pI++) {
      int cur = nums[i + pI + 1];
      if (!check(cur, before, pattern[pI])) {
        isFine = false;
        break;
      }
      before = cur;
    }

    if (isFine) answer++;
  }
  return answer;
}
```

### KMP

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      18      |  O(N + M)   |  O(N + M)   |

nums를 연이은 수의 diff를 가진 배열로 변환하고 해당 배열에서 pattern이 몇번 나타나는지 검사한다.

이를 위해 KMP 알고리즘을 사용한다.

```cpp
int kmp(vector<int>& nums, vector<int>& pattern) {
  int answer = 0;
  int size = nums.size(), pSize = pattern.size();
  vector<int> pIndexes(pSize, 0);

  for (int curIdx = 1, patternIdx = 0; curIdx < pSize; curIdx++) {
    while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
      patternIdx = pIndexes[patternIdx - 1];
    }
    if (pattern[curIdx] == pattern[patternIdx]) {
      patternIdx++;
      pIndexes[curIdx] = patternIdx;
    }
  }

  for (int lineIdx = 0, patternIdx = 0; lineIdx < size; lineIdx++) {
    while (patternIdx > 0 && nums[lineIdx] != pattern[patternIdx]) {
      patternIdx = pIndexes[patternIdx - 1];
    }

    if (nums[lineIdx] == pattern[patternIdx]) {
      if (patternIdx == pSize - 1) {
        answer++;

        patternIdx = pIndexes[patternIdx];
      } else {
        patternIdx++;
      }
    }
  }

  return answer;
}

int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
  int size = nums.size();
  int pSize = pattern.size();

  int answer = 0;

  vector<int> pI;
  for (int i = 0; i < size - 1; i++) {
    int cur = 0;
    if (nums[i + 1] > nums[i]) {
      cur = 1;
    } else if (nums[i + 1] == nums[i]) {
      cur = 0;
    } else {
      cur = -1;
    }

    pI.emplace_back(cur);
  }

  return kmp(pI, pattern);
}
```


## 고생한 점
