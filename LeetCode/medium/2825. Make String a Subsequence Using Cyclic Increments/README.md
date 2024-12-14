# 2825. Make String a Subsequence Using Cyclic Increments

[링크](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 문자열 str1, str2의 길이를 각각 N, M이라 하자.

투 포인터를 사용해 str1을 순회하며 str2의 문자를 찾는 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

투 포인터를 사용하며 비교하는데 O(1)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

str1을 순회하며 str2의 문자를 앞에서 부터 subsequence로 만들 수 있는지 검사한다.

이 때 str1의 현재 문자열과, 해당 문자열에서 한번 증갛시킨 문자열을 비교한다.

```cpp
bool canMakeSubsequence(string str1, string str2) {
  int size1 = str1.size(), size2 = str2.size();

  for (int i1 = 0, i2 = 0; i1 < size1; i1++) {
    char cur = str1[i1];
    char next = cur + 1;
    if (next > 'z') next = 'a';

    if (i2 < size2 && (str2[i2] == cur || str2[i2] == next)) {
      i2++;
    }

    if (i2 == size2) return true;
  }
  return false;
}
```

## 고생한 점
