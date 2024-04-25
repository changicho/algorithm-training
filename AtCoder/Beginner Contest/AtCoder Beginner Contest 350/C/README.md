# C - Sort

[링크](https://atcoder.jp/contests/abc350/tasks/abc350_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

각 수마다의 index를 이용해 각 위치마다 이동시킬 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수의 index를 저장하는 데 O(N)의 공간 복잡도가 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |    O(N)     |    O(N)     |

정답을 만들 수 있다면 어떤 쿼리를 반환해도 가능하다.

따라서 1부터 필요한 위치에 맞게 이동시키며 정답을 만들 수 있도록 한다.

이 때 각 수마다 현재 index를 빠르게 접근하기 위해 index를 저장하는 배열을 사용한다.

```cpp
vector<pair<int, int>> solution(int size, vector<int> &nums) {
  vector<pair<int, int>> answer;

  int indexes[200001] = {
      0,
  };

  for (int i = 0; i < size; i++) {
    indexes[nums[i]] = i + 1;
  }

  for (int n = 1; n <= size; n++) {
    if (indexes[n] == n) continue;

    int curNum = nums[n - 1];

    int targetI = indexes[n];

    // target -> n
    // n -> target

    answer.push_back({n, targetI});

    nums[n - 1] = n;
    nums[targetI - 1] = curNum;

    indexes[n] = n;
    indexes[curNum] = targetI;
  }

  return answer;
}
```

## 고생한 점
