# 2226. Maximum Candies Allocated to K Children

[링크](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

candies의 크기를 N, candy의 최대값을 M이라 하자.

특정 값에 대해서 K명의 아이에게 나눌 수 있는지 여부는 candies를 순회하며 알 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

가능한 최대값을 사용하기 위해 이분 탐색을 사용한다. 이 경우 O(log_2(M))의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N \* log_2(M))이다.

### 공간 복잡도

이분 탐색에 별도의 배열등을 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     277      | O(N \* log_2(M)) |    O(1)     |

K명의 아이에게 사탕을 나눌 수 있는지 판단하기 위해 나머지연산을 사용한다.

이 경우 현재 pile개의 사탕을 나눌 수 있는지 판단하는 로직은 다음과 같다.

- 각 candy를 pile로 나눈 몫을 더한다.
- 이 값이 K보다 큰지 판단한다.

해당 로직은 다음과 같이 구현한다.

```cpp
bool isPossible(vector<int> &candies, long long &k, int &pile) {
  long long count = 0;

  for (int &candy : candies) {
    count += candy / pile;

    if (count >= k) return true;
  }

  return false;
}
```

탐색할 범위는 1부터 candies의 최대값 이다.

여기서 0으로 나눌 수 없기 때문에 정답의 초기값으로만 0을 설정하고, 탐색하진 않는다.

특정 X에 대해 이분 탐색을 사용할 수 있다. 이는 threshold가 linear하기 때문이다.

이를 이용해 구현하면 다음과 같다.

```cpp
int maximumCandies(vector<int> &candies, long long k) {
  int left = 1, right = 1e7 + 1;
  int answer = 0;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isPossible(candies, k, mid)) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
