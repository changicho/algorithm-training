# 424. Longest Repeating Character Replacement

[링크](https://leetcode.com/problems/longest-repeating-character-replacement/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 L이라 하자.

각 문자를 기준으로, 나머지 다른 문자들의 갯수를 K이하로 하는 가장 긴 문자열의 갯수를 슬라이딩 윈도우를 이용해 구할 수 있다.

슬라이딩 윈도우를 이용할경우 O(L)의 시간 복잡도를 사용한다.

여기서 기준점의 종류는 최대 26가지이므로 시간 복잡도는 O(L)이다.

### 공간 복잡도

슬라이딩 윈도우를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      22      |    O(L)     |    O(1)     |

'A' ~ 'Z'까지의 문자중 하나를 기준으로 삼는다.

이후 슬라이딩 윈도우를 이용해 기준 문자열과 다른 문자의 갯수가 K이하인 가장 긴 subString을 구한다.

이를 모든 기준문자에 대해 반복한다.

```cpp
int characterReplacement(string s, int k) {
  int length = s.length();

  int answer = 0;
  for (char target = 'A'; target <= 'Z'; target++) {
    int diff = 0;
    int left = 0;
    for (int right = 0; right < length; right++) {
      if (s[right] != target) diff++;

      while (diff > k) {
        if (s[left] != target) diff--;
        left++;
      }

      answer = max(answer, right - left + 1);
    }
  }

  return answer;
}
```

## 고생한 점
