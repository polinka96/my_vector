#pragma once

#include <string> 
#include <assert.h>


using namespace std;


template <class T>
class Vector {
	T* m_data;           
	unsigned m_capacity; 
	unsigned m_size;      
	enum { initialSize = 10 };


public:
	typedef T* iterator;

	Vector() :m_data(0), m_capacity(0), m_size(0) 
    {
		reserve(initialSize);
	}

	Vector(unsigned n) :m_data(0), m_capacity(0), m_size(0) 
    {
		resize(n);
	}

	Vector <T> (const Vector & vec)
	{
		m_size = vec.m_size;
		m_capacity = vec.m_capacity;
		m_data = new T[m_capacity];
		
		for (int k = 0; k < m_size; k++)
			m_data[k] = vec.m_data[k];

	}

	~Vector() 
    {
		clear();
	}

	Vector <T> & operator=(const Vector & vec)
	{
		delete[] m_data;
		
		m_size = vec.m_size;
		m_capacity = vec.m_capacity;
		m_data = new T[m_capacity];
		
		for (int k = 0; k < m_size; k++)
			m_data[k] = vec.m_data[k];

		return *this;
	}

	T& front() 
    {
		return m_data[0];
	}

	T& back() 
    {
		return m_data[m_size - 1];
	}

	void erase(int index) 
    {
		if (m_size == 1)
			clear();
		else
		{
			for (int j = index + 1; j < m_size; j++)
				m_data[j - 1] = m_data[j];

			m_size--;
		}
	}

	void insert(int index, T data) 
    {
		push_back(m_data[m_size-1]);
		
		for (int j = index+1; j < m_size; j++)
			m_data[j-1] = m_data[j];
			
		m_data[index] = data;
		m_size++;
	}


	void clear() {
		delete[] m_data;
		m_data = 0;
	}

	bool     empty()     const 
    { 
             return m_size == 0; 
    }
    
	unsigned size()      const 
    { 
             return m_size; 
    }
    
	unsigned capacity()  const 
    {
             return m_capacity; 
    }

	void reserve(unsigned n) 
    {
		if (n > m_capacity)
		{
            T* p = new T[n];

			for (unsigned i = 0; i < m_size; ++i) 
            {
				new (p + i) T(*(m_data + i));  
			}
			
			delete[] m_data;
			m_data = p;
			m_capacity = n;
		}
	}

	void resize(unsigned n) 
    {
		if (n < m_size) 
        {
			for (unsigned i = n; i < m_size; ++i) 
            {
				(m_data + i)->~T(); 
			}
			m_size = n;
		}

		if (n > m_capacity) 
        {
			reserve(n);
		}

		for (unsigned i = m_size; i < n; ++i) 
        {
			new(m_data + i) T(); 
		}
		m_size = n;
	}

	void pop_back() 
    {
		m_size--;
	}

	void push_back(const T& t) 
    {
		assert(m_capacity != 0);

		if (m_size == m_capacity) {
			reserve(m_capacity * 2);
		}

		new(m_data + m_size) T(t); 
		++m_size;
	}


	T& operator[](unsigned i)
	{
		if (i<m_size)
			return *(m_data + i);
		else
			throw "my_array: operator[]: index out of range";
	}

	iterator begin() 
    { 
      return m_data; 
    }

	iterator end() 
    { 
      return m_data + m_size; 
    }

};

