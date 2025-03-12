# 1100. Find K-Length Substrings With No Repeated Characters

[링크](https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* K)이다.

슬라이딩 윈도우를 이용할 경우 O(N)에 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 각 문자의 갯수를 사용하므로 O(1)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

길이가 K며 K개의 유니크한 문자로 이루어진 substring들을 판단해야한다.

순회하며 윈도우의 크기를 K로 유지시키며 윈도우 내의 유니크한 문자의 갯수를 판단한다.

각 경우마다 이 갯수가 K개일 경우 정답을 증가시킨다.

```cpp
int numKLenSubstrNoRepeats(string s, int k) {
  int size = s.size();
  int counts[26] = {
      0,
  };

  int uniques = 0;
  int answer = 0;
  for (int l = 0, r = 0; r < size; r++) {
    if (counts[s[r] - 'a'] == 0) {
      uniques++;
    }
    counts[s[r] - 'a']++;

    if (r - l + 1 > k) {
      counts[s[l] - 'a']--;
      if (counts[s[l] - 'a'] == 0) {
        uniques--;
      }
      l++;
    }

    if (uniques == k) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
