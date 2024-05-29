# 1208. Get Equal Substrings Within Budget

[링크](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s와 t의 길이를 N이라 하자. N은 최대 10^5 이다.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 풀이할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 index만 저장하면 되므로 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(1)     |

슬라이딩 윈도우를 이용해 각 index마다 s와 t의 차이를 계산하고, 이 값이 maxCost를 초과하는 경우 left를 증가시키며 윈도우의 크기를 조절한다.

```cpp
int equalSubstring(string s, string t, int maxCost) {
  int size = s.size();

  int temp = maxCost;
  int answer = 0;

  for (int left = 0, right = 0; right < size; right++) {
    temp -= abs(s[right] - t[right]);
    while (left < right && temp < 0) {
      temp += abs(s[left] - t[left]);
      left++;
    }

    if (temp >= 0) {
      answer = max(answer, right - left + 1);
    }
  }

  return answer;
}
```

## 고생한 점
