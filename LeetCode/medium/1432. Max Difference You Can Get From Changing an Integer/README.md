# 1432. Max Difference You Can Get From Changing an Integer

[링크](https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

글자 수를 N이라 하자.

모든 경우를 탐색해 볼 경우 하나의 숫자를 0부터 9까지 변경하며 탐색해야 한다.

이 경우 하나의 문자에 대해서 가능한 모든 경우의 수는 O(N \* 9^9)가 된다.

그리디 알고리즘을 이용해 특정 숫자에 대해서만 변경을 진행할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

가능한 최대 숫자, 최소 숫자를 저장하면 된다.

따라서 공간 복잡도는 O(N)이 된다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

x를 y로 바꾸는 가능한 모든 경우는 9^2이다.

이렇게 모든 글자를 바꿀 경우 바꾸는 데 시간 복잡도는 O(N)이다.

이를 모든 수에대해서 반복해 최대값과 최소값을 구한다.

```cpp
int maxDiff(int num) {
  string number = to_string(num);
  int length = number.length();

  string minimum = number;
  string maximum = number;

  for (char from = '0'; from <= '9'; from++) {
    for (char to = '0'; to <= '9'; to++) {
      string current = number;
      if (from == to) continue;

      for (int i = 0; i < length; i++) {
        if (current[i] == from) current[i] = to;
      }

      if (current == number) continue;
      if (current.front() == '0') continue;

      if (stoi(maximum) < stoi(current)) {
        maximum = current;
      }
      if (stoi(minimum) > stoi(current)) {
        minimum = current;
      }
    }
  }

  int answer = stoi(maximum) - stoi(minimum);
  return answer;
}
```

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

x에서 y로 글자를 변환했을 때 최대값이 되기 위해선 가장 앞에있는 글자가 클 수록 유리하다. 이는 반대도 마찬가지이다.

따라서 가장 앞에서부터 가장 큰 수, 가장 작은 수로 변환한 값의 차이를 구한다.

이 때 가장 작은수로 변환했을 때 앞자리가 0인 경우는 무시해야 한다.

따라서 가장 작은 수를 구할 때는 다음과 같은 두 경우를 탐색한다.

- 앞에서부터 특정 x를 1로 맞추는 경우
- 앞에서 두번째 숫자부터 특정 x를 0으로 맞추는 경우

```cpp
string getMaximum(string number) {
  string maximum = number;
  int length = number.length();
  char target = ' ';

  for (char c : number) {
    if (c != '9') {
      target = c;
      break;
    }
  }
  for (int i = 0; i < length; i++) {
    if (maximum[i] == target) {
      maximum[i] = '9';
    }
  }
  return maximum;
}

string getMinimum(string number) {
  string minimumA = number, minimumB = number;
  int length = number.length();

  // change first number to '1'
  char target = minimumA.front();
  for (int i = 0; i < length; i++) {
    if (minimumA[i] == target) {
      minimumA[i] = '1';
    }
  }

  // change second number to '0';
  if (length >= 2) {
    for (char c : minimumB) {
      if (c != minimumB.front() && c != '0') {
        target = c;
        break;
      }
    }

    for (int i = 0; i < length; i++) {
      if (minimumB[i] == target) {
        minimumB[i] = '0';
      }
    }
    if (minimumB.front() == '0') minimumB = number;
  }

  if (stoi(minimumA) < stoi(minimumB)) {
    return minimumA;
  }
  return minimumB;
}

int maxDiff(int num) {
  string numString = to_string(num);

  string minimum = getMinimum(numString);
  string maximum = getMaximum(numString);

  int diff = stoi(maximum) - stoi(minimum);
  return diff;
}
```

## 고생한 점
