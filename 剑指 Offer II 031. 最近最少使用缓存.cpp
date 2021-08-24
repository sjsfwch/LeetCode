#include "headers.h"

struct Node {
    int val, key;
    Node *next, *prev;
    Node(const int _key, const int _val) { key = _key, val = _val; }
};

class DoubleLinkedList {
   private:
    Node *head, *tail;

   public:
    DoubleLinkedList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void move_to_front(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insert_front(node);
    }
    int delete_tail() {
        auto node = tail->prev;
        if (node == head) return -1;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        int key = node->key;
        delete node;
        return key;
    }
    void insert_front(Node *node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
};

class LRUCache {
   private:
    int _capacity;
    unordered_map<int, Node *> _map;
    DoubleLinkedList _list;

   public:
    LRUCache(int capacity) { _capacity = capacity; }

    int get(int key) {
        if (_map.find(key) != _map.end()) {
            _list.move_to_front(_map[key]);
            return _map[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            _map[key]->val = value;
            _list.move_to_front(_map[key]);
            return;
        }
        if (_map.size() == _capacity) {
            int key = _list.delete_tail();
            _map.erase(key);
        }
        auto node = new Node(key, value);
        _list.insert_front(node);
        _map[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lru(2);
    cout << lru.get(2) << endl;
    // lru.put(1, 1);
    lru.put(2, 6);
    cout << lru.get(1) << endl;
    lru.put(1, 5);
    lru.put(1, 2);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;

    // cout << lru.get(3) << endl;
    // cout << lru.get(4) << endl;
    return 0;
}