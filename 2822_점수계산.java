import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main_2822 {

    static class Question {
        int score, num;
        public Question(int score, int num) {
            this.score = score;
            this.num = num;
        }
    }

    public static Comparator<Question> comp = new Comparator<Main_2822.Question>(){

        @Override
        public int compare(Main_2822.Question o1, Main_2822.Question o2) {
            if(o1.score < o2.score) return 1;
            else if(o1.score > o2.score) return -1;
            return 0;
        }
        
    };

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Question> pq = new PriorityQueue<>(comp);
        ArrayList<Integer> questions = new ArrayList<>();

        for(int i = 0; i < 8; i++) {
            int score = Integer.parseInt(br.readLine());
            if(score == 0) continue;
            Question q =  new Question(score, i+1);
            pq.add(q);
        }

        int ans = 0;
        for(int i = 0; i < 5; i++) {
            if(pq.isEmpty()) break;
            Question q = pq.poll();
            // System.out.println(q.score);
            ans += q.score;
            questions.add(q.num);
        }

        Collections.sort(questions);
        System.out.println(ans);
        for(int i = 0; i < questions.size(); i++) {
            System.out.print(questions.get(i) + " ");
        }
        System.out.println();
    
        br.close();
    }
    
}
