# A. Insert Digit

[링크](https://codeforces.com/contest/1811/problem/A)

## 시간 복잡도

문자열의 길이를 N이라 하자.

삽입했을 때 가장 수가 높아지는 위치를 찾고 이에 삽입한다.

이 경우 순회에 O(N), 삽입 후 새로운 문자열을 반환하는데 O(N)의 시간 복잡도를 사용한다.

## 공간 복잡도

새로운 문자열에 O(N)의 공간 복잡도를 사용한다.

## 순회

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

입력받은 수를 맨 앞에서부터 순회하며 추가하려는 수 보다 작은 수가 나올 때 까지 순회한다.

만약 현재 위치의 수가 추가하려는 수보다 작다면 추가하려는 수를 현재 위치 왼쪽에 추가한다.

```cpp
auto solution(int size, string &number, int digit) {
  for (int i = 0; i < size; i++) {
    int cur = number[i] - '0';

    if (cur < digit) {
      number.insert(i, to_string(digit));
      break;
    }
  }
  if (number.size() == size) {
    number += to_string(digit);
  }

  return number;
}
```