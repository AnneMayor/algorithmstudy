import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class LeetCode_WordLadder1 {
    class Word {
        String text;
        int depth;

        public Word(String text, int depth) {
            this.text = text;
            this.depth = depth;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        
        Set<String> seen = new HashSet<>(wordList), visited = new HashSet<>();

        Queue<Word> q = new LinkedList<>();
        q.add(new Word(beginWord, 1));
        seen.add(beginWord);

        while(!q.isEmpty()) {
            Word currentWord = q.poll();

            if(currentWord.text.equals(endWord)) return currentWord.depth;
            seen.add(currentWord.text);

            // 와...이렇게 해야 시간초과 안난다...ㅎㄷ
            for (int j = 0; j < currentWord.text.length(); j++) {
                char[] ch = currentWord.text.toCharArray();
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == currentWord.text.charAt(j)) continue;
                    ch[j] = c;
                    String nb = String.valueOf(ch);
                    if (seen.contains(nb) && visited.add(nb)) q.offer(new Word(nb, currentWord.depth + 1));
                }
            }
        }

        return 0;
    }
}
