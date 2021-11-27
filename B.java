import java.util.ArrayList;
import java.util.Collections;

public class B {
    public static int solution(int[] arr) {
        int answer = 0;
        ArrayList<Integer> aPoints = new ArrayList<>();
        ArrayList<Integer> dPoints = new ArrayList<>();

        int len = arr.length;
        boolean [] checked = new boolean[len];
        for(int i = 1; i < len-1; i++) {
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
                checked[i] = true;
                aPoints.add(i);
            }
        }

        int curPoint = len-1;
        for(int i = len-1; i > 0; i--) {
            if(checked[i]) {
                dPoints.add(curPoint);
                curPoint = i;
            }
            if(arr[i-1] <= arr[i]) curPoint = i-1;
        }

        answer += aPoints.size();

        dPoints.add(0);
        Collections.sort(dPoints);

        // for(int num : aPoints) {
        //     System.out.println("num: " + arr[num]);
        // }

        int curDIdx = 0;
        for(int i = 0; i < aPoints.size(); i++) {
            int front = aPoints.get(i) - dPoints.get(curDIdx++) - 1;
            int back = dPoints.get(curDIdx) - aPoints.get(i) - 1;
            if(front > 0 && back > 0) answer++;
            System.out.println("front: " + front + ", back: " + back);
            System.out.println("answer: " +answer);
            answer += front + back;
        }

        // for(int num : dPoints) {
        //     System.out.println(num);
        // }

        return answer;
    }

    public static void main(String...args) {
        int [] arr1 = {1, 2, 3, 2, 1, 4, 3, 2, 2, 1};
        System.out.println(solution(arr1));
        int [] arr2 = {0, 1, 2, 5, 3, 7};
        System.out.println(solution(arr2));
        int [] arr3 = {1, 2, 3, 2, 1};
        System.out.println(solution(arr3));
        int [] arr4 = {1,2,3,4, 3,2,1};
        System.out.println(solution(arr4));
    }
}
