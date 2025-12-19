# C. Odd Process

[링크](https://codeforces.com/contest/2176/problem/C)

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬을 이용해 최대값을 순서대로 구하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 짝수를 사용해 만들 수 있는 최대 합을 미리 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬과 짝수, 홀수 배열을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     171      | O(N \* log_2(N)) |    O(N)     |

문제 조건에 맞게 매번 홀수를 만들기 위해선 다음 조건을 만족해야 한다.

- 첫번째 숫자는 홀수여야만 한다.
- 이후 숫자들은 짝수여야만 한다.

따라서 가능한 최대 합을 각 경우마다 가능한 최대값을 골라 더하는 방법으로 만들 수 있다.

만약 현재 선택해야 하는 숫자가 최대값을 만들 수 있는 숫자보다 많을 경우 다음 방법을 사용할 수 있다.

- 더 사용해야 하는 숫자를 X라 하자.
- 남은 짝수가 있는 경우 짝수를 하나 더 사용한다.
- 남은 짝수가 없는 경우 홀수를 2개 더 사용하고 짝수를 하나 덜 사용한다.

숫자를 고르는 갯수를 순차적으로 순회하며, 현재 사용가능한 숫자들을 갱신한다.

이 때 현재 사용하는 홀수의 갯수가 짝수인 경우는 불가능하므로 0을 저장한다.

```cpp
vector<long long> solution(int n, vector<int>& nums) {
  sort(nums.begin(), nums.end());

  vector<int> odds;
  vector<int> evens;
  for (int& num : nums) {
    if (num % 2 == 0) {
      evens.push_back(num);
    } else {
      odds.push_back(num);
    }
  }

  if (odds.size() == 0) {
    return vector<long long>(n, 0);
  }

  vector<long long> evenUseMaxs(n + 1);
  evenUseMaxs[0] = 0;

  for (int i = 1; i <= evens.size(); i++) {
    evenUseMaxs[i] = evenUseMaxs[i - 1] + evens[evens.size() - i];
  }

  vector<long long> answer(n);
  int oddUsed = 1;
  int evenUsed = 0;
  answer[0] = odds.back();
  for (int i = 1; i < n; i++) {
    if (evenUsed < evens.size()) {
      evenUsed++;
    } else {
      if (oddUsed + 2 <= odds.size() && evenUsed > 0) {
        oddUsed += 2;
        evenUsed--;
      } else {
        oddUsed++;
      }
    }

    if (oddUsed % 2 == 1) {
      answer[i] = odds.back() + evenUseMaxs[evenUsed];
    } else {
      answer[i] = 0;
    }
  }

  return answer;
}
```

## 고생한 점

합이 int형을 벗어날 수 있다.
