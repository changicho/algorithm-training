# 1304. Find N Unique Integers Sum up to Zero

[링크](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

탐욕 알고리즘을 사용해 임의의 수를 채워넣는다. 이에 O(N) 이 소요된다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

1부터 n/2까지의 해당 수를 절대값으로 하는 양수, 음수를 정답에 추가한다.

두 수의 합은 0이 된다.

이후 n이 홀수인 경우 0을 추가한다.

```cpp
vector<int> sumZero(int n) {
  vector<int> answer = {};

  if (n % 2 == 1) {
    answer.push_back(0);
    n--;
  }

  for (int i = 0; i < n; i += 2) {
    answer.push_back(i + 1);
    answer.push_back(-(i + 1));
  }

  return answer;
}
```

## 고생한 점
