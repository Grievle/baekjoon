#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int permut[N];
    for(int i = 0; i < N; i++) 
        cin >> permut[i];
    
    priority_queue<int> pq;

    int prev = -1;
    int point = N-1;
    while(point >= 0 && prev < permut[point]) {
        pq.push(-permut[point]);
        prev = permut[point];
        point--;
    }
    pq.push(-permut[point]);
    if(point < 0) {
        cout << -1 << endl;
    } else {
        vector<int> tmp;
        for(int i =0 ; i < point; i++) {
            cout << permut[i] << " ";
        }
        int val = permut[point];
        while(pq.size() > 0) {
            if(val == -pq.top()) {
                tmp.push_back(-pq.top());
                pq.pop();
                cout << -pq.top() << " ";
                pq.pop();
            }else {
                tmp.push_back(-pq.top());
                pq.pop();
            }
        }
        for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
            cout << *iter << " ";
        }

    }
    
    return 0;
}