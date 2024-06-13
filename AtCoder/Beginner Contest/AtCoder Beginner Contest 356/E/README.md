# E - Max/Min

[링크](https://atcoder.jp/contests/abc356/tasks/abc356_e)

| 난이도 |
| :----: |
|  475   |

## 설계

### 시간 복잡도

입력받은 수의 갯수를 N, 수의 범위를 M이라 하자. (M <= 1e6)

직접 모든 쌍을 구할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

M의 범위가 작으므로 카운팅 정렬과 각 범위에 숫자의 갯수를 prefix sum을 이용해 빠르게 구할 수 있다.

이 때 각 숫자마다 범위를 탐색하는 데 harmonic series만큼 탐색하므로 총 O(M \* log_2(M))의 시간 복잡도를 사용한다.

따라서 총 O(M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

카운팅 정렬, prefix sum을 사용하는 데 O(M)의 공간 복잡도를 사용한다.

### 카운팅 정렬 & prefix sum

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      54      | O(M \* log_2(M)) |    O(M)     |

N보다 M이 작으므로 카운팅 정렬을 사용한다.

현재 수를 X라 할 때 각 범위마다 정답에 더해지는 숫자는 다음과 같다.

- X ~ (2-1) : 1
- 2X ~ (3X-1) : 2
- 3X ~ (4X-1) : 3

각 더해지는 숫자마다 범위에 규칙이 있고, 해당 범위에 존재하는 수의 갯수를 안다면 정답에 더해지는 갯수를 빠르게 파악할 수 있다.

각 X마다 탐색하는 범위의 수는 다음과 같다.

- X=1 : M/1
- X=2 : M/2
- X=3 : M/3
- ...

따라서 X에 대해 순회하면서 더해지는 범위의 총 합은 M/1 + M/2 + M/3 + ... + M/M이 된다.

이는 M * log_2(M)이다.

여기서 현재 X에 대해서 X ~ (2X-1)을 탐색할 때 X가 중복되서 counting 될 수 있으므로 (중복쌍은 제외해야함)

해당 경우에는 별도로 처리한다.

```cpp
long long solution(int n, vector<int> &arr) {
  long long sum = accumulate(arr.begin(), arr.end(), 0LL);
  long long maximum = *max_element(arr.begin(), arr.end());

  long long answer = 0;

  int counts[1000001] = {
      0,
  };
  int prefixSums[1000002] = {
      0,
  };
  for (int i = 0; i < n; i++) {
    int num = arr[i];
    counts[num]++;
  }

  for (int i = 1; i <= 1e6; i++) {
    prefixSums[i] = prefixSums[i - 1] + counts[i];
  }

  for (long long num = 1; num <= 1e6; num++) {
    if (counts[num] == 0) continue;

    // num+1 ~ num*2-1
    long long left = num, right = min(num * 2 - 1, (long long)1e6);

    long long count = prefixSums[right] - prefixSums[left];
    answer += count * counts[num];
    answer += (long long)counts[num] * (counts[num] - 1) / 2;

    for (long long multiple = num * 2; multiple <= 1e6; multiple += num) {
      // multiple ~ multiple+num-1
      long long left = multiple,
                right = min(multiple + num - 1, (long long)1e6);
      long long count = prefixSums[right] - prefixSums[left - 1];
      long long curScore = multiple / num;

      answer += count * curScore * counts[num];
    }
  }

  return answer;
}
```

## 고생한 점
