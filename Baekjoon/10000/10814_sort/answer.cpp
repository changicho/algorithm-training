#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct account {
    int age;
    string name;
};

bool compare(account a, account b) {
    if (a.age < b.age) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<account> accounts;
    accounts.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> accounts[i].age >> accounts[i].name;
    }

    stable_sort(accounts.begin(), accounts.end(), compare);

    for (account a : accounts) {
        cout << a.age << " " << a.name << "\n";
    }

    return 0;
}