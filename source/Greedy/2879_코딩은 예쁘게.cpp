//
//  2879_코딩은 예쁘게.cpp
//  algo
//
//  Created by jm on 2020/09/02.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

int N, wrong_tap[1001], correct_tap[1001], ans=0;

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> wrong_tap[i];
    for(int i=0; i<N; i++) cin >> correct_tap[i];
    
    int pos=0, dif=0;
    for(int i=0; i<N; i++){
        if(wrong_tap[i] == correct_tap[i]) continue; // 추가/삭제가 필요없는 경우
        
        else if(wrong_tap[i] < correct_tap[i]){ // 탭을 더 추가해야 되는 경우
            pos = i+1; dif = correct_tap[i] - wrong_tap[i];
            ans += dif;
            wrong_tap[i] += dif;
            while(1){
                
                if(correct_tap[pos] - wrong_tap[pos] >= dif){ // 그 다음의 경우에도 탭을 추가해야 될 경우 && 첫번째경우 이상만.
                    wrong_tap[pos] += dif;
                    pos++;
                }
                
                else if(correct_tap[pos] - wrong_tap[pos] < dif && wrong_tap[pos] < correct_tap[pos]){
                    // 그 다음의 경우에도 탭을 추가해야 하지만 차이가 최소인경우 -> 새로운 중단점이 될 수 있으므로 처리.
                   
                    dif = correct_tap[pos] - wrong_tap[pos];
                    wrong_tap[pos] += dif;
                    pos++;
                }
                
                else break; // 탭을 더 삭제해야 되는 경우를 만날때 종료.
            }
        }
        
        else{ // 탭을 더 삭제해야 되는 경우
            pos = i+1; dif = wrong_tap[i] - correct_tap[i];
            ans += dif;
            wrong_tap[i] -= dif;
            while(1){
                
                if(wrong_tap[pos] - correct_tap[pos] >= dif){ // 그 다음의 경우에도 탭을 첫번째경우 이상만큼 삭제해야 되는 경우
                    wrong_tap[pos] -= dif;
                    pos++;
                }
                
                else if(wrong_tap[pos] - correct_tap[pos] < dif && correct_tap[pos] < wrong_tap[pos]){
                    // 그 다음의 경우에도 탭을 삭제해야 하지만 차이가 최소인경우 -> 새로운 중단점이 될 수 있으므로 처리.
                   
                    dif = wrong_tap[pos] - correct_tap[pos];
                    wrong_tap[pos] -= dif;
                    pos++;
                }
                
                else break;
            }
        }
    }
    cout << ans;
    return 0;
}
