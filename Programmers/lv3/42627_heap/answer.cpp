#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Job {
  int arrived_time;
  int start_time;
  int cost;

  bool operator<(const Job &b) const {
    return cost > b.cost;
  }
};

bool compare(vector<int> a, vector<int> b) {
  return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
  int answer = 0;
  int count = 0;
  priority_queue<Job> pq;
  queue<Job> q;

  sort(jobs.begin(), jobs.end(), compare);

  for (int time = 0; time <= 1000000; time++) {
    if (count < jobs.size() && jobs[count][0] <= time) {
      pq.push({jobs[count][0], time, jobs[count][1]});
      count += 1;
    }

    if (!q.empty() && q.front().start_time + q.front().cost == time) {
      answer += time - q.front().arrived_time;
      q.pop();
    }

    if (q.empty() && !pq.empty()) {
      q.push({pq.top().arrived_time, time, pq.top().cost});
      pq.pop();
    }
  }

  return answer / count;
}

struct TestCase {
  vector<vector<int>> jobs;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {{{0, 3}, {1, 9}, {2, 6}}, 9}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.jobs);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}