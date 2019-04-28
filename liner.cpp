#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;
int res = -1;
int n, p;
queue<char> q[2];
char M_S; //현재 내가 낸 가위바위보 정보
int flag;

//가위바위보 해서 a와 b중 누가 이겼는지 확인하는 코드
//중간에 M이 있을 경우 안 바꿔도 되면 그대로, 바꿔야하면 바꾸고 res변수(정답) 증가시킴
int RSP(char a, char b){
    if(a == 'R'){
        if(b == 'S')
            return 1;
        else if(b == 'M'){
            if(M_S == 'P'){
                return 0;
            }else{
                M_S = 'P';
                res++;
                return 0;
            }
        }else
            return 0;
    }else if(a == 'S'){
        if(b == 'R')
            return 0;
        else if(b == 'M'){
            if(M_S == 'R'){
                return 0;
            }else{
                M_S = 'R';
                res++;
                return 0;
            }
        }else
            return 1;
    }else if(a == 'P'){
        if(b == 'S')
            return 0;
        else if(b == 'M'){
            if(M_S == 'S'){
                return 0;
            }else{
                M_S = 'S';
                res++;
                return 0;
            }
        }else
            return 1;
    }else{
        if(b == 'R'){
            if(M_S == 'P'){
                return 1;
            }else{
                M_S = 'p';
                res++;
                return 1;
            }
        }else if(b == 'S'){
            if(M_S == 'R'){
                return 1;
            }else{
                M_S = 'R';
                res++;
                return 1;
            }
        }else{
            if(M_S=='S'){
                return 1;
            }else{
                M_S == 'S';
                res++;
                return 1;
            }
        }
    }
}

void beat(){
    int i,j;
    char a,b;
    while(q[flag].empty() == 0){
        if(q[flag].size() == 1)
        { //부전승일 경우
            q[(flag+1)%2].push(q[flag].front());
            q[flag].pop();
            break;
        }
        else
        {
            a = q[flag].front();
            q[flag].pop();
            b = q[flag].front();
            q[flag].pop();
            if(RSP(a,b)){ //1이면 a가 이긴거, 0이면 b가 이긴거
                q[(flag+1)%2].push(a);
            }else
                q[(flag+1)%2].push(b);
        }
    }

}

int main(){
    int i,j;
    char tmp;
    cin>>n;
    cin>>p;

    //큐는 두개 번갈아가면서 사용 flag이용
    //RSP를 큐에 담음, 나 자신은 M으로 표현
    for(i=0;i<n;i++)
    {
        if(i == p){
            q[flag].push('M');
        }else{
            cin>>tmp;
            q[flag].push(tmp);
        }
    }

    while(1)
    {
        while(q[(flag+1)%2].empty() == 0) //다음에 쓸 큐 초기화
            q[(flag+1)%2].pop();
        if(q[flag].size() == 1) //우승했을 때
            break;
        beat(); //가위바위보 해서 다른 큐에 다음 라운드 정보 입력
        flag = (flag+1) % 2; //플래그 전환
    }
    cout << res;
    return 0;
}
