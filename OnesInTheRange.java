public class OnesInTheRange {

    // Facebook Problem
    int[] arr;
	public OnesInTheRange(int[] arr) {
        this.arr = arr;
	}

    public int numOfOnes(int s, int e) {
        int res = 0;

        // abnormal case: out of array range
        if(e >= arr.length) return -1;

        while(s <= e) {
            res += arr[s];
            s++;
        }

        return res;
    }

    public static void main(String... args) {
        int[] test1 = {0, 0, 1, 0, 1};
        int[] test2 = {0, 1, 1, 0, 0, 1, 1, 1};
        int[] test3 = {0, 1, 1, 0, 0, 1, 1, 1};

        OnesInTheRange onesInTheRange1 = new OnesInTheRange(test1);
        OnesInTheRange onesInTheRange2 = new OnesInTheRange(test2);
        OnesInTheRange onesInTheRange3 = new OnesInTheRange(test3);

        System.out.println(onesInTheRange1.numOfOnes(2, 4));
        System.out.println(onesInTheRange2.numOfOnes(2, 6));
        System.out.println(onesInTheRange3.numOfOnes(1, 7));

    }

}
