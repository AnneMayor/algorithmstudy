public class LinkedList {
    
    private static class Node {
        int value;
        Node prev;
        Node next;
    }

    public class ListIterator {
        private Node lastReturned;
        private Node next;
        private int nextIndex;

        public ListIterator() {
            next = head;
            nextIndex = 0;
        }

        public ListIterator listIterator() {
            return new ListIterator();
        }

        public Node next() {
            lastReturned = next;
            next = next.next;
            nextIndex++;
            return lastReturned;
        }

        public void add(Node node) {
            if(lastReturned == null) {
                head = node;
                node.next = next;
            } else {
                lastReturned.next = node;
                node.next = next;
            }
            lastReturned = node;
            nextIndex++;
            size++;
        }

        public void remove() {
            // 여긴 이렇게 방어로직 구현을 하는 것이 맞는 것일까...?
            if(nextIndex > 0) {
                LinkedList.this.remove(nextIndex-1);
                nextIndex--;
            }
        }
    }

    private Node head;
    private Node tail;
    private int size;

    public LinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public void addFirst(Node node) {
        node.next = head;
        head = node;
        size++;

        if(head.next == null) {
            tail = head;
        }
    }

    public void addLast(Node node) {
        if(size == 0) {
            addFirst(node);
        } else {
            node.next = tail;
            tail = node;
            size++;
        }
    }

    public void add(int index, Node node) {
        if(size == 0) {
            addFirst(node);
        } else {
            Node current = head;
            for(int i = 1; i < index; i++) {
                current = current.next;
            }

            Node next = current.next;

            current.next = node;
            size++;
            node.next = next;

            if(node.next == null) {
                tail = node;
            }
        }
    }

    public void removeFirst() {
        Node temp = head;
        head = temp.next;

        temp = null;
        size--;
    }

    public void remove(int index) {
        if(size == 0) removeFirst();
        else {
            Node prev = head;
            for(int i = 1; i < index; i++) {
                prev = prev.next;
            }

            Node toBeDeleted = prev.next;

            prev.next = prev.next.next;

            if(toBeDeleted == null) {
                tail = prev;
            }
            
            toBeDeleted = null;
            size--;
        }
    }
}
