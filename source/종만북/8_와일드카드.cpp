//
//  8_와일드카드.cpp
//  algo
//
//  Created by jm on 2020/07/31.
//  Copyright © 2020 jm. All rights reserved.
//

// DP 문제를 풀때는, 완전 탐색으로 먼저 해결한 뒤, 중복된 부분 문제를 한 번만 계산하도록 메모이제이션 적용.
// 재귀 호출을 이용하지 않은 동적 계획법 알고리즘 -> 반복적 동적 계획법.
// 하지만 메모이제이션을 통한 접근이 좀더 직관적이기 때문에 재귀호출 자주사용

#include <bits/stdc++.h>

using namespace std;

vector<string> ans;

// 완전 탐색으로 구현
bool match(const string& w, const string& s){
    int pos = 0;
    while(pos < w.size() && pos < s.size() && (w[pos] == '?' || w[pos] == s[pos]) ) pos++;
    
    if(pos == w.size())
        return pos == s.size();
    
    if(w[pos] == '*')
        for(int i = 0; i + pos < s.size(); i++){
            if(match(w.substr(pos+1), s.substr(pos+i))) return true;
        }
    
    return false;
}

// 중복계산이 얼마나 일어날까? -> 입력으로 주어질 수 있는 w와 s의 종류는 제한되어 있다!! 즉, w[i~], s[j~] 의 결과값은 같다는것.
// 입력으로 주어질 수 있는 w와 s는 각각 최대 101개, match()rk 101 x 101만큼 호출되었다면 비둘기집의 원리에 따라 여러번 계산되고 있다는 뜻.
// w는 항상 전체 패턴 W의 접미사이므로, w의 길이가 결정되면 w 또한 결정된다. 이 점을 이용하면 답을 저장할 수 있음.
// 문자열을 인자로 넘기지않고, 시작위치만을 넘긴다.

// DP로 구현
int cache[101][101];
string W,S;
bool matchMemorized(int w, int s){
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    
    while( w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]) ){
        w++;
        s++;
    }
    
    if(w == W.size()) return ret = (s == S.size());
    
    if(W[w] == '*')
        for(int i=0; i+w<W.size(); i++)
            if(matchMemorized(w+1, s+i)) {return ret = 1;}
    
    return ret = 0;
}
// 부분문제의 개수는 n^2개, matchMemorized 함수는 호출 될때마다 최대 N번의 재귀 호출을 하므로 O(n^3)이 된다.

// 위의 코드가 O(n^3)이 걸리는 이유는, 내부에서 첫 *을 찾고 *에 몇 글자가 대응되어야 할지 검사하는 반복문이 존재하기 때문이다.
// 만약 재귀 함수 자체에 반복문이 하나도 없도록 코드를 바꿀 수 있다면, 부분 문제 개수와 같은 시간만을 사용해 문제를 풀 수 있다.

// 조금더 똑똑한 분해 방식 O(n^2)
bool matchMemorized2(int w, int s){
    int &ret = cache[w][s];
    if(ret != -1) return ret;
    
//    이 조건을 통과했다는 의미는 각 문자열의 두 글자가 서로 대응된다는 의미이다.
//    이떄 각각 1씩 증가시키고 계속하는 대신, 각 한글자씩을 뗴고 이들이 서로 대응되는지를 재귀 호출로 확인할 수 있다.
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]) ) return ret = matchMemorized2(w+1, s+1);
    
    if(w == W.size()) return ret = (s == S.size());
//    다음으로는 *에 몇글자가 대응되어야 할지를 확인하는 반복문을 재귀 호출로 바꿔보자.
//    1차원 for문을 재귀 호출로 바꾸는 것은 간단하다. 매 단계에서 *에 아무 글자도 대응시키지 않을 것인지, 아니면 한 글자를 더 대응 시킬것인지 결정하면 된다.
    if(W[w] == '*'){
        if(matchMemorized2(w+1, s) || (s<S.size() && matchMemorized2(w, s+1))) return ret = 1;
    }
    
    return ret = 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t, c;
    string wildCard, test;
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> wildCard >> c;
        for(int j=0; j<c; j++){
            cin >> test;
            if(match(wildCard, test)) ans.push_back(test);
        }
    }
}
