#pragma once

// ���������ķ��������
// ������������
namespace bit
{
	// vector<T>::iterator
	// list<T>::iterator
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		// typedef ReverseIterator<T, T&, T*>
		// typedef ReverseIterator<T, const T&, const T*>
		typedef ReverseIterator<Iterator, Ref, Ptr> rever_iterator;//�����������������������Ϊrever_iterator
		
		Iterator _it;//����һ��������������͵Ķ��󣬲�������г�ʼ���ͷ�װ

		ReverseIterator(Iterator it)//����������Ķ���������������Ķ����ʼ��
			:_it(it)
		{}

		Ref operator*()
		{
			Iterator tmp = _it;//���ı�ԭ�����������ָ��ֻ���ȡ������ָ�����һ��λ�õ����ݵ�ֵ
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());//���ظö����ַ������ֵ��������Ptr*������ָ��
		}

		//++��--�߼�������������෴
		//ǰ��++
		rever_iterator& operator++()//����������һ����������������͵�����
		{
			--_it;
			return *this;
		}

		//ǰ��--
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
