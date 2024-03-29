# 5872. Clumsy Cows

[링크](https://www.acmicpc.net/problem/5872)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 골드 5 |   61.905    |       1       |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

그리디 알고리즘을 사용해 S를 순회하며 열고 닫는 괄호쌍의 valid한 갯수를 센다. 이 때 valid하지 않은 경우 해당 괄호를 수정한다.

한번의 순회를 이용하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

열고닫는 괄호쌍의 차이를 저장할 때 O(1)의 공간 복잡도를 사용한다.

## 그리디 알고리즘

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

숫자 diff를 선언하며 여는 괄호는 +1, 닫는 괄호는 -1을 더해주며 왼쪽부터 문자열을 순회한다.

이 때 diff가 음수가 되는 경우가 발생하면 해당 괄호를 여는 괄호로 수정한다.

모든 순회가 끝난 후 diff가 양수인 경우 diff / 2만큼의 괄호를 여는 괄호로 수정한다.

(절반의 여는 괄호를 닫는 괄호로 수정함)

```cpp
int solution(string s) {
  int diff = 0;

  int answer = 0;
  for (char &c : s) {
    if (c == '(') {
      diff += 1;

    } else {
      diff -= 1;
    }

    if (diff < 0) {
      diff = 1;
      answer++;
    }
  }

  if (diff > 0) {
    answer += diff / 2;
  }
  return answer;
}
```

## 고생한 점
