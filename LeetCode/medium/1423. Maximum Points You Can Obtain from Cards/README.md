# 1423. Maximum Points You Can Obtain from Cards

[링크](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

카드의 갯수를 N, 입력받은 수를 K라고 하자.

왼쪽에서, 오른쪽에서 합쳐 총 K개의 카드를 뽑으면 된다.

따라서 왼쪽의 갯수, 오른쪽의 갯수를 변경하기 위해 순회를 통해 탐색할 수 있으며,

이는 O(K)의 시간 복잡도를 사용한다.

해당 K개의 숫자를 빠르게 뽑기 위해서 이전에 동적 계획법으로 미리 부분합을 구해놓고 사용한다.

이 경우 부분합을 모두 구하는 데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + K)이다.

부분합을 최적화 해 왼쪽, 오른쪽에서 뽑는 수만을 투 포인터로 변경하며 정답을 구할 수 있다.

이 경우 한쪽에서 모든 값을 뽑는 경우를 구하는 데 O(K)의 시간 복잡도를 사용하며 순회에도 동일하게 사용한다.

따라서 시간 복잡도는 O(K)가 된다.

### 공간 복잡도

부분합을 사용하기 위해 O(N)의 공간이 필요하다.

투 포인터를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 부분합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      74      |  O(N + K)   |    O(N)     |

부분합을 이용해 특정 range의 합을 빠르게 구할수 있도록 한다.

이후에 왼쪽, 오른쪽에서 뽑을 카드의 수를 변경하며 모든 경우를 탐색한다.

이를 구현하면 다음과 같다.

```cpp
int maxScore(vector<int>& cardPoints, int k) {
  int size = cardPoints.size();
  vector<int> dp(size + 1, 0);

  dp[1] = cardPoints[0];
  for (int i = 2; i <= size; i++) {
    dp[i] = dp[i - 1] + cardPoints[i - 1];
  }

  int answer = dp[k - 1];
  int diff = size - k - 1;
  for (int left = 0; left <= k; left++) {
    int leftPart = dp[left];
    int rightPart = dp[size] - dp[size - (k - left)];

    int curAnswer = leftPart + rightPart;
    answer = max(curAnswer, answer);
  }

  return answer;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |    O(K)     |    O(1)     |

연속된 합을 구해야 하므로 다음과 같이 구할 수 있다.

미리 왼쪽에서 모든 카드를 뽑는 경우를 구한다.

이후 왼쪽에서 뽑은 카드 중 가장 오른쪽값을 빼고, 오른쪽에서 가장 왼쪽에 있는 값을 더한다.

이를 K번 반복한다.

이는 연속된 카드를 뽑아야 하기 때문이다.

이를 구현하면 다음과 같다.

```cpp
int maxScore(vector<int>& cardPoints, int k) {
  int size = cardPoints.size();

  int curSum = 0;
  for (int i = 0; i < k; i++) {
    curSum += cardPoints[i];
  }
  int answer = curSum;

  for (int left = k - 1; left >= 0; left--) {
    int right = left + size - k;

    curSum -= cardPoints[left];
    curSum += cardPoints[right];

    answer = max(curSum, answer);
  }

  return answer;
}
```

## 고생한 점
