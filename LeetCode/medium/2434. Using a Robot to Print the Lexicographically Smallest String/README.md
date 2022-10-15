# 2434. Using a Robot to Print the Lexicographically Smallest String

[링크](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

탐욕 알고리즘을 이용해 현재 가능한 가장 최선의 값을 p로 이동시킨다.

이 경우 스택을 사용하며 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘 (stack)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     163      |    O(N)     |    O(N)     |


t는 LIFO구조이다. 이는 stack으로 구현 가능하다.

각 과정에서 t의 top부터 p에 더할 수 있다.

따라서 현재 t의 top을 빼고 p에 더하는 경우가 최선의 해인지를 판단한다.

만약 t.top이 이후 남은 모든 문자들보다 사전순으로 우선한다면 (알파벳 빠른순) 이 경우 p에 더할 수 있다.

이를 위해 미리 s의 각 알파벳을 count 하고, t에 삽입할 때마다 count를 줄인다. (남은 문자열 기준으로만 생각)

이 때 t에 삽입하는 순서는 left -> right 순으로 수행한다.

이를 구현하면 다음과 같다.

```cpp
string robotWithString(string s) {
  string answer;
  stack<char> t;

  map<char, int> count;
  for (char &c : s) {
    count[c]++;
  }

  for (char &c : s) {
    t.push(c);
    count[c]--;
    if (count[c] == 0) {
      count.erase(c);
    }

    char lowest = count.empty() ? 'z' : count.begin()->first;
    while (!t.empty() && t.top() <= lowest) {
      answer += t.top();
      t.pop();
    }
  }
  return answer;
}
```

## 고생한 점
