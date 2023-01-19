# 926. Flip String to Monotone Increasing

[링크](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 N이라 하자.

monotone한 경우는 최대 N+1가지가 존재하며 이를 순회하며 비교해 정답을 구할 수 있다.

각 경우 모두 직접 비교할 경우 O(N^2)의 시간 복잡도를 사용한다.

prefix sum을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

순회와 동시에 답을 구할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |    O(N)     |    O(N)     |

monotone한 상태를 다음과 같이 두 부분으로 나눠 생각할 수 있다.

- 0 ~ (i-1) : 0으로 바꿈
- i ~ (N-1) : 1로 바꿈

여기서 i를 이동시키며 s의 각 위치를 바꿧을 때의 비용을 계산한다.

이 때 각 구간마다의 0, 1의 갯수를 빠르게 세기 위해 prefix sum을 이용한다.

1에 대한 prefix sum을 구하고 왼쪽 부분은 1을 0으로 바꾸고 오른쪽 부분은 0을 1로 바꿔야 하므로 계산에 주의한다.

이를 구현하면 다음과 같다.

```cpp
int minFlipsMonoIncr(string s) {
  int size = s.size();
  vector<int> prefixSums(size + 1, 0);

  for (int i = 0; i < size; i++) {
    prefixSums[i + 1] = prefixSums[i] + (s[i] == '1');
  }

  int answer = prefixSums[size];
  for (int i = 0; i < size; i++) {
    int left = prefixSums[i];                      // 0 ~ (i-1)
    int right = prefixSums[size] - prefixSums[i];  // i ~ (size-1)
    right = (size - i) - right;

    answer = min(answer, left + right);
  }
  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(N)     |    O(1)     |

위 prefix sum을 이용한 방법에서 왼쪽에서부터 i 순회하며 왼쪽 부분과 오른쪽 부분에 존재하는 1의 갯수를 갱신하며 진행한다.

```cpp
int minFlipsMonoIncr(string s) {
  int size = s.size();

  int leftOnes = 0, rightOnes = 0;
  for (int i = 0; i < size; i++) {
    rightOnes += (s[i] == '1');
  }

  int answer = size - rightOnes;
  for (int i = 0; i < size; i++) {
    if (s[i] == '1') {
      leftOnes++;
      rightOnes--;
    }

    int rightLength = size - 1 - i;

    answer = min(answer, leftOnes + (rightLength - rightOnes));
  }
  return answer;
}
```

## 고생한 점
