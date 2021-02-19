//
//  lower,upper_bound.cpp
//  algo
//
//  Created by jm on 2020/08/12.
//  Copyright © 2020 jm. All rights reserved.
// 출처 : https://blockdmask.tistory.com/168#recentComments

// lower_bound
// 이진 탐색기반의 탐색방법 / 배열 또는 리스트가 정렬되어있어야 한다.
// 찾으려 하는 key값이 없으면 key값 보다 큰 가장 작은 정수값을 찾는다.
// 같은 원소가 여러개 있어도 상관없음. 항상 유일한 해 구할 수 있다.
// arr[mid-1] < key 이면서, arr[mid] >= key 인 최소의 m 값을 찾으면 된다. (m >= 2)

int mylower_bound(int * arr, int n, int key){
    int start = 0;
    int end = n;
    
    int mid = n;
    while(start<end){
        int mid = (start+end)/2;
        
        if(arr[mid] < key) start = mid+1;
        else end = mid; // 미드 포함 왼쪽(포함하는 이유는 KEY값과 같은것이 없을때 key보다 큰 가장 작은 정수값 반환 위해
    }
    return end + 1;
}

// auto it = lower_bound(arr, arr + n, key) 하면 반환값은 찾은 값의 주소이다.
// 따라서 it으로 주소를 받아서
// int key_num = *it 으로 사용 혹은,
// int key_position = it - arr + 1 로 사용 하면됨.

// upper_bound
// 이진 탐색 기반의 탐색방법 / 마찬가지로 오름차순 정렬 필요.
// key값을 초과하는 가장 첫번째 원소의 위치를 반환.

int myupper_bound(int * arr, int n, int key){
    int start = 0;
    int end = n;
    
    int mid = n;
    while(start<end){
        int mid = (start+end)/2;
        
        if(arr[mid] <= key) start = mid+1; // 이부분 = 이 추가된것만 다름.
        else end = mid;
    }
    return end + 1;
}
