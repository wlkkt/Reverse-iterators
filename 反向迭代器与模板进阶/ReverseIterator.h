#pragma once

//所有容器的反向迭代器
//迭代器适配器

namespace bit
{
	//vector<T>::iterator -> 
	//list<T>::iterator -> 
	template <class Iterator>
	struct ReverseIterator
	{
		Iterator _it;


	};



}