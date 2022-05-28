#ifndef MATAM_EX3_QUEUE_H
#define MATAM_EX3_QUEUE_H

typedef bool (*filterFunction)(int);

// TODO: Make it generic when finished testing
class Queue {
public:
    Queue():
        m_front(nullptr),
        m_back(nullptr),
        m_size(0)
    {};
    
    void pushBack(int value) {
        // TODO: Should we really allocate manually?
        QNode *newNode = new QNode(value);
        
        if(m_front == nullptr) {
            m_front = newNode;
        }
        
        if(m_back != nullptr) {
            m_back->setNext(newNode);
        }
        
        m_back = newNode;
        m_size++;
    }
    
    void popFront() {
        if(m_front == m_back) {
            m_back = nullptr;
        }
        
        m_front = m_front->getNext();
        // TODO: Should we use it like that?
        delete m_front;
        m_size--;
    }

    //returning it as reference is the key to support the syntax "queue.front() = ??"
    //can't make the function const because of this
    int& front() {
        return m_front->m_data;
    }

    int size() const {
        return m_size;
    }
    
    class Iterator;
    
//    Iterator begin() const {
//    }
    
//    Iterator end() const {
//        return m_back->getNext();
//    }

    Queue(Queue& queue) = default;
    ~Queue() = default;
    
    class InvalidOperation {};
    
private:
    class QNode {
    public:
        QNode(int& data) :
            m_data(data),
            m_next(nullptr)
        {};

        int getData() const {
            return m_data;
        }
        
        QNode* getNext() const {
            return m_next;
        }

        void setData(int dataToSet) {
            m_data = dataToSet;
        }
        
        void setNext(QNode* next) {
            m_next = next;
        }
        
        // TODO: default copy c'tor and operator=?
    
    private:
        int m_data;
        QNode* m_next;
        friend class Queue;
    };

    QNode* m_front;
    QNode* m_back;
    int m_size;
};

class Queue::Iterator {
public:
    // T
    // TODO: Should it be int&?
    const int& operator*() const {
        return currentNode->getData();
    }
    
    Iterator& operator++() {
        currentNode = currentNode->getNext();
        return *this;
    }
    
    Iterator operator++(int) {
        Iterator oldIterator = *this;
        ++*this;
        return oldIterator;
    }
    
    const bool operator!=(Iterator iterator) {
        return this->currentNode != iterator.currentNode;
    }
    
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    
private:
    const Queue* queue;
    QNode* currentNode;
    
    Iterator(const Queue* queue, QNode* node):
        queue(queue),
        currentNode(node)
    {}
    
    friend class Queue;
};

#endif //MATAM_EX3_QUEUE_H
