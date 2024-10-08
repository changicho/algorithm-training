# 1813. Sentence Similarity III

[링크](https://leetcode.com/problems/sentence-similarity-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 문자열의 길이를 N, M이라 하자.

각 문자열을 공백을 기준으로 split 한 뒤 투 포인터를 이용해 특정 구간만 다른지 비교할 수 있다.

이 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

문자열을 split한 뒤 비교할 경우 별도의 공간이 필요하다.

이는 O(N + M)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

두 문자열을 split 한 두 배열을 비교한다.

이 때 앞에서부터 순회하며 다른 연속된 구간이 1개 이하인지 판단한다.

다른 연속된 구간이 2개 이상인 경우 일부 문자열을 한번 추가해도 같은 문자열을 만들 수 없다.

```cpp
vector<string> split(string &line) {
  stringstream ss(line);
  vector<string> ret;
  string temp;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

bool check(vector<string> &arr1, vector<string> &arr2) {
  int size1 = arr1.size(), size2 = arr2.size();
  int i1 = 0, i2 = 0;

  int diffCount = 0;
  bool isContinuous = false;
  while (i1 < size1) {
    if (i2 < size2 && arr1[i1] == arr2[i2]) {
      i1++;
      i2++;

      isContinuous = false;
    } else {
      if (!isContinuous) {
        isContinuous = true;
        diffCount++;
      }
      i1++;
    }
  }

  return i2 == size2 && diffCount < 2;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
  vector<string> arr1 = split(sentence1), arr2 = split(sentence2);
  if (arr1.size() < arr2.size()) swap(arr1, arr2);

  if (check(arr1, arr2)) return true;
  reverse(arr1.begin(), arr1.end());
  reverse(arr2.begin(), arr2.end());

  if (check(arr1, arr2)) return true;
  return false;
}
```

### 데크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |  O(N + M)   |

두 문자열을 split한 뒤 데크에 저장한다.

이후 맨 앞에서부터, 맨 뒤에서부터 데크의 값이 같은지 비교한다.

같지 않을 때 까지 pop을 수행한다.

이후 두 데크 중 하나라도 비어있는 경우 남은 데크의 값을 추가해 두 문자열을 같은 문자열로 만들 수 있다.

```cpp
vector<string> split(string &line) {
  stringstream ss(line);
  vector<string> ret;
  string temp;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
  vector<string> arr1 = split(sentence1), arr2 = split(sentence2);

  deque<string> dq1(arr1.begin(), arr1.end()), dq2(arr2.begin(), arr2.end());

  while (!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
    dq1.pop_front();
    dq2.pop_front();
  }
  while (!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
    dq1.pop_back();
    dq2.pop_back();
  }

  return dq1.empty() || dq2.empty();
}
```

## 고생한 점
