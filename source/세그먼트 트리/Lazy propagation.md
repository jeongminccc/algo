# Lazy propagation
세그먼트 트리를 이용하여 구간 합을 갱신할때, 우리는 보통 한개의 인덱스만 받아서 갱신을 하게되어 O(lgN)의 시간이 걸리게 된다.  
그렇다면 [i,j] 구간의 원소들을 모두 갱신하라는 쿼리를 요청받으면 O(NlgN)의 시간복잡도를 가지고 쿼리를 행해야 할까?    

```cpp
void update_range(int start, int end, int node, int left, int right, int dif){
    if(start > right || end < left) return;
    if(start == end){
        tree[node] += dif;
        return;
    }
    
    int mid = (start+end)/2;
    update_range(start, mid, node*2, left, right, dif);
    update_range(mid+1, end, node*2+1, left, right, dif);
    tree[node] = tree[node*2] + tree[node*2+1];
}
```
먼저 구간안의 모든 원소들을 갱신하기 위해 update 함수를 조금 수정하였다. 이때 update_range는 그 숫자를 트리상에서 찾고, 업데이트 해야 한다. 따라서, 리프 노드를 나타내는 start == end가 나올 때 까지 계속해서 탐색을 하게 되고, 리프 노드가 아닌 경우에는 두 자식의 합을 계산하는 방식을 사용하게 됩니다.  

하지만 이 update방식은 전체 숫자를 업데이트 할 시 결국 모든 노드를 방문해야 하므로 O(NlgN)이 걸리게 된다.  

O(NlgN)보다 더 빠르게 이 쿼리를 처리할 수 있는 방법이 있는데, 이를 __Lazy propagation__ 이라고 한다.
이는 구간의 업데이트가 필요한 경우, 미리 Lazy[] 배열에 저장 해 놓은뒤, 꼭 필요한 때가 오기 전까지 업데이트를 미뤄두는 방법으로, update 함수 실행중에 이 노드가 가지고 있는 Lazy[] 배열이 0 이 아닐경우, 업데이트를 해주는 방식을 말한다.

```cpp
void update_lazy(int start, int end, int node){
    if(lazy[node] != 0){
        tree[node] += (end-start+1)*lazy[node];
        // leaf가 아니면
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }  
}

void update_range(int start, int end, int node, int left, int right, int dif){
    update_lazy(start, end, node); // 이 node의 값이 필요할 때만 갱신을 해주도록
    
    if(start > right || end > left) return;
    
    if(left <= start && end <= right){
        tree[node] += (end-start+1)*dif;
        if(start != end){
            lazy[node*2] += dif;
            lazy[node*2+1] += dif;
        }
        return;
    }
    int mid = (start+end)/2;
    update_range(start, mid, node*2, left, right, dif);
    update_range(mid+1, end, node*2+1, left, right, dif);
    tree[node] = tree[node*2] + tree[node*2+1];
}
```
출처 : https://www.acmicpc.net/blog/view/26
