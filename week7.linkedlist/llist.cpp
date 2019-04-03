#include<iostream>



template<class T>
struct ListNode{
    T data;
    ListNode<T>* next;
    ListNode(const T& _data, ListNode<T>* _next = nullptr) : data(_data), next(_next) {}
};

template<class T>
class List {
    ListNode<T>* start;
    ListNode<T>* end;
    size_t length;
    void copy(const List<T>&);
    void destroy();
    public:
    List();
    List(const List<T>&);
    List<T>& operator=(const List<T>&);
    ~List();
    void print() const;
    size_t size() const;
    void toEnd(const T&);
    void toStart(const T&);
};

template<class T>
List<T>::List() : start(nullptr), end(nullptr), length(0) {}

template<class T>
List<T>::List(const List<T>& other) {
    copy(other);
}

template<class T>
void List<T>::copy(const List<T>& other) {
    ListNode<T>* tmp = other.start;
    start = end = nullptr;
    length = other.length;
    while(tmp){
        if(!start) {
            start = new ListNode<T>(tmp->data);
            end = start;
        } else {
            end->next = new ListNode<T>(tmp->data);
            end = end->next;
        }
        tmp=tmp->next;
    }
}

template<class T>
void List<T>::destroy() {
    while(start) {
        ListNode<T>* toDelete = start;
        start = start->next;
        delete toDelete;
    }
    start = end = nullptr;
    length = 0;
}

template<class T>
List<T>::~List() {
    destroy();
}


template<class T>
List<T>& List<T>::operator=(const List& other) {
    if(this != &other) {
        destroy();
        copy();
    }
    return *this;
}

template<class T>
void List<T>::print() const {
    ListNode<T>* current = start;
    while(current){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<class T>
size_t List<T>::size() const {
    return length;
}

template<class T>
void List<T>::toEnd(const T& elem) {
    if(start == nullptr) { // if(!start)
        start = new ListNode<T>(elem);
        end = start;
    } else {
        end->next = new ListNode<T>(elem);
        end = end->next;
    }
    length++;
}

template<class T>
void List<T>::toStart(const T& elem) {
    if(!start) {
        end = start = new ListNode<T>(elem);
    } else {
        start = new ListNode<T>(elem, start);
    }
    length++;
}

template<class T>
void List<T>::insertAfter(const T& elem, ListNode<T>* pos) {
    if (!pos) {
        return;
    }
    length++;
    if (pos->next) {
        //pos->next = new ListNode<T>(elem, pos->next);
        ListNode<T>* toAdd = new ListNode<T>(elem);
        toAdd->next = pos->next;
        pos->next = toAdd;
    } else {
        toEnd(elem);
    }
}

int main() {
    List<int> l;
    std::cout << l.size();
    List<int> l2;
    l2.toEnd(1);
    l2.toEnd(2);
    l2.print();
    List<int> l3(l2);
    l3.print();
}