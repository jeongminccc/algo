//
//  facebook2020_QualificationR_A.cpp
//  algo
//
//  Created by jm on 2020/07/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;
bool checkPoint[51][51];

int main(){
    int t, l, k=0;
    string incoming, outgoing;
    ifstream readFile;
    ofstream writeFile;
    readFile.open("test.txt");
    writeFile.open("output.txt");
    
    string n, ans, T_case;
    getline(readFile, n);
    t = atoi(n.c_str());
    
    while(t--){
        getline(readFile, n);
        l = atoi(n.c_str());
        
        getline(readFile, incoming);
        getline(readFile, outgoing);
        
        k++;
        T_case = "Case #" + to_string(k) + ":\n";
        writeFile.write(T_case.c_str(), T_case.size());
        
        for(int i=0; i<l; i++){
            for(int j=i; j<l; j++){
                if(i==j) checkPoint[i][j] = true;
                else{
                    if(abs(i-j) == 1){
                        if(outgoing[i] == 'Y' && incoming[j] == 'Y' && checkPoint[i][j-1]) checkPoint[i][j] = true;
                        else checkPoint[i][j] = false;
                    }else{
                        if(outgoing[j-1] == 'Y' && incoming[j] == 'Y' && checkPoint[i][j-1]) checkPoint[i][j] = true;
                        else checkPoint[i][j] = false;
                    }
                }
            }
        }
        for(int i=0; i<l; i++){
            for(int j=i; j>=0; j--){
                if(i==j) checkPoint[i][j] = true;
                else{
                    if(abs(i-j) == 1){
                        if(outgoing[i] == 'Y' && incoming[j] == 'Y' && checkPoint[i][j+1]) checkPoint[i][j] = true;
                        else checkPoint[i][j] = false;
                    }else{
                        if(outgoing[j+1] == 'Y' && incoming[j] == 'Y' && checkPoint[i][j+1]) checkPoint[i][j] = true;
                        else checkPoint[i][j] = false;
                    }
                }
            }
        }

        for(int i=0; i<l; i++){
            ans = "";
            for(int j=0; j<l; j++){
                if(checkPoint[i][j]) ans += 'Y';
                else ans += 'N';
            }ans += "\n";
            writeFile.write(ans.c_str(), ans.size());
        }
    }
    
    readFile.close();
    writeFile.close();
    
    return 0;
}

