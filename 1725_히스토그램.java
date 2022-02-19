import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    static class Square {
        int width;
        int height;

        public Square(int width, int height) {
            this.width = width;
            this.height = height;
        }
    }
    
    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int [] heights = new int[n+1];

        for(int i = 0; i < n; i++) {
            heights[i] = Integer.parseInt(br.readLine());
        }

        Stack<Square> st = new Stack<>();
        long ans = 0;
        heights[n] = -1;
        for(int i = 0; i <= n; i++) {
            int currentIdx = i;
            while(!st.empty() && st.peek().height > heights[i]) {
                Square square = st.pop();
                ans = Math.max(ans, ((long) (i - square.width) * square.height));
                currentIdx = square.width;
            }
            st.add(new Square(currentIdx, heights[i]));
        }

        System.out.println(ans);
    }

    
}
