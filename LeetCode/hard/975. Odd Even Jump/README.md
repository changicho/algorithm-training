# 975. Odd Even Jump

[링크](https://leetcode.com/problems/odd-even-jump/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자.

브루트 포스 방법으로 풀이할 경우 각 index 마다 순회하며 맨 끝까지 도달 가능한지 검사한다.

이 때 현재 index에서 넘어갈 다음 index를 찾는데 O(N)의 시간 복잡도가 소요되며, 이를 끝까지 도달하기 위해서 최대 N번 반복하게 된다.

따라서 브루트 포스의 경우 시간 복잡도는 O(N^3)이며 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전에 탐색한 경우에 대해서 또 탐색하지 않고 이전 결과를 사용할 수 있다. 이 경우 각 index마다 dp값을 구해야 하므로 O(N)의 시간 복잡도를 사용한다.

짝수, 홀수 점프마다 넘어갈 다음 index를 구하기 위해 이진 탐색을 사용할 수 있다.

따라서 이진 탐색 + 동적 계획법을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 + upper bound, lower bound

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     112      | O(N \* log_2(N)) |    O(N)     |

완전 탐색의 경우를 의사 코드로 나타내면 다음과 같다.

```cpp
// iterate all index. 0 <= i < size
  // check canReachable(index)
  // if canReachable
    // answer += 1
// return answer
```

여기서 현재 index에서 jump의 수가 홀수, 짝수인경우 다음으로 넘어갈 때의 index들을 각각 다음과 같다고 하자.

- oddNext
- evenNext

만약 이전에 oddNext, evenNext에 대해서 끝까지 도달 가능한지 탐색했던 경우 이를 사용할 수 있다.

따라서 다음과 같은 dp를 사용한다.

```cpp
// dp[index][isOdd]; can reach to last
vector<vector<bool>> dp(size, vector<bool>(2, false));

// initialize
dp[size - 1][true] = true;
dp[size - 1][false] = true;

// update
if(oddNext) dp[index][true] = dp[oddNext][false];
if(evenNext) dp[index][false] = dp[evenNext][true];
```

index에 대해서 (index + 1) ~ (size - 1)까지만 탐색하면 되므로 뒤에서부터 탐색할 경우 이전에 탐색한 모든 결과를 이용할 수 있다.

여기서 oddNext와 evenNext를 빠르게 구해야 한다.

이를 위해 map과 lower_bound, upper_bound를 이용한다.

- 짝수 : lower_bound 로 찾은 값 (이상이며 최소인 경우)
- 홀수 : upper_bound 로 찾은 값의 이전 값 (이하이며 최대인 경우)

이는 lower_bound를 사용할 경우 이상인 가장 작은 값을, upper_bound를 이용할 경우 초과인 가장 작은 값을 찾기 때문이다.

매 값마다 뒤에서부터 순회하며 map에 삽입하며 현재 index에서 이후의 값들만 바라보도록 구성한다.

map의 구조는 다음과 같다.

- key : number
- value : index

여기서 이전에 나온 number가 중복될 경우는 더 작은 index로 갱신한다. (문제 조건)

```cpp
int oddEvenJumps(vector<int>& arr) {
  int size = arr.size();

  // dp[index][isOdd]; can reach to last
  vector<vector<bool>> dp(size, vector<bool>(2, false));
  map<int, int> numbers;  // key : num, value : index

  dp[size - 1][true] = true;
  dp[size - 1][false] = true;

  numbers[arr.back()] = size - 1;

  for (int index = size - 2; index >= 0; index--) {
    auto odd = numbers.lower_bound(arr[index]);
    if (odd != numbers.end()) {
      int oddNext = odd->second;
      dp[index][true] = dp[oddNext][false];
    }

    auto even = numbers.upper_bound(arr[index]);
    if (even != numbers.begin()) {
      --even;
      int evenNext = even->second;
      dp[index][false] = dp[evenNext][true];
    }

    numbers[arr[index]] = index;
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (dp[i][true]) answer += 1;
  }

  return answer;
}
```

## 고생한 점

map구조의 경우 insert 메소드를 사용할 경우 overwrite가 되지 않는다.
