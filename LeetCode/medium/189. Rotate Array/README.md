# 189. Rotate Array

[링크](https://leetcode.com/problems/rotate-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 모든 요소의 갯수를 N이라 하자.

결국 배열의 모든 요소를 한칸씩 이동하기 위해선 한번 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

이 때 배열의 모든 요소를 한번씩 shift 하는것이 아니라 이동해야 할 위치로 한 칸씩 이동할 경우 결국 모든 요소에 대해서 한번씩만 방문하면 된다.

이 경우 시간 복잡도는 O(N)이다.

배열의 뒤집기 연산을 이용할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

이동해야 할 위치끼리 한꺼번에 이동시키는 경우 별도의 공간 복잡도가 필요하지 않다.

뒤집기 연산을 이용할 경우 별도의 공간 복잡도가 필요하지 않다.

### cyclic replacement

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

우선 k가 0인 경우 이동할 이유가 없으므로 제외한다.

현재 위치에서 k번 이동할 경우 해당 위치에 원래 존재하던 값도 k번 이동한다.

이를 한 숫자의 이동에 연관된 모든 숫자들에 대해서 반복한다.

이 사이클이 끝난 경우 처음 위치의 바로 다음 칸에서 이를 반복한다.

만약 k가 N의 약수인 경우에는 여러개의 싸이클이 나올 수 있다.

싸이클의 갯수는 k와 N의 최대공약수 이므로 gcd를 이용해 사이클의 횟수를 구한다.

만약 k와 N이 서로소인 경우에는 한번의 싸이클로 모든 숫자를 방문이 가능하다.

```cpp
void rotate(vector<int>& nums, int k) {
  if (k == 0) return;
  int size = nums.size();

  int limit = gcd(k, size);

  for (int i = 0; i < limit; i++) {
    int index = i;
    int temp = nums[index];

    while ((index + k) % size != i) {
      int next = (index + k) % size;
      swap(nums[next], temp);
      index = next;
    }
    nums[i] = temp;
  }
}
```

gcd를 이용하지 않고 사이클을 k번 반복하는경우 다음과 같다.

```cpp
void rotate(vector<int>& nums, int k) {
  int size = nums.size();
  k %= size;
  int count = 0;

  for (int start = 0; count < size; start++) {
    int index = start;
    int temp = nums[index];

    while ((index + k) % size != start) {
      int next = (index + k) % size;
      swap(nums[next], temp);
      index = next;
      count++;
    }
    nums[start] = temp;
    count++;
  }
}
```

### reverse

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

모든 배열을 뒤집는다.

이후 k번째 index를 기준으로 2번 뒤집을 경우 k번 shift한 것과 같은 효과를 나타낼 수 있다.

```plain_text
// n = 7, k = 3
Original List                   : 1 2 3 4 5 6 7
After reversing all numbers     : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result
```

## 고생한 점
