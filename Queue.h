#ifndef MATAM_EX3_QUEUE_H
#define MATAM_EX3_QUEUE_H

typedef bool (*filterFunction)(int);

// TODO: Make it generic when finished testing
class Queue {
public:
    /**
     *  Constructor of Queue class.
     */
    Queue();
    
    /**
     *  Adds a new node with a value to the end of the queue.
     *
     *  @param value - the value to be inserted.
     */
    void pushBack(int value);
    
    /**
     *  Removes the first node of the queue.
     */
    void popFront();

    /**
     *  @return
     *      A reference to the first value in the queue.
     */
    int& front();

    const int& front() const;

    /**
     *  @return
     *      The size of the queue.
     */
    int size() const;


    
    class Iterator;
    
    Iterator begin() const;
    Iterator end() const;
    
    ~Queue();

    Queue(Queue& queue) = default;
    
    /**
     *  A class for InvalidOperation exception.
     *
     *  Thrown when an invalid operation is executed on an iterator that
     *  points to the end of the queue.
     */
    class InvalidOperation {};

    /**
    *  A class for EmptyQueue exception.
    *
    *  Thrown when an invalid operation is executed on an iterator that
    *  points to the end of the queue.
    */
    class EmptyQueue {};
    
private:
    class QNode {
    public:
        int m_data;
        QNode* m_next;
        
        /**
         *  Constructor of QNode class.
         *
         *  @param data - a reference to data
         */
        QNode(int& data);
        
        // TODO: default copy c'tor and operator=?
    };

    QNode* m_front;
    QNode* m_back;
    int m_size;
};

class Queue::Iterator {
public:
    // T
    /**
     *  Asterisk operator overloading.
     *
     *  @return
     *      The value the of the node the iterator currently points to.
     */
    const int& operator*() const;
    
    /**
     *  Righthand side increment operator overloading.
     *
     *  Changes the node the iterator points to, to the next one.
     *
     *  @return
     *      A reference to the Iterator (which now points to the next node).
     */
    Iterator& operator++();
    
    /**
     *  Lefthand side increment operator overloading.
     *
     *  Changes the node the iterator points to, to the next one.
     *
     *  @return
     *      A copy of the last pointed to Iterator
     */
    Iterator operator++(int);
    
    /**
     *  Not equal operator overloading.
     *
     *  Checks if two iterators not point to the same node.
     *
     *  @return
     *      True if iterators are not equal.
     */
    const bool operator!=(Iterator iterator);
    
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    
private:
    const Queue* queue;
    QNode* currentNode;
    
    Iterator(const Queue* queue, QNode* node);
    
    friend class Queue;
};


template<class TransformFunction>
void transform(Queue& queue, TransformFunction transform);

Queue::Queue():
    m_front(nullptr),
    m_back(nullptr),
    m_size(0)
{}

void Queue::pushBack(int value) {
    // TODO: Should we really allocate manually?
    Queue::QNode *newNode = new Queue::QNode(value);
    
    if(m_front == nullptr) {
        m_front = newNode;
    }
    
    if(m_back != nullptr) {
        m_back->m_next = newNode;
    }
    
    m_back = newNode;
    m_size++;
}

void Queue::popFront() {
    if(m_front == m_back) {
        m_back = nullptr;
    }
    
    m_front = m_front->m_next;
    
    delete m_front;
    m_size--;
}

int& Queue::front() {
    if(m_size == 0) {
        throw EmptyQueue();
    }
    return m_front->m_data;
}

const int& Queue::front() const {
    if(m_size == 0) {
        throw EmptyQueue();
    }

    return m_front->m_data;
}

Queue::Iterator Queue::begin() const {
    return Queue::Iterator(this, m_front);
}

int Queue::size() const {
    return m_size;
}

Queue::Iterator Queue::end() const {
    return Queue::Iterator(this, m_back->m_next);
}

Queue::~Queue() {
    while(m_front != nullptr) {
        popFront();
    }
}

// TODO: Why did we use a reference here?
Queue::QNode::QNode(int& data):
    m_data(data),
    m_next(nullptr)
{}



const int& Queue::Iterator::operator*() const {
    return currentNode->m_data;
}

Queue::Iterator& Queue::Iterator::operator++() {
    currentNode = currentNode->m_next;
    return *this;
}

Queue::Iterator Queue::Iterator::operator++(int) {
    Iterator oldIterator = *this;
    ++*this;
    return oldIterator;
}

const bool Queue::Iterator::operator!=(Iterator iterator) {
    return this->currentNode != iterator.currentNode;
}

Queue::Iterator::Iterator(const Queue* queue, QNode* node):
    queue(queue),
    currentNode(node)
{}

template<class TransformFunction>
void transform(Queue& queue, TransformFunction transform) {
    for(int& queueElement : queue) {
        transform(queueElement);
    }
}


#endif //MATAM_EX3_QUEUE_H
