#include <galaxy-explorer/AsteroidList.hpp>


AsteroidListItem::AsteroidListItem() {
	this->next = nullptr;
	this->data = nullptr;
}

AsteroidListItem::AsteroidListItem(Asteroid a) {
	this->next = nullptr;
	this->data = new Asteroid(a);
}

AsteroidListItem::~AsteroidListItem() {
    if (data != nullptr) {
        delete data; // free Asteroid
    }
}

AsteroidList::AsteroidList()
{
    head.setNext(nullptr);
}

AsteroidList::AsteroidList(const AsteroidList& src)
{
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the destructor (because you should put all your constructors together).
    if (src.begin() == nullptr) {
        head.setNext(nullptr); // empty src
    
    } else {
        const AsteroidListItem* ptr = src.begin(); // src
        AsteroidListItem* newPtr = nullptr; // to copy item
        AsteroidListItem* last = nullptr; // to keep track of the last item inserted

        while (ptr != nullptr) {
            newPtr = new AsteroidListItem(ptr->getData()); // copy
            // insert nptr at the end of the list
            if (last == nullptr) {
                head.setNext(newPtr);
            } else {
                last->setNext(newPtr);
            }
            ptr = ptr->getNext(); // traverse src
            last = newPtr;
        }
        
    }

}

AsteroidList::~AsteroidList() {
	// The functions in this class are listed in a suggested order of implementation,
	// except for this one and the copy constructor (because you should put all your constructors together).

    AsteroidListItem* ptr;
    while (head.getNext() != nullptr) {
        ptr = head.getNext(); // to delete first item
        head.setNext(ptr->getNext()); // shrink size of list
        delete ptr;
    }
}

void AsteroidList::pushFront(Asteroid e) {
    AsteroidListItem* newItem = new AsteroidListItem(e);
    newItem->setNext(head.getNext()); // set previous first item as newItem's next
    head.setNext(newItem); // add new item as first item
}

Asteroid& AsteroidList::front() {
    if (head.getNext()!= nullptr) {
        return head.getNext()->getData(); // first item in list
    } else {
	return *(Asteroid*)nullptr; // empty list
    }
}

const Asteroid& AsteroidList::front() const {
    if (head.getNext() != nullptr) {
        return head.getNext()->getData(); // first asteroid
    } else {
	return *(const Asteroid*)nullptr;
    }
}

bool AsteroidList::isEmpty() const {
	return (head.getNext() == nullptr);
}

int AsteroidList::size() const {
    int count = 0;
    const AsteroidListItem* start = head.getNext();
    
    while (start != nullptr) {
        count ++;
        start = start->getNext(); // traverse and increment count
    }
    return count; // return 0 if empty
}

AsteroidListItem* AsteroidList::beforeBegin() {
    return &head;
}

const AsteroidListItem* AsteroidList::beforeBegin() const {
    return &head;
}

AsteroidListItem* AsteroidList::begin() {
    if (head.getNext() != nullptr) {
        return head.getNext(); // first item
    } else {
	return nullptr;
    }
}

const AsteroidListItem* AsteroidList::begin() const {
	if (head.getNext() != nullptr) {
            return head.getNext();
        } else {
            return nullptr;
        }
}

AsteroidListItem* AsteroidList::beforeEnd() {
    if (head.getNext() != nullptr) {
        AsteroidListItem* curr = head.getNext();
        
        // traverse till its next item is null
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        return curr;
    }
    return nullptr;
}

const AsteroidListItem* AsteroidList::beforeEnd() const {
    if (head.getNext() != nullptr) {
        const AsteroidListItem* curr = head.getNext();
        while (curr->getNext() != nullptr) {
            curr = curr->getNext();
        }
        return curr;
    }
    return nullptr;
}

AsteroidListItem* AsteroidList::end() {
	return nullptr;
}

const AsteroidListItem* AsteroidList::end() const {
	return nullptr;
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    AsteroidListItem* newItem = new AsteroidListItem(e); // item to insert
    
    newItem->setNext(prev->getNext()); // set newItem's next as prev
    prev->setNext(newItem);
    return newItem;
}

AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) {
    if (others.isEmpty()) return prev;
    
    const AsteroidListItem* otherHead = others.begin();
    AsteroidListItem* currPtr = prev; // ptr to traverse list
    AsteroidListItem* next = prev->getNext(); // get the next after prev to set it to the next after traversing

    while (otherHead != nullptr) {
        AsteroidListItem* newItem = new AsteroidListItem(otherHead->getData()); // copy object
        currPtr -> setNext(newItem); 
        currPtr = currPtr -> getNext();
        otherHead = otherHead->getNext(); // traverse other list
    }
    currPtr->setNext(next); //attach remaining list after insertion
    
    return currPtr;
    
    
}

AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    if (prev -> getNext() == nullptr || prev == nullptr) return prev; // nothing to delete after prev
    else {
        AsteroidListItem* toDelete = prev->getNext(); // item to be deleted
        prev ->setNext(prev->getNext()->getNext()); // remove linkage
        delete toDelete; // deletion
    }
    if (prev->getNext() != nullptr) {
        return prev->getNext(); 
    }else {
        return prev;
    }
	return nullptr;
}

void AsteroidList::clear() {
    if (head.getNext() == nullptr) return; // empty list
    
    AsteroidListItem* ptr;
    while (head.getNext() != nullptr) {
        ptr = head.getNext(); // to be deleted
        head.setNext(ptr->getNext()); // remove linkage 
        delete ptr;
    }
}

AsteroidList& AsteroidList::operator=(const AsteroidList& src) {
    // check if self-assignment
    if (this == &src) return *this;
    
    // delete self first
    AsteroidListItem* ptr;
    while (head.getNext() != nullptr) {
        ptr = head.getNext();
        head.setNext(ptr->getNext());
        delete ptr;
    }
    // after deletion, check if src is empty
    if (src.isEmpty()) return *this;
    
    // begin copying
    const AsteroidListItem* srcHead = src.begin();
    AsteroidListItem* nptr = nullptr; // new item to be inserted/copied
    AsteroidListItem* last = nullptr; // to keep track of last ptr
    head.setNext(nullptr);
    
    while (srcHead != nullptr) {
        nptr = new AsteroidListItem(srcHead->getData());
        // insert nptr at the end of the list
        if (last == nullptr) {
            head.setNext(nptr);
        } else {
            last->setNext(nptr);
        }
        srcHead = srcHead->getNext();
        last = nptr;
    }
    return *this;
}
