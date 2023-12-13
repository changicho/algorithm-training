# 5875. 오타

[링크](https://www.acmicpc.net/problem/5872)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| 골드 2 |   37.109    |       1       |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

왼쪽부터 순회하며 여는 괄호, 닫는 괄호의 수를 세며 또한 괄호값의 차이 또한 구한다.

이 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 괄호들과 현재까지의 차이를 저장할 때 O(1)의 공간 복잡도를 사용한다.

## 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

왼쪽부터 순회하며 여는 괄호, 닫는 괄호의 수를 세며 또한 괄호값의 차이 또한 구한다.

여는 괄호의 경우 +1, 닫는 괄호의 경우 -1을 더한다.

이 때 직전까지 valid했고 여는괄호의 수와 닫는 괄호의 수가 같았던 경우 현재 시작하는 여는 괄호쌍은 무조건 존재해야 한다.

만약 순회가 끝나지 않았는데 괄호값의 차이가 음수가 되는 경우, 현재까지 순회한 닫는 괄호들 중 하나를 여는 괄호로 수정하면 valid한 괄호쌍을 생성할 수 있다.

순회가 끝나고 변경 가능한 여는 괄호쌍의 수가 1개 이상인 경우 그중 하나를 변경해 valid한 괄호쌍을 생성할 수 있다.

```cpp
int solution(string &s) {
  int size = s.size();
  int answer = 0;

  int opens = 0, closes = 0;
  int diff = 0;

  for (char &c : s) {
    if (c == '(') {
      opens += 1;
      diff += 1;

    } else {
      closes += 1;
      diff -= 1;
    }

    if (diff <= 1) {
      opens = 0;
    }

    if (diff == -1) {
      answer = closes;
      break;
    }
  }

  if (diff > 0) {
    answer = opens;
  }

  return answer;
}
```

## 순회 (닫는 괄호)

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

왼쪽부터 순회하며 여는 괄호, 닫는 괄호의 수를 세며 또한 괄호값의 차이 또한 구한다.

여는 괄호의 경우 +1, 닫는 괄호의 경우 -1을 더한다.

만약 순회가 끝나지 않았는데 괄호값의 차이가 음수가 되는 경우, 현재까지 순회한 닫는 괄호들 중 하나를 여는 괄호로 수정하면 valid한 괄호쌍을 생성할 수 있다.

이를 왼쪽부터 한번 순회하고, 오른쪽부터 한번 순회해 두 변경 가능한 횟수를 모두 구한다.

```cpp
int countChangeClose(string &s) {
  int answer = 0;

  int opens = 0, closes = 0;
  int diff = 0;

  for (char &c : s) {
    if (c == '(') {
      diff += 1;
    } else {
      closes += 1;
      diff -= 1;
    }

    if (diff < 0) {
      return closes;
      break;
    }
  }

  return 0;
}

int solution(string &s) {
  int size = s.size();

  int answer = 0;

  answer += countChangeClose(s);
  reverse(s.begin(), s.end());
  for (int i = 0; i < size; i++) {
    if (s[i] == '(')
      s[i] = ')';
    else
      s[i] = '(';
  }
  answer += countChangeClose(s);

  return answer;
}

```

## 고생한 점
