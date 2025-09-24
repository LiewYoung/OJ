#include<iostream>

template<typename T>
struct ListNode {
  T value;
  struct ListNode* next;
  ListNode(T val) : value(val),next(nullptr){

  }
};

template<typename T>
struct TreeNode {
  T value;
  ListNode< TreeNode<T>* >* childHead;
  
  void addChild(TreeNode<T>* node) {
    ListNode< TreeNode<T>* >* childnode = new ListNode< TreeNode<T>* > (node);
    if(childnode==NULL){
      std::cerr<<"Error Memory remalloc fail";
    }
    
    if(childHead==NULL){
      childHead = childnode;
    }else{
      childnode->next = childHead;
      childHead = childnode;
      /* Append a child in font of Head */
    }
  } 
};

template<typename T>
class Tree {
private:
  TreeNode<T>* treeNodes;
  TreeNode<T>* root;
public:
  Tree();
  Tree(int maxNum);
  ~Tree();
  TreeNode<T>* GetNode(int id);
  void SetRoot(int rootId);
  void AddChild(int parentId,int childId);
  void SetData(int id,T data);
  void print(TreeNode<T>* node = NULL);
};

template<typename T>
Tree<T>::Tree() {
  treeNodes = new TreeNode<T>[10001];
}

template<typename T>
Tree<T>::Tree(int maxNum) {
  treeNodes = new TreeNode<T>[maxNum];
}

template<typename T>
Tree<T>::~Tree() {
  delete[] treeNodes;
}

template<typename T>
TreeNode<T>* Tree<T>::GetNode(int id) {
  return &treeNodes[id]; 
}
template<typename T>
void Tree<T>::SetRoot(int rootId) {
  root = GetNode(rootId);
}

template<typename T>
void Tree<T>::AddChild(int parentId,int childId) {
  TreeNode<T>* parent = GetNode(parentId);
  TreeNode<T>* child = GetNode(childId);
  parent -> addChild(child);
}

template<typename T>
void Tree<T>::SetData(int id,T data){
  GetNode(id)->value = data;
}

template<typename T>
void Tree<T>::print(TreeNode<T>* node){
  if(node == NULL){
    node = root;
  }
  std::cout<<node->value;
  ListNode< TreeNode<T>* >* tmp = node->childHead;
  while(tmp){
   print(tmp->value);
    tmp = tmp->next;
  }
}

int main(void){
  std::cout << "Now we will use tree";
  Tree<int> T(10);
  T.SetRoot(0);
  T.AddChild(0,1);
  T.AddChild(0,2);
  T.SetData(0,0);
  T.SetData(1,1);
  T.SetData(2,2);
  T.print();
  return 0;
}

