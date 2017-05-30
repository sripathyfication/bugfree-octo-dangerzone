#/usr/bin/python

# A basic python based trie class implementation
# see trie_notes
lookup=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] 

class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_leaf = False

    def set_is_leaf(self, is_leaf):
        self.is_leaf = is_leaf

    def is_leaf(self):
        return self.is_leaf

    def get_node(self, index):
        if index in range(0,25):
            return self.children[index]        
        else:    
            print "Invalid index"
            return None

class Trie:
    def __init__(self):
        self.head = TrieNode()
        self.head.set_is_leaf(False)

    def get_head(self):
        return self.head    

    def char_to_index(self,c):
        return lookup.index(c) 

    def insert(self, word):
        level = len(word)
        node = self.get_head()
        for c in word:
            level = self.char_to_index(c)
            print c
            if node.children[level] is None:
                node.children[level] = TrieNode() 
            node = node.children[level]
        node.set_is_leaf(True)          
             
    def search(self, word):    
        print "searching .." + word
        level = len(word)
        node = self.get_head()
        for c in word:
            level = self.char_to_index(c)
            if node.children[level] is None:
                return False
            node = node.children[level]
        return (node is not None and node.is_leaf)

    def print_trie(self):
# parse through trie starting at head and printing all children
        node = self.get_head()
        for level in range(0,26):
            if node is not None:
                if node.children[level] is not None:
                    if node.children[level].is_leaf is True:
                        print lookup[level].upper()
                    else:
                        print lookup[level]
                node = node.children[level]           
                  
if __name__ == '__main__':
    t = Trie()

    t.insert("sripathy")
    t.insert("shrikanth")
    print t.search("sripathy")
    print t.search("shrikathy")
    t.print_trie()
