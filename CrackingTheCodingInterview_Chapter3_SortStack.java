
public class SortStack {

    static class Range {
        int start;
        int end;

        public Range(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    public void sort(Stack<Integer> s) {
        Stack<Integer> r = new Stack<>();

        while (!s.isEmpty()) {
            while (!r.isEmpty() && r.peek() > s.peek()) {
                s.push(r.pop());
            }

            r.push(s.pop());
        }

        while (!r.isEmpty()) {
            s.push(r.pop());
        }
    }

    public static void quickSort(int [] nums, int start, int end) {
        Stack<Range> s = new Stack<>();

        s.push(new Range(start, end));

        while (!s.isEmpty()) {
            Range current = s.pop();
            int pivotIndex = partition(nums, current.start, current.end);

            if (pivotIndex - 1 > current.start) {
                s.push(new Range(current.start, pivotIndex - 1));
            }

            if (pivotIndex + 1 < current.end) {
                s.push(new Range(pivotIndex + 1, current.end));
            }
        }
    }

    private static int partition(int [] nums, int start, int end)
    {
        int pivot = nums[end];

        int pivotIndex = start;

        for (int index = start; index < end; index++)
        {
            if (nums[index] <= pivot) {
                int temp = nums[index];
                nums[index] = nums[pivotIndex];
                nums[pivotIndex] = temp;
                pivotIndex++;
            }
        }

        int temp = nums[pivotIndex];
        nums[pivotIndex] = nums[end];
        nums[end] = temp;

        return pivotIndex;
    }

  public void mergeSort(Stack<Integer> s, Stack<Integer> left, Stack<Integer> right) {
      // TODO
  }
  
}
