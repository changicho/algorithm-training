# 28. Implement strStr()

[링크](https://leetcode.com/problems/implement-strstr/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

각 문자열의 최대 길이는 5 \* 10^4 까지이다.

KMP알고리즘을 이용할 경우 시간 복잡도는 O(N + M)에 끝낼 수 있다. (N: 원본문자열 길이, M: 패턴문자열 길이)

### 공간 복잡도

문자열은 모두 소문자 영어이다.

### STL string.find()

> 4ms

STL을 이용해 간단히 풀이할 수 있다.

```cpp
int strStr(string haystack, string needle) {
  return (int)haystack.find(needle);
}
```

### 브루트 포스

> 0ms

브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N \* M) 이다.

```cpp
int strStr(string haystack, string needle) {
  if (needle.length() == 0) {
    return 0;
  }

  if (haystack.length() < needle.length()) {
    return -1;
  }

  for (int index = 0; index <= haystack.size() - needle.size(); index++) {
    if (haystack[index] != needle[0]) {
      continue;
    }

    int needleIndex = 1;
    for (; needleIndex < needle.size(); needleIndex++) {
      if (haystack[index + needleIndex] != needle[needleIndex]) {
        break;
      }
    }

    if (needleIndex == needle.size()) {
      return index;
    }
  }

  return -1;
}
```

### KMP 알고리즘

> 4ms

패턴을 비교할 때 패턴에서 이전 접두사들이 중복되어 패턴으로 나타나는 경우 이를 이용한다.

시간 복잡도는 O(N + M)이다.

```cpp
class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }

    vector<int> patternIndexArray = getPatternIndexArray(needle);

    for (int index = 0, needleIndex = 0; index < haystack.size();) {
      if (haystack[index] == needle[needleIndex]) {
        index++, needleIndex++;
      }

      if (needleIndex == needle.size()) {
        return index - needleIndex;
      }

      if (index < haystack.size() && haystack[index] != needle[needleIndex]) {
        if (needleIndex != 0) {
          needleIndex = patternIndexArray[needleIndex - 1];
        } else {
          index++;
        }
      }
    }
    return -1;
  }

 private:
  vector<int> getPatternIndexArray(string needle) {
    vector<int> patternIndexArray(needle.size(), 0);

    for (int i = 1, len = 0; i < needle.size();) {
      if (needle[i] == needle[len]) {
        len++;
        patternIndexArray[i] = len;
        i++;
      } else if (len) {
        len = patternIndexArray[len - 1];
      } else {
        patternIndexArray[i++] = 0;
      }
    }
    return patternIndexArray;
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
