# 2802. Find The K-th Lucky Number

[링크](https://leetcode.com/problems/find-the-k-th-lucky-number/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 K라 하자.

K로 정답을 구할 때 해당 정답의 길이는 log_2(K)이다.

K에 대해 자리수를 구한 뒤 이진수로 변환해 풀이할 수 있다.

이 경우 O(log_2(K))의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 문자열에 O(log_2(K))의 공간 복잡도가 필요하다.

### 비트 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       | O(log_2(K)) | O(log_2(K)) |

K번째 수의 자리수를 우선 구한다.

이는 K가 1-index 이므로 K에 1을 더한 값을 K'로 놓으며 log2(K')로 자리수를 구할 수 있다.

이후 해당 길이의 문자열을 생성한다.

4와 7로만 구성된 문자열이며 이를 2진수로 생각하면 다음과 같다.

- 4를 0, 7을 1로 대입해 생각하면 K'를 2진수로 변환한 값이 된다.

이를 이용해 구하면 다음과 같다.

```cpp
string convert(int num, int length) {
  string ret(length, '4');
  for (int i = 0; i < length; i++) {
    if (num % 2 == 1) {
      ret[i] = '7';
    }
    num /= 2;
  }

  reverse(ret.begin(), ret.end());
  return ret;
}

string kthLuckyNumber(int k) {
  k++;
  int digit = log2(k);
  k -= pow(2, digit);

  return convert(k, digit);
}
```

## 고생한 점
