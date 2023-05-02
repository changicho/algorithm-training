# Collecting Pancakes (4pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c9607c/0000000000cad7d1)

## 설계

### 시간 복잡도

pancakes의 크기를 N이라 하자.

alice와 bob의 선택할 수 있는 경우의 수는 최대 N^2가지 이다. (선택 가능한 범위가 N에 좌우되므로)

한 경우마다 탐색을 O(N)의 시간복잡도로 진행한다 하더라도 O(N^3)의 시간 복잡도를 사용하므로 모든 경우를 탐색하는 건 제한시간 내에 불가능하다.

그리디 알고리즘을 이용해 최선의 값을 선택한다.

이 경우 alice가 먼저 선택하므로 alice가 선택 가능한 범위에 대해 탐색하며 해당 경우마다 bob이 최선의 값을 선택한다.

이를 위해 미리 prefix sum, suffix sum을 구해놓을 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum, suffix sum에 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘 & prefix sum, suffix sum

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

alice와 bob은 처음 선택한 값과 연결되어있는 값들 (이웃한 값들)만 선택 가능하다.

이는 alice가 선택했을 때 bob이 어떤 값을 선택하느냐에 따라 alice가 이후에 선택 못하도록 막을 수 있다.

따라서 alice가 선택한 값에 대해서만 탐색을 진행하며 각 경우마다 bob이 최선의 값을 (방어)선택하도록 한다.

alice가 값을 선택했을 때 bob이 오른쪽, 왼쪽으로 막는 경우마다 값을 구해보고 이 중 최선의 값을 선택한다.

이 때 두 구간이 겹치지 않는 경우는 가장 많이 막을 수 있는 값으로 선택한다.

만약 두 구간이 겹치는 경우는 alice가 선택한 값의 이웃한 값 중 하나를 선택한다.

만약 alice가 선택한 값과 bob이 선택한 값 사이에 다른 값들이 존재하는 경우는 해당 구간의 절반은 alice가 선택하고 남은 절반은 bob이 선택하게 된다.

이 때 해당 구간의 값이 홀수개인 경우 alice가 하나 더 선택하게 된다. (먼저 선택하므로)

```cpp
struct Range {
  int start, end;
};

long long solution(vector<long> &pancakes, Range &alice, Range &bob) {
  int size = pancakes.size();
  long long answer = 0;

  vector<long long> prefixes(size, 0), suffixes(size, 0);
  prefixes[0] = pancakes[0];
  suffixes[size - 1] = pancakes[size - 1];

  for (int i = 1; i < size; i++) {
    prefixes[i] = prefixes[i - 1] + pancakes[i];
    suffixes[size - 1 - i] = suffixes[size - i] + pancakes[size - 1 - i];
  }
  long long allSum = prefixes[size - 1];

  for (int choose = alice.start; choose <= alice.end; choose++) {
    long long bobMaximum = 0;

    // left block case
    int leftBlock = choose - 1;
    if (leftBlock >= 0) {
      if (bob.start <= leftBlock && leftBlock <= bob.end) {
        // bob block (choose - 1)
        long long bobSum = prefixes[choose - 1];
        long long aliceSum = suffixes[choose];

        bobMaximum = max(bobMaximum, bobSum);
      } else if (bob.end < leftBlock) {
        // bob block his most right
        int diff = leftBlock - bob.end;

        int bobRight = bob.end + (diff) / 2;
        int aliceLeft = choose - (diff) / 2;
        if (bobRight == aliceLeft) bobRight--;

        long long bobSum = prefixes[bobRight];
        long long aliceSum = suffixes[aliceLeft];

        bobMaximum = max(bobMaximum, bobSum);
      }
    }

    int rightBlock = choose + 1;
    if (rightBlock < size) {
      if (bob.start <= rightBlock && rightBlock <= bob.end) {
        // bob block (choose + 1)
        long long bobSum = suffixes[choose + 1];
        long long aliceSum = prefixes[choose];

        bobMaximum = max(bobMaximum, bobSum);
      } else if (rightBlock < bob.start) {
        // bob block his most left
        int diff = bob.start - rightBlock;

        int bobLeft = bob.start - (diff) / 2;
        int aliceRight = choose + (diff) / 2;
        if (bobLeft == aliceRight) bobLeft++;

        long long bobSum = suffixes[bobLeft];
        long long aliceSum = prefixes[aliceRight];

        bobMaximum = max(bobMaximum, bobSum);
      }
    }

    answer = max(answer, allSum - bobMaximum);
  }

  return answer;
}
```

## 고생한 점
