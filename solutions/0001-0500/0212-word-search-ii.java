class Solution {
    public class TrieNode {
             Map<Character, TrieNode> charToNode;
             boolean isEnd = false;
             public TrieNode() {
                charToNode = new HashMap<>();
            }
         }

    public class Trie {
            TrieNode root;
            public Trie() {
                root = new TrieNode();
            }
            public void insert(String word) {
                TrieNode node = root;
                for (int i=0; i<word.length(); i++) {
                    char ch = word.charAt(i);
                    if (!node.charToNode.containsKey(ch)) {
                        node.charToNode.put(ch, new TrieNode());
                    }
                    node = node.charToNode.get(ch);
                }
                node.isEnd = true;
            }
        
         }
        public List<String> findWords(char[][] board, String[] words) {
         Trie trie = new Trie();
         for (String st: words) {
             trie.insert(st);
         }
         List<String> res = new ArrayList<>();
         TrieNode node = trie.root;
         for (int i = 0; i < board.length; i++) {
             for (int j = 0; j < board[0].length; j++) {
                 dfsTrie(board, node, i, j, new ArrayList<>(), res);
             }
         }
         return res;
    }
    public void dfsTrie(char[][] board, TrieNode node, int i, int j, List<String> path, List<String> res) {
         if (board[i][j] == '?' || !node.charToNode.containsKey(board[i][j])) return;
         char curr = board[i][j];
         TrieNode prev = node;
         node = node.charToNode.get(curr);
         path.add(String.valueOf(curr));
         if (node.isEnd) {
             String str = String.join("", path);
             res.add(str);
             node.isEnd = false;
         }
         board[i][j] = '?';
         if (i < board.length - 1) dfsTrie(board, node, i + 1, j, path, res);
         if (i > 0) dfsTrie(board, node, i - 1, j, path, res);
         if (j < board[0].length - 1) dfsTrie(board, node, i, j + 1, path, res);
         if (j > 0) dfsTrie(board, node, i, j - 1, path, res);
         node = prev;
         path.remove(path.size() - 1);
         board[i][j] = curr;
    }
}
