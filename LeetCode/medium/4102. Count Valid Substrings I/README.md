# 4102. Count Valid Substrings I

[링크](https://leetcode.com/problems/count-valid-substrings-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

슬라이딩 윈도우를 사용해 현재 가능한 substring의 길이를 매번 구할 수 있다.

이를 이용해 정답을 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

윈도우의 크기를 증가시켜가며 현재 윈도우의 맨 마지막 문자열이 "abc"인 경우 윈도우를 초기화한다.

이 때 현재 윈도우의 오른쪽 부분중 "bc"까지는 선택한다.

이를 이용해 각 윈도우의 right를 증가시켜가며 유효한 윈도우의 크기를 구할 수 있고,

현재 right를 포함하는 subString의 수를 매번 정답에 더한다.

```cpp
long long countValidSubstrings(string s) {
  int size = s.size();
  long long answer = 0;

  for (int left = 0, right = 0; right < size; right++) {
    if (right >= 2) {
      if (s[right] == 'c' && s[right - 1] == 'b' && s[right - 2] == 'a') {
        left = right - 1;
      }
    }

    answer += right - left + 1;
  }
  return answer;
}
```

## 고생한 점
