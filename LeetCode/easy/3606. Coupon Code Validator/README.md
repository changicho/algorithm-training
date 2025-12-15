# 3606. Coupon Code Validator

[링크](https://leetcode.com/problems/coupon-code-validator/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 쿠폰에 대해서 유효한 코드를 판단하고 남은 코드들을 정렬해 반환한다.

각 쿠폰이나 코드를 판단하는데 길이 L에 대해서 O(L)만큼의 시간 복잡도를 사용하며 L은 최대 100 이므로 상수 시간 복잡도로 간주할 수 있다.

이에 O(N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

```cpp
bool isValidCode(string& code) {
  if (code.size() == 0) return false;
  for (char& c : code) {
    if (islower(c)) continue;
    if (isupper(c)) continue;
    if (isdigit(c)) continue;
    if (c == '_') continue;
    return false;
  }
  return true;
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
  unordered_set<string> validBusinesses = {"electronics", "grocery", "pharmacy", "restaurant"};

  int size = code.size();
  vector<vector<string>> arr;
  for (int i = 0; i < size; i++) {
    if (isActive[i] == false) continue;
    if (!isValidCode(code[i])) continue;
    if (!validBusinesses.count(businessLine[i])) continue;

    arr.push_back({businessLine[i], code[i]});
  }

  sort(arr.begin(), arr.end());

  vector<string> answer;
  for (vector<string>& a : arr) {
    answer.push_back(a[1]);
  }
  return answer;
}
```

## 고생한 점
