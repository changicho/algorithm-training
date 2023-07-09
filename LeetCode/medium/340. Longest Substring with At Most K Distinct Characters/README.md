# 340. Longest Substring with At Most K Distinct Characters

[링크](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

슬라이딩 윈도우를 이용해 유효한 범위만 탐색하며 최적의 값을 갱신할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 문자별로 count할 공간이 필요하다. 문자의 종류는 최대 256가지이므로 공간 복잡도는 O(1)이다.

슬라이딩 윈도우를 사용하는데 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

s의 문자의 종류의 수가 정의되지 않았으므로 모든 char에 대해 가능하다고 가정한다.

오른쪽, 왼쪽 index를 서로 관리한다.

오른쪽 index를 증가시키며 현재 윈도우에 오른쪽 문자를 추가한다.

이 때 현재 윈도우의 문자의 종류가 k개를 넘어간 경우 왼쪽 index를 증가시키며 윈도우의 크기를 줄인다. 이를 문자의 종류가 k 이하가 될때까지 반복한다.

여기서 윈도우의 문자의 종류와 수를 관리하기 위해 hash map 혹은 배열을 사용한다.

만약 k가 0인 경우는 윈도우의 크기가 0이 되므로 0을 반환한다.

```cpp
int lengthOfLongestSubstringKDistinct(string s, int k) {
  int counts[256] = {
      0,
  };
  int notZeroCount = 0;

  int size = s.size();

  int answer = 0;
  for (int left = 0, right = 0; right < size; right++) {
    counts[s[right]]++;
    if (counts[s[right]] == 1) {
      notZeroCount++;
    }

    while (left <= right && notZeroCount > k) {
      char target = s[left];
      counts[target]--;
      left++;

      if (counts[target] == 0) {
        notZeroCount--;
      }
    }

    answer = max(answer, right - left + 1);
  }
  return answer;
}
```

## 고생한 점

k가 0인 엣지케이스를 고려해야함.
