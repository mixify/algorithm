#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;
int N, M;

bool complen(string str1, string str2)
{
    return str1.length() < str2.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    multimap<string,int> p;
    sort(phone_book.begin(), phone_book.end(),complen);
    for(int i = 0 ; i < phone_book.size() ; i++)
    {
        for(int j = 1 ; j < phone_book[i].length(); j++)
        {
            auto itr = p.find(phone_book[i].substr(0,j));
            if(itr != p.end())
            {
                answer = false;
                break;
            }
        }
        if(answer==false)
            break;
        p.insert(make_pair(phone_book[i],i));
    }
    return answer;
}

vector<int> findCompletePrefixes(vector<string> names, vector<string> query)
{
    vector<int> counts;
    for (int i = 0; i < query.size(); ++i)
    {
        string qry = query[i];
        int count = 0;
        for (int j = 0; j < names.size(); ++j)
        {
            string sstr = names[j].substr(0,qry.length());
            // if(j==0)
            //     cout<<sstr<<endl;
            if(names[j].size() == qry.size()) continue;
            if(qry.compare(sstr) == 0)
                count++;
        }
        counts.push_back(count);

    }
    return counts;
}
int main(int argc, char *argv[])
{
    vector<string> names;
    vector<string> query;
    cin>>N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin>>str;
        names.push_back(str);
    }
    cin>>M;
    for (int i = 0; i < M; ++i) {
        string str;
        cin>>str;
        query.push_back(str);
    }
    vector<int> res = findCompletePrefixes(names,query);
    for (int i = 0; i < res.size(); ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}

