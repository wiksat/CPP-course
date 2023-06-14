//#ifndef MYLIST_H
#define MYLIST_H
#ifndef ZAD5MYLISTANDSORTING_MYLIST_H
#define ZAD5MYLISTANDSORTING_MYLIST_H
#define IMPLEMENTED_constructorOfEmptyList
#define IMPLEMENTED_pushingAndPopingElementsFront
#define IMPLEMENTED_nodesStoredAsUniquePtrs
#define IMPLEMENTED_popFromWhenEmptyList
#define IMPLEMENTED_copyingDisabled
#define IMPLEMENTED_removingElements
#define IMPLEMENTED_iteratorOperations
#define IMPLEMENTED_iteratorWithRangedForLoop
#define IMPLEMENTED_iteratorWithStlAlgorithm
#define IMPLEMENTED_ostreamOperator
template<class T>
class MyList {
protected:
    struct Node {
        T value;
        std::unique_ptr<Node> next_;
    };
    std::unique_ptr<MyList::Node> head_;
public:
    // Iterator class
    class Iterator : public std::iterator<std::forward_iterator_tag, int> {
    private:
        Node *point;
    public:
        explicit Iterator(Node *node) {
            point = node;
        };

        Iterator &operator=(Node *node) {
            this->point = node;
            return *this;
        }

        Iterator &operator++() {
            if (this->point != nullptr)
                this->point = this->point->next_.get();
            return *this;
        }
        Iterator operator++(int) {
            Iterator iterator = *this;
            ++(*this);
            return iterator;
        }


        friend bool operator!=(Iterator iterator1, Iterator iterator2) {
            return iterator1.point != iterator2.point;
        }

        friend bool operator==(Iterator iterator1, Iterator iterator2) {
            return iterator1.point == iterator2.point;
        }

        T &operator*() {
            return this->point->value;
        }

        T *operator->() {
            return &this->point->value;
        }
    };

    using value_type = T;

    Iterator begin() const { return Iterator(head_.get()); }

    Iterator end() const { return Iterator(nullptr); }

    // constructor and size
    MyList() : head_{} {};

    [[nodiscard]] int size() const;

    // push_front and pop_front
    void push_front(T);

    T pop_front();

    // front
    T front() const { return head_->value; }

    // remove
    void remove(T);

    MyList(MyList<T> &array) = delete;

    MyList<T> operator=(MyList<T> &array) = delete;

    // ostream
    friend std::ostream &operator<<(std::ostream &os, const MyList<T> &array) {
        for (auto val: array) {
            os << val << " ";
        }
        return os;
    }
};

template<class T>
int MyList<T>::size() const {
    int count = 0;
    for ([[maybe_unused]] const auto& elem : *this)
        count++;
    return count;
}

template<class T>
void MyList<T>::push_front(T value_to_push) {
    std::unique_ptr<MyList::Node> new_head;
    new_head = std::make_unique<Node>();
    new_head->value = value_to_push;
    new_head->next_ = std::move(head_);
    head_ = std::move(new_head);
}

template<class T>
T MyList<T>::pop_front() {
    if (head_ == nullptr)
        throw std::out_of_range("List is empty.");
    T value;
    value = head_->value;
    head_ = std::move(head_->next_);
    return value;
}

template<typename T>
void MyList<T>::remove(const T element) {
    if (head_ == nullptr)
        return;
    std::unique_ptr<Node> *node1, *node2;
    node1 = &(head_->next_);
    node2 = &head_;
    while (*node1 != nullptr) {
        if ((*node1)->value == element) {
            (*node2)->next_ = std::move((*node1)->next_);
            node1 = node2;
        }
        node2 = node1;
        node1 = &((*node1)->next_);
    }
    if (head_->value == element) {
        std::unique_ptr<Node> new_head;
        new_head = std::move(head_->next_);
        head_ = std::move(new_head);
    }
}

#endif // MYLIST_H