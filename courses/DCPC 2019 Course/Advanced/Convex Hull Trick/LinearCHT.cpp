#include <bits/stdc++.h>
using namespace std;
struct LinearCHT
{
    #define m first
    #define c second
    #define queryDir 1 // 1 if queries are increasing, -1 if decreasing
    typedef long long ftype;
    typedef pair<ftype,ftype> line;
    ftype f(line l,ftype x) { return l.m*x+l.c; }
    bool bad(line l1,line l2,line l3)
    {
        return (l3.c-l1.c)*(l1.m-l2.m)<=(l2.c-l1.c)*(l1.m-l3.m);
    }
    deque<line> q;
    int curQ;
    void init()
    {
        q.clear();
        curQ = 0;
    }
    void add_line(ftype a,ftype b)
    {
        line l = line(a,b);
        if (q.size()==0)
        {
            q.push_back(l);
            return;
        }
        bool left = (l.m>=q.at(0).m);
        while(q.size()>=2)
        {
            if (left)
            {
                line l1 = q.at(0) , l2 = q.at(1);
                if (!bad(l,l1,l2))
                    break;
                q.pop_front();
                curQ-=queryDir;
            }
            else
            {
                line l1 = q.at(q.size()-2) , l2 = q.at(q.size()-1);
                if (!bad(l1,l2,l))
                    break;
                q.pop_back();
                curQ-=queryDir;
            }
        }
        if (left)
            q.push_front(l);
        else
            q.push_back(l);
    }
    ftype query(ftype x)
    {
        if (curQ<0)curQ=0;
        if (curQ>=q.size()) curQ = (int)q.size()-1;
        while(curQ+queryDir<q.size() && curQ+queryDir>=0 && f(q.at(curQ+queryDir),x)<f(q.at(curQ),x))
            curQ+=queryDir;
        return f(q.at(curQ),x);
    }
};
