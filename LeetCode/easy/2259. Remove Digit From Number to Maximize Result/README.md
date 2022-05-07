# 2259. Remove Digit From Number to Maximize Result

[링크](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

number의 길이를 N이라 하자.

특정 위치의 문자를 제거할 경우 O(N)의 시간 복잡도를 사용한다.

모든 경우를 탐색하며 정답을 찾을 경우 O(N^2)의 시간 복잡도를 사용한다.

그리디 알고리즘을 이용할 경우 한번의 순회중에 정답을 찾아 탐색을 중지할 수 있다.

이 경우 탐색에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 정답을 반환하는데 O(N)의 공간 복잡도를 사용한다.

문자열의 길이는 최대 100 까지이며, 이를 숫자형으로 사용할 경우 big integer를 사용해야 한다.

따라서 문자열을 이용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |   O(N^2)    |    O(N)     |

모든 문자열을 순회하며 digit인 경우 삭제한 숫자를 생성하고, 가장 큰 값을 반환한다.

```cpp
string removeDigit(string number, char digit) {
  int length = number.length();

  string maximum = "";

  for (int i = 0; i < length; i++) {
    if (number[i] != digit) continue;
    string curStr = number;
    curStr.erase(i, 1);

    if (curStr > maximum) {
      maximum = curStr;
    }
  }

  return maximum;
}
```

### check last digit

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(N)     |

현재 문자를 삭제했을 때 정답이 될 수 있는 경우는 다음 2가지중 하나이다.

- 삭제할 문자 이후 문자의 값이 현재값보다 큰 경우
- 삭제할 문자가 제일 끝 문자인 경우

첫번째 경우는 현재 값을 제거했을 때 같은 자리수에 더 큰값이 오기 때문이다.

이를 구현하면 다음과 같다.

```cpp
string removeDigit(string number, char digit) {
  int length = number.length();
  int target = number.rfind(digit);

  for (int i = 0; i < length - 1; i++) {
    if (number[i] != digit || number[i + 1] <= digit) continue;

    target = i;
    break;
  }

  number.erase(target, 1);
  return number;
}
```

## 고생한 점

숫자로 변환해 비교할 경우 out_of_range 에러가 발생한다.

```cpp
number[length]; // 이렇게 참조해도 에러가 발생하지 않음.
```