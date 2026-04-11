class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> nodes_map;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;    
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void addInFront(Node* node) {
        node->next = head->next;
        node->next->prev = node;

        node->prev = head;
        head->next = node;
    }
    
    int get(int key) {
        if(nodes_map.find(key) == nodes_map.end()) return -1;
        removeNode(nodes_map[key]);
        addInFront(nodes_map[key]);
        return nodes_map[key]->val;
    }
    
    void put(int key, int value) {
        if(nodes_map.find(key) != nodes_map.end()) {
            Node* node = nodes_map[key];
            removeNode(node);
            node->val = value;
        } else {
            if(cap == nodes_map.size()) {
                Node* lru_node = tail->prev;
                removeNode(lru_node);
                nodes_map.erase(lru_node->key);
                delete lru_node;
            }
            nodes_map[key] = new Node(key, value);
        }
        addInFront(nodes_map[key]);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
