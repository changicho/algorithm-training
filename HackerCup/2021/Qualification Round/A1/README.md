# Problem A1: Consistency - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1)

| 난이도 |
| :----: |
| 11 pt  |

## 설계

### 시간 복잡도

글자의 갯수를 N이라 하자.

자음 -> 모음 -> 자음 -> 모음 ... 과 같은 형태로 바꿀 수 있다.

모두 같은 문자를 만들어야 하므로 target문자를 지정하고 다른 모든 문자들을 이에 맞춰본다.

target문자는 최대 26가지 이며 이를 모두 순회하는데 O(1)의 시간 복잡도를 사용한다.

문자열을 순회하며 각 문자의 갯수를 count하고, 이후 target문자로 변환하는 데 필요한 cost들을 계산하는데 사용한다. 이 순회에 O(N)의 시간복잡도를 사용한다.

이후 target으로 변경하는데 필요한 cost를 순회하며 계산하고 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자의 갯수를 count하고 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 브루트 포스

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

각 문자열을 순회하며 count한다.

이후 모두 같게 만들고자 하는 target을 지정하고 cost를 계산한다.

현재 문자에 대해 다음과 같은 경우들이 존재한다.

- 같은 문자 : cost 0
- 같은 타입, 다른문자 : cost 2
- 다른 타입, 다른 문자 : cost 1

이를 이용해 cost들을 계산해준다.

```cpp
int solution(string &s) {
  int length = s.length();
  unordered_map<char, int> counts;

  int vowelCount = 0;
  int consonantCount = 0;

  for (char &c : s) {
    counts[c]++;

    if (isVowel(c)) {
      vowelCount++;
    } else {
      consonantCount++;
    }
  }

  int answer = length * 2;
  for (char target = 'A'; target <= 'Z'; target++) {
    int curCost = 0;
    for (auto &it : counts) {
      char c = it.first;
      int count = it.second;

      if (c == target) continue;

      if (isVowel(c) && isVowel(target) || !isVowel(c) && !isVowel(target)) {
        curCost += count * 2;
      } else {
        curCost += count;
      }
    }

    answer = min(answer, curCost);
  }

  return answer;
}
```

## 고생한 점
