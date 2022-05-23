# 393. UTF-8 Validation

[링크](https://leetcode.com/problems/utf-8-validation/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

data의 크기를 N이라 하자.

입력받은 수를 이진수로 표현할 경우 최대 8자리 까지이다.

각 숫자를 이진수로 나타낸 문자열로 치환 후에 한번씩 순회하며 오류가 발생하는 지 판단한다.

이 경우 변환, 순회에 O(N)의 시간 복잡도를 사용하며 비교에 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N)이다.

이진수 변환 외에 비트 연산을 이용해 판단할 수 도 있다. 이 경우 바로 순회하면 되므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

자료를 변환한 값들을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

직접 숫자를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 이진수 변환 & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(N)     |

각 숫자들을 이진수로 변환한 뒤 배열에 삽입한다.

이후 각 숫자들을 순회하며 sequence의 시작점인 경우 이후 연속된 수들을 순회한다.

만약 "10"으로 시작되어야 하는데 아닌 경우 false를 반환한다.

이렇게 각 숫자들을 순회하며 sequence에 맞는지 비교한다.

순회가 끝나고 끝나지 않은 sequence가 있는 경우 정답은 false이다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<string>> sequences = {
    {"0"}, {"110", "10"}, {"1110", "10", "10"}, {"11110", "10", "10", "10"}};

string convert(int num) {
  string ret = "";
  while (num > 0) {
    ret += num % 2 == 1 ? "1" : "0";
    num /= 2;
  }
  while (ret.length() < 8) {
    ret += "0";
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

bool isPrefix(string &prefix, string &data) {
  int size = prefix.size();
  for (int i = 0; i < size; i++) {
    if (prefix[i] != data[i]) return false;
  }
  return true;
}

bool validUtf8(vector<int> &data) {
  vector<string> bytes;
  for (int &d : data) {
    bytes.push_back(convert(d));
  }

  int size = bytes.size();
  int i = 0;
  while (i < size) {
    string cur = bytes[i];

    bool isPass = false;
    for (vector<string> &sequence : sequences) {
      if (!isPrefix(sequence.front(), cur)) continue;

      int temp = i;
      for (string &se : sequence) {
        if (temp >= size) return false;
        if (!isPrefix(se, bytes[temp])) return false;
        temp++;
      }

      i = temp;

      isPass = true;
      break;
    }

    if (!isPass) return false;
  }

  return true;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |    O(N)     |    O(1)     |

위 방법에서 비트연산을 이용해 자료를 변환하지 않고 사용한다.

각 sequence의 시작 비트를 만난 경우 앞으로 나와야 하는 "10" 비트의 갯수를 설정한다.

만약 남은 갯수가 1 이상인 경우 현재 수가 "10"으로 시작하는지 판단한다.

순회를 끝냈을 때 남은 갯수가 1 이상인 경우는 오류이므로 false를 반환한다.

이를 구현하면 다음과 같다.

```cpp
bool validUtf8(vector<int> &data) {
  int left = 0;

  for (int num : data) {
    if (left > 0) {
      if ((num >> 6) != 0b10) return false;
      left--;
      continue;
    }

    if ((num >> 5) == 0b110) {
      left = 1;
    } else if ((num >> 4) == 0b1110) {
      left = 2;
    } else if ((num >> 3) == 0b11110) {
      left = 3;
    } else if ((num >> 7)) {
      return false;
    }
  }

  return left == 0;
}
```

## 고생한 점
