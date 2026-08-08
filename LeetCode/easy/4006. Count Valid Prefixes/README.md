# 4006. Count Valid Prefixes

[링크](https://leetcode.com/problems/count-valid-prefixes/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

prefix를 왼쪽부터 순회하며 정답을 갱신한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 0, 1의 갯수만 저장하므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

0과 1의 갯수의 차이가 1개 이하일 때 문제 조건에 맞는 연속된 숫자가 같지 않도록 배치 가능하다.

```cpp
int countValidPrefixes(string s) {
  int size = s.size();

  int answer = 0;
  int zero = 0, one = 0;

  for (int i = 0; i < size; i++) {
    if (s[i] == '0') {
      zero++;
    } else {
      one++;
    }

    if (abs(zero - one) <= 1) answer++;
  }

  return answer;
}
```

## 고생한 점
