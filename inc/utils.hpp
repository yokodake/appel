
template<typename T>
struct list {
    T head;
    list<T>* tail;

    list(T head, list<T>* tail) : head(head), tail(tail) {}
};

namespace list {
    List<T>* cons(T hd, List<T>* tail);
}
