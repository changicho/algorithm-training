# 1768. Merge Strings Alternately

[링크](https://leetcode.com/problems/merge-strings-alternately/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

합칠 두 문자열의 길이를 각각 N, M이라 하자.

각 원소를 순회하며 순서대로 합치면 되므로 총 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

두 문자열을 합친 새로운 문자열을 반환하므로 O(N + M)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

두 문자열의 index를 각각 i, j라 하자.

i, j를 0부터 시작해 순서대로 문자열을 합친다.

이 때 i, j가 각각 문자열의 길이보다 작은 경우에만 합친다.

```cpp
string mergeAlternately(string word1, string word2) {
  string ret = "";
  int idx1 = 0, idx2 = 0;
  int size1 = word1.size(), size2 = word2.size();

  while (idx1 < size1 || idx2 < size2) {
    if (idx1 < size1) {
      ret += word1[idx1];
      idx1++;
    }
    if (idx2 < size2) {
      ret += word2[idx2];
      idx2++;
    }
  }
  return ret;
}
```

## 고생한 점
