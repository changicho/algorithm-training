# 2279. Maximum Bags With Full Capacity of Rocks

[링크](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배낭과 바위의 현재 상태의 갯수를 N, additionalRocks를 M이라 하자.

(N <= 4 \* 10^4, M <= 10^9)

각 배낭 중 남은 공간이 적은 배낭부터 채울 수 있다. 이 남은 공간들에 대해 정렬할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 각 남은 공간을 순회하며 채울수 있을 만큼 채울 수 있다.

이 경우 순회에 O(N)의 공간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

남은 공간들을 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     202      | O(N \* log_2(N)) |    O(N)     |

남은 공간의 갯수가 적은 배낭부터 채워넣는 편이 유리하다.

따라서 각 가방마다 남은 공간에 대해 정렬한다.

이후 각 가방을 순회하며 부족한만큼 additionalRocks에서 빼고 채워넣는다.

이 때 additionalRocks의 크기가 매우 크므로 하나씩 채워넣는 경우 제한시간 내에 불가능하다.

이를 구현하면 다음과 같다.

```cpp
int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
  int size = capacity.size();

  vector<int> diffs;

  for (int i = 0; i < size; i++) {
    diffs.push_back(capacity[i] - rocks[i]);
  }
  sort(diffs.begin(), diffs.end());

  int answer = 0;
  for (int& diff : diffs) {
    if (additionalRocks < diff) break;

    additionalRocks -= diff;
    answer++;
  }

  return answer;
}
```

## 고생한 점
