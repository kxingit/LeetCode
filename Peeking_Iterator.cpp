/*
 * Given an Iterator class interface with methods: next() and hasNext(), design and implement a 
 * PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be 
 * returned by the next call to next().
 */
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data* data;
  public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};


class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
      // Initialize any member here.
      // **DO NOT** save a copy of nums and manipulate it directly.
      // You should only use the Iterator interface methods.
      peeked = false;
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
      if(!peeked) {
	value = Iterator::next();
	peeked = true;
      }
      return value;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
      bool temp = peeked;
      peeked = false;
      if(temp) return value;
      else return Iterator::next();
    }

    bool hasNext() const {
      if(peeked || Iterator::hasNext()) return true;
      else return false;
    }
  private:
    int value;
    bool peeked;
};
