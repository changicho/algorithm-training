# 1675. Minimize Deviation in Array

[링크](https://leetcode.com/problems/minimize-deviation-in-array/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 nums의 크기를 N, nums의 원소의 최대값을 M이라 하자.

각 수를 변환 가능한 가장 작은 수로 변환하는 데 O(log_2(M))의 시간 복잡도를 사용한다.

따라서 총 O(N * log_2(M))의 시간 복잡도를 사용한다.

이를 map 구조에 삽입 후 가장 작은 수부터 순회하며 최소값을 갱신한다.

BST기반의 map을 사용할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

각 과정마다 최대값과 최소값의 차이를 정답으로 갱신한다.

따라서 총 시간 복잡도는 O(N * log_2(N * M)) 이다.

### 공간 복잡도

map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|     425      | O(N * log_2(N * M)) |    O(N)     |

각 수를 최대한 작게 만든다. 이는 더이상 2로 나누어 떨어지지 않을 때 까지 수를 변환하면 된다.

해당 값들은 홀수들 이므로 2의 배수를 곱해 변환할 수 있다.

가장 큰 값과 작은 값의 차이를 최소로 만들 기 위해 각 홀수들은 최대 한번씩만 2의 배수를 곱하는 것이 이득이다.

변환된 수들을 map에 저장하고 가장 작은 값부터 순회하며 최소값과 최대값의 차이를 갱신한다.

각 과정마다 현재 값이 변환 가능한 최대 값에 도달했다면, 가장 작은 값이 한계에 도달했으므로 탐색을 중지한다.

이를 구현하면 다음과 같다.

```cpp
int convert(int num) {
  if (num % 2 == 1) return num;

  while (num % 2 == 0) {
    num /= 2;
  }
  return num;
}

int minimumDeviation(vector<int>& nums) {
  map<int, int> uniqueNums;
  for (int& num : nums) {
    int converted = convert(num);

    int limit = num % 2 == 0 ? num : num * 2;
    if (uniqueNums.count(converted) == 0) {
      uniqueNums[converted] = limit;
    } else {
      uniqueNums[converted] = min(limit, uniqueNums[converted]);
    }
  }

  if (uniqueNums.size() == 1) return 0;

  // maximum - minimum
  int answer = abs(uniqueNums.begin()->first - uniqueNums.rbegin()->first);
  while (true) {
    auto lowest = *uniqueNums.begin();

    if (lowest.first == lowest.second) break;
    uniqueNums.erase(lowest.first);

    uniqueNums[lowest.first * 2] = lowest.second;

    // maximum - minimum
    int curDiff = abs(uniqueNums.begin()->first - uniqueNums.rbegin()->first);
    answer = min(answer, curDiff);
  }
  return answer;
}
```

## 고생한 점
