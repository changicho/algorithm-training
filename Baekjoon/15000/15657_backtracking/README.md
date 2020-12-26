# 15657. N과 M (8)

[링크](https://www.acmicpc.net/problem/15657)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   86.486    |

## 설계

### 시간 복잡도

N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

N은 최대 8이며, M또한 최대 8 이므로 가능한 경우의 수는 8^8 = 16,777,216 이다.

여기에 각 경우마다 오름차순인지 검사하는데 M번 만큼의 시간복잡도가 소요되므로, 최악의 경우 시간 복잡도는

O(134,217,728) 이므로 제한시간 내에 불가능하다.

따라서 탐색에서 불가능한 경우는 백트래킹을 이용해 탐색을 중지해야 한다.

### 공간 복잡도

입력받는 숫자는 전부 10,000 이하의 자연수이다. 따라서 int형으로 선언한다.

### 백트래킹

모든 경우를 탐색하는 경우, 시간초과가 발생한다.

따라서 탐색을 진행할 때 현재 추가하려는 수가 조건에 위배되는지를 검사한다.

이는 이전까지 추가된 수가 조건에 위배되지 않음이 보장되기 때문이다.

```cpp
void recursive(vector<int> combination) {
  if (combination.size() == M) {
    for (int number : combination) {
      cout << number << " ";
    }
    cout << "\n";
    return;
  }

  combination.push_back(-1);
  int size = combination.size();
  int before = size == 1 ? 0 : combination[size - 2];

  for (int number : arr) {
    if (before > number) continue;
    combination[size - 1] = number;
    recursive(combination);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      4       |       0        |

## 고생한 점
