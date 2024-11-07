# 3324. Find the Sequence of Strings Appeared on the Screen

[링크](https://leetcode.com/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

target의 길이를 N이라 하자.

시뮬레이션을 이용해 풀이할 경우 각 자리수마다 target과 일치하는지 시뮬레이션을 이용해 풀이할 수 있다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 경우마다 저장해야 한다. 이에 O(N)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

맨 마지막 글자만 변경 가능하므로 각 과정마다 현재 target의 index를 완성하며 answer에 추가한다.

```cpp
vector<string> stringSequence(string target) {
  vector<string> answer;

  string cur = "";
  int size = target.size();
  for (int i = 0; i < size; i++) {
    cur += "a";

    for (char c = 'a'; c <= target[i]; c++) {
      cur[i] = c;
      answer.push_back(cur);
    }
  }

  return answer;
}
```

## 고생한 점
