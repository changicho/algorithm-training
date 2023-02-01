# 21757. 나누기

[링크](https://www.acmicpc.net/problem/21757)

| 정답률 (%) | 난이도  |
| :--------: | :-----: |
|   20.726   | 골드 II |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^4)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

문제에서 모든 합에 대해 구성할 수 있는 가능한 경우의 수를 각 index마다 더할 수 있다.

누적합 (prefix sum)을 이용해 각 index에 대한 필요한 값을 미리 계산하는 데 O(N)의 시간 복잡돌르 사용한다.

이를 모든 index에 대해 구할 경우 O(N)의 시간 복잡도를 사용한다.

만약 합이 0인 경우는 조합론을 이용해 구할 수 있다. 이 때 중복호출을 줄일 경우 O(N) 의 시간 복잡도로 풀이 가능하다.

### 공간 복잡도

누적합을 사용하는데 O(N)의 공간 복잡도를 사용한다.

조합론을 사용하는 데 O(N)의 공간 복잡도를 사용한다.

### 조합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

만약 모든 수의 합을 S라 하자.

특정 index까지의 합이 S/2 인 경우 해당 index를 기준으로 왼쪽에서 S/4, 오른쪽에서 S/4가 되는 지점을 찾으면 된다.

이 때 S/4가 되는 지점이 여러개 있을 수 있으므로 index를 기준으로 왼쪽에 존재하는 수와 오른쪽에 존재하는 수의 곱 (경우의 수)을 정답에 더한다.

만약 S가 0인 경우가 존재할 수 있다.

이 경우는 누적합이 0이 되는 지점의 수를 구하고, 이에 대해 combination을 구하면 된다.

여기서 구간을 4개로 나누기 위해 골라야 하는 분기점은 총 3개이며, 맨 마지막 점은 마지막 구간의 끝이므로 combination(N - 1, 3)에 대해 구한다.

이를 구현하면 다음과 같다.

```cpp
long long combiDp[100000 + 1][3 + 1];

long long combination(int n, int r) {
  if (n < r) return 0;
  if (combiDp[n][r] != 0) return combiDp[n][r];
  if (n == r || r == 0)
    return combiDp[n][r] = 1;
  else
    return combiDp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

long long getZeroCaseAnswer(int n, vector<int> &array) {
  int count = 0;
  for (int i = 0, leftSum = 0; i < n; i++) {
    leftSum += array[i];
    if (leftSum == 0) count++;
  }

  return combination(count - 1, 4 - 1);
}

long long solution(int n, vector<int> &array) {
  int sum = 0;
  for (int &num : array) {
    sum += num;
  }

  if (sum % 4 != 0) return 0;
  if (sum == 0) {
    return getZeroCaseAnswer(n, array);
  }

  vector<int> quartersLeft(n), quartersRight(n);
  for (int i = 0, leftSum = 0; i < n; i++) {
    leftSum += array[i];

    quartersLeft[i] = i > 0 ? quartersLeft[i - 1] : 0;

    if (leftSum == (sum / 4)) {
      quartersLeft[i]++;
    }
  }

  for (int i = n - 1, rightSum = 0; i >= 0; i--) {
    rightSum += array[i];

    quartersRight[i] = i < n - 1 ? quartersRight[i + 1] : 0;

    if (rightSum == (sum / 4)) {
      quartersRight[i]++;
    }
  }

  long long answer = 0;
  for (int i = 0, leftSum = 0; i < n - 1; i++) {
    leftSum += array[i];

    if (leftSum == (sum / 2)) {
      answer += (long long)quartersLeft[i] * (long long)quartersRight[i + 1];
    }
  }

  return answer;
}
```

## 고생한 점
