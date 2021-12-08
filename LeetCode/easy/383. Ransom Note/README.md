# 383. Ransom Note

[링크](https://leetcode.com/problems/ransom-note/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 문자열의 길이를 각각 N, M이라 하자

두 문자열의 문자들을 각각 순회하며 count한 배열을 만든다.

이후 ransomNote의 각 문자들의 count가 magazine의 문자의 count보다 큰 지를 판별한다.

이 순회에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

알파벳 lowercase만 존재하므로 O(26)크기의 공간이 필요하다.

따라서 공간 복잡도는 O(1)이다.

### counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N + M)   |    O(1)     |

magazine에서 문자들을 뽑아 ransomNote를 만들 수 있는지 판별한다.

magazine의 모든 문자들의 개수를 세고, ransomNote의 각 문자별로 부족한지 판단한다.

```cpp
bool canConstruct(string ransomNote, string magazine) {
  vector<int> counts(26, 0);

  // count all alphabet in magazine
  for (char &c : magazine) {
    counts[c - 'a'] += 1;
  }

  // iterate all alphabet in ransomNote
  for (char &c : ransomNote) {
    // decrease current alphabet count in magazine
    counts[c - 'a'] -= 1;
    // if current count is lower than 0,
    // that means there are no current alphabet in magazine
    if (counts[c - 'a'] < 0) return false;
  }

  return true;
}
```

## 고생한 점
