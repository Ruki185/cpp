#pragma once

#include <cstdint>
#include <utility>

/*
 * ToDo:
 *   * Make a template out of ForwardList. What template parameter(s) do you
 *     need?
 *   * Add data members to the classes if necessary
 *   * Implement all functions
 *   * Test your solution in main.cpp
 */

namespace a08 {
/**
 * This class represents a linked list. It supports constant time insertion and
 * removal of elements anywhere in the list.
 */
  template<typename T>
  class ForwardList {
      /**
       * This internal class represents a node of the linked list holding a data
       * member and a pointer to the next element. It is in the private part of
       * the class because it is an implementation detail that is not part of the
       * class's public interface.
       */
      struct Node {
          /// Constructs a Node from a data value and a link to the next element.
          Node(const T& data, Node* next) : data{data}, next{next} {}

          /// A Node owns all nodes after it, so it deletes them on destruction
          ~Node() {
            delete next;
          }

         /**
          * Performs a deep copy of the Node and all Nodes after it. Note that
          * this function returns an (owning) raw pointer to storage that was
          * allocated using new inside the function. Usually, this is bad
          * practice, as the calling code must not forget to call delete on the
          * pointer. In this case, it is sort of fine, because the Node class is
          * private and can only be used from within the ForwardList class. This
          * means that if we do not make any mistakes while implementing
          * ForwardList, no one else can make mistakes with this either. A better
          * approach would be to use a smart pointer (such as std::unique_ptr) to
          * hold the next node, but we have not learned about that in the lecture
          * yet.
          */
          Node* clone() const {
              if(next == nullptr) {
                  return new Node{data, nullptr};
              }
              else {
                  return new Node{data, next->clone()};
              }
          }

          T data;
          Node* next;
      };
  public:

      /**
       * This class represents an iterator on the ForwardList. It implements the
       * basic operations needed for an iterator, namely incrementation,
       * dereferencing and comparison. Note that to conform to the requirements
       * the STL has for iterators we would also have to provide some special
       * member typedefs. However, our Iterator is sufficient to work with a range
       * for loop.
       */
      class Iterator {
      public:
          /// Dereference the iterator. Returns a reference to the data element
          /// stored at the current position in the list. If the iterator does not
          /// point to a valid node, the behavior is undefined.
          T& operator*() {
            return node->data;
          }

          /// Pre-increment (++it). Advances the iterator to the next element
          /// and returns the modified iterator. If the iterator does not
          /// point to a valid node, the behavior is undefined.
          Iterator operator++() {
            node = node->next;
            return *this;
          }

          /// Post-increment (it++). Advances the iterator to the next element
          /// and returns a copy of the previous value. If the iterator does not
          /// point to a valid node, the behavior is undefined.
          Iterator operator++(int) const {
            auto temp = this->node;
            if(node->next != nullptr) {
              node = node->next;
            }
            return Iterator(temp);

          }

          /// Returns true if two iterators refer to the same elements in the list.
          bool operator==(const Iterator& other) const {
            return this->node == other.node;
          }

          /// Returns true if two iterators do not refer to the same element.
          bool operator!=(const Iterator& other) const {
            return !(*this == other);
          }
      private:
          /// The constructor of iterator is private and ForwardList is listed
          /// as a friend. This means that only ForwardList can construct new
          /// instances of its Iterator class and users of ForwardList can not
          /// create iterators to random locations.
          friend class ForwardList;
          Iterator(Node* node) {
            this->node = node;
          }
          Node* node;
          // ToDo: Data member(s)?
      };

      /// Default constructor creates an empty list
      ForwardList() {
        node = nullptr;
        _size = 0;
      }
      /// Copy constructor performs a deep copy of the other list's Nodes
      ForwardList(const ForwardList& other) {
        this->node = other.node->clone();
        this->_size = other._size;
      }
      /// Destructor makes sure that all Nodes are correctly destroyed
      ~ForwardList() {
        delete this->node;
      }

      /// Copy assignment operator uses the copy-and-swap idiom to make a safe
      /// assignment
      ForwardList& operator=(ForwardList other) {
          swap(*this, other);
          return *this;
      }

      /// Return an iterator to the first element of the list
      Iterator begin() {
        return Iterator(this->node);
      }

      /// Return an iterator to one-past-the-end of the list. A common trick for
      /// non-contiguous containers like this to represent a one-past-the-end
      /// iterator is to return an iterator holding a nullptr internally.
      /// Dereferencing or incrementing the iterator returned by end() is undefined
      /// behavior.
      Iterator end() {
        return Iterator(nullptr);
      }

      /// Add an element to the front of the list.
      void push_front(const T& value) {
        this->node = new Node(value, this->node);
        //node.next = this->node;
        //node.data = value;
        this->_size += 1;
      }

      /// Remove the first element of the list. Calling this function on an empty
      /// list is undefined behavior. When implementing this function, be careful
      /// to delete the one and only the one element that is removed.
      void pop_front() {
        if(this->_size == 0)
          return;
        auto temp = this->node;
        this->node = this->node->next;
        temp->next = nullptr;
        delete temp;
        this->_size -= 1;
      }

      /// Get a reference to the first element of the list
      /// (const and non-const version)
      T& front() {
        return this->node->data;
      }
      const T& front() const {
        return this->node->data;
      }

      /// Return true is the list is empty
      bool empty() const {
        if(this->_size == 0)
          return true;
        else
          return false;
      }

      /// Return the number of elements stored in the list.
      std::size_t size() const {
        return this->_size;
      }

      /// Insert a new element after the one pointed to by the given Iterator.
      /// Returns an Iterator to the newly inserted element
      Iterator insert_after(Iterator pos, T value) {
        _size += 1;
        auto temp = new Node(value, pos.node->next);
        pos.node->next = temp;
        return Iterator(temp);
      }

      /// Swaps the contents of two ForwardLists without making any deep copies!
      /// This is a commonly implemented function that makes in possible to
      /// cheaply swap two objects of the same class, and that aids in
      /// implementing the assignment operator using the copy-and-swap idiom.
      friend void swap(ForwardList& l, ForwardList& r) {
        auto node_tmp = l.node;
        auto size_tmp = l._size;

        l._size = r._size;
        l.node = r.node;
        r.node = node_tmp;
        r._size = size_tmp;
      }

  private:
      Node* node;
      std::size_t _size;
      // ToDo: Data member(s)?
  };

} // namespace a08
