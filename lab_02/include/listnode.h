#ifndef _LISTNODE_H_
#define _LISTNODE_H_

template <typename typeData>
class ListNode
{
public:
    ListNode();
    explicit ListNode(const typeData dataToAdd);
    explicit ListNode(const std::shared_ptr<ListNode<typeData>> node);
    ListNode(const typeData data, const std::shared_ptr<ListNode<typeData>> nextNode);
    virtual ~ListNode();

    void setData(const typeData data);
    typeData getData() const;
    typeData &getPtrData();

    void setNext(const std::shared_ptr<ListNode<typeData>> nextNode);
    std::shared_ptr<ListNode<typeData>> getNext();

    bool operator==(const ListNode<typeData> &secondNode) const;
    bool operator!=(const ListNode<typeData> &secondNode) const;
    bool operator>(const ListNode<typeData> &secondNode) const;
    bool operator<(const ListNode<typeData> &secondNode) const;
    bool operator>=(const ListNode<typeData> &secondNode) const;
    bool operator<=(const ListNode<typeData> &secondNode) const;

private:
    typeData data;
    std::shared_ptr<ListNode<typeData>> next;

protected:
};

#endif
