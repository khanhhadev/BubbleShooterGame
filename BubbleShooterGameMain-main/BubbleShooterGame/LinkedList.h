#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList
{
protected:
	struct m_node
	{
		T m_value;
		m_node* m_previous = nullptr;
		m_node* m_next = nullptr;

		//m_node(T* value) :m_value(value) {};

		//derefrencing operator * overloading
		T& operator*()
		{
			return m_value;
		};
	};
	m_node* m_head = nullptr;
	m_node* m_tail = nullptr;
	int m_size = 0;
public:
	//declare nested class to implement iterator-loop in container LinkedList
	class Iterator
	{
	private:
		m_node* m_nodeptr;
	public:
		//default constructor
		Iterator():m_nodeptr(m_head) {}

		//copy constructor
		Iterator(m_node* const NodePtr) noexcept :
			m_nodeptr(NodePtr) { }

		static void swap(Iterator& itr1, Iterator& itr2)
		{
			m_node* temp = itr1.m_nodeptr;
			itr1.m_nodeptr = itr2.m_nodeptr;
			itr2.m_nodeptr = temp;
		}

		//prefix ++ overloading
		LinkedList::Iterator& operator++()
		{
			if (m_nodeptr)
				m_nodeptr = m_nodeptr->m_next;
			return *this;
		}

		//postfix ++ overloading
		LinkedList::Iterator& operator++(int)
		{
			Iterator iterator = *this;
			++* this;
			return iterator;
		}

		//operator + overloading
		LinkedList::Iterator& operator+(int n)
		{
			Iterator iterator = *this;
			if (m_nodeptr)
				while (n > 0)
				{
					iterator.m_nodeptr = iterator.m_nodeptr->m_next;
					n--;
				}
			return iterator;
		}

		//operator - overloading
		LinkedList::Iterator& operator-(int n)
		{
			Iterator iterator = *this;
			if (m_nodeptr)
				while (n > 0)
				{
					iterator.m_nodeptr = iterator.m_nodeptr->m_previous;
					n--;
				}
			return iterator;
		}

		//assignment operator = overloading
		LinkedList::Iterator& operator=(m_node* pNode)
		{
			this->m_nodeptr = pNode;
			return *this;
		}

		//assignment operator = overloading
		LinkedList::Iterator& operator=(Iterator itr)
		{
			this->m_nodeptr = itr.m_nodeptr;
			return *this;
		}

		//assignment operator = overloading
		LinkedList::Iterator& operator=(const Iterator& itr)
		{
			this->m_nodeptr = itr.m_nodeptr;
			return *this;
		}

		//prefix -- overloading
		LinkedList::Iterator& operator--()
		{
			if (m_nodeptr)
				m_nodeptr = m_nodeptr->m_previous;
			return *this;
		}

		//postfix -- overloading
		LinkedList::Iterator& operator--(int)
		{
			Iterator iterator = *this;
			--* this;
			return iterator;
		}

		//logical operator == overloading
		bool operator==(m_node* pNode)
		{
			return this->m_nodeptr == pNode;
		}

		//logical operator == overloading
		bool operator==(const Iterator& itr)
		{
			return this->m_nodeptr == itr.m_nodeptr;
		}

		//logical operator != overloading
		bool operator!=(const Iterator& iterator)
		{
			return m_nodeptr != iterator.m_nodeptr;
		}

		//derefrencing operator * overloading
		T& operator*()
		{
			return m_nodeptr->m_value;
		}

		friend class LinkedList;
	};

	void move(LinkedList<T>& list, Iterator itr)
	{
		if (m_size != 0)
		{
			if (m_size != 1)
			{
				if ((itr.m_nodeptr) == m_head)
				{
					(itr.m_nodeptr)->m_next->m_previous = nullptr;
					m_head = m_head->m_next;
				}
				else if ((itr.m_nodeptr) == m_tail)
				{
					(itr.m_nodeptr)->m_previous->m_next = nullptr;
					m_tail = (itr.m_nodeptr)->m_previous;
				}
				else
				{
					(itr.m_nodeptr)->m_previous->m_next = (itr.m_nodeptr)->m_next;
				}
			}
			else { m_head = m_tail = nullptr; }
			m_size--;
			list.push_back(*itr);
			//if (itr.m_nodeptr != nullptr) delete itr.m_nodeptr;
		}
	}

	//remove element from container
	void remove(Iterator itr)
	{
		if (m_size != 0)
		{
			if (m_size != 1)
			{
				if ((itr.m_nodeptr) == m_head)
				{
					(itr.m_nodeptr)->m_next->m_previous = nullptr;
					m_head = m_head->m_next;
				}
				else if ((itr.m_nodeptr) == m_tail)
				{
					(itr.m_nodeptr)->m_previous->m_next = nullptr;
					m_tail = (itr.m_nodeptr)->m_previous;
				}
				else
				{
					(itr.m_nodeptr)->m_previous->m_next = (itr.m_nodeptr)->m_next;
				}
			}
			delete itr.m_nodeptr;
			m_head = m_tail = nullptr;
			m_size--;
		}
		else
		{
		}
	};

	void clear()
	{
		while (m_size > 0)
		{
			pop_front();
		}
	}

	//remove first element from container
	T pop_front()
	{
		m_node* tempPtr = m_head;
		m_node temp = *m_head;
		/*if (m_size == 2)
		{
			m_head = m_tail;
		} else */
		if (m_size == 1)
		{
			delete m_head;
			m_size--;
			m_head = m_tail = nullptr;
			return temp.m_value;
		}
		else
		{
			m_head = m_head->m_next;
			delete tempPtr;
			m_size--;
			return temp.m_value;
		}
	};

	//remove last element from container
	T pop_back()
	{
		m_node* tempPtr = m_tail;
		m_node temp = *m_tail;
		m_tail = m_tail->m_previous;
		delete tempPtr;
		m_size--;
		return temp.m_value;
	};

	//insert element to first of container
	void push_front(const T& newvalue)
	{
		m_node* newnode = new m_node;
		newnode->m_value = newvalue;
		if (m_tail == nullptr)
		{
			m_tail = m_head = newnode;
		}
		else
		{
			newnode->m_next = m_head;
			m_head->m_previous = newnode;
			m_head = newnode;
		}
		m_size++;
	};

	//insert element to last of container
	void push_back(const T& newvalue)
	{
		m_node* newnode = new m_node;
		newnode->m_value = newvalue;
		if (m_tail == nullptr)
		{
			m_tail = m_head = newnode;
		}
		else
		{
			newnode->m_previous = m_tail;
			m_tail->m_next = newnode;
			m_tail = newnode;
		}
		m_size++;
	};

	//return size of stack container
	int size()
	{
		return m_size;
	};

	//check whether container is empty
	bool isEmpty()
	{
		if (m_head == nullptr) return true;
		else return false;
	};

	//find node by value of node
	LinkedList<T>::Iterator find(const T& value)
	{
		for (Iterator itr = begin(); itr != end(); itr++)
		{
			if (*itr == value) 
				return itr;
		}
		return end();
	};

	//return first node
	LinkedList<T>::Iterator begin()
	{
		return m_head;
	};

	//return next node of tail (nullptr)
	LinkedList<T>::Iterator end()
	{
		return nullptr;
	};

	//return last node
	LinkedList<T>::Iterator rbegin()
	{
		return m_tail;
	};

	//return previous node of head (nullptr)
	LinkedList<T>::Iterator rend()
	{
		return nullptr;
	};

};
#endif