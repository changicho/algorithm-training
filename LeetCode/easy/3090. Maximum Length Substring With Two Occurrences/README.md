# 3090. Maximum Length Substring With Two Occurrences

[링크](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

완전 탐색으로 구현할 경우 O(N^2)의 시간 복잡도를 사용한다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

슬라이딩 윈도우를 사용해 현재 증가시킨 오른쪽 문자의 갯수가 2를 초과할 경우 왼쪽을 이동시키며 갯수를 줄인다.

```cpp
int maximumLengthSubstring(string s) {
  int size = s.size();

  int count[26] = {
      0,
  };

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    count[s[right] - 'a']++;

    while (count[s[right] - 'a'] > 2 && left < right) {
      count[s[left] - 'a']--;
      left++;
    }

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점
