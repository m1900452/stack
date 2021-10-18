#include <iostream>

class Stack {
public:
  Stack() = default;
  Stack(const Stack& s);
  Stack& operator= (const Stack& rhs);
  ~Stack();
  bool is_empty() const noexcept;
  void push(const float value);
  void pop();
  float& top();
private:
  struct Node {
    float value = 0.0f;
    Node* next = nullptr;
  };
private:
  Node* head_ = nullptr;
};

Stack::Stack(const Stack& s) {
  
  Node* p;
  Node* p2;
  Node* p3;

  head_ = nullptr;
  p3 = nullptr;

  p = s.head_;
  while (p != nullptr)
  {
    try {
      p2 = new Node;
    }
    catch(std::bad_alloc e) {
      std::cout << e.what() << std::endl;
      return;
    }
    p2->value = p->value;
    p2->next = nullptr;

    if (head_ == nullptr)
    {
      head_ = p2;
      p3 = p2;
    }
    else {
      p3->next = p2;
      p3 = p3->next;
    }

    p = p->next;
  }
}

Stack& Stack::operator=(const Stack& rhs) {
  Node* p;
  Node* p2;
  Node* p3;

  head_ = nullptr;
  p3 = nullptr;

  p = rhs.head_;
  while (p != nullptr)
  {
    try {
      p2 = new Node;
    }
    catch (std::bad_alloc e) {
      std::cout << e.what() << std::endl;
      return *this;
    }
    p2->value = p->value;
    p2->next = nullptr;

    if (head_ == nullptr)
    {
      head_ = p2;
      p3 = p2;
    }
    else {
      p3->next = p2;
      p3 = p3->next;
    }
    p = p->next;
  }
  return *this;
}

void Stack::pop(){
  if (is_empty())
    throw std::out_of_range("Stack is empty. pop()");
  Node* node = head_;
  head_ = head_->next;
  delete node;
}

void Stack::push(const float value) {
  Node* node;
  try {
    node = new Node;
  }
  catch (std::bad_alloc e)
  {
    std::cout << e.what() << std::endl;
    return;
  }
  node->value = value;
  node->next = head_;
  head_ = node;
}

bool Stack::is_empty() const noexcept {
  if (head_ == nullptr)
    return true;
  else return false;
}

Stack::~Stack() {
  Node* p;
  Node* p2;

  p = head_;

  while (p != nullptr)
  {
    p2 = p;
    p = p->next;
    delete p2;
  }
  head_ = nullptr;
}

float& Stack::top() {
  if (is_empty())
  {
    throw std::out_of_range("Stack is empty. top()");
  }
  else
  return head_->value;
}

int main()
{
  Stack a;
  try {
    std::cout << "top: " << a.top() << std::endl;
  }
  catch (std::out_of_range e)
  {
    std::cout << e.what() << std::endl;
  }
  
  a.push(2.0f);
  a.push(3.0f);
  std::cout << "top: " << a.top() << std::endl;
  a.pop();
  std::cout << "top: " << a.top() << std::endl;
  a.pop();
  
  try {
    a.pop();
  }
  catch (std::out_of_range e)
  {
    std::cout << e.what() << std::endl;
  }
  
  try {
    std::cout << "top: " << a.top() << std::endl;
  }
  catch (std::out_of_range e)
  {
    std::cout << e.what() << std::endl;
  }
  
  return 0;
}

