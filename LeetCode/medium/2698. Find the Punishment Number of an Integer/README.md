# 2698. Find the Punishment Number of an Integer

[링크](https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 N까지 모든 수에 대해 조건을 만족하는지 판단한다.

이 때 각 수에대해 조건을 만족하는지 판단하는데 완전탐색을 사용할 수 있다.

이 경우 각 수를 N이라 할 때 O(2^log_2(N^2))의 시간 복잡도를 사용한다.

이를 모든 수에 대해 반복하므로 O(N \* 2^(log_10(N^2)))의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀 호출로 완전 탐색을 진행할 경우 call stack에 O(log_10(N^2))의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |       시간 복잡도       |  공간 복잡도   |
| :----------: | :---------------------: | :------------: |
|     285      | O(N \* 2^(log_10(N^2))) | O(log_10(N^2)) |

특정 숫자에 대해서 조건을 만족하는지 재귀호출을 이용한 완전 탐색으로 구현할 수 있다.

여기서 현재 숫자를 이전까지 잘라진 수 뒤에 붙이는지, 아니면 현재 수를 시작점으로 새로 잘라진 수를 만들지에 대해 탐색한다.

이를 1부터 N까지의 수에 대해 반복한다.

```cpp
void recursive(string &num, int temp, int sum, int index, bool &isValid) {
  int size = num.size();

  if (index == size) {
    int origin = sqrt(stoi(num));

    sum += temp;
    if (sum == origin) {
      isValid = true;
    }
    return;
  }

  int beforeTemp = temp;
  temp = temp * 10 + num[index] - '0';
  recursive(num, temp, sum, index + 1, isValid);

  temp = beforeTemp;
  sum += temp;
  temp = num[index] - '0';
  recursive(num, temp, sum, index + 1, isValid);
}

bool check(int num) {
  int converted = num * num;

  string str = to_string(converted);

  bool isValid = false;
  recursive(str, 0, 0, 0, isValid);

  return isValid;
}

int punishmentNumber(int n) {
  int answer = 0;
  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      answer += i * i;
    }
  }
  return answer;
}
```

## 고생한 점
