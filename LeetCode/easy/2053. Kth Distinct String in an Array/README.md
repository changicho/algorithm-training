# 2053. Kth Distinct String in an Array

[링크](https://leetcode.com/problems/kth-distinct-string-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

각 배열의 원소를 count 한 뒤 count가 1인 K번째 원소를 찾아야 한다.

이를 위해 hash map을 사용할 경우 count에 O(N)의 시간 복잡도를 사용한다.

이후 정답을 찾는 데 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

hash map에 count를 저장한 뒤 K번째 count가 1인 문자열을 찾는다.

```cpp
string kthDistinct(vector<string> &arr, int k) {
  unordered_map<string, int> counts;

  for (string &s : arr) {
    counts[s]++;
  }

  for (string &s : arr) {
    if (counts[s] > 1) continue;

    k--;
    if (k == 0) return s;
  }

  return "";
}
```

## 고생한 점
