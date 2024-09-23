#pragma once

class IIterator {
  public:
    virtual IIterator operator++() = 0;
};

template <typename T, typename Node> class IContainer {
  public:
    virtual ~IContainer() {};
    virtual void push_back() = 0;
    virtual void insert() = 0;
    virtual void erase() = 0;
    virtual void size() const = 0;

    virtual IContainer& operator=(const IContainer& container) = 0;
    virtual IContainer& operator=(IContainer&& container) = 0;

    virtual T operator[](const long int pos) = 0;

    virtual void reserve(const long int new_cap) = 0;

    class IIterator {
      public:
        virtual IIterator operator++() = 0;
        virtual IIterator operator--() = 0;

        virtual IIterator get() = 0;
        virtual IIterator operator*() {
            return get();
        }
        virtual void setCurrent(Node* node) {//TODO do unvisible for user
            currentNode = node;
        }

      private:
        Node* currentNode;
    };
    virtual IIterator begin() = 0;
    virtual IIterator end() = 0;

  private:
    long int m_size = 0;
    IIterator m_begin;
};
