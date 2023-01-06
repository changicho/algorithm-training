# 1056. Confusing Number

[링크](https://leetcode.com/problems/confusing-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 숫자를 N이라 할 때 N을 문자열로 나타낼 때의 길이를 L이라 하자. (N <= 10^9, L <= 10)

N을 문자열로 변경하고 이를 뒤집어 순회하며 새로운 수를 만든다.

이 둘이 같은지 비교한다.

이 경우 순회에 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 숫자를 변환할 경우 O(L)의 공간 복잡도를 사용한다.

### 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(L)     |    O(L)     |

n을 거꾸로 순회하며 각 숫자에 대해 변환 후 이를 숫자로 바꿧을 때 n과 같은지 판단한다.

이 때 회전했을 때 유효하지 않은 숫자가 나오는 경우는 바로 false를 반환한다.

```cpp
bool confusingNumber(int n) {
  unordered_map<char, char> table = {
      {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

  string num = to_string(n);
  string converted = "";

  for (int i = num.length() - 1; i >= 0; i--) {
    if (table.count(num[i]) > 0) {
      converted += table[num[i]];
    } else {
      return false;
    }
  }

  return stoi(converted) != n;
}
```

## 고생한 점
