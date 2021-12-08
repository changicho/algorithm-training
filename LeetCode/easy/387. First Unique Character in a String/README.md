# 387. First Unique Character in a String

[링크](https://leetcode.com/problems/first-unique-character-in-a-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

매 글자마다 유일한 글자인지를 판별해서 가장 빨리 유일한 글자를 찾아야 한다.

매번 순회를 이용해 유일한지 판별할 경우 O(N)의 시간 복잡도를 사용한다.

혹은 기존에 글자의 갯수를 미리 세놓고 이를 판단할 경우 O(1)의 시간 복잡도를 사용한다.

각 글자를 순회하는데 각각 O(N)의 시간 복잡도가 소요되므로 최종 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

모든 글자가 나타나는 횟수를 count하는 배열을 생성하는데 O(1)의 공간 복잡도를 사용한다. (26글자)

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |    O(N)     |    O(1)     |

한번 순회를 통해 모든 글자의 갯수를 센다.

이후 순회를 진행하며 글자의 수가 1인 가장 빠르게 찾는 글자의 index를 반환한다.

```cpp
int firstUniqChar(string s) {
  // key : alphabet, value : count
  unordered_map<char, int> counts;
  int length = s.length();
  // set init value -1
  int answer = -1;

  // count all alphabet
  for (char &c : s) {
    counts[c] += 1;
  }

  // iterate all index of s
  for (int i = 0; i < length; i++) {
    // if current char's count is 1 that is First Unique Character
    if (counts[s[i]] == 1) {
      answer = i;
      break;
    }
  }

  return answer;
}
```

## 고생한 점
