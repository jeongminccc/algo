//
//  [trie]5670_휴대폰 자판.cpp
//  algo
//
//  Created by jm on 2020/09/08.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int GO_MAX = 26;

int N;

struct Trie{
    Trie* go[GO_MAX]; // 다음 노드를 가리키는 포인터 배열
    bool output;
    int branch; // 자식 노드의 개수
    int words; // 몇개의 단어가 중복되는지
    
    Trie(){
        fill(go, go+GO_MAX, nullptr);
        words = 0; branch =0; output=false;
    }
    ~Trie(){
        for(int i=0; i<GO_MAX; ++i)
            if(go[i]) delete go[i];
    }
    
    // 문자열 key를 현재 노드부터 삽입
    void insert(const char* key){
        // 문자열이 끝남
        if(*key == '\0'){
            output = true;
            branch++;
            words++;
        }
        // 아닐 경우
        else{
            words++;
            int next = *key - 'a';
            // 해당 노드가 없으면 동적 할당해서 만듦
            if(!go[next]){
                go[next] = new Trie;
                branch++;
            }
            // 자식 노드에서 이어서 삽입
            go[next]->insert(key+1);
        }
    }
    
    ll cntKeystrokes(bool isRoot){
        ll ret = 0;
        if(words == 1) return 1; // 앞으로 이 문자열 밖에 없음
        if(!isRoot && branch != 1) ret += words; // 문자를 입력할수 밖에 없는 경우
        
        for(int i=0; i<GO_MAX; ++i){
            if(go[i]) ret += go[i]->cntKeystrokes(false);
        }
        return ret;
    }
    
};

int main(){
    while(cin >> N){
        Trie *root = new Trie;
        
        for(int i=0; i<N; ++i){
            char input[81];
            cin >> input;
            root->insert(input);
        }
        cout << fixed << setprecision(2) << (double)root->cntKeystrokes(true) / (double)N << endl;
        delete root;
    }
    
    return 0;
}

