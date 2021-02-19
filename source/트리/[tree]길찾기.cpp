//
//  [tree]길찾기.cpp
//  algo
//
//  Created by jm on 2020/09/12.
//  Copyright © 2020 jm. All rights reserved.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int id;
    int x,y;
    Node* left;
    Node* right;
};

bool comp(Node& a, Node& b){
    if(a.y == b.y) //y값이 같으면 x값이 작은 것이 앞으로
        return a.x < b.x;
    return a.y > b.y; //아니면 y값이 큰게 앞으로
}

void addNode(Node* parent, Node* child){
    if(child->x < parent->x){
        if(parent->left == NULL) parent->left = child;
        else
            addNode(parent->left, child);
    }else{
        if(parent->right == NULL) parent->right = child;
        else addNode(parent->right, child);
    }
}
void preorder(vector<int>& ans, Node* node){
    if(node == NULL) return;
    ans.push_back(node->id);
    preorder(ans,node->left);
    preorder(ans,node->right);
}

void postorder(vector<int>& ans, Node* node){
    if(node == NULL) return;
    postorder(ans,node->left);
    postorder(ans,node->right);
    ans.push_back(node->id);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int size = nodeinfo.size();
    vector<Node> nodes;
    
    for(int i = 0; i < size; ++i){
        nodes.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]} );
    }
    sort(nodes.begin(),nodes.end(), comp);
    
    Node* root = &nodes[0]; //제일 첫번째 원소가 루트가 됨.
    for(int i = 1; i < size; ++i){
        addNode(root, &nodes[i]);
    }
    // 모든 노드에 대해 삽입을 수행하므로 이진트리가 만들어짐.
    
    vector<vector<int>> answer{{},{}};
    preorder(answer[0],root);
    postorder(answer[1],root);
    
    return answer;
}
