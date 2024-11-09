# 3325. Count Substrings With K-Frequency Characters I

[링크](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도가 필요하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 경우마다 문자의 빈도수를 저장한다 이에 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

슬라이딩 윈도우를 이용해 각 문자의 최대 빈도가 K가 되지 않는 경우를 찾을 수 있다.

이 때 해당 substring의 개수는 right - left + 1 이다.

전체 경우의 수에서 해당 경우의 수를 모두 뺀 값이 정답이 된다.

이 때 최대 빈도가 K가 되지 않는 경우를 찾는 이유는 조건을 만족하는 경우 중복을 제거해야 하기 때문이다. 따라서 불가능한 경우만 count한다.

```cpp
int numberOfSubstrings(string s, int k) {
  int size = s.size();
  int answer = size * (size + 1) / 2;

  int counts[26] = {
      0,
  };

  for (int left = 0, right = 0; right < size; right++) {
    counts[s[right] - 'a']++;

    while (counts[s[right] - 'a'] >= k) {
      counts[s[left] - 'a']--;
      left++;
    }

    answer -= (right - left) + 1;
  }

  return answer;
}
```

## 고생한 점
