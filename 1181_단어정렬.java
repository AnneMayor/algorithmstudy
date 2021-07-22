import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;

public class Main_1181 {

    public static Comparator<String> comp = new Comparator<String>(){

        @Override
        public int compare(String o1, String o2) {
            if(o1.length() == o2.length()) return o1.compareTo(o2);
            else return o1.length() - o2.length();
        }
        
    };

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<String> words = new ArrayList<>();
        HashSet<String> duplicate = new HashSet<>();

        for(int i = 0; i < n; i++) {
            String word = br.readLine();
            if(duplicate.contains(word)) continue;
            duplicate.add(word);
            words.add(word);
        }

        Collections.sort(words, comp);

        for(int i = 0; i < words.size(); i++) {
            System.out.println(words.get(i));
        }

        br.close();
    } 
}
