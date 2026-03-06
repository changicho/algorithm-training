# 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

[링크](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회하며 각 문자중 가장 큰 숫자를 찾는 경우 순회에 (N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1) 의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

0, 1로만 이루어진 숫자를 최소한의 갯수로 더해서 N을 만들어야 한다.

이 때 각 자리수별로 존재하는 숫자가 1로 이루어진 숫자를 더할 수 있다.

이를 반복할 때 결국 각 자리수에 존재하는 가장 큰 숫자만큼 1로 이루어진 숫자를 더해야 한다.

```cpp
int minPartitions(string n) {
  int answer = 0;
  for (char& c : n) {
    answer = max(answer, c - '0');
  }
  return answer;
}
```

## 고생한 점
