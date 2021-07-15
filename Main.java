import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static LinkedList<LinkedList<Integer> > parent;
    public static boolean[] isChecked;
    public static Stack<Integer> st;

    public static void main(String...args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt(); m = sc.nextInt();
        parent = new LinkedList<>();

        for(int i = 0; i < n+1; i++) {
            parent.add(new LinkedList<>());
        }

        for(int i = 0; i < m; i++) {
            int a, b;
            a = sc.nextInt(); b = sc.nextInt();
            parent.get(b).add(a);
        }

        for(int i = 0; i < n+1; i++) {
            Collections.sort(parent.get(i));
        }

        ArrayList<Integer> res = new ArrayList<>();
        isChecked = new boolean[n+1];

        for(int i = 1; i <= n; i++) {
            st = new Stack<>();

            st.add(i);
            search(st, i);

            while(!st.isEmpty()) {
                int val = st.pop();
                if(!isChecked[val]) {
                    isChecked[val] = true;
                    res.add(val);
                }
            }
        }

        for(int q : res) {
            System.out.print(q + " ");
        }

        System.out.println();
    }

    public static void search(Stack<Integer> st, int start) {
    
        st.add(start);

        for(int i = 0; i < parent.get(start).size(); i++) {
            if(!isChecked[parent.get(start).get(i)]) {
                isChecked[parent.get(start).get(i)] = true;
                search(st, parent.get(start).get(i));
                isChecked[parent.get(start).get(i)] = false;
            }
        }

        return ;
    }
    
}
