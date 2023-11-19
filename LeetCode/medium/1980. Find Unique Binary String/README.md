# 1980. Find Unique Binary String

[링크](https://leetcode.com/problems/find-unique-binary-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. nums의 원소 num의 길이 또한 N이다.

각 문자열을 숫자로 변환할 때 O(N)의 시간 복잡도를 사용한다.

가능한 경우의 수는 총 2^N개이며 이중 N개의 숫자만 존재하므로 정답의 범위는 0 ~ N임을 유추할 수 있다.

각 수들을 순회하며 변환하는데 O(N^2)의 시간 복잡도를, 이후 정답을 찾는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

변환한 수를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(N^2)    |    O(N)     |

가능한 숫자의 경우의 수는 총 2^N개이며 이중 N개의 숫자만 nums에 존재하므로 정답의 범위는 0 ~ N임을 유추할 수 있다.

따라서 nums의 원소들을 숫자로 변환 후 hash set에 저장 후 0부터 N까지 순회하며 정답을 찾는다.

```cpp
string findDifferentBinaryString(vector<string>& nums) {
  int size = nums.size();
  unordered_set<int> us;
  for (string& num : nums) {
    us.insert(stoi(num, 0, 2));
  }

  string answer = "";
  for (int num = 0; num <= size; num++) {
    if (us.count(num) > 0) continue;

    answer = bitset<16>(num).to_string().substr(16 - size);
    break;
  }

  return answer;
}
```

## 고생한 점
