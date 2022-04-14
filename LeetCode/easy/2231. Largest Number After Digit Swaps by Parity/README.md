# 2231. Largest Number After Digit Swaps by Parity

[링크](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

num의 글자수를 N이라 하자.

몇번이고 swap을 해도 되므로 (짝수는 짝수끼리, 홀수는 홀수끼리) 2파트로 나눠서 생각한다.

앞에서부터 짝수파트에는 짝수중 가장 큰수부터, 홀수파트에는 홀수중 가장 큰 수부터 채워넣는다.

이 때 정렬후에 큰 수부터 앞에서 채워넣는다.

일반 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

카운팅 정렬을 이용할 경우 정렬에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 글자들을 별도의 배열 등에 사용하므로 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

입력받은 숫자의 홀수, 짝수 부분을 서로 나누고 이를 정렬한다.

이후 각 자리를 순회하며 원래 짝수자리, 홀수자리인지 여부에 따라서 각 파트의 큰 수부터 채워넣는다.

이를 구현하면 다음과 같다.

```cpp
int largestInteger(int num) {
  string numStr = to_string(num);

  int length = numStr.length();

  vector<bool> isOdd(length);
  vector<char> odds, evens;
  for (int i = 0; i < length; i++) {
    if ((numStr[i] - '0') % 2 == 1) {
      isOdd[i] = true;
      odds.push_back(numStr[i]);
    } else {
      isOdd[i] = false;
      evens.push_back(numStr[i]);
    }
  }

  sort(odds.begin(), odds.end());
  sort(evens.begin(), evens.end());

  int largest = 0;
  for (int i = 0; i < length; i++) {
    if (isOdd[i]) {
      largest = largest * 10 + odds.back() - '0';
      odds.pop_back();
    } else {
      largest = largest * 10 + evens.back() - '0';
      evens.pop_back();
    }
  }

  return largest;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(N)     |

```cpp
vector<int> countingSort(vector<int> &v) {
  vector<int> ret;
  for (int i = 0; i < 10; i++) {
    for (int c = 0; c < v[i]; c++) {
      ret.push_back(i);
    }
  }
  return ret;
}

int largestInteger(int num) {
  string numStr = to_string(num);
  int length = numStr.length();

  vector<bool> isOdd(length);
  vector<int> oddsCount(10, 0), evensCount(10, 0);
  for (int i = 0; i < length; i++) {
    if ((numStr[i] - '0') % 2 == 1) {
      isOdd[i] = true;
      oddsCount[numStr[i] - '0']++;
    } else {
      isOdd[i] = false;
      evensCount[numStr[i] - '0']++;
    }
  }

  vector<int> odds = countingSort(oddsCount),
              evens = countingSort(evensCount);

  int largest = 0;
  for (int i = 0; i < length; i++) {
    if (isOdd[i]) {
      largest = largest * 10 + odds.back();
      odds.pop_back();
    } else {
      largest = largest * 10 + evens.back();
      evens.pop_back();
    }
  }

  return largest;
}
```

## 고생한 점
