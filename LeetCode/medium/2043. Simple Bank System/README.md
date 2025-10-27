# 2043. Simple Bank System

[링크](https://leetcode.com/problems/simple-bank-system/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 balance 배열의 크기를 N이라 하자.

초기 값 세팅에 O(N)의 시간 복잡도를 사용한다.

각 연산마다 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

balance를 관리하는데 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(1)     |    O(N)     |

각 경우마다 현재 존재하지 않는 계좌인 경우, 금액이 불가능한 경우를 판단한다.

가능한 경우 연산을 수행하고 그 외의 경우 실행하지 않는다.

```cpp
class Bank {
 private:
  vector<long long> balance;

 public:
  Bank(vector<long long>& balance) { this->balance = balance; }

  bool transfer(int account1, int account2, long long money) {
    account1--;
    account2--;
    if (account1 >= balance.size() || account2 >= balance.size()) return false;
    if (account1 < 0 || account2 < 0) return false;
    if (balance[account1] < money) return false;

    balance[account1] -= money;
    balance[account2] += money;

    return true;
  }

  bool deposit(int account, long long money) {
    account--;
    if (account >= balance.size()) return false;
    if (account < 0) return false;

    balance[account] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    account--;
    if (account >= balance.size()) return false;
    if (account < 0) return false;

    if (balance[account] < money) return false;
    balance[account] -= money;
    return true;
  }
};
```

## 고생한 점
