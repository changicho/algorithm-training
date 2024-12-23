# 2182. Construct String With Repeat Limit

[링크](https://leetcode.com/problems/construct-string-with-repeat-limit/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

그리디 알고리즘을 사용해 문자열을 생성할 경우, 문자열을 순회하며 문자열을 생성할 수 있다.

이 때 매 경우마다 가장 우선순위가 높은 문자를 선택해야 한다.

문자의 종류를 M이라 하며 이는 26이다.

모든 경우마다 직접 탐색할 경우 O(N \* M)의 시간 복잡도를 사용한다.

힙을 이용해 매번 가장 우선순위가 높은 문자를 선택할 경우 O(N \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답과 각 문자의 개수를 저장하는데 O(N + M)의 공간 복잡도를 사용한다.

힙에 O(M)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |  O(N \* M)  |  O(N + M)   |

매 경우 가장 유리한 문자를 선택해야 한다. (사전적으로 가장 느린 문자)

이 때 repeatLimit만큼 해당 문자가 반복되는 경우,

그 다음으로 유리한 문자를 1개씩 중간에 섞어야 한다.

이를 위해 문자의 개수를 세고, 가장 높은 우선순위의 문자를 선택한다.

그리고 중간에 다른 문자를 섞어야 하는 경우 다음으로 높은 우선순위의 문자를 선택한다.

```cpp
string repeatLimitedString(string s, int repeatLimit) {
  int counts[26] = {
      0,
  };
  for (char& c : s) {
    counts[c - 'a']++;
  }

  string answer = "";
  int index = 25;
  while (index >= 0) {
    if (counts[index] == 0) {
      index--;
      continue;
    }

    int use = min(counts[index], repeatLimit);
    answer.append(use, 'a' + index);
    counts[index] -= use;

    if (counts[index] > 0) {
      int sI = index - 1;
      while (sI >= 0 && counts[sI] == 0) {
        sI--;
      }

      if (sI < 0) break;

      answer.push_back('a' + sI);
      counts[sI]--;
    }
  }

  return answer;
}
```

## 고생한 점
