public class QueueWithStacks<T> {
    private Stack<T> stackNewest;
    private Stack<T> stackOldest;
    
    public QueueWithStacks<T>(Stack<T> stackNewest, Stack<T> stackOldest) {
        this.stackNewest = stackNewest;
        this.stackOldest = stackOldest;
    }
    
    public int size() {
        return stackNewest.size() + stackOldest.size();
    }
    
    public void add(T value) {
        stackNewest.push(value);
    }
    
    public int peek() {
        shiftStack();
        return stackOldest.peek();
    }
    
    public int remove() {
        shiftStack();
        return stackOldest.pop();
    }
    
    private void shiftStack() {
        if (stackOldest.isEmpty()) {
            while (!stackNewest.isEmpty()) {
                stackOldest.push(stackNewest.pop());
            }
        }
    }
}