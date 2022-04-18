import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class LeetCode_DelimiterWord {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String delimiter = br.readLine();
        String word = br.readLine();
        String [] delimiters = delimiter.split("");
        String [] words = word.split("");

        int delimiterLength = delimiter.length();
        int wordLength = word.length();

        int numOfTotalCase = (int) Math.pow(delimiters.length, words.length-1);

        if(delimiterLength <= 0 || wordLength <= 0) numOfTotalCase = 0;

        System.out.println(numOfTotalCase);

        List<String> possibleCases = new ArrayList<>();
        List<String> temp = new ArrayList<>();

        dfsSearch(0, delimiters.length, words.length-1, delimiters, temp, possibleCases);

        for(String d : possibleCases) {
            int dLength = d.length();
            StringBuilder sb = new StringBuilder();
            if(wordLength > dLength) {
                for(int i = 0; i < dLength; i++) {
                    sb.append(words[i]);
                    sb.append(d.charAt(i));
                }

                for(int i = dLength; i < wordLength; i++) {
                    sb.append(words[i]);
                }
            }
            
            System.out.println(sb.toString());
        }
    }

    public static void dfsSearch(int count, int n, int wd, String[] delimiters, List<String> temp, List<String> possibleCases) {
        if(count >= wd) {
            StringBuilder sb = new StringBuilder();
            for(String d : temp) sb.append(d);
            possibleCases.add(sb.toString());
            return ;
        }

        for(int i = 0; i < n; i++) {
            temp.add(delimiters[i]);
            dfsSearch(count+1, n, wd, delimiters, temp, possibleCases);
            temp.remove(temp.size()-1);
        }
    }
}
