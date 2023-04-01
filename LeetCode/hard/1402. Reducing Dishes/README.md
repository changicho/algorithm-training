# 1402. Reducing Dishes

[링크](https://leetcode.com/problems/reducing-dishes/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

satisfaction의 크기를 N이라 하자. (N <= 500)

모든 수를 배열하는 경우 경우의 수는 N!이며 이를 모두 탐색할 경우 제한시간 내에 불가능하다.

따라서 정렬 이후, 어느 점에서 시작하는지에 따라 최대값을 구해야 한다.

이 때 각 과정마다 직접 구해볼 경우 시작 점을 순회하고 각 정답을 구하는데 총 시간 복잡도는 O(N^2)이다.

suffix sum을 이용해 최적의 위치를 찾고 정답을 구할 수 있다.

이 경우 최적의 위치를 찾는데 O(N)의 시간 복잡도가 소요되며, 정답을 구하는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 최대 O(1) ~ O(N)의 공간 복잡도를 사용한다.

각 과정마다 정답을 구하는 데 O(1)의 공간 복잡도를 사용한다.

satisfaction의 값의 범위는 -1,000 ~ 1,000 이며 값은 최대 500이다. 이를 모두 더해도 int 형을 넘지 않는다.

### 정렬 & suffix sum

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      3       | O(N \* log_2(N)) |    O(1)     |

satisfaction을 정렬한다. 이는 정답에 추가했을 때 큰 수 순서대로 오른쪽에 배치할 경우 기대값이 크기 때문이다.

이후 어떤 시작점에서 시작했을 때 가장 큰 정답이 나오는지를 구해야 한다.

시작 위치가 왼쪽으로 한칸 이동할 때마다, 이후 값들이 정답에 포함되는 횟수가 한번씩 증가한다.

따라서 suffix sum을 구하며 이 값이 음수가 되지 않는 마지막 위치부터 시작할 경우 suffix sum이 최대이므로 가장 큰 정답이 된다.

이는 suffix sum을 구하며 이전 값들이 0이거나 양수인 경우, 현재 시작점부터 정답을 구할 때 해당 이전 값들이 모두 포함된 값이 되기 때문이다.

```cpp
int maxSatisfaction(vector<int>& satisfaction) {
  int size = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());

  int suffixSum = 0;
  int start = -1;
  for (int i = size - 1; i >= 0; i--) {
    suffixSum += satisfaction[i];

    if (suffixSum < 0) {
      break;
    }
    start = i;
  }

  if (start == -1) return 0;

  int answer = 0;
  for (int i = start; i < size; i++) {
    answer += satisfaction[i] * (i - start + 1);
  }
  return answer;
}
```

### 정렬 & brute force

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |   O(N^2)    |    O(1)     |

위 방법에서 모든 시작점에 대해 탐색을 진행한다.

```cpp
int maxSatisfaction(vector<int>& satisfaction) {
  int size = satisfaction.size();
  sort(satisfaction.begin(), satisfaction.end());

  int answer = 0;
  for(int start = 0; start < size; start++){
    int temp = 0;
    for(int i=start; i<size;i++){
        temp += satisfaction[i] * (i - start + 1);
    }
    answer = max(answer, temp);
  }

  return answer;
}
```

## 고생한 점
