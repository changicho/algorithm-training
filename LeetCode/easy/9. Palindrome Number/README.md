# 9. Palindrome Number

[링크](https://leetcode.com/problems/palindrome-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

숫자 N은 정수형이다. N의 자리수 만큼만 연산을 수행하면 되므로 시간복잡도는 O(log_10(N)) 이다.

이는 상수이다.

### 공간 복잡도

int형 이내의 수가 주어지며 연산시에 int범위를 초과하지 않으므로 int형으로 충분하다.

### 배열

문자열, 배열, 데크 등으로 변환한 뒤에 맨 앞과 맨 뒤를 비교해가며 판별한다.

```cpp
string str = to_string(x);
int length = str.length();
for (int index = 0; index < length / 2; index++) {
  if (str[index] != str[length - 1 - index]) return false;
}
```

### 숫자

위 배열 방법과 비슷한 방법이며 절반을 기준으로 숫자를 구분한다.

x를 나머지 연산을 이용해 자리를 뒤집으며 수를 reversed를 생성한다.

이 뒤집은 수가 x와 비교해 같거나, 커졌을 때 까지 연산을 지속한다.

만약 x의 자리수가 짝수인 경우, 같은 자리수의 x와 reversed가 생성된다. 두 수가 같은 경우 팰린드롬이라 판별할 수 있다.

x의 자리수가 홀수인 경우 x보다 한자리수가 더 큰 reversed가 생성된다. reversed의 맨 마지막 자리는 펠린드롬에 영향을 주지 않는다.

따라서 해당 자리를 제거하고 비교한다.

만약 x의 맨 뒤자리에 0이 존재하는 경우 절대로 팰린드롬이 될 수 없다. (입력받는 수 x의 앞에 0이 붙어있지 않으므로)

이 경우 x가 0인 경우는 팰린드롬이므로 예외처리한다.

```cpp
if (x < 0) return false;
if (x == 0) return true;
if (x % 10 == 0) return false;

int reversed = 0;
while (x > reversed) {
  reversed *= 10;
  reversed += x % 10;
  x /= 10;
}

return x == reversed || x == reversed / 10;
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
