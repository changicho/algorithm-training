# 3042. Count Prefix and Suffix Pairs I

[링크](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 문자열의 최대 길이를 L이라 하자.

두 word가 prefix&suffix 인지 판단하는데 O(L)의 시간 복잡도를 사용한다.

이를 가능한 모든 쌍에 대해 수행해볼 경우 O(N^2 \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix, suffix를 문자열로 저장후 판단할 경우 O(L)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(N^2 \* L) |    O(L)     |

가능한 모든 쌍 (i, j)에 대해 판단한다.

이 때 i번째 문자열이 j의 prefix & suffix 인지 판별하기 위해 다음과 같은 조건을 사용한다.

- i번째 문자열의 길이가 j번째 문자열의 길이보다 짧아야 한다.
- j번째 문자열의 prefix와 suffix가 같아야 한다. (길이가 i번째 문자열과 같은)
- prefix와 suffix가 i번째 문자열과 같아야 한다.

이를 구현하면 다음과 같다.

```cpp
bool isFine(string &s, string &line) {
  int size = s.size();

  if (size > line.size()) return false;

  string prefix = line.substr(0, size);
  string suffix = line.substr(line.size() - size, size);

  if (prefix != suffix) return false;

  return s == prefix;
}

int countPrefixSuffixPairs(vector<string> &words) {
  int size = words.size();
  int answer = 0;

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (isFine(words[i], words[j])) {
        answer++;
      }
    }
  }

  return answer;
}
```

## 고생한 점
