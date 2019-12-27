#include "utils.hpp"

namespace list {
    template<typename T>
    List<T>* cons(T hd, List<T>* tail) {
        return new list(hd, tail);
    }
}
