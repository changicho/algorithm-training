# 2186. Minimum Number of Steps to Make Two Strings Anagram II

[링크](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 문자열 s와 t의 길이를 각각 N, M이라 하자.

두 문자열을 anagram 관계로 만들기 위해선 두 문자열의 각 글자의 수를 비교했을 때 부족한 부분들을 채워넣어주면 된다.

각 문자들을 count하는데 각 문자열을 순회해야 하므로 O(N + M)의 시간 복잡도를 사용한다.

이후 알파벳 소문자를 모두 순회하며 차이만큼을 더해준다. 이 순회는 O(26)의 시간 복잡도를 사용한다.

이 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

count하기 위해 필요한 공간 복잡도는 O(1)이다.

### counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     132      |  O(N + M)   |    O(1)     |

두 문자열 각 문자를 count한다.

이후 각 문자를 순회하며 차이를 비교해 더한다.

이를 구현하면 다음과 같다.

```cpp
int minSteps(string s, string t) {
  vector<int> countS(26, 0), countT(26, 0);

  for (char &c : s) {
    countS[c - 'a']++;
  }
  for (char &c : t) {
    countT[c - 'a']++;
  }

  int step = 0;
  for (int i = 0; i < 26; i++) {
    if (countS[i] == countT[i]) continue;

    int diff = abs(countS[i] - countT[i]);
    step += diff;
  }
  return step;
}
```

## 고생한 점
