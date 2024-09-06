# 1894. Find the Student that Will Replace the Chalk

[링크](https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 chalk의 크기를 N, 반복 횟수를 K라 하자. (N <= 10^5, K <= 10^9)

K에 대해 직접 반복할 경우 최악의 경우 시간 복잡도는 O(K)이며 이는 제한시간 내에 불가능하다.

chalk의 합에 대해 mod를 수행하고 이를 이용해 풀이할 수 있다. 이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

합이 int형을 초과할 수 있다.

수를 이용해 풀이할 경우 O(1)의 공간 복잡도를 사용한다.

### 나머지

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      91      |    O(N)     |    O(1)     |

실제 k번을 움직일 때, 현재 주어진 배열 chalk의 합보다 더 움직이는 경우가 생길 수 있다.

따라서 반복되는 부분은 무시하기 위해 k를 chalk의 합으로 나눈 나머지만큼만 이동한다.

이후 실제 남은 k에 대해 이동하며, k가 음수로 변화는 index를 찾는다.

```cpp
int chalkReplacer(vector<int>& chalk, int k) {
  int size = chalk.size();

  long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);

  k %= sum;

  for (int i = 0; i < size; i++) {
    k -= chalk[i];
    if (k < 0) return i;
  }
  return 0;
}
```

## 고생한 점
