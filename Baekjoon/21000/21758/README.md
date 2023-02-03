# 21758. 꿀 따기

[링크](https://www.acmicpc.net/problem/21758)

| 정답률 (%) | 난이도 |
| :--------: | :----: |
|   37.332   | 골드 V |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

모든 index에 대해 벌 2마리와 꿀통의 위치에 대해 모두 탐색할 경우 경우의 수에 O(N^3)의 시간 복잡도를 사용한다.

두 벌중 한마리는 양 끝에 위치하고 꿀통은 맨 끝이나 index중 하나에 위치시키는 탐욕 알고리즘을 사용할 수 있다.

이 경우 prefixSum을 이용할 경우 한번의 순회로 답을 구할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefixSum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 누적 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

문제에서 정답의 종류는 다음 3가지 중 하나이다.

- bee ~ bee ~ honey
- honey ~ bee ~ bee
- bee ~ honey ~ bee

위는 벌들과 꿀통의 위치를 나타낸다.

각 index마다 꿀의 양은 양수이다.

따라서 벌과 꿀통은 3번의 경우를 제외하곤 양 끝에 위치하는편이 유리하다.

(벌이 꿀까지 이동하는 길이가 길면 길수록 유리하기 때문)

이 때 벌과 꿀통 사이 2번째 벌이 위치하는 공간의 꿀을 얻지 못하므로 2번째 벌의 위치를 순회시키며 정답을 찾는다.

꿀통이 벌 사이에 위치하는 경우는 꿀통을 index를 순회하며 위치시켜 정답을 갱신한다.

```cpp
long long solution(int n, vector<int> &nums) {
  long long answer = 0;

  vector<long long> prefixLeft(n, 0);
  vector<long long> prefixRight(n, 0);

  for (int i = 0, leftSum = 0; i < n; i++) {
    prefixLeft[i] = i > 0 ? prefixLeft[i - 1] : 0;
    prefixLeft[i] += nums[i];
  }

  for (int i = n - 1, rightSum = 0; i >= 0; i--) {
    prefixRight[i] = i < n - 1 ? prefixRight[i + 1] : 0;
    prefixRight[i] += nums[i];
  }

  // bee ~ bee ~ honey
  for (int i = 1; i < n - 1; i++) {
    long long cur = prefixLeft[n - 1] - nums[0];
    cur -= nums[i];
    cur += prefixRight[i] - nums[i];

    answer = max(answer, cur);
  }

  // honey ~ bee ~ bee
  for (int i = n - 2; i >= 1; i--) {
    long long cur = prefixLeft[n - 1] - nums[n - 1];
    cur -= nums[i];
    cur += prefixLeft[i] - nums[i];

    answer = max(answer, cur);
  }

  // bee ~ honey ~ bee
  for (int i = 1; i < n - 1; i++) {
    long long cur = prefixLeft[i] + prefixRight[i] - nums[0] - nums[n - 1];

    answer = max(answer, cur);
  }

  return answer;
}
```

## 고생한 점
