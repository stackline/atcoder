#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  int key;
  Node *prev, *next;
};

class DoublyLinkedList {
private:
  Node *nil;

public:
  DoublyLinkedList() {
    init();
  }

private:
  void init() {
    // ### malloc
    //
    // malloc で Node 型が利用するメモリサイズを動的に確保する
    // malloc はメモリ確保が成功すると、メモリブロックへのポインタを返す
    // 戻り値は汎用ポインタ (void *) である
    //
    // c++ は (void *) から (Node *) への型変換を暗黙的に行わない
    // void 型のポインタを逆参照するには、型キャストする必要がある
    //
    // ### sizeof
    //
    // sizeof(int)    =  4 byte = 32 bit
    // sizeof(Node *) =  4 byte = 32 bit
    // sizeof(Node *) =  4 byte = 32 bit
    // --------------------------------
    // sizeof(Node)   = 24 byte
    //
    // 構造体のメモリサイズが、構造体の各メンバのメモリサイズの合計以上になるケースがある
    // これは sizeof が構造体のパディング領域も含めたサイズを返すため
    // パディング領域はコンパイラによって配置される
    //
    // 以下は番兵を示す nil ノードであり、prev, next を自分自身 = 番兵につなぐ
    nil = (Node *)malloc(sizeof(Node));
    // アロー演算子で、ポインタ変数からメンバにアクセスしている
    nil->next = nil;
    nil->prev = nil;
  }

public:
  void insert(int key) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    x->prev = nil;
    nil->next = x;
  }

  void deleteNode(Node *t) {
    if (t == nil) { return; }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
  }

  void deleteFirst() {
    deleteNode(nil->next);
  }

  void deleteLast() {
    deleteNode(nil->prev);
  }

  void deleteKey(int key) {
    Node *t = listSearch(key);
    deleteNode(t);
  }

  Node* listSearch(int key) {
    Node *cur = nil->next;
    while (cur != nil && cur->key != key) {
      cur = cur->next;
    }
    return cur;
  }

  Node* selectNil() {
    return nil;
  }
};

int main() {
  int n;
  cin >> n;

  DoublyLinkedList dll;
  for (int i = 0; i < n; i++) {
    char c[12];
    int x;
    // c は配列であり、アドレスを表す
    // x は整数型変数であり、& (アドレス演算子) でアドレスを表す
    scanf("%s %d", c, &x);
    string s = c;
    if (s == "insert") {
      dll.insert(x);
    } else if (s == "delete") {
      dll.deleteKey(x);
    } else if (s == "deleteFirst") {
      dll.deleteFirst();
    } else if (s == "deleteLast") {
      dll.deleteLast();
    }
  }

  Node *nil = dll.selectNil();
  Node *cur = nil->next;
  bool is_first = true;
  while (1) {
    if (cur == nil) { break; }
    if (is_first == false) { cout << " "; }
    cout << cur->key;
    cur = cur->next;
    is_first = false;
  }
  cout << endl;
  return 0;
}
