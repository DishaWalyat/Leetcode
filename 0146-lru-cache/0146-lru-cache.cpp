class LRUCache {
public:
    // Doubly Linked List Node Definition
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Dummy Head aur Tail pointers taaki boundary conditions ka jhanjhat na ho
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> m; // Key -> Node* Address

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Helper 1: Node ko Head ke just baad add karna (MRU)
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    // Helper 2: Node ko beech se pointer badal kar delete karna
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        // Agar key map me mil gayi
        if (m.find(key) != m.end()) {
            node* resnode = m[key];
            int res = resnode->val;
            
            // Kyunki isko abhi touch kiya, toh yeh Most Recent ban gaya!
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next; // Naya address map me update kiya
            
            return res;
        }
        return -1; // Not found
    }

    void put(int key, int value) {
        // Case 1: Agar key pehle se hai, toh purani wali ko hatao
        if (m.find(key) != m.end()) {
            node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }

        // Case 2: Agar cache full ho gayi hai, toh LRU (Tail->prev) ko delete karo
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        // Naya node banao aur use MRU (Head->next) par insert karo
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */