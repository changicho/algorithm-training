# B. Three Threadlets

[링크](https://codeforces.com/contest/1881/problem/B)

## 설계

### 시간 복잡도

입력받은 세 숫자를 A, B, C라 하자.

각 수 중에서 true를 반환할 수 있는 경우는 가장 작은 숫자대로 쪼개거나 가장 작은 숫자의 절반으로 쪼개는 경우이다.

이를 판단하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 이용해 판단하는데 O(1)의 공간 복잡도를 사용한다.

### 가장 작은 수를 이용해 판단

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(1)     |    O(1)     |

제일 작은 수가 A라고 가정하자.

A를 이용해 B, C를 쪼갤 수 있는지 판단한다.

이 때 A를 기준으로 쪼갤 경우 B, C에 최대 3번 쪼개는 횟수를 사용할 수 있다.

만약 A 이하의 수가 기준이 될 경우는 A/2 인 경우만이 존재할 수 있다.

이 경우 A를 쪼개는 데 이미 한번 사용했으므로 다른 수를 최대 2번 쪼갤 수 있다.

A를 2번 이상 쪼개 정답이 되는 경우는 A가 가장 작은 수가 아닌 경우가 되므로 불가능하다.

```cpp
bool canDivide(vector<int> &arr, int target) {
  int count = 0;
  vector<int> lefts;
  for (int &num : arr) {
    if (num < target) return false;
    if (num == target) continue;

    if (num % target != 0) return false;
    lefts.push_back(num);
  }

  for (int &left : lefts) {
    count += (left / target) - 1;
  }
  if (count > 3) return false;

  return true;
}

bool solution(int a, int b, int c) {
  vector<int> arr = {a, b, c};
  sort(arr.begin(), arr.end());

  // case fit to first
  if (canDivide(arr, arr.front())) {
    return true;
  }

  // case fit to first / 2
  if (arr.front() % 2 == 0 && canDivide(arr, arr.front() / 2)) {
    return true;
  }

  return false;
}
```

## 고생한 점
