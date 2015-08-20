/*
 * Implement a trie with insert, search, and startsWith methods.
 */
class TrieNode {
  public:
    // Initialize your data structure here.
    bool isChar;
    TrieNode* child[26];
    TrieNode() {
      for(int i = 0; i < 26; i++) {
	child[i] = NULL;
	isChar = false;
      } 
    }
};

class Trie {
  public:
    Trie() {
      root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
      TrieNode* node = root;
      for(int i = 0; i < word.size(); i++) {
	if(node->child[word[i] - 'a'] == NULL){
	  TrieNode* temp = new TrieNode();
	  node->child[word[i] - 'a'] = temp;
	} 
	node = node->child[word[i] - 'a'];
      }
      node->isChar = true; // only mark the node for the last char
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      TrieNode* node = root;
      for(int i = 0; i < word.size(); i++) {
	if(node->child[word[i] - 'a'] == NULL) return false;
	node = node->child[word[i] - 'a'];
      }
      return node->isChar;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
      TrieNode* node = root;
      for(int i = 0; i < prefix.size(); i++) {
	if(node == NULL) return false;
	if(node->child[prefix[i] - 'a'] == NULL) return false;
	node = node->child[prefix[i] - 'a'];
      }
      return true;
    }

  private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
