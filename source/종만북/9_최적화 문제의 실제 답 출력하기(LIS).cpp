#include <bits/stdc++.h>

using namespace std;

int cache[501][501];

int main(){
    int M;
    
    cin >> M;
    vector<int> v1(M);
    for(auto& a:v1) cin >> a;
    
    cin >> M;
    vector<int> v2(M);
    for(auto& a:v2) cin >> a;
    
    int lastBigV1[501],lastBigV2[501], pos1 = 0, pos2=0, posOfV1[501], lastPos2=0;
    cout << "  "; for(int i=0; i<v2.size(); i++) cout << v2[i] << " "; cout << endl;
    
    lastBigV1[0] = -1e9; lastBigV2[0] = -1e9;
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << " ";
        for(int j=0; j<v2.size(); j++){
            if(v1[i] == v2[j]){
                if(v1[i] >= lastBigV1[pos1]){
//                    if(j < lastPos2){
//                        cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
//                        continue;
//                    }
                    lastPos2 = j;
                    pos1++;
                    lastBigV1[pos1] = v1[i];
                    cache[i+1][j+1] = cache[i][j] + 1;
//                    posOfV1[i] = pos1;
                }else{
                    auto it = lower_bound(lastBigV1, lastBigV1+pos1, v1[i]);
                    *it = v1[i];
                    cache[i+1][j+1] = cache[i][j] + 1;
//                    cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
//                    posOfV1[i] = (int)(it - lastBigV1);
                }
            }
            else cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
            cout << cache[i+1][j+1] << " ";
        }
        cout << endl;
    }
    
    cout << cache[v1.size()][v2.size()] << endl;
    vector<int> ans;
    cout << endl;
    for(int i=(int)v1.size()-1; i>=0; --i){
        if(posOfV1[i] == pos1){
            ans.push_back(v1[i]);
            pos1--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto& a:ans) cout << a << " ";
    cout << endl;
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
/*
back: 트레이싱을 할 때 따라가는 값.
(다음 A 항의 위치 * 1000 + 다음 B 항의 위치)로 해싱.
*/
int Alen, Blen, A[500], B[500], dp[500][500], back[500][500];
 
// LCIS 길이를 구하며 back 배열도 채우는 함수
int LCIS(int Apos, int Bpos){
    // 기저 사례: 어느 한쪽이 수열의 끝에 도달함
    if(Apos==Alen || Bpos==Blen) return 0;
    int &ret = dp[Apos][Bpos];
    if(ret != -1) return ret;
 
    ret = 1;
    // back 배열의 초기값: 더 이상 따라갈 항이 없음
    back[Apos][Bpos] = Alen*1000 + Blen;
    // A의 뒤에 있는 항들에 대해 매칭해서 결과를 구함
    for(int i=Apos+1; i<Alen; i++){
        if(A[Apos] >= A[i]) continue;
        for(int j=Bpos+1; j<Blen; j++){
            if(A[i] == B[j]){
                int temp = LCIS(i, j) + 1;
                if(ret < temp){
                    ret = temp;
                    back[Apos][Bpos] = i*1000 + j;
                }
                break;
            }
        }
    }
    return ret;
}
 
// LCIS를 찾아가는 함수
void trace(int Apos, int Bpos){
    if(Apos==Alen || Bpos==Blen) return;
    printf("%d ", A[Apos]);
    trace(back[Apos][Bpos]/1000, back[Apos][Bpos]%1000);
}
 
int main(){
    scanf("%d", &Alen);
    for(int i=0; i<Alen; i++)
        scanf("%d", A+i);
    scanf("%d", &Blen);
    for(int i=0; i<Blen; i++)
        scanf("%d", B+i);
 
    // dp로 LCIS를 구함. 이때 시작 항의 정보 역시 start에 해싱해서 보유
    memset(dp, -1, sizeof(dp));
    int result = 0, start = -1;
    for(int i=0; i<Alen; i++){
        for(int j=0; j<Blen; j++){
            if(A[i] == B[j]){
                int temp = LCIS(i, j);
                if(result < temp){
                    result = temp;
                    start = i*1000 + j;
                }
                break;
            }
        }
    }
    // LCIS의 길이
    printf("%d\n", result);
    // LCIS 출력
    if(start != -1) trace(start/1000, start%1000);
}
출처 : https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220603373411&proxyReferer=https:%2F%2Fwww.google.com%2F
