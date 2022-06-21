# B. All Distinct

[링크](https://codeforces.com/contest/1692/problem/B)

| 난이도 |
| :----: |
| \*800  |

## 설계

### 시간 복잡도

매번 2가지 수를 빼는 모든 경우를 탐색할 경우의 시간 복잡도는 대략 O(2^N)이다.

이는 제한시간 내에 불가능하므로 수학적 방법을 이용한다.

각 수를 세고, 1개 초과인 수들을 1이하의 갯수가 남을 때 까지 뺀다.

이 과정을 count한다.

이 경우 시간 복잡도는 O(N)이 된다.

### 공간 복잡도

모든 수를 count하는 hash map을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### count & math

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

각 수를 세며 hash map에 카운팅한다.

이후 각 수들의 갯수가 1을 초과할 경우 1을 빼고 중복된 갯수에 더한다.

결국 정답을 구하기 위해 없애야 하는 최소갯수는 위에서 구한 중복된 갯수이다.

여기서 중복된 갯수가 짝수인 경우, 한번에 2개씩 제거할 수 있으므로 해당 갯수만큼 길이에서 뺀 값이 정답이 된다.

만약 홀수인 경우 해당 갯수만큼 길이에서 빼고 1을 더 빼준다. (짝수를 맞추기 위해 1개를 더 빼야함)

```cpp
int solution(vector<int> &nums) {
  int size = nums.size();

  int length = size;
  int dupCount = 0;
  unordered_map<int, int> counts;
  for (int &n : nums) {
    counts[n]++;
  }

  for (auto it : counts) {
    int val = it.second;
    dupCount += val - 1;
  }

  if (dupCount % 2 == 0) {
    length -= dupCount;
  } else {
    length -= dupCount + 1;
  }

  return length;
}
```

## 입출력

### input

```text
4
6
2 2 2 3 3 3
5
9 1 9 9 1
4
15 16 16 15
4
10 100 1000 10000
```

### output

```text
2
1
2
4
```

## 고생한 점
