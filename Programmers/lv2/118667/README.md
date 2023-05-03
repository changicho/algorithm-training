# 두 큐 합 같게 만들기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/118667)

| 난이도 |
| :----: |
| 레벨 2 |

## 설계

### 시간 복잡도

큐의 크기를 N이라 하자.

각 큐에서 특정 범위에 대한 합을 모두 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

이는 제한시간 내에 불가능하다.

따라서 하나의 큐의 범위를 이동시켜가며 합을 구하고 이를 둘로 나눌 수 있는지 판단한다.

이 때 다른 큐의 합을 미리 구해놓아 prefix sum을 이용한다.

이 경우 sliding window를 이용하면 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 구하는데 O(N)의 공간 복잡도를 사용한다.

### prefix sum & sliding window

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

두 큐의 원소를 다음과 같다고 하자.

```javascript
const queue1 = [A,B,C,D,E];
const queue2 = [a,b,c,d,e];
```

여기서 큐1의 원소를 일부 빼서 옮기고, 큐2의 원소를 일부 빼서 옮겼을 때 정답이 될 수 있다.

이 경우 하나의 큐의 구성은 다음과 같이 될 수 있다.

```cpp
const queue2 = [c,d,e,A,B];
// move a,b to queue1
// move A B to queue2
```

여기서 큐2로 이동한 A,B ... 의 경우는 큐1에 대한 prefix sum들이 된다.

따라서 큐1의 prefix sum을 구해놓고, 큐2의 suffix sum을 구하며 큐1의 prefix sum과 비교한다.

이후 다음과 같은 조건을 만족하는지 확인한다.

- (모든 값의 합 : sum)
- sum / 2 = prefix + suffix

여기서 prefix sum들을 미리 구해놓고, 해당 prefix sum을 구성하는 원소의 갯수를 저장해놓을 경우

suffix sum의 값과 해당 원소의 수를 토대로 최소 이동 횟수를 구할 수 있다.

반대로 특정 큐의 일부 값이 정답이 되는 경우를 살펴보자.

```javascript
const queue1 = [A,B,C,D,E];
const queue2 = [a,b,c,d,e];

// answer case
const queue = [c,d];
const otherQueue = [e,A,B,C,D,E,a,b];
```

위 경우 c,d의 합에 다른 합을 더하는 경우 sum/2 보다 큰 값이 된다.

따라서 suffix를 구할 때 sum/2 보다 커지는 경우 슬라이딩 윈도우를 이용해 해당 구간을 이동시킬 수 있다.

이 경우 최소 이동 횟수는 다음과 같이 구할 수 있다.

- left, right는 sliding window의 index이다.
- 큐의 일부만 선택해야 하기 때문에, 해당 구간을 포함하는 prefix를 다른 큐로 이동해야한다. (right + 1)
- 이후 다른 큐에서 해당 구간만 남기고 또 이동시킨다. (left + N)
- 이러면 다른 큐에 해당 구간만이 남게 된다.

여기서 두 큐중 어느 큐에 일부 구간만이 정답이 되는지 알 수 없다.

따라서 두 큐를 swap하며 두 번 정답을 구해 실제 정답을 구한다.

```cpp
int getMinimumCost(vector<int> queue1, vector<int> queue2) {
  int size = queue1.size();
  int answer = INT_MAX;

  unordered_map<long long, int> prefixes;

  long long sum = 0;
  for (int n : queue1) {
    sum += n;
  }
  for (int n : queue2) {
    sum += n;
  }

  if (sum % 2 != 0) {
    return INT_MAX;
  }

  long long temp = 0;
  prefixes[0] = 0;
  for (int i = 0; i < size; i++) {
    temp += queue1[i];
    prefixes[temp] = i + 1;
  }

  if (temp == (sum / 2)) {
    return 0;
  }

  temp = 0;
  for (int left = size - 1, right = size - 1; left >= 0; left--) {
    temp += queue2[left];
    // 슬라이딩 윈도우를 이용해 temp가 sum/2 이하가 될 때까지 right를 줄인다.
    while (temp > (sum / 2) && left < right) {
      temp -= queue2[right];
      right--;
    }

    // (sum/2 - temp) 라는 값이 prefixes에 있는가??
    if (right == size - 1) {
      if (prefixes.count((sum / 2) - temp) > 0) {
        int moveCount = prefixes[(sum / 2) - temp] + (left);

        answer = min(answer, moveCount);
      }
    }
    // 일부 구간이 sum/2가 되는 경우
    if (temp == (sum / 2)) {
      // 일부 구간만을 만들기 위해 다른 큐를 전부 비우고, 현재 구간까지 옮긴 뒤
      // 앞의 부분을 다시 뺀다.
      int moveCount = left + (right + 1) + size;

      answer = min(answer, moveCount);
    }
  }

  return answer;
}

int solution(vector<int> queue1, vector<int> queue2) {
  // 두 큐중에 한 큐의 일부 구간이 정답일 수 있으므로 두 경우를 모두 계산한다.
  int answer =
      min(getMinimumCost(queue1, queue2), getMinimumCost(queue2, queue1));

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
