# 4012. Count of Unfinished Tasks After Each Shift

[링크](https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

tasks의 크기를 N, shifts의 크기를 M이라 하자.

각 shift마다 어디까지 완료 가능한지를 빠르게 찾아야 한다. 이에 prefix sum와 이분 탐색을 사용할 수 있다.

이 경우 O(M \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum과 정답에 O(N + M)의 공간 복잡도를 사용한다.

### prefix sum & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(M \* log_2(N)) |  O(N + M)   |

특정 shift에 어디까지 task를 완료 가능한지 빠르게 판단하기 위해 tasks의 prefix sum을 생성한다.

이 때 아무것도 완료 못할 수도 있으므로 맨 앞에는 0을 넣어준다.

이후 각 shift마다 upper_bound를 구한 뒤 해당 포인터 앞까지 완료 가능하다.

이를 각 shift마다 구하며, 만약 특정 task의 일부만 완료한 경우 이를 다음 shift에 더해준다.

이를 반복한다.

```cpp
vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
  int size = tasks.size();
  vector<int> answer;

  vector<long long> prefixSum;
  prefixSum.push_back(0);
  for (int i = 0; i < size; i++) {
    prefixSum.push_back(prefixSum.back() + tasks[i]);
  }

  int left = 0;
  int sI = 0;  // index
  for (int& shift : shifts) {
    int target = upper_bound(prefixSum.begin() + sI, prefixSum.end(), prefixSum[sI] + shift + left) - prefixSum.begin();
    target--;
    left = (prefixSum[sI] + shift + left) - prefixSum[target];

    answer.push_back(size - target);
    sI = target;

    if (sI >= size) {
      sI = 0;
      left = 0;
    }
  }
  return answer;
}
```

## 고생한 점
