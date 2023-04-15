public class CrackingTheCodingInterview_Chapter3_StackMin {
    private NodeWithMin[] stack;
    private int index;
    private int maxLen = 100;
    private class NodeWithMin {
        private int value;
        private int minValue;

        public NodeWithMin(int value) {
            this.value = value;
            this.minValue = Integer.MAX_VALUE;
        }
    }

    public CrackingTheCodingInterview_Chapter3_StackMin(NodeWithMin[] stack) {
        this.stack = stack;
        this.index = 0;
    }

    public int pop() {
        int value = stack[index].value;
        stack[index] = null;
        if (index == 0) throw new IndexOutOfBoundsException();
        index--;
        return value;
    }

    public int push(int value) {
        int minVal = Math.min(value, stack[index].minValue);

        if (index >= maxLen) throw new IndexOutOfBoundsException();

        stack[index] = new NodeWithMin(value, minVal);
        return stack[index].value;
    }

    public int min() {
        return stack[index].minValue;
    }
    
}