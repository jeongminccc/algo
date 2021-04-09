#include <iostream>

using namespace std;

int N, arr[1001], tallest = 0, ans = 0;

void toRight(){
    int idx = 0, size = 0;
    while (arr[idx] < tallest && idx <= 1000){
    	size = max(size, arr[idx]);
        ans += size;
        idx++;
    }
}

void toLeft(){
    int idx = 1000, size = 0;
    while (arr[idx] < tallest && idx >= 0){
    	size = max(size, arr[idx]);
        ans += size;
        idx--;
    }
}

int main(){
    cin >> N;
    int tmpIdx;
    for (int i=0; i<N; ++i){
        cin >> tmpIdx;
        cin >> arr[tmpIdx];
        tallest = max(tallest, arr[tmpIdx]);
    }

    toRight();
    toLeft();
    ans += tallest;
    cout << ans;
    return (0);
}