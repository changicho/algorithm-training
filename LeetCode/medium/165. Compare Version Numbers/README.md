# 165. Compare Version Numbers

[링크](https://leetcode.com/problems/compare-version-numbers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s1의 길이를 N, s2의 길이를 M이라 하자.

각 문자열을 순회하며 '.'을 기준으로 숫자들을 분할해야 한다.

숫자들을 찾는데 한번 순회하므로 O(N + M)의 시간 복잡도를 사용한다.

이후 각 숫자들을 첫번째부터 순서대로 비교하며 비교를 수행한다. 이 경우 O(N + M)의 시간 복잡도를 사용한다.

혹은 숫자를 찾는것과 동시에 비교할 수 있다. 이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

숫자들을 찾은 별도의 배열을 사용할 경우 O(N + M)의 공간 복잡도를 사용한다.

동시에 비교하며 추출할 경우 별도의 배열을 사용하지 않는다. 따라서 O(1)의 공간 복잡도를 사용한다.

### split, two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |  O(N + M)   |  O(N + M)   |

각 문자열에서 숫자부분만 추출하기 위해 다음과 같은 함수를 이용한다.

```cpp
vector<int> convert(string version) {
  vector<int> ret;

  string temp = "";
  for (char &c : version) {
    if (c == '.') {
      ret.push_back(stoi(temp));
      temp = "";
      continue;
    }
    temp += c;
  }

  if (temp != "") {
    ret.push_back(stoi(temp));
  }

  return ret;
}
```

이후 두 문자열에서 숫자만 추출할 벡터를 만든다.

이후 순서대로 각 벡터의 숫자를 비교한다.

이 때 한쪽 벡터의 크기가 더 큰 경우는 뒤에 0을 채워 크기를 맞춰준다. (빈 숫자와 0은 같다고 문제에서 취급)

```cpp
int compareVersion(string version1, string version2) {
  vector<int> arr1 = convert(version1), arr2 = convert(version2);

  while (arr1.size() < arr2.size()) {
    arr1.push_back(0);
  }
  while (arr2.size() < arr1.size()) {
    arr2.push_back(0);
  }

  int size = min(arr1.size(), arr2.size());

  for (int i = 0; i < size; i++) {
    if (arr1[i] < arr2[i]) {
      return -1;
    } else if (arr1[i] > arr2[i]) {
      return 1;
    }
  }
  return 0;
}
```

### two pointer

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

위 방법에서 숫자를 찾는것과 동시에 비교를 진행한다.

```cpp
int compareVersion(string s1, string s2) {
  int length1 = s1.length(), length2 = s2.length();

  int idx1 = 0, idx2 = 0;
  while (idx1 < length1 || idx2 < length2) {
    int number1 = 0, number2 = 0;

    // get next number of s1
    while (idx1 < length1 && s1[idx1] != '.') {
      number1 = number1 * 10 + (s1[idx1] - '0');
      idx1++;
    }
    // get next number of s2
    while (idx2 < length2 && s2[idx2] != '.') {
      number2 = number2 * 10 + (s2[idx2] - '0');
      idx2++;
    }

    if (number1 > number2) {
      return 1;
    } else if (number1 < number2) {
      return -1;
    }

    number1 = 0, number2 = 0;

    idx1++, idx2++;
  }

  return 0;
}
```

## 고생한 점
