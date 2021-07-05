import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import javax.swing.GroupLayout;

public class Main {
    // public static void main(String...args) {

    //     SortedSet<String> group = new TreeSet<>();

    //     Scanner sc = new Scanner(System.in);
    //     int T = sc.nextInt();
    //     sc.nextLine();
    //     for(int tc = 0; tc < T; tc++) {
    //         String employee = sc.nextLine();
    //         String[] status = employee.split(" ");
    //         if(status[1].equals("leave")) {
    //             if(group.contains(status[0])) {
    //                 group.remove(status[0]);
    //             }
    //         } else {
    //             group.add(status[0]);
    //         }
    //     }

    //     List<String> ans = new ArrayList<>(group);
    //     int n = ans.size();
    //     for(int i = n-1; i >= 0; i--) {
    //         System.out.println(ans.get(i));
    //     } 
    // }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        Set<String> group = new TreeSet<>();

        StringTokenizer st;
        for(int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String status = st.nextToken();

            if(status.equals("enter")) {
                group.add(name);
            } else {
                if(group.contains(name)) {
                    group.remove(name);
                }
            }
        }

        List<String> ans = new ArrayList<>(group);

        Collections.reverse(ans);

        StringBuilder sb = new StringBuilder();
        for(String emp : ans) {
            sb.append(emp).append("\n");
        }

        System.out.println(sb);
    }
}