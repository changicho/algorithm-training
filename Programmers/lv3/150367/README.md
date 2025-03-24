# 2023 KAKAO BLIND RECRUITMENT - 표현 가능한 이진트리

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150367)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

배열 numbers의 크기를 N, 각 number의 최대값을 이진수로 나타냈을 때의 길이를 M이라 하자.

각 수를 포화 이진 트리로 변환하는데 O(M)의 시간 복잡도를 사용한다.

이를 재귀 호출하며 가능한 이진 트리인지 판별하는 데 O(M \* log_2(M))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* M \* log_2(M))이다.

### 공간 복잡도

이진 트리를 만드는데 O(M)의 공간 복잡도가 필요하다.

재귀호출로 이를 탐색하는 데 O(log_2(M))의 공간 복잡도가 필요하다.

### 재귀 호출

|      시간 복잡도      |   공간 복잡도   |
| :-------------------: | :-------------: |
| O(N \* M \* log_2(M)) | O(M + log_2(M)) |

각 수를 이진트리로 변환했을 때 가능한지 여부는 다음과 같이 판단할 수 있다.

우선 각 수를 포화 이진트리의 형태의 문자열로 변환한다. (문자열의 길이는 (2^X)-1 이여야 한다.)

이후 각 범위의 중앙값을 서브트리의 루트로 지정하며 왼쪽 서브트리, 오른쪽 서브트리에 대해 탐색을 진행한다.

이 때 부모가 '0'인데 (빈 노드) 자식이 '1'인 경우는 불가능한 경우이다.

이를 모든 number에 대해 판단하며, 가능한 경우에 대해서만 정답에 추가한다.

```cpp
bool check(string &bits) {
  int size = bits.size();
  bool isFine = true;
  int left = 0, right = size - 1;

  auto recursive = [&](int left, int right, char parent, auto &&recursive) {
    if (left > right) return;
    int mid = left + (right - left) / 2;

    char cur = bits[mid];

    if (parent == '0' && cur == '1') {
      isFine = false;
      return;
    }

    if (left == right) return;

    recursive(left, mid - 1, cur, recursive);
    recursive(mid + 1, right, cur, recursive);
  };

  recursive(0, right, '1', recursive);
  return isFine;
}

string convert(long long num) {
  string ret = "";
  while (num > 0) {
    ret += (num % 2) + '0';
    num /= 2;
  }

  int length = 1;
  while (ret.size() > (length - 1)) {
    length *= 2;
  }
  length--;
  ret += string(length - ret.size(), '0');

  reverse(ret.begin(), ret.end());

  return ret;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;

  for (long long &num : numbers) {
    string converted = convert(num);
    bool cur = check(converted);

    answer.push_back(cur);
  }

  return answer;
}
```

## 고생한 점
