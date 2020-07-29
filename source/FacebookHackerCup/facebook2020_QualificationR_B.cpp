//
//  facebook2020_QualificationR_B.cpp
//  algo
//
//  Created by jm on 2020/07/26.
//  Copyright © 2020 jm. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

bool ans;
string check(string a){
    if(a == "AAB" || a == "ABA" || a == "BAA") return "A";
    else if(a == "ABB" || a == "BAB" || a == "BBA") return "B";
    else return a;
}

void foo(string stone){
    while(stone.size() > 1){
        bool flag = false;
        for(int i=0; i<stone.size()-2; i++){
            string temp_stone = stone;
            string temp = check(stone.substr(i,3));
            if(temp == stone.substr(i,3)) continue;
            else {
                stone.replace(i,3,temp); i--; flag=true;
                if(stone.size() == 1) break;
            }
        }
        if(!flag) return;
    }
    ans = true;
}

int main(){
    int t,n,k=0;
    string stone, temp, an;
    
    ifstream readFile;
    ofstream writeFile;
    readFile.open("test.txt");
    writeFile.open("output.txt");
    
    getline(readFile, temp);
    t = atoi(temp.c_str());
    
    while(t--){
        getline(readFile, temp);
        n = stoi(temp);
        
        getline(readFile, stone);
        k++;
        ans = false;
        foo(stone);
        
        if(ans) an = "Y";
        else an = "N";
        string wr = "Case #" + to_string(k) + ": " + an + "\n";
        writeFile.write(wr.c_str(), wr.size());
    }
    
    readFile.close();
    writeFile.close();
    
    return 0;
}

