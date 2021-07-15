import java.nio.channels.NotYetBoundException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main_2210 {

    public static Set<String> group;
    public static int[][] map;

    final static int[] dx = {-1, 1, 0, 0};
    final static int[] dy = {0, 0, -1, 1};

    static class Point {
        int x;
        int y;
        int cnt;
        String nums;

        public Point(int x, int y, int cnt, String nums) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.nums = nums;
        }
    }

    public static void main(String...args) {

        Scanner sc = new Scanner(System.in);
        map = new int[6][6];

        group = new HashSet<>();

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                StringBuilder sb = new StringBuilder();
                sb.append(map[i][j]+"");
                search(sb, i, j, 1);
            }
        }

        System.out.println(group.size());
    }

    public static void search(StringBuilder nums, int x, int y, int cnt) {
        if(cnt >= 6) {
            group.add(nums.toString());
            return ;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

            nums.append(map[nx][ny]+"");
            search(nums, nx, ny, cnt+1);
            nums.deleteCharAt(cnt);
        }

    }
    
}
