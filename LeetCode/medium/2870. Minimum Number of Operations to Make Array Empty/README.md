# 2870. Minimum Number of Operations to Make Array Empty

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 숫자의 수를 세고 이를 2,3개씩 삭제했을 때 최소 횟수를 구해야 한다.

이를 수학적 방법으로 구할 경우 O(1)의 시간 복잡도로 구할 수 있다.

원소의 수를 세기 위한 순회와 각 count를 순회하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 count하는데 최대 O(N)의 공간 복잡도가 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     124      |    O(N)     |    O(N)     |

특정 수의 갯수를 X라 하자. 2,3개씩 삭제했을 때 최소 횟수는 다음과 같다.

- 최대한 3개씩 많이 삭제하고 남은 수를 본다.
- 1개인 경우 : 직전 삭제를 3개에서 2개로 변경하고 남은 2개의 수를 삭제한다
- 2개인 경우 : 2개의 수를 삭제한다.
- 0개인 경우 : 더이상 삭제할 수가 없다.

따라서 X를 3으로 나눈 뒤 몫을 구하고, 나머지가 존재하면 몫 + 1이 최소횟수가 된다.

이 때 X가 1인 경우는 삭제 자체가 불가능하므로 -1을 반환한다.

이를 모든 수의 갯수에 대해 반복한다.

```cpp
int minOperations(vector<int> &nums) {
  unordered_map<int, int> um;
  for (int &num : nums) {
    um[num]++;
  }

  int answer = 0;
  for (auto &[_num, count] : um) {
    if (count == 1) return -1;

    answer += count / 3;
    if (count % 3 != 0) answer++;
  }
  return answer;
}
```

## 고생한 점
