# 43. Multiply Strings

[링크](https://leetcode.com/problems/multiply-strings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

큰 수의 곱을 하기 위해선 N개의 숫자를 M번 순회해야 한다. (N, M은 두 숫자 각각의 길이)

두 수의 길이는 최대 200이다. 시간 복잡도는 O(N \* M) 이며 최악의 경우 O(200^2)

### 공간 복잡도

새로 곱한 수를 반환할 문자열이 필요하다. 이 문자열의 최대 길이는 N + M이므로 필요한 공간 복잡도는 O(N + M) 이다.

### 큰 수 곱

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N \* M)  |  O(N + M)   |

뒤집어 곱을 만드는 경우 다시 뒤집어 줘야 하므로 한꺼번에 계산한다.

정답은 최대 N + M 자리 이며 끝 자리부터 채운다. (N + M - 1번째 index부터 채움)

또한 곱의 경우 매 자리수별로 곱을 해줘야 한다. ABC와 DEF의 곱을 수행한다고 하자.

```cpp
ABC * DEF = ABC * F * 1 + ABC * E * 10 + ABC * D * 100;
```

여기서 10의 자리수는 그저 자리수일 뿐이므로 계산에선 index로 이용한다.

따라서 각 자리수의 값은 매번 다음과 같다.

```cpp
// 편의상 모두 숫자라 생각한다.
int cur = num1[first] * num2[second] + answer[first + second + 1];

answer[first + second + 1] = cur % 10;
answer[first + second] += cur / 10; // adder
```

위를 이용해 구현하며 미리 모든 자리수를 만들어 놨기 때문에 불필요한 자리수는 제거한다.

```cpp
string multiply(string num1, string num2) {
  int length1 = num1.length();
  int length2 = num2.length();
  string answer(length1 + length2, '0');

  for (int first = length1 - 1; first >= 0; first--) {
    for (int second = length2 - 1; second >= 0; second--) {
      int cur = (num1[first] - '0') * (num2[second] - '0') + (answer[first + second + 1] - '0');

      answer[first + second + 1] = cur % 10 + '0';
      answer[first + second] += cur / 10;
    }
  }
  for (int i = 0; i < length2 + length1; i++) {
    // 불필요한 자리수 제거
    if (answer[i] != '0') return answer.substr(i);
  }
  return "0";
}
```

## 고생한 점
