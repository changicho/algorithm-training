# 532. K-diff Pairs in an Array

[링크](https://leetcode.com/problems/k-diff-pairs-in-an-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

nums의 모든 수를 hash map에 count한 뒤, 각 수를 순회하며 K만큼 차이나는 값이 존재하는지 판단한다.

이 경우 모든 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(N)     |    O(N)     |

각 수를 모두 count한다.

이를 hash map에 count하므로 다음과 같은 구조가 될 것이다.

- key : 숫자
- val : 갯수

각 숫자에 대해 비교하며 (key + K)인 key가 hash map에 존재하는지 판단한다.

만약 K가 0인 경우 val이 2 이상인지 판별한다.

이를 구현하면 다음과 같다.

```cpp
int findPairs(vector<int> &nums, int k) {
  unordered_map<int, int> counts;

  for (int &num : nums) {
    counts[num]++;
  }

  int answer = 0;
  for (auto &it : counts) {
    int key = it.first, val = it.second;

    if (k == 0) {
      if (2 <= val) {
        answer++;
      }
      continue;
    }

    if (counts.count(key + k) > 0) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
