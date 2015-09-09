/*
 * tag
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. 
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */
class LRUCache{
  public:
    struct CacheEntry {
      public:
	int key;
	int value;
	CacheEntry(int k, int v) :key(k), value(v) {}
    };

    LRUCache(int capacity) {
      m_capacity = capacity;
    }

    int get(int key) {
      if(m_map.find(key) == m_map.end()) {
	return -1;
      }
      moveToHead(key);
      return m_map[key]->value;
    }

    void set(int key, int value) {
      if(m_map.find(key) == m_map.end()) {
	CacheEntry newItem(key, value);
	if(m_LRU_cache.size() >= m_capacity) {
	  m_map.erase(m_LRU_cache.back().key);
	  m_LRU_cache.pop_back();
	}
	m_LRU_cache.push_front(newItem);
	m_map[key] = m_LRU_cache.begin();
	return;
      }
      m_map[key]->value = value;
      moveToHead(key);
    }

  private:
    unordered_map<int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    int m_capacity;

    void moveToHead(int key) {
      auto updateEntry = *m_map[key];
      m_LRU_cache.erase(m_map[key]);
      m_LRU_cache.push_front(updateEntry);
      m_map[key] = m_LRU_cache.begin();
    }
};
