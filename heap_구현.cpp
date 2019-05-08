#include <iostream>

using namespace std;

const int MAX = 100;
class PriorityQueue {

    // 노드 번호가 낮은 데이터가 우선순위가 큰 경우

    private:
        int data[MAX];
        // len 초기화 안해줄 경우, 터미널 에러 발생.(Bus Error, Segmentation Fault)
        int len = 1;

    public:
        void push(int x) {
            data[len++] = x;

            int idx = len-1;

            while(idx > 1) {
                if(data[idx] < data[idx/2]) {
                    int temp = data[idx];
                    data[idx] = data[idx/2];
                    data[idx/2] = temp;
                } else {
                    break;
                }

                idx /= 2;
            }
        }

        void pop() {
            data[1] = data[len-1];
            data[len-1] = 0;
            len--;

            int idx = 1;
            int pIdx = -1;

            while(1) {
                
                // 자식 노드가 없는 경우
                if(idx*2 >= len) {
                    break;
                }

                // 왼쪽 자식만 있는 경우
                if(idx*2 >= 1 && idx*2 < len && idx*2+1 >= len) {
                    pIdx = idx*2;
                }

                // 둘 다 있는 경우
                else {
                    if(data[idx*2] > data[idx*2+1]) {
                        pIdx = idx*2+1;
                    } else {
                        pIdx = idx*2;
                    }
                }

                if(data[idx] > data[pIdx]) {
                    int temp = data[idx];
                    data[idx] = data[pIdx];
                    data[pIdx] = temp;
                    idx = pIdx;
                } else {
                    break;
                }

            }

        }

        int top() {
            return data[1];
        }

};

int main() {

    PriorityQueue pq;

    pq.push(10);
    pq.push(3);
    pq.push(20);
    pq.push(-1);

    printf("%d\n", pq.top());
    pq.pop();

    printf("%d\n", pq.top());
    pq.pop();

    printf("%d\n", pq.top());
    pq.pop();

    printf("%d\n", pq.top());
    pq.pop();

    return 0;
}