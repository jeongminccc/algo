//
//  [trie]5052_전화번호 목록.cpp
//  algo
//
//  Created by jm on 2020/09/08.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
const int GO_MAX = 10;

int N;

struct Trie{
    Trie* go[GO_MAX]; // 다음 노드를 가리키는 포인터 배열
    bool output; // 이 노드에서 끝나는 전화번호가 있는가
    bool goexist; // 이 노드의 자식이 있는가
    
    Trie(){
        fill(go, go+GO_MAX, nullptr);
        output = goexist = false;
    }
    
    ~Trie(){
        for(int i=0; i<GO_MAX; ++i)
            if(go[i]) delete go[i];
    }
    
    // 문자열 key를 현재 노드부터 삽입
    void insert(const char* key){
        // 문자열이 끝남
        if(*key == '\0') output = true;
        // 아닐 경우
        else{
            int next = *key - '0';
            // 해당 노드가 없으면 동적 할당해서 만듦
            if(!go[next]) go[next] = new Trie;
            goexist = true;
            // 자식 노드에서 이어서 삽입
            go[next]->insert(key+1);
        }
    }
    
    // 이 노드가 일관성이 있는가?
    bool consistent(){
        // 자식이 있는데 여기서 끝나면 일관성이없음.
        if(goexist && output) return false;
        // 자식들 중 하나라도 일관성이 없으면 일관성이 없음.
        for(int i=0; i<GO_MAX; ++i)
            if(go[i] && !go[i]->consistent()) return false;
        
        return true;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        Trie *root = new Trie;

        cin >> N;
        for(int i=0; i<N; ++i){
            char input[11];
            cin >> input;
            root->insert(input);
        }
        if(root->consistent()) cout << "YES" << endl;
        else cout << "NO" << endl;
        delete root;
    }
}

// 출처 : https://blog.naver.com/kks227/220938122295
