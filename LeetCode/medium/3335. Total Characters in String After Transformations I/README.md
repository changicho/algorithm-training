# 3335. Total Characters in String After Transformations I

[링크](https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 변환할 횟수를 T라 하자.

각 경우마다 알파벳의 수를 세고 이를 이용해 변환을 진행한다.

이 경우 처음 알파벳을 세는 데 O(N) 시간이 걸리고, 변환을 T번 진행하므로 총 O(N + T)의 시간이 걸린다.

### 공간 복잡도

알파벳의 갯수에 O(1) 공간이 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      55      |  O(N + T)   |    O(1)     |

각 알파벳마다 변환되는 경우는 정해져있다.

결과적으로 최종 문자열의 길이만 알면 되므로, 

각 알파벳별로 다른 알파벳의 갯수를 세는 count 배열을 만든 뒤 이를 이용해 변환을 수행한다.

이후 최종 갯수를 센다.

```cpp
int lengthAfterTransformations(string s, int t) {
  const int MOD = 1e9 + 7;

  int count[26] = {
      0,
  };
  for (char &c : s) {
    count[c - 'a']++;
  }

  for (int i = 0; i < t; i++) {
    int newCount[26] = {
        0,
    };

    for (int i = 0; i < 25; i++) {
      newCount[i + 1] = count[i];
      newCount[i + 1] %= MOD;
    }
    newCount[0] += count[25];
    newCount[0] %= MOD;
    newCount[1] += count[25];
    newCount[1] %= MOD;

    swap(newCount, count);
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    answer += count[i];
    answer %= MOD;
  }
  return answer;
}
```

## 고생한 점
