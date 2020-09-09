# Associative Container
- 연관 컨테이너와 다르게, key - value 구조를 가진다.

우리는 보통 key - value 구조를 가지고 두가지의 질문을 할 수 있다.
1. key가 연관 컨테이너에 존재 하는가? -> True or False
2. 만약 존재한다면 이에 대응되는 값이 무엇인가? -> value  

1번 질의를 처리할 수 있는 컨테이너는 set과 multiset이고, 2번 질의를 처리할 수 있는 컨테이너는 map과 multimap이다.  
물론 맵과 멀티맵을 셋 처럼 사용할 수는 있지만, 셋 보다 사용하는 메모리가 크기 때문에 키의 존재 유무 만 궁금하다면 셋을 사용하는 것이 좋다.  

## set
set은 BST로, 자동으로 정렬이 되며, 원소를 추가하거나 삭제하는데에 O(logN)이 걸린다. 시퀀스 컨테이너와 비교하면 성능이 좋다는것을 알 수 있다.

```cpp
set<int> s;
s.insert();
s.find(key); // 못찾으면 s.end()를 리턴
```
- set의 진가는 find()함수에 있다. vector에서 원소가 있는지 찾으려면 O(N)이 걸리지만, set은 O(logN)이면 된다.  
- set에는 중복된 원소가 없다. 중복된 원소를 넣고 싶다면 multiset을 사용하면 된다.  

### set과 priority_queue
- priority_queue는 in-place로 heap을 구성한다. 때문에 메모리 할당도 Container 방식을 따라간다.
- set은 BST이고, 순회/정렬/삽입이 가능하다. 따라서 한 노드가 들고 있는 자료가 많다. 트리구조이기 때문에 메모리가 연속적인 공간에 있지 않다. (map또한 트리형태임)

-> 그러므로, 메모리 할당 측면만 봐도 1~2개의 자료만 저장하면 되는 prioirity_queue에 비해 5개의 자료를 저장해야 하는 set이 더 느릴수 밖에 없음을 알 수 있다.  
게다가, priority_queue를 vector를 이용하여 만들 때 발생하는 재할당 문제도 reserve로 해결할 수 있다. 

## map
map은 set과 똑같은 구조이지만(트리구조, 자동으로 정렬), 키만 저장하는 set과는 달리 map은 key - value를 저장한다.

```cpp
map<string, int> m;
m.insert(make_pair("abc", 1)); // or m[abc] = 1;
auto iter = m.find(key) // 못찾으면 m.end()를 리턴, 찾으면 iter에 해당 key-value 저장
```

- multimap은 한개의 key에 여러개의 value가 대응될 수 있지만, m[key]와 같은 연산자를 사용할 수 없다.  
만약 이를 모두 출력하거나 알고 싶다면?  
```cpp
auto range = m.equal_range(1);
for (auto itr = range.first; itr != range.second; ++itr) {
  cout << itr->first << " : " << itr->second << " " << endl;
}
```
equal_range함수는 대응되는 값들의 begin()과 end()를 pair로 만들어 반환한다. 즉 first가 begin()을, second가 end()를 나타낸다.  

## unordered_set, unordered_map
- insert, erase, find가 O(1)으로 수행된다. -> 해쉬함수를 사용하기때문.  

하지만 최악의 경우에는 O(N)으로 수행될수도 있는 반면에, set과 map은 항상 O(logN)에 수행된다.  

> 그러므로 보통의 경우엔 set과 map을 사용하되, 최적화가 매우 필요한 작업인 경우에 해시함수를 잘 계산하여 쓰는것이 좋다.  



### 
출처 : https://modoocode.com/224
출처 : http://www.secmem.org/blog/2019/12/13/c++-container-memory-usage-2/
