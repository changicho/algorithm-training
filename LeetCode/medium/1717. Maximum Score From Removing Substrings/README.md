# 1717. Maximum Score From Removing Substrings

[링크](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

ab, ba중 우선하는 것부터 제거하는 것이 최적이다. 이러한 탐욕 알고리즘을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이 때 스택을 이용해 문자열을 연속적으로 삭제할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 이용해 문자열을 연속적으로 삭제할 수 있다. 이 경우 O(N)의 공간 복잡도를 사용한다.

### 스택 & 그리디

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      89      |    O(N)     |    O(N)     |

ab, ba를 둘 다 만들 수 있는 경우 어느 경우를 우선해야 하는지를 정해야 한다.

ab, ba 중 점수가 큰 쪽을 우선적으로 삭제한 뒤 남은 문자열에서 다시 삭제한다.

이 때 삭제시 스택을 이용해 문자열을 연속적으로 삭제한다.

```cpp
int getPoint(string &s, int point, string target) {
  int result = 0;

  string ret = "";
  for (char &c : s) {
    ret += c;

    while (ret.size() >= 2 && ret[ret.size() - 1] == target[1] &&
            ret[ret.size() - 2] == target[0]) {
      ret.pop_back();
      ret.pop_back();
      result += point;
    }
  }
  s = ret;
  return result;
}

int maximumGain(string s, int x, int y) {
  int answer = 0;

  if (x > y) {
    answer += getPoint(s, x, "ab");
    answer += getPoint(s, y, "ba");
  } else {
    answer += getPoint(s, y, "ba");
    answer += getPoint(s, x, "ab");
  }
  return answer;
}
```

## 고생한 점
