# 2568. 전깃줄 - 2

[링크](https://www.acmicpc.net/problem/2568)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   34.754    |       1       |

## 설계

### 시간 복잡도

전기줄의 개수는 최대 100,000 이하이다. 위치의 번호는 최대 500,000 이하이다.

LIS 알고리즘을 사용하는 경우 시간 복잡도는 O(N \* log(N)) 이다. 이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

위치의 최대 값은 500,000 이하이므로 int형으로 선언한다.

### LIS(Longest Increasing Subsequence)

최장 증가 수열

시간 복잡도 : O(N \* log(N))

- N : O(N)으로 배열을 탐색함
- logN : lower_bound로 최적의 자리를 찾음

배열을 순회하면서 벡터의 맨 뒤 원소와 현재 보고있는 수열의 원소를 비교한다.

수열의 원소가 더 클 시 벡터에 push_back해준 뒤 LIS의 크기(답)을 1증가 시킨다.
수열의 원소가 벡터의 맨 뒤 원소보다 작을 경우 lower_bound를 이용하여 최적의 자리를 찾은 뒤 그 자리의 값을 해당 수열의 원소로 교체한다.

LIS 배열을 구하기 위해선 각 index별로 어떤 값이 있는지 같이 저장해야한다.

```cpp
struct LIS {
  int index, from;
};
```

```cpp
vector<int> longestIncreasingSubsequence(int N, vector<int> array) {
  vector<LIS> lis;
  int lis_cache[MAX] = {
      0,
  };
  int index = 0;

  lis_cache[index] = array[0];
  lis.push_back({0, array[0]});
  for (int i = 1; i < N; i++) {
    if (lis_cache[index] < array[i]) {
      index++;
      lis_cache[index] = array[i];
      lis.push_back({index, array[i]});
    } else {
      int new_index = lower_bound(lis_cache, lis_cache + index, array[i]) - lis_cache;

      lis_cache[new_index] = array[i];
      lis.push_back({new_index, array[i]});
    }
  }

  // index + 1은 LIS 배열의 크기를 의미한다.
  // 역순으로 LIS 배열을 구한다. (index를 이용해 역순으로 구함)
  stack<int> s;
  for (int i = N - 1; i >= 0; i--) {
    if (lis[i].index == index) {
      s.push(lis[i].from);
      index--;
    }
  }

  // stack에 역순으로 저장되어있으므로 뒤집어 LIS 배열을 구함
  vector<int> ret;
  while (!s.empty()) {
    ret.push_back(s.top());
    s.pop();
  }

  return ret;
}
```

### 정답을 출력하는 경우

정답을 출력하기 위해 set 자료구조와 단순 배열을 사용했을 때 시간 차이는 다음과 같다.

- set : 64 ms
- array : 40 ms

set을 이용한 경우 시간 복잡도는 O(N \* log(N)) 이며 이는 최악의 경우 100,000 \* 17 = 1,700,000 이다.

단순 배열을 사용한 경우 시간 복잡도는 O(500,000) 이므로 단순 배열을 이용한 경우가 더 빠르다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      40      |       8        |

## 고생한 점
