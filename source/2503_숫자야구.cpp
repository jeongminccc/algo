//
//  2503_숫자야구.cpp
//  algo
//
//  Created by jm on 2020/07/13.
//  Copyright © 2020 jm. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

typedef struct _tagGame{
    string ballNum;
    int ballSt;
    int ballB;
}Game;

vector<Game> G;
int ans;

bool CheckEqual(string ballNum){
    if( (ballNum[0] != ballNum[1]) && (ballNum[0] != ballNum[2]) && (ballNum[1] != ballNum[2])) {
        if( (ballNum[0] != '0') && (ballNum[1] != '0') && (ballNum[2] != '0') ) return true;
        else return false;
    }
    else return false;
}

void Solve(){
    for(int i=123; i<988; i++){
        
        string Tmp_Num = to_string(i);
        if(!CheckEqual(Tmp_Num)) continue;
        
        for(int j=0; j<G.size(); j++){
            int Tmp_St = 0;
            int Tmp_B = 0;
            
            if(Tmp_Num[0] == G[j].ballNum[0]) Tmp_St++;
            else if(Tmp_Num[0] == G[j].ballNum[1] || Tmp_Num[0] == G[j].ballNum[2]) Tmp_B++;
            
            if(Tmp_Num[1] == G[j].ballNum[1]) Tmp_St++;
            else if(Tmp_Num[1] == G[j].ballNum[0] || Tmp_Num[1] == G[j].ballNum[2]) Tmp_B++;
            
            if(Tmp_Num[2] == G[j].ballNum[2]) Tmp_St++;
            else if(Tmp_Num[2] == G[j].ballNum[1] || Tmp_Num[2] == G[j].ballNum[0]) Tmp_B++;
            
            if(Tmp_St == G[j].ballSt && Tmp_B == G[j].ballB) {
                if(j == G.size() - 1) ans++;
                continue;
            }
            else break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        Game input;
        cin >> input.ballNum >> input.ballSt >> input.ballB;
        G.push_back(input);
    }
    
    Solve();
    
    cout << ans << endl;
    
    return 0;
}
