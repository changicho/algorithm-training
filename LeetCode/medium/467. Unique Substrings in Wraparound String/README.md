# 467. Unique Substrings in Wraparound String

[링크](https://leetcode.com/problems/unique-substrings-in-wraparound-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 p의 길이를 N이라 하자.

각 문자로 끝나는 가장 긴 subString의 길이를 구하고, 각 길이들을 더하면 된다. (중복을 제외해야 하므로)

이 경우 한번의 순회를 통해 가장 긴 subString의 길이를 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 글자마다의 가장 긴 길이를 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 가장 긴 subString

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |    O(1)     |

연속된 문자열 X가 있다고 하자. ('abcde...z'라 하자)

이 문자열의 길이를 L이라고 했을 때 특정 문자로 끝나는 가장 긴 문자열의 길이는 다음과 같다.

- z : L
- y : L-1
- x : L-2
- ...

여기서 각 subString마다 만들 수 있는 중복된 경우를 제거해야 하며 이는 특정 문자로 끝나는 가장 긴 문자열의 길이를 이용해 유일한 경우를 셀 수 있다.

위 경우에 대해서 z로 끝나는 문자열의 subString의 정답 갯수는 L개이다.

('z', 'yz', 'xyz', ... , 'abc...z')

z로 끝나는 경우는 해당 경우 밖에 없으며 이를 y, x, ... , b, a에 대해서 모두 적용할 수 있다.

따라서 P를 모두 순회하며 해당 글자로 끝나는 가장긴 subString의 갯수들을 갱신하고 이를 정답에 더한다.

```cpp
bool isNext(char &from, char &to) {
  if (from == 'z' && to == 'a') return true;
  return to - from == 1;
}

int findSubstringInWraproundString(string p) {
  int length = p.length();

  int tempLength = 0;
  vector<int> maxLengths(26, 0);
  for (int i = 0; i < length; i++) {
    if (tempLength == 0 || !isNext(p[i - 1], p[i])) {
      tempLength = 0;
    }
    tempLength++;
    maxLengths[p[i] - 'a'] = max(tempLength, maxLengths[p[i] - 'a']);
  }

  int answer = 0;
  for (int &length : maxLengths) {
    answer += length;
  }

  return answer;
}
```

## 고생한 점
