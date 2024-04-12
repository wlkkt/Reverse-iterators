#pragma once

// 所有容器的反向迭代器
// 迭代器适配器
namespace bit
{
	// vector<T>::iterator
	// list<T>::iterator
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		// typedef ReverseIterator<T, T&, T*>
		// typedef ReverseIterator<T, const T&, const T*>
		typedef ReverseIterator<Iterator, Ref, Ptr> rever_iterator;//将反向迭代器的类型重命名为rever_iterator
		
		Iterator _it;//定义一个正向迭代器类型的对象，并对其进行初始化和封装

		ReverseIterator(Iterator it)//反向迭代器的对象由正向迭代器的对象初始化
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;//不改变原迭代器本身的指向，只想获取迭代器指向的下一个位置的数据的值
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());//返回该对象地址，返回值的类型是Ptr*，匿名指针
		}

		//++和--逻辑与正向迭代器相反
		//前置++
		rever_iterator& operator++()//返回类型是一个反向迭代器类类型的引用
		{
			--_it;
			return *this;
		}

		//前置--
		rever_iterator& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const rever_iterator& s)
		{
			return _it != s._it;
		}
	};
}
