#include <bits/stdc++.h>

using namespace std;

struct POINT{
    int m_STR, m_INT, m_PNT;
};

int N, ans=0;
POINT s[101];

int main(){
    cin >> N;
    
    for(int i=0; i<N; ++i) cin >> s[i].m_STR >> s[i].m_INT >> s[i].m_PNT;
    
    sort(s, s+N, [](POINT& a, POINT& b){
        if(a.m_STR + a.m_INT == b.m_STR + b.m_INT)
            return a.m_PNT > b.m_PNT;
        return (a.m_STR + a.m_INT) < (b.m_STR + b.m_INT);
    });
    
    s[100].m_PNT = 0;
    int posSTR=1, posINT=1, leftPNT = 0, ans=0; // PNT을 바로 쓰지 않고 필요할 때 만 쓰도록
//    int qwe=10;
    
    while(1){
        int difSTR = 1e9, difINT = 1e9; // 최소인 STR || INT의 차이
        int posMinSTR=100, posMinINT=100; // 현재 STR || INT와의 차이가 최소인 퀘스트의 번호
        bool flag = false;
        
        for(int j=0; j<N; ++j){ // 모든 퀘스트 돌면서 현재 STR, INT와의 차이가 최소인 퀘스트를 찾는다.
            if(s[j].m_STR != 0){ // 아직 깨지 않은 퀘스트인 경우
                flag = true; // 안깬 퀘스트가 남음.
                if(difSTR >= s[j].m_STR - posSTR){
                    if(difSTR == s[j].m_STR - posSTR){ // 같으면 PNT로 비교
                        posMinSTR = s[j].m_PNT > s[posMinSTR].m_PNT ? j : posMinSTR;
                    }
                    
                    difSTR = s[j].m_STR - posSTR;
                    posMinSTR = j;
                }
                if(difINT >= s[j].m_INT - posINT){
                    if(difINT == s[j].m_INT - posINT){ // 같으면 PNT로 비교
                        posMinINT = s[j].m_PNT > s[posMinINT].m_PNT ? j : posMinINT;
                    }
                    
                    difINT = s[j].m_INT - posINT;
                    posMinINT = j;
                }
            }
        }
        // 가장 최소인 STR, INT의 차이와 인덱스를 찾음.
        if(!flag) break; // 퀘스트 다깸
//        cout << difSTR << " " << difINT << " " << leftPNT << endl;
        if(difSTR <= leftPNT || difINT <= leftPNT){ // STR, INT 둘중 하나라도 만족할 수 있는경우
            if(difSTR <= difINT){ // STR의 차이가 더 작은 경우
                posSTR = s[posMinSTR].m_STR;
                leftPNT -= difSTR;
                leftPNT += s[posMinSTR].m_PNT;
                s[posMinSTR].m_STR = 0; // 이미 깬 퀘스트
            }
            
            else{ // INT와의 차이가 더 작은 경우
                posINT = s[posMinINT].m_INT;
                leftPNT -= difINT;
                leftPNT += s[posMinINT].m_PNT;
                s[posMinINT].m_STR = 0; // 이미 깬 퀘스트
            }
        }
        
        else{ // 둘 다 만족 하지 못하는 경우
            cout << ans;
            return 0;
        }
        ans++;
//        cout << posSTR << " " << posINT << endl;
    }
    cout << ans << endl;
    return 0;
}

// 먼저 1. STR + INT 순
//     2. PNT 순으로 정렬 하자
//     3. 그 다음 순서대로 뽑으면 될까?
//     -> 탐욕적 선택 속성 증명 : 만약 STR + INT이 더 큰 것부터 선택하는 최적해가 있다고 가정하자
//     이 최적해에서 STR + INT가 최소인 퀘스트와 저 퀘스트를 푸는 순서를 바꾼다고 한다면,
//     STR + INT가 최소인 퀘스트를 푸는 순서 이후의 순서들은 똑같은 PNT를 가지고 퀘스트를 풀게되므로 바뀌는것이 없음.
//     STR + INT가 최소이므로 순서를 바꾸어도 당연히 풀릴것이고, 그 반대도 마찬가지.
//     원래 제일 먼저 풀었던 퀘스트를 풀 수 있었으므로, 그만큼 PNT가 있었다는 말이된다. 그러므로 순서를 바꾸어서 풀어도
//     순서를 바꾼 퀘스트들을 모두 풀 수 있으므로, 최적해가 성립할 것이다.

