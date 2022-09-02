#include <string>
#include <vector>
#include <queue>

using namespace std;

int check(queue<int> q1, queue<int> q2, long goal, long s)
{
    int cnt = 0;
    int limit = q1.size() * 5;
    while(s != goal)
    {
        if(s > goal)
        {
            s -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else
        {
            s += q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        cnt++;
        if(cnt == limit)
        {
            cnt = -1;
            break;
        }
    }
    return cnt;
}

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long s1 = 0, s2 = 0;
    for(int i=0;i<queue1.size();i++)
    {
        s1 += queue1[i]; 
        s2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    return check(q1,q2,(s1+s2)/2,s1);
}
