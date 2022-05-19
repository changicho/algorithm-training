# 386. Lexicographical Numbers

[링크](https://leetcode.com/problems/lexicographical-numbers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 N까지 순회하는데 O(N)의 시간 복잡도를 사용한다.

이후 이 숫자들을 정렬하는 데 O(N * log_2(N))의 시간 복잡도를 사용한다.

L을 숫자의 길이라 했을 때 각 수를 문자열로 변환하는 데 최대 O(L)의 시간 복잡도를 사용하며 이는 거의 상수이다.

따라서 총 시간 복잡도는 O(N * log_2(N))

### 공간 복잡도

정답을 반환할 배열을 생성하는 데 O(N)의 시간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     113      | O(N * log_2(N)) |    O(N)     |

1부터 N까지의 수를 문자열로 변환해 vector에 저장한다.

이후 해당 vector를 정렬 후 (문자열에 대한 오름차순으로) 이후 각 수를 int형으로 변환하고 새로운 vector에 저장한다.

```cpp
vector<int> lexicalOrder(int n) {
  vector<string> arr;
  for (int i = 1; i <= n; i++) {
    arr.push_back(to_string(i));
  }

  sort(arr.begin(), arr.end());
  vector<int> ret;
  for (string &num : arr) {
    ret.push_back(stoi(num));
  }
  return ret;
}
```

## 고생한 점
