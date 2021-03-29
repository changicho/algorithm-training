# 67. Add Binary

[링크](https://leetcode.com/problems/add-binary/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

a와 b의 길이는 최대 10^4 이다.

순회하며 더하면 되므로 최악의 경우 시간 복잡도는 O(10^4) 이다.

### 공간 복잡도

0과 1로 이루어진 string을 반환한다.

### 덧셈

입력받은 숫자들을 뒤집은 뒤 하나하나 더해간다.

이 때 편의를 위해 a.length 보다 b.length를 크게 설정한다.

덧셈이 끝난 이후 정답을 다시 뒤집는다.

```cpp
string addBinary(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string answer = "";
  if (a.length() > b.length()) swap(a, b);

  bool carry = false;

  for (int i = 0; i < a.length(); i++) {
    int count = (a[i] - '0') + (b[i] - '0') + carry;

    if (count >= 2) {
      count -= 2;
      carry = true;
    } else {
      carry = false;
    }

    answer += count == 0 ? '0' : '1';
  }

  for (int i = a.length(); i < b.length(); i++) {
    int count = (b[i] - '0') + carry;

    if (count >= 2) {
      count -= 2;
      carry = true;
    } else {
      carry = false;
    }

    answer += count == 0 ? '0' : '1';
  }

  if (carry) {
    answer += '1';
  }

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
