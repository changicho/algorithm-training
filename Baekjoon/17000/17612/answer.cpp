#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 1e9 + 1;

struct Customer {
  int id;
  int w;
};

struct Counter {
  int id;
  int endTime;

  const bool operator<(const Counter &c) const {
    if (endTime == c.endTime) {
      return id > c.id;
    }
    return endTime > c.endTime;
  }
};

struct OutCustomer {
  int customerId;
  int counterId;
  int outTime;
};

long long solution(int size, int k, vector<Customer> &customers) {
  priority_queue<Counter> counters;
  for (int counter_id = 0; counter_id < k; counter_id++) {
    counters.push({counter_id, 0});
  }

  vector<OutCustomer> counterWaitingLines[k];
  for (Customer &customer : customers) {
    Counter counter = counters.top();
    counters.pop();
    int lastEndTime = counter.endTime;
    int counterId = counter.id;

    counterWaitingLines[counterId].push_back(
        {customer.id, counterId, lastEndTime + customer.w});
    counter.endTime += customer.w;

    counters.push(counter);
  }

  vector<OutCustomer> outCustomers;
  for (int i = 0; i < k; i++) {
    for (OutCustomer &outCustomer : counterWaitingLines[i]) {
      outCustomers.push_back(outCustomer);
    }
  }

  sort(outCustomers.begin(), outCustomers.end(),
       [](OutCustomer &a, OutCustomer &b) {
         if (a.outTime == b.outTime) {
           return a.counterId > b.counterId;
         }
         return a.outTime < b.outTime;
       });

  vector<int> answerList;
  for (OutCustomer &outCustomer : outCustomers) {
    answerList.push_back(outCustomer.customerId);
  }

  long long answer = 0;
  for (int i = 0; i < answerList.size(); i++) {
    answer += (long long)(i + 1) * answerList[i];
  }
  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  vector<Customer> customers(N);
  for (int i = 0; i < N; i++) {
    cin >> customers[i].id >> customers[i].w;
  }

  long long answer = solution(N, K, customers);
  cout << answer;
  cout << "\n";

  return 0;
}
