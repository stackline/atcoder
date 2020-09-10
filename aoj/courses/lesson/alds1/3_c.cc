#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
  int key;
  Node *prev, *next;
};

class DoublyLinkedList {
// private:
public:
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

    // 番兵 (nil ノード) の直後、既存の先頭ノードの前に要素を追加する
    //
    // nil - y に x を追加して nil - x - y とする場合
    //
    // * nil->next である y を x->next にセットする
    // * nil->next である y の prev を x にする
    //   * これで x->next = y, y->prev = x となり、双方向に連結する
    // * nil->next = x, x->prev = nil として、nil と x を双方向に連結する
    //
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
};

int main() {
#ifndef ONLINE_JUDGE
  int n;
  cin >> n;

  vector<pair<string, int>> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int x;
    if (s == "insert" || s == "delete") {
      cin >> x;
    } else {
      x = -1;
    }
    v.at(i) = make_pair(s, x);
  }
#endif

#ifdef ONLINE_JUDGE
  DoublyLinkedList dll;
  cout << "# DoublyLinkedList dll;" << endl;
  cout << "nil->prev: " << dll.nil->prev << endl;
  cout << "nil->key:  " << dll.nil->key  << endl;
  cout << "nil->next: " << dll.nil->next << endl;
  dll.insert(10);
  cout << endl;
  cout << "dll.insert(10);" << endl;
  cout << "nil->prev:       " << dll.nil->prev << endl;
  cout << "nil->key:        " << dll.nil->key  << endl;
  cout << "nil->next:       " << dll.nil->next << endl;
  cout << "nil->next->prev: " << dll.nil->next->prev << endl;
  cout << "nil->next->key:  " << dll.nil->next->key  << endl;
  cout << "nil->next->next: " << dll.nil->next->next << endl;
  dll.insert(20);
  cout << endl;
  cout << "dll.insert(20);" << endl;
  cout << "nil->prev:            " << dll.nil->prev << endl;
  cout << "nil->key:             " << dll.nil->key  << endl;
  cout << "nil->next:            " << dll.nil->next << endl;
  cout << "nil->next->prev:      " << dll.nil->next->prev << endl;
  cout << "nil->next->key:       " << dll.nil->next->key  << endl;
  cout << "nil->next->next:      " << dll.nil->next->next << endl;
  cout << "nil->next->next-prev: " << dll.nil->next->next->prev << endl;
  cout << "nil->next->next-key:  " << dll.nil->next->next->key  << endl;
  cout << "nil->next->next-next: " << dll.nil->next->next->next << endl;

  dll.insert(30);
  cout << endl;
  cout << "dll.insert(30);" << endl;
  cout << "dll.listSearch(30): " << dll.listSearch(30) << endl;
  cout << "dll.listSearch(20): " << dll.listSearch(20) << endl;
  cout << "dll.listSearch(10): " << dll.listSearch(10) << endl;
  cout << "dll.listSearch(0):  " << dll.listSearch(0) << endl;

  dll.deleteKey(20);
  cout << endl;
  cout << "dll.deleteKey(20);" << endl;
  cout << "dll.listSearch(30): " << dll.listSearch(30) << endl;
  cout << "dll.listSearch(20): " << dll.listSearch(20) << endl;
  cout << "dll.listSearch(10): " << dll.listSearch(10) << endl;
  cout << "dll.listSearch(0):  " << dll.listSearch(0) << endl;
#endif

  return 0;
}
