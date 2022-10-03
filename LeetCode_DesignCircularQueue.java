public class MyCircularQueue {
    int[] queue;
    int front = 0, back = -1, length = 0;

    public MyCircularQueue(int k) {
        queue = new int[k];
    }
    
    public boolean enQueue(int value) {
        if(length < queue.length) {
            back = (back + 1) % queue.length;
            queue[back] = value;
            length++;
            return true;
        }

        return false;
    }
    
    public boolean deQueue() {
        if(length > 0) {
            front = (front + 1) % queue.length;
            length--;
            return true;
        }

        return false;
    }
    
    public int Front() {
        if(length > 0) return queue[front];
        return -1;
    }
    
    public int Rear() {
        if(length > 0) return queue[back];
        return -1;
    }
    
    public boolean isEmpty() {
        return length == 0;
    }
    
    public boolean isFull() {
        return length >= queue.length;
    }
    
}
