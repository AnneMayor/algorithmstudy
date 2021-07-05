import java.util.*;

public class 9086_문자열 {
    public static void main(String... args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for(int tc = 0; tc < T; tc++) {
            String st = sc.next();
            char first = st.charAt(0);
            char last = st.charAt(st.length()-1);
            System.out.println(first+""+last);
        }
        
        
    }
}