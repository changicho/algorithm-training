# 1207. Unique Number of Occurrences

[링크](https://leetcode.com/problems/unique-number-of-occurrences/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열 arr의 크기를 N이라 하자.

각 값들을 hash map에 count 후 이를 이용할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

```cpp
bool uniqueOccurrences(vector<int> &arr) {
  unordered_map<int, int> counts;
  for (int &num : arr) {
    counts[num]++;
  }

  unordered_set<int> occur;
  for (auto &it : counts) {
    int count = it.second;
    if (occur.count(count)) {
      return false;
    }
    occur.insert(count);
  }
  return true;
}
```

## 고생한 점
