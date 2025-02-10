# 1790. Check if One String Swap Can Make Strings Equal

[링크](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s1, s2의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

문자의 갯수와 다른 부분의 수를 count해 비교할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

문자열을 비교할 때 별도의 공간이 필요하지 않다.

문자를 카운팅하는데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

s1과 s2의 문자의 수를 센다.

그리고 index를 순회하며 두 문자가 다른 경우를 count한다.

만약 다른 문자의 수가 0개인 경우 두 문자열이 같은 경우이다.

만약 다른 문자의 수가 2개이며 두 문자열을 구성하는 문자들의 수가 같은 경우 같은 문자열을 만들 수 있다.

그 외의 경우 불가능하다.

```cpp
bool areAlmostEqual(string s1, string s2) {
  int size = s1.size();
  vector<int> counts1(26, 0), counts2(26, 0);

  int diff = 0;
  for (int i = 0; i < size; i++) {
    char c1 = s1[i], c2 = s2[i];

    counts1[c1 - 'a']++;
    counts2[c2 - 'a']++;

    if (c1 != c2) diff++;
  }

  return (diff == 2 || diff == 0) && counts1 == counts2;
}
```

## 고생한 점
