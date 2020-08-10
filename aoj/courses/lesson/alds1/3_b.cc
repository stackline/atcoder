#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ProcessInfo = pair<string, int>;

class TinyRingBuffer {
private:
  ProcessInfo Q[100000];
  int head; // 先頭ポインタ
  int tail; // 末尾ポインタ
  int MAX;  // リングバッファの容量

public:
  TinyRingBuffer(int max) {
    // isEmpty が true の状態
    head = 0;
    tail = 0;
    // キューが空のときと満杯のときを区別するために tail -> head の間に1つ以上の空きを設ける
    MAX = max+1;
  }

  bool isEmpty() {
    return head == tail;
  }

  // ### 例
  // * n=5
  // * time=[150, 80, 200, 350, 20]
  // * MAX = n+1 = 6
  //
  // step0.
  //   head=0, tail=0
  // step1. enqueue(150)
  //   0 = (0+1)%6 --> 0 = 1 --> isFull() false
  //   head=0, tail=1, |150|
  // step2. enqueue(80)
  //   0 = (1+1)%6 --> 0 = 2 --> isFull() false
  //   head=0, tail=2, |150|80|
  // step3. enqueue(200)
  //   0 = (2+1)%6 --> 0 = 3 --> isFull() false
  //   head=0, tail=3, |150|80|200|
  // step4. enqueue(350)
  //   0 = (3+1)%6 --> 0 = 4 --> isFull() false
  //   head=0, tail=4, |150|80|200|350|
  // step5. enqueue(20)
  //   0 = (4+1)%6 --> 0 = 5 --> isFull() false
  //   head=0, tail=5, |150|80|200|350|20|
  // step6. enqueue(110)
  //   0 = (5+1)%6 --> 0 = 0 --> isFull() true となるため、オーバーフローする
  //
  bool isFull() {
    // > ここでキューが満杯かどうかの判定基準ですが、
    // > ここでは「あと 1 個要素を追加したらリングバッファの先頭と最後尾が繋がってしまう状態」としています。
    // > すなわちバッファに追加されている要素が MAX - 1 個の状態を満杯であるとしています。
    //
    // 参考: [スタックとキューを極める！ 〜 考え方と使い所を特集 〜](https://qiita.com/drken/items/6a95b57d2e374a3d3292)
    return head == (tail + 1) % MAX;
  }

  void enqueue(ProcessInfo p) {
    if (isFull()) { exit_failure("enqueue", "overflow"); }
    Q[tail] = p;
    if (tail+1 == MAX) { tail = 0; } else { tail++; }
  }

  ProcessInfo dequeue() {
    if (isEmpty()) { exit_failure("dequeue", "underflow"); }
    ProcessInfo p = Q[head];
    if (head+1 == MAX) { head = 0; } else { head++; }
    return p;
  }

private:
  void exit_failure(string method, string error) {
      cout << "TinyRingBuffer::" << method << ": " << error << " error" << endl;
      exit(EXIT_FAILURE);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  TinyRingBuffer rb(n);
  for (int i = 0; i < n; i++)
  {
    string process;
    int time;
    cin >> process >> time;
    rb.enqueue(make_pair(process, time));
  }

  int total_time = 0;
  while (!rb.isEmpty()) {
    ProcessInfo process = rb.dequeue();

    int processed_time = min(q, process.second);
    process.second = process.second - processed_time;
    total_time += processed_time;

    if (process.second == 0) {
      cout << process.first << " " << total_time << endl;
    } else {
      rb.enqueue(process);
    }
  }
  return 0;
}
