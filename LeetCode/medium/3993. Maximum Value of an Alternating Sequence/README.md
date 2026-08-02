# 3993. Maximum Value of an Alternating Sequence

[링크](https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

시뮬레이션을 이용해 정답을 찾을 경우 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

수학을 이용해 가능한 최대값을 찾을 수 있다. 이에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

계산에 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

최대한 증가하는 방향으로 이어나갈 경우 다음과 같이 값이 변환한다.

```cpp
+m, -1, +m, -1, +m, -1 ...
```

이를 이용해 n이 주어졌을 때 `(n - 1) / 2`번 만큼 (m-1) 크기의 값이 증가함을 알 수 있다.

이 때 n이 짝수, 홀수인지 여부에 따라 마지막에 값이 감소하는지 증가하는지가 구분된다.

만약 마지막에 값이 감소할 경우 직전값이 최대값이 된다.

```cpp
long long maximumValue(int n, int s, int m) {
  long long answer = s;
  long long half = (n - 1) / 2;

  answer += (m - 1) * (half);

  if (n % 2 == 0) {
    answer += m;
  } else if (n % 2 == 1 && n > 1) {
    answer++;
  }

  return answer;
}
```

## 고생한 점
