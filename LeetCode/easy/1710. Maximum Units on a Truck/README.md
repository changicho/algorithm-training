# 1710. Maximum Units on a Truck

[링크](https://leetcode.com/problems/maximum-units-on-a-truck/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

boxTypes의 크기를 N, 특정 box의 최대 갯수를 X라 하자.

모든 box의 weight는 같다. 따라서 가치가 높은 순서대로 truckSize만큼 고르면 된다.

이를 위해 정렬을 수행한다. 이 과정에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 각 box를 순회하며 고른다. 이 과정에 순회가 아니라 계산을 이용해 구현할 경우 O(1)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

입력받은 배열을 바로 정렬할 경우 별도의 공간 복잡도를 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 정렬 & 그리디

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      50      | O(N \* log_2(N)) |    O(1)     |

모든 box를 가치에 따라 정렬 후 가치가 높은 순서대로 고른다.

이 때 해당 box type을 모두 고를 수 있는경우 모두 더한다.

일부만 고르는 경우는 고를 수 있는 수 만큼과 가치를 곱한 값을 더한다.

```cpp
int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
  sort(boxTypes.begin(), boxTypes.end(),
        [](vector<int> &a, vector<int> &b) { return a[1] > b[1]; });

  int count = 0;
  int answer = 0;
  for (vector<int> &box : boxTypes) {
    if (count + box[0] < truckSize) {
      count += box[0];
      answer += box[0] * box[1];

      continue;
    }

    int diff = truckSize - count;
    count += diff;
    answer += box[1] * diff;

    if (count == truckSize) break;
  }

  return answer;
}
```

## 고생한 점
