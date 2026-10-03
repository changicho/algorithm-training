# 4065. Rearrange Array by Removing Distinct Values

[링크](https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 원소의 종류를 M이라 하자.

원소의 갯수를 count하는데 O(N)의 시간 복잡도를 사용한다.

이후 매번 값을 탐색하며 정답을 생성할 경우 O(NM)의 시간 복잡도를 사용한다.

큐를 이용해 키를 순서대로 넣고 이후 키를 생성하는 방법을 사용할 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

카운팅에 O(M)의 공간 복잡도를 사용한다.

정답 배열, 큐에 O(N)의 공간 복잡도를 사용한다.

### 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

각 값들의 수를 센다.

이후 큐에 작은 값 순으로 집어넣은뒤 큐를 순회하며 정답을 생성해나간다.

이 때 현재 숫자를 큐에서 pop할 때 count도 감소시키며, count가 0이 아닌 경우 다시 큐에 넣는다.

```cpp
vector<int> rearrangeArray(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer;

  queue<int> keys;
  int count[101];
  for (int& num : nums) {
    count[num]++;
  }

  for (int num = 0; num <= 100; num++) {
    if (count[num] > 0) {
      keys.push(num);
    }
  }

  while (!keys.empty()) {
    int key = keys.front();
    keys.pop();

    answer.push_back(key);
    count[key]--;

    if (count[key] > 0) {
      keys.push(key);
    }
  }
  return answer;
}
```

## 고생한 점
