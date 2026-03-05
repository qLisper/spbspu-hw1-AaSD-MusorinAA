template< class T >
struct BiList
{
  T val;
  BiList<T>* next;
  BiList<T>* prev;
};

template< class T >
BiList<T>* add(BiList<T>* h, const T& v)
{
  //T Должен поддерживать копирование
  BiList<T>* node = new BiList<T>{ v, h, nullptr };
  if (h)
  {
    h->prev = node;
  }
  return node;
}

template< class T >
BiList<T>* insert(BiList<T>* h, const T& v)
{
  BiList<T>* node = add(h->next, v);
  node->prev = h;
  if (h->next)
  {
    h->next->prev = node;
  }
  h->next = node;
  return node;
}

template< class T >
BiList<T>* addBack(BiList<T>*& head, BiList<T>* tail, const T& v)
{
  if (!tail)
  {
    head = add(head, v);
    return head;
  }
  return insert(tail, v);
}

template< class T >
BiList<T>* cut(BiList<T>* h) noexcept
{
  BiList<T>* ret = h->next;
  delete h;
  if (ret)
  {
    ret->prev = nullptr;
  }
  return ret;
}

template< class T >
BiList<T>* erase(BiList<T>* h) noexcept
{
  BiList<T>* deleted = h->next;
  h->next = cut(deleted);
  if (h->next)
  {
    h->next->prev = h;
  }
  return h->next;
}

template< class T >
BiList<T>* cutBack(BiList<T>* tail) noexcept
{
  BiList<T>* ret = tail->prev;
  delete tail;
  if (ret)
  {
    ret->next = nullptr;
  }
  return ret;
}

template< class T >
BiList<T>* eraseBefore(BiList<T>* h) noexcept
{
  if (!h || !(h->prev))
  {
    return nullptr;
  }
  BiList<T>* deleted = h->prev;
  h->prev = cutBack(deleted);
  if (h->prev)
  {
    h->prev->next = h;
  }
  return h->prev;
}

template< class T >
BiList<T>* clear(BiList<T>* h, BiList<T>* e) noexcept
{
  // T должен поддерживать деструктор
  while (h != e)
  {
    h = cut(h);
  }
  if (e)
  {
    e->prev = nullptr;
  }
  return h;
}

template< class T, class F >
F traverse(F f, BiList<T>* h, BiList<T>* e)
{
  for (h; h != e; h = h->next)
  {
    f(h->val);
  }
  return f;
}

template< class T, class F >
F traverseBack(F f, BiList<T>* h, BiList<T>* e)
{
  for (h; h != e; h = h->prev)
  {
    f(h->val);
  }
  return f;
}
