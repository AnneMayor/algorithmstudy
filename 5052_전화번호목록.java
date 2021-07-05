import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class 5052_전화번호목록 {

//     static final int DIGIT = 10;
//     static TrieNode root;

//     static class TrieNode {
//         boolean isLastWord;
//         TrieNode[] childNode;

//         public TrieNode() {
//             isLastWord = false;
//             childNode = new TrieNode[DIGIT];
//             for(int i = 0; i < DIGIT; i++) {
//                 childNode[i] = null;
//             }
//         }
//     }

//     static void trie_push(String st) {
//         TrieNode curTrie = root;
//         int length = st.length();

//         for(int i = 0; i < length; i++) {
//             int idx = st.charAt(i)-'0';
//             if(curTrie.childNode[idx] == null) {
//                 curTrie.childNode[idx] = new TrieNode();
//             }
//             curTrie = curTrie.childNode[idx];
//         }

//         curTrie.isLastWord = true;
//     }

//     static boolean trie_search(String st) {
//         TrieNode curTrie = root;
//         int length = st.length();

//         for(int i = 0; i < length; i++) {
//             int idx = st.charAt(i) - '0';
//             if(curTrie.isLastWord) return false;
//             curTrie = curTrie.childNode[idx];
//         }

//         return true;
//     }

//     public static void main(String...args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringBuilder sb = new StringBuilder();
//         int T = Integer.parseInt(br.readLine());

//         for(int tc = 1; tc <= T; tc++) {

//             int n = Integer.parseInt(br.readLine());
//             root = new TrieNode();

//             String[] numbers = new String[n+1];
//             for(int i = 0; i < n; i++) {
//                 numbers[i] = br.readLine();
//                 trie_push(numbers[i]);
//             }

//             boolean isNotFound = true;

//             for(int i = 0; i < n; i++) {
//                 if(!trie_search(numbers[i])) {
//                     isNotFound = false;
//                     break;
//                 }
//             }

//             if(isNotFound) sb.append("YES\n");
//             else sb.append("NO\n");
//         }
//         System.out.println(sb.toString());
//     }

    public static void main(String...args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++) {
            int n = Integer.parseInt(br.readLine());
            PriorityQueue<String> pq = new PriorityQueue<>();
            for(int i = 0; i < n; i++) {
                String name = br.readLine();
                pq.offer(name);
            }

            String prefix = pq.poll();
            boolean isFound = false;
            while(!pq.isEmpty()) {
                String rep = pq.poll();
                if(prefix.length() <= rep.length()) {
                    if(rep.startsWith(prefix)) {
                        bw.write("NO\n");
                        isFound = true;
                        break;
                    }
                }
                prefix = rep;
            }
            if(!isFound) bw.write("YES\n");
        }
        bw.close();
    }
}