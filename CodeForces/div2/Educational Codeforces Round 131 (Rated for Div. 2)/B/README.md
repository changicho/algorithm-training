# B. Permutation

[링크](https://codeforces.com/contest/1701/problem/B)

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

permutation의 크기를 N이라 하자.

모든 경우를 탐색할 경우 N!의 경우를 모두 탐색해야 하므로 제한시간 내에 불가능하다.

그리디 알고리즘을 이용해 정답으로 가능한 경우의 수를 확인할 경우 D가 2, 3인 경우만 확인하면 된다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답으로 배열을 만들어 반환할 경우 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(N)     |

```cpp
P[i] * d = P[i+1];
```

위 식을 만족하는 d의 갯수가 가장 많을 수 있는 경우는 인수가 가장 작은 경우일 것이다.

이는 크기가 N인 배열의 원소가 1 ~ N까지만 가능하기 때문이다.

따라서 D가 2, 3인 경우를 각각 체크하고 두 경우중 정답을 반환한다.

```cpp
void solution(int n) {
  vector<bool> visited(n + 1, false);

  vector<int> twoArr, threeArr;
  // check 2 case
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    twoArr.push_back(i);
    visited[i] = true;

    int target = i * 2;
    while (target <= n && !visited[target]) {
      twoArr.push_back(target);
      visited[target] = true;

      target *= 2;
    }
  }

  for (int i = 0; i <= n; i++) {
    visited[i] = false;
  }

  // check 3 case
  for (int i = 1; i <= n; i++) {
    if (visited[i]) continue;
    threeArr.push_back(i);
    visited[i] = true;
    int target = i * 3;
    while (target <= n && !visited[target]) {
      threeArr.push_back(target);
      visited[target] = true;

      target *= 3;
    }
  }

  int twoCost = 0, threeCost = 0;
  for (int i = 0; i < n - 1; i++) {
    if (twoArr[i] * 2 == twoArr[i + 1]) twoCost++;
    if (threeArr[i] * 3 == threeArr[i + 1]) threeCost++;
  }

  if (twoCost > threeCost) {
    cout << 2 << "\n";
    for (int &num : twoArr) {
      cout << num << " ";
    }
    cout << "\n";
  } else {
    cout << 3 << "\n";
    for (int &num : threeArr) {
      cout << num << " ";
    }
    cout << "\n";
  }
}
```

## 고생한 점
