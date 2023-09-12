# 1647. Minimum Deletions to Make Character Frequencies Unique

[링크](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

s의 알파벳은 영어 소문자만이므로 빈도는 총 26개가 생성된다.

각 빈도들로 알파벳을 묶고, 겹치는 빈도가 존재하는 경우 이동시키며 빈도를 조정한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

빈도들을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 빈도 hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      |    O(N)     |    O(1)     |

각 문자들을 count한다. 만약 특정 문자와 같은 빈도를 갖는 다른 문자가 존재하는 경우 둘중 하나의 문자를 이동해야한다.

이를 모든 문자에 대해서 겹치지 않는 빈도를 갖도록 조정한다.

이를 위해 각 문자를 빈도에 따라 묶은 뒤 만약 겹칠 경우 이동시키며 빈도를 조정한다.

이 때 빈도가 높은 순으로, 낮은 순으로 방문해도 이동하는 횟수의 총 합은 동일하다.

```cpp
int minDeletions(string s) {
  int counts[26] = {
      0,
  };
  for (char &c : s) {
    counts[c - 'a']++;
  }

  // key freq, val count
  unordered_map<int, int> um;
  vector<int> freqs;
  for (int i = 0; i < 26; i++) {
    um[counts[i]]++;
  }

  int answer = 0;
  for (int i = 0; i < 26; i++) {
    int count = counts[i];
    if (count == 0) continue;
    if (um[count] <= 1) continue;
    um[count]--;
    while (count > 0 && um[count] >= 1) {
      count--;
      answer++;
    }
    um[count]++;
  }

  return answer;
}
```

## 고생한 점
