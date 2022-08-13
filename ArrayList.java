public class ArrayList {
    private static class Node {
        int data;
    }

    private int size;
    private Node[] array;
    private final int INITIAL_SIZE = 100;
    
    public ArrayList() {
        array = new Node[INITIAL_SIZE];
    }

    public void addLast(Node node) {
        array[size] = node;
        size++;
    }

    public void add(int index, Node node) {
        for(int i = size - 1; i >= index; i--) {
            array[i+1] = array[i];
        }
        array[index] = node;
        size++;
    }

    public void addFirst(Node node) {
        add(0, node);
    }

    public void remove(int index) {
        for(int i = index + 1; i <= size; i++) {
            array[i-1] = array[i];
        }

        size--;
        array[size] = null;
    }
}
