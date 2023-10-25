class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = NULL;
            next  = NULL;
        }
    };
    int capacity;
    unordered_map<int, Node*> m;
    Node* head, *tail;
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        Node* k = head;
        if(m.find(key) == m.end())
        {
            return -1;
        }
        Node* temp = m[key];
        int x = temp->val;

        // changing existing pointers

        temp->prev-> next = temp->next;
        temp-> next->prev = temp-> prev;

        // linking pointers to head

        temp-> next = head->next;
        head->next->prev = temp;
        temp->prev = head;
        head->next = temp;

        //change value in map

        m[key] = temp;
        return x;
    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end())
        {
            if(m.size() < capacity)
            {
                Node* temp = new Node(key, value);
                m[key] = temp;

                // changing existing pointers

                temp-> next = head->next;
                head->next->prev = temp;

                // linking pointers to head

                temp->prev = head;
                head->next = temp;
            }
            else
            {
                // deleting lru node
                Node* d = tail -> prev;
                m.erase(d->key);
                tail->prev = d-> prev;
                d->prev -> next = tail;
                delete(d);
                Node* temp = new Node(key, value);
                m[key] = temp;

                // changing existing pointers

                temp-> next = head->next;
                head->next->prev = temp;

                // linking pointers to head

                temp->prev = head;
                head->next = temp;
            }
        }
        else
        {
            Node* temp = m[key];
            temp->prev-> next = temp->next;
            temp-> next->prev = temp-> prev;
            temp->val = value;
            temp-> next = head->next;
            head->next->prev = temp;
            temp->prev = head;
            head->next = temp;
            m[key] = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */