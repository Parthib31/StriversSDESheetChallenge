#include <bits/stdc++.h>

struct meeting
{

    int start;

    int end;

    int pos;
};

bool comparator(struct meeting m1, meeting m2)
{

    if (m1.end < m2.end)
        return true;

    else if (m1.end > m2.end)
        return false;

    else if (m1.pos < m2.pos)
        return true;

    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{

    // Write your code here.

    int n = start.size();

    struct meeting meet[n];

    for (int i = 0; i < n; i++)
    {

        meet[i].start = start[i], meet[i].end = end[i], meet[i].pos = i + 1;
    }

    sort(meet, meet + n, comparator);

    vector<int> ans;

    int finish_time = meet[0].end;

    ans.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {

        if (meet[i].start > finish_time)
        {

            finish_time = meet[i].end;

            ans.push_back(meet[i].pos);
        }
    }

    return ans;
}