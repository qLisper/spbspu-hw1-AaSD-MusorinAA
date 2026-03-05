template< class T >
struct BiList {
  T val;
  BiList<T> * next;
  BiList<T> * prev;
};
template< class T >
BiList<T> * add(BiList<T> * h, const T & d);

template< class T >
BiList<T> * insert(BiList<T> * h, const T & d);

template< class T >
BiList<T> * addBack(BiList<T> * & head, BiList<T> * tail, const T & d);

template< class T >
BiList<T> * cut(BiList<T> * h) noexcept;

template< class T >
BiList<T> * erase(BiList<T> * h) noexcept;

template< class T >
BiList<T> * eraseBefore(BiList<T> * h) noexcept;

template< class T >
BiList<T> * cutBack(BiList<T> * tail) noexcept;

template< class T >
BiList<T> * clear(BiList<T> * h, BiList<T> * e) noexcept;

template< class T, class F >
F traverse(F f, BiList<T> * h, BiList<T> * e);

template< class T, class F >
F traverseBack(F f, BiList<T> * h, BiList<T> * e);
