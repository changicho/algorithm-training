# B. Remove Prefix

[링크](https://codeforces.com/contest/1714/problem/B)

| 난이도 |
| :----: |
| \*800  |

## 설계

### 시간 복잡도

원소의 갯수를 N이라 하자.

숫자를 한번 순회하며 count한다. 이후 왼쪽부터 순회하며 현재 숫자를 제거했을 때 2개 이상인 수가 남아있는지 검사한다.

2개 이상인 수가 남았는지 검사하는 데 hash set을 이용할 경우 O(1)의 시간 복잡도로 확인 가능하다.

순회에 O(N)의 시간복잡도를 사용한다.

### 공간 복잡도

숫자를 count할 공간에 O(N), 삭제할 수를 저장할 공간에 O(N)의 공간 복잡도를 사용한다.

### count & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      78      |    O(N)     |    O(N)     |

각 숫자를 순회하며 count한다. 이 때 2개이상이 나오는 경우는 삭제해야 할 목록에 저장한다.

이후 왼쪽부터 순회하며 현재 숫자의 count를 감소시킨 뒤 1개만 남은 경우 삭제해야 할 목록에서 삭제한다.

삭제 목록이 빈 경우 탐색을 중지하며 이를 정답으로 반환한다.

```cpp
int solution(int n, vector<int> &a) {
  int answer = 0;

  unordered_map<int, int> counts;
  unordered_set<int> needToErase;
  for (int &num : a) {
    counts[num]++;

    if (counts[num] >= 2) needToErase.insert(num);
  }

  for (int left = 0; left < n && !needToErase.empty(); left++) {
    int num = a[left];
    counts[num]--;

    if (counts[num] == 1) needToErase.erase(num);

    if (needToErase.empty()) {
      answer = left + 1;
      break;
    }
  }

  return answer;
}
```

## 고생한 점
