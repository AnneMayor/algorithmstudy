public class WordDictionary {

    static class TrieNode {
        private final TrieNode[] trieNodes = new TrieNode[26];

        private boolean isEnd;

        public boolean containsKey(char value) {
            return trieNodes[value - 'a'] != null;
        }

        public void put(char value, TrieNode newNode) {
            trieNodes[value - 'a'] = newNode;
        }

        public TrieNode getNode(char value) {
            return trieNodes[value - 'a'];
        }

        public void setEnd() {
            isEnd = true;
        }

        public boolean getEnd() {
            return isEnd;
        }
    }

    private TrieNode root;

    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        int wLen = word.length();
        TrieNode node = root;

        for(int i = 0; i < wLen; i++) {
            char wChar = word.charAt(i);
            if(wChar == '.') continue;
            if(!node.containsKey(wChar)) {
                node.put(wChar, new TrieNode());
            }

            node = node.getNode(wChar);
        }

        node.setEnd();
    }
    
    public boolean wordSearch(String word,TrieNode node,int index)
    {
        char[]chars=word.toCharArray();
        int i=index;
        if(node==null)
            return false;
        for(;i<chars.length;i++)
        {
            if(chars[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    char current = (char) ('a' + j);
                    if(node.getNode(current)!=null)
                        if(wordSearch(word,node.getNode(current),i+1))
                            return true;
                }
                        return false;
            }
            else
            {
                if(node==null || node.getNode(chars[i])==null)
                    return false;
                node=node.getNode(chars[i]);
            }
                
        }
        if(node!=null && node.isEnd==true)
            return true;
        else
            return false;
    }
    public boolean search(String word) {
        return wordSearch(word,root,0);
    }
}
