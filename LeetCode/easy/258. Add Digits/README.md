# 258. Add Digits

[링크](https://leetcode.com/problems/add-digits/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

정답의 최대 값은 2,147,483,647 이다. 총 10자리 수 이며 10자리 수를 전부 더했을 때 최대로 가능한 수는 90 이다.

즉 모든 자리의 덧셈을 3번 이내로 수행해 1자리 숫자로 만들 수 있다.

따라서 시간 복잡도는 O(1)이다.

### 공간 복잡도

매 자리수들을 더하는 연산을 수행할 별도의 공간 하나만 필요하다.

이는 int형 이내임이 보장되며 공간 복잡도는 O(1)이다.

### 나머지 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

모든 수의 자리수를 더한 값이 10 미만일 때까지 반복한다.

최대 숫자가 int형임이 보장되므로 새로운 더한 값도 int형으로 선언한다.

```cpp
int addDigits(int num) {
  while (num >= 10) {
    int newNum = 0;
    while (num > 0) {
      newNum += num % 10;
      num /= 10;
    }
    num = newNum;
  }
  return num;
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

입력받은 숫자 N은 다음과 같이 나타낼 수 있다.

```javascript
n = d_0 + d_1 * 10 + d_2 * 100 + ... + d_k * (10^k)
```

10단위 숫자에 대해서 다음과 같이 생각할 수 있다.

```javascript
10 = 9 * 1 + 1
100 = 99 + 1 = 9 * 11 + 1
1000 = 999 + 1 = 9 * 111 + 1
// ...
10^k = 100 ... 0 = 99 ... 9 + 1 = 9 * 11 ... 1 + 1
```

따라서 위 식을 변경하면 다음과 같이 된다.

```javascript
n = (d_0 + d_1 + d_2 + ... + d_k) + 9 (d_1 * 1 + d_2 * 11 + ... + d_k * 11 ... 1)
```

이 수를 9로 나눈 나머지에 대해 생각할 경우 다음과 같이 변경된다.

```javascript
n % 9 = (d_0 + d_1 + d_2 + ... + d_k) % 9
```

따라서 N을 9로 나눈 나머지로 digit의 합을 구할 수 있다.

여기서 N이 9의 배수인경우, 0인 경우, 그 외 나머지 경우에 대해서 분기 처리한다.

따라서 다음 3가지 경우가 존재한다.

- 0인 경우 : 0
- 9의 배수인 경우 : 9
- 그 외의 경우 : 9로 나눈 나머지값

이를 이용해 구현하면 다음과 같다.

```cpp
int addDigits(int num) {
  if (num == 0) return 0;
  if (num % 9 == 0) return 9;

  return num % 9;
}
```

## 고생한 점
