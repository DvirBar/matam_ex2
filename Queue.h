//
// Created by 222ro on 21-May-22.
//

#ifndef MATAM_EX3_QUEUE_H
#define MATAM_EX3_QUEUE_H
class Queue {
public:
    Queue() :
    m_front(nullptr),
    m_back(nullptr),
    m_size(0)
    { };

    int front() {
        return m_front->getData();
    }

    Queue(Queue& queue) = default;
    ~Queue() = default;
private:

    class QNode {
    public:
        QNode(int data) :
            m_data(data),
            m_next(nullptr)
        { };

        int getData() const {
            return m_data;
        }

        void setData(int dataToSet) {
            m_data = dataToSet;
        }

    private:
        int m_data;
        int* m_next;
    };

    QNode* m_front;
    QNode* m_back;
    int m_size;

};
#endif //MATAM_EX3_QUEUE_H
