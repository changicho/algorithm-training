#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation
// time : O(1)
// space : O(N)
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

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */