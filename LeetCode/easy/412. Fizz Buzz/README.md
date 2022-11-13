# 412. Fizz Buzz

[링크](https://leetcode.com/problems/fizz-buzz/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 하자.

1부터 N까지 순회하며 각 경우마다 문자열로 변환한 값을 정답에 추가해야한다.

이 순회에 O(N)의 시간 복잡도를 사용한다.

각 숫자를 문자열로 변환하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(N)     |

Fizz, Buzz, FizzBuzz를 생성하는 경우를 분석하면 다음과 같다.

- 3으로 나누어 떨어지는 경우 Fizz를 추가
- 5로 나누어 떨어지는 경우 Buzz를 추가

15의 경우 FizzBuzz를 생성하기 위해 3으로 나누어 떨어지는 경우부터 분기처리한다.

이를 구현하면 다음과 같다.

```cpp
string convert(int &num) {
  string ret = "";
  if (num % 3 == 0) {
    ret += "Fizz";
  }
  if (num % 5 == 0) {
    ret += "Buzz";
  }

  if (ret == "") {
    return to_string(num);
  }
  return ret;
}

vector<string> fizzBuzz(int n) {
  vector<string> answer;
  for (int i = 1; i <= n; i++) {
    answer.push_back(convert(i));
  }
  return answer;
}
```

## 고생한 점
