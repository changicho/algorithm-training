# 395. Longest Substring with At Least K Repeating Characters

[링크](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s의 길이를 N이라 하자.

brute force 방법을 이용해 subString의 시작점과 끝점에 대해서 모두 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

여기서 각 경우마다 모든 lower case 문자에 대해 K개 이상인지 판단하는 데 O(26)의 시간 복잡도를 사용하므로 이는 O(1)이 된다.

슬라이딩 윈도우를 이용해 O(N)의 시간 복잡도로 풀이할 수 있다. 이 경우 subString에 존재하는 유일한 문자들의 갯수에 대해서 모두 탐색해봐야 한다. 

### 공간 복잡도

brute force 방법을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

슬라이딩 윈도우를 사용할 경우 알파벳에 대한 갯수만 저장하면 되므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     426      |   O(N^2)    |    O(1)     |

subString의 시작, 끝 index에 대해서 완전탐색을 수행한다.

각 경우마다의 subString의 알파벳 대해 counts 배열을 갱신하고 이 배열이 조건을 만족하는 경우 정답을 갱신한다.

이 때 counts배열의 갱신을 O(1)의 시간 복잡도로 수행하기 위해 직전 위치에서 right를 증가시키며 갱신하도록 구성한다.

```cpp
bool isPossible(int counts[26], int k) {
  for (int i = 0; i < 26; i++) {
    if (counts[i] == 0) continue;
    if (counts[i] < k) return false;
  }
  return true;
}

int longestSubstring(string s, int k) {
  int length = s.length();

  int maximum = 0;
  for (int start = 0; start < length; start++) {
    int counts[26] = {
        0,
    };

    for (int i = start; i < length; i++) {
      counts[s[i] - 'a']++;

      if (isPossible(counts, k)) {
        maximum = max(maximum, i - start + 1);
      }
    }
  }

  return maximum;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |    O(N)     |    O(N)     |

left, right만으로는 슬라이딩 윈도우 방법을 이용할 수 없다.

따라서 subString의 유일한 문자 갯수를 변화하며 슬라이딩 윈도우를 이용한다.

이 경우 유일한 문자 갯수가 변할 때마다 윈도우의 크기를 증가, 감소시킬 수 있다.

이를 이용해 각 경우마다 탐색을 수행한다.

```cpp
int longestSubstring(string s, int k) {
  int length = s.length();

  int maximum = 0;
  for (int target = 1; target <= 26; target++) {
    unordered_map<char, int> counts;

    int left = 0, right = 0;
    int leastK = 0;
    while (right < length) {
      if (counts.size() <= target) {
        // expand the sliding window
        counts[s[right]]++;
        if (counts[s[right]] == k) leastK++;

        right++;
      } else {
        // shrink the sliding window
        if (counts[s[left]] == k) leastK--;

        counts[s[left]]--;
        if (counts[s[left]] == 0) counts.erase(s[left]);

        left++;
      }

      // update answer
      if (counts.size() == target && counts.size() == leastK) {
        maximum = max(right - left, maximum);
      }
    }
  }

  return maximum;
}
```

## 고생한 점
