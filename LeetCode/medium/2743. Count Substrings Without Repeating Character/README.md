# 2743. Count Substrings Without Repeating Character

[링크](https://leetcode.com/problems/count-substrings-without-repeating-character/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

슬라이딩 윈도우를 사용해 풀이할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

슬라이딩 윈도우에 각 알파벳마다의 갯수를 저장하므로 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |    O(N)     |    O(1)     |

right를 증가시키며 만약 중복된 문자가 발생할 경우 left를 증가시키며 중복된 문자를 제거한다.

이 과정에서 subString의 길이로 정답을 갱신한다.

```cpp
int numberOfSpecialSubstrings(string s) {
  int size = s.size();

  int counts[26] = {0};
  int answer = 0;
  for (int l = 0, r = 0; r < size; r++) {
    counts[s[r] - 'a']++;

    while (l < r && counts[s[r] - 'a'] > 1) {
      counts[s[l] - 'a']--;
      l++;
    }

    answer += (r - l + 1);
  }

  return answer;
}
```

## 고생한 점
