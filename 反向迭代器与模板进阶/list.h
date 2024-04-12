#pragma once
#include<assert.h>
#include"ReverseIterator.h"

namespace bit
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};


//�������������ģ��
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{

		typedef ListNode<T> Node;
		// typedef ListIterator<T, T&, T*>
		// typedef ListIterator<T, const T&, const T*>
		typedef ListIterator<T, Ref, Ptr> iterator;

		Node* _node;

		ListIterator(Node* node)
			:_node(node)
		{}

		// *it
		//T& operator*()
		Ref operator*()
		{
			return _node->_data;
		}

		// it->
		//T* operator->()
		Ptr operator->()
		{
			return &_node->_data;
		}

		// ++it
		iterator& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		iterator operator++(int)
		{
			iterator tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		iterator& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		iterator operator--(int)
		{
			iterator tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const iterator& it)
		{
			return _node != it._node;
		}

		bool operator==(const iterator& it)
		{
			return _node == it._node;
		}
	};

//list��ģ��
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		//<������>
		typedef ListIterator<T, T&, T*> iterator;//�������������ģ��
		typedef ListIterator<T, const T&, const T*> const_iterator;//const�������������ģ��

		//<�����������������>
		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;//�������������ģ��
		typedef ReverseIterator<const_iterator, const T&, const T*> const_reverse_iterator;//const�������������ģ��

		//���������
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		// const����������Ҫ�ǵ����������޸ģ����ǵ�����ָ������ݣ�
		// ������ָ������ݲ����޸ģ�const iterator����������Ҫconst������

		// T* const p1
		// const T* p2
		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		//C++11��initializer_list
		list(initializer_list<T> il)
		{
			empty_init();

			for (auto& e : il)
			{
				push_back(e);
			}
		}


		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		// ��Ҫ������һ�����Ҫ�Լ�д���
		// ����Ҫ������һ��Ͳ���Ҫ�Լ�д�����Ĭ��ǳ�����Ϳ���

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// lt1 = lt3
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		/*void push_back(const T& x)
		{
			Node* newnode = new Node(x);
			Node* tail = _head->_prev;

			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}*/

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;

			// prev newnode cur;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			_size++;
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			delete cur;
			_size--;

			return iterator(next);
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

	private:
		Node* _head;
		size_t _size;
	};
}





