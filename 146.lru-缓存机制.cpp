/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include "headers.h"
// @lc code=start

struct node {
    int val, key;
    node* pre = nullptr;
    node* next = nullptr;
    node(int k, int v) {
        val = v;
        key = k;
    }
};

class LinkedList {
   private:
    node *head = nullptr, *tail = nullptr;

   public:
    LinkedList() {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    void push_front(node* p) {
        p->next = head->next;
        head->next->pre = p;
        head->next = p;
        p->pre = head;
    }
    void move_to_begin(node* p) {
        // auto next = p->next, pre = p->pre;
        p->next->pre = p->pre;
        p->pre->next = p->next;

        p->next = head->next;
        head->next->pre = p;
        head->next = p;
        p->pre = head;
    }
    int remove_end() {
        auto p = tail->pre;
        p->pre->next = tail;
        tail->pre = p->pre;
        int key = p->key;
        p->next = nullptr, p->pre = nullptr;
        delete p;
        return key;
    }
};

class LRUCache {
   private:
    LinkedList _cachelist;
    unordered_map<int, node*> _cache;
    int _capacity;

   public:
    LRUCache(int capacity) { _capacity = capacity; }

    int get(int key) {
        if (_cache.find(key) != _cache.end()) {
            _cachelist.move_to_begin(_cache[key]);
            return _cache[key]->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (_cache.find(key) != _cache.end()) {
            _cache[key]->val = value;
            _cachelist.move_to_begin(_cache[key]);
        } else {
            if (_cache.size() >= _capacity) {
                int key = _cachelist.remove_end();
                _cache.erase(key);
            }
            auto p = new node(key, value);
            _cachelist.push_front(p);
            _cache[key] = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
