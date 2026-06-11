class LFUCache {
public:
    // Doubly Linked List Node Definition
    class Node {
    public:
        int key, val, freq;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            freq = 1; // Shuruat me har naye node ki frequency 1 hoti hai
        }
    };

    // Har frequency ke liye ek alag Doubly Linked List ka structure
    class List {
    public:
        int size;
        Node* head;
        Node* tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
            size++;
        }

        void removeNode(Node* node) {
            Node* delprev = node->prev;
            Node* delnext = node->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }
    };

    unordered_map<int, Node*> keyNodeMap;
    unordered_map<int, List*> freqListMap;
    int maxCacheSize;
    int minFreq;
    int curSize;

    LFUCache(int capacity) {
        maxCacheSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    // Node ki frequency badhane aur list shift karne ka helper function
    void updateFreqListMap(Node* node) {
        keyNodeMap.erase(node->key);
        freqListMap[node->freq]->removeNode(node);
        
        // Agar minFreq wali list khali ho gayi, toh minFreq ko aage badhao
        if (node->freq == minFreq && freqListMap[node->freq]->size == 0) {
            minFreq++;
        }
        
        node->freq++;
        // Agar naye frequency ki list pehle se nahi bani, toh banao
        if (freqListMap.find(node->freq) == freqListMap.end()) {
            freqListMap[node->freq] = new List();
        }
        
        freqListMap[node->freq]->addFront(node);
        keyNodeMap[node->key] = node;
    }

    int get(int key) {
        if (keyNodeMap.find(key) == keyNodeMap.end()) return -1;
        
        Node* node = keyNodeMap[key];
        int res = node->val;
        updateFreqListMap(node); // Frequency badhao aur aage shift karo
        return res;
    }

    void put(int key, int value) {
        if (maxCacheSize == 0) return;

        // Case 1: Agar key pehle se hai, toh value badlo aur freq update karo
        if (keyNodeMap.find(key) != keyNodeMap.end()) {
            Node* node = keyNodeMap[key];
            node->val = value;
            updateFreqListMap(node);
        } 
        // Case 2: Nayi key aayi hai
        else {
            // Cache full hai, toh eviction karo (LFU + LRU)
            if (curSize == maxCacheSize) {
                List* list = freqListMap[minFreq];
                keyNodeMap.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }
            
            curSize++;
            // Naya node hamesha freq 1 me jayega, toh minFreq = 1 ho gaya
            minFreq = 1;
            if (freqListMap.find(minFreq) == freqListMap.end()) {
                freqListMap[minFreq] = new List();
            }
            
            Node* node = new Node(key, value);
            freqListMap[minFreq]->addFront(node);
            keyNodeMap[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */