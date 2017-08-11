#include <bits/stdc++.h>
using namespace std;

// implementation using doubly linked list and unordered_map
class LRUCache {
  public:
    // doubly linked list
    struct dll {
        int key;
        dll *left, *right;

        // constructor
        dll(int k, dll *prev, dll *next) {
            key = k;
            left = prev;
            right = next;
        }
    };

    // member function declarations:
    // constructor
    LRUCache(int cap);

    int get(int key);
    void set(int key, int value);

  private:
    dll *head, *tail;
    int capacity;
    unordered_map<int, dll*> q_map;
    unordered_map<int, int> cache;
};

int main() {
    int sz, noq, qt, a, b;
    cin >> sz >> noq; // sz = maximum cache capacity and noq = number of queries
    LRUCache obj(sz);
    while (noq--) {
        cin >> qt;
        if (qt == 1) { // get(val)
            cin >> a;
            cout << obj.get(a) << endl;
        } else { // set(key,val)
            cin >> a >> b;
            obj.set(a, b);
        }
    }
}

// writing member functions
LRUCache::LRUCache(int cap) {
    head = tail = NULL;
    capacity = cap;
    q_map.clear();
    cache.clear();
}

int LRUCache::get(int key) {
    // if key not found, return -1
    if (cache.find(key) == cache.end()) { return -1; }

    // if key found and size == 1, just return it without rearranging the map
    if (cache.size() == 1) { return cache[key]; }

    dll *node = q_map[key], *prev = node->left, *next = node->right;

    // if present at the head, no need to rearrange
    if (node == head) { return cache[key]; }

    // for other cases where kay is somewhere else in the map
    if (node == tail) { tail = node->left; }
    if (prev) { prev->right = next; }
    if (next) { next->left = prev; }

    node->left = NULL;
    node->right = head;
    head->left = node;
    head = node;

    return cache[key];
}

void LRUCache::set(int key, int value) {
    // if the key is present somewhere in the cache
    if (cache.find(key) != cache.end()) {
        cache[key] = value;
        dll *node = q_map[key], *prev = node->left, *next = node->right;

        // value present in the beginning, so no need to update anything
        if (node == head) { return; }

        if (node == tail) { tail = node->left; }
        if (prev) { prev->right = next; }
        if (next) { next->left = prev; }

        node->left = NULL;
        node->right = head;
        head->left = node;
        head = node;
        return;
    }

    // value not present, so can be inserted since cache isn't full
    if (cache.size() < capacity) {
        cache[key] = value;
        dll *node = new dll(key, NULL, head);

        // if cache is initially empty
        if (!tail) { tail = node; }
        else { head->left = node; }

        head = node;
        q_map[key] = node;
        return;
    }

    // now, we consider the case when the cache is full and there is a page fault
    int key_del = tail->key;
    if (head == tail) { // when there is only 1 element in the cache
        delete tail;
        head = tail = NULL;
    } else {
        tail = tail->left;
        delete tail->right;
        tail->right = NULL;
    }

    q_map.erase(key_del);
    cache.erase(key_del);
    cache[key] = value;
    dll *node = new dll(key, NULL, head);

    // when the cache is empty
    if (!tail) {
        tail = node;
    } else {
        head->left = node;
    }
    head = node;
    q_map[key] = node;
}