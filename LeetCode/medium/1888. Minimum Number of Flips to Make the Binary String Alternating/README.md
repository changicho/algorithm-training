# 1888. Minimum Number of Flips to Make the Binary String Alternating

[링크](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 경우를 직접 계산할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

prefix suffix를 이용해 각 index별로 나누었을 때 변경횟수를 이용해 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix suffix 갯수만 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix suffix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

특정 index를 기준으로 왼쪽과 오른쪽으로 나누어 생각할 수 있다.

왼쪽 부분을 이동시켜 오른쪽 부분 뒤에 붙인다고 가정하자.

이 경우 실제 시작 문자가 '0', '1'일 때 변경 횟수를 각각 구할 수 있다.

이후 변경된 문자열의 시작 문자에 따라 필요한 변경 횟수 중 작은 값을 반환한다.

문자열의 길이가 짝수인 경우는 왼쪽 부분을 이동시키더라도 시작 문자에 따라 규칙을 유지한다.

그러나 문자열의 길이가 홀수인 경우는 왼쪽 부분이 이동한 이후 시작 문자에 따른 규칙이 변경된다.

```cpp
int minFlips(string s) {
  int size = s.size();

  int fromLeft = 0;
  for (int i = 0; i < size; i++) {
    char target = (i % 2 + '0');
    if (target != s[i]) {
      fromLeft++;
    }
  }

  int answer = min(fromLeft, size - fromLeft);

  if (size % 2 == 1) {
    int fromRight = 0;
    for (int i = size - 1; i >= 0; i--) {
      char target = (i % 2 + '0');
      if (target != s[i]) {
        fromRight++;
        fromLeft--;
      }

      answer = min(fromRight + (i - fromLeft), answer);
      answer = min(size - (fromRight + (i - fromLeft)), answer);
    }
  }

  return answer;
}
```

## 고생한 점
