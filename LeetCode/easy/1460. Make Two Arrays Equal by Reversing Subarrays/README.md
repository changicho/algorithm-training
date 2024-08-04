# 1460. Make Two Arrays Equal by Reversing Subarrays

[링크](https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 배열의 크기를 N이라 하자.

정렬 후 비교할 경우 O(N \* log_2(N)) 이다.

hash map을 이용해 비교할 경우 O(N) 이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

hash map을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

target의 원소들을 카운트하고, arr의 원소들을 카운트한다.

두 배열의 원소들의 수가 같은지 비교한다.

```cpp
bool canBeEqual(vector<int>& target, vector<int>& arr) {
  unordered_map<int, int> counts;

  for (int& num : target) {
    counts[num]++;
  }

  for (int& num : arr) {
    counts[num]--;

    if (counts[num] < 0) return false;
  }

  return true;
}
```

## 고생한 점
