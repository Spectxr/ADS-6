// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Item {
    T value;
    Item* next;
    explicit Item(const T& value) : value(value), next(nullptr) {}
  };
  Item* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head) {
      pop();
    }
  }
  bool isEmpty() const {
        return head == nullptr;
  }
  void push(const T& item) {
    Item* newItem = new Item(item);
    if (isEmpty() || head->value.prior < item.prior) {
      newItem->next = head;
      head = newItem;
    } else {
      Item* current = head;
      while (current->next && current->next->value.prior >= item.prior) {
        current = current->next;
      }
      newItem->next = current->next;
      current->next = newItem;
    }
  }
  T pop() {
    if (isEmpty()) {
      throw std::string("Queue is empty");
    }
    Item* temp = head;
    T value = head->value;
    head = head->next;
    delete temp;
    return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
