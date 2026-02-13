# D - Many Repunit Sum

[링크](https://atcoder.jp/contests/abc444/tasks/abc444_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자. 각 숫자의 범위는 M이라 하자.

각 숫자만큼 1로 이루어진 숫자들을 모두 더해 결과를 계산해야 한다.

이를 직접 구할 경우 O(N \* M)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

차이 배열을 이용해 각 자리수에 대한 차이를 누적해 각 자리별로 몇번 더해졌는지 O(N)의 시간 복잡도로 구할 수 있다.

이후 캐리와 값을 이용해 덧셈을 수행하는데 O(M)의 시간 복잡도를 사용한다.

따라서 전체 시간 복잡도는 O(N + M)이 된다.

### 공간 복잡도

각 자리수마다 합을 누적하기 위해 O(M)의 공간 복잡도를 사용한다.

### 덧셈 & 차이 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N + M)   |    O(M)     |

각 자리수별로 몇번 더해졌는지 계산해야 한다. 이를 차이 배열을 이용해 구간별로 카운트를 누적하여 빠르게 계산한다.

이후 각 자리수별로 실제 누적된 합을 계산하며 최종 결과를 구한다.

이 때 이전 합에서 캐리를 고려하여 덧셈을 수행한다.

만약 최종적으로 캐리가 남아있는 경우 문자열로 변환해 결과에 추가한다.

```cpp
string solution(int size, vector<long long>& nums) {
  string answer = "";

  int count[200001] = {
      0,
  };

  long long maximum = *max_element(nums.begin(), nums.end());

  int diffs[200001] = {
      0,
  };

  for (long long& num : nums) {
    diffs[0] += 1;

    diffs[num] -= 1;
  }

  for (int i = 0, acc = 0; i < maximum; i++) {
    acc += diffs[i];
    count[i] = acc;
  }

  long long carry = 0;
  for (int i = 0; i < maximum; i++) {
    long long total = count[i] + carry;

    answer += (total % 10) + '0';
    carry = total / 10;
  }
  if (carry > 0) {
    string s = to_string(carry);
    reverse(s.begin(), s.end());
    answer += s;
  }

  reverse(answer.begin(), answer.end());

  return answer;
}
```

## 고생한 점
