#pragma once


#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
	size_t _length;
	size_t _capacity;
	char* _text;
	void set_text(const char* text)
	{
		if (this->_text != nullptr)
			delete[] this->_text;
		int len = strlen(text);
		while (this->_capacity <= len)
		{
			this->_capacity += 16;
		}
		this->_text = new char[this->_capacity];
		strcpy_s(this->_text, len + 1, text);
	}
public:
	MyString()
	{
		this->_length = 0;
		this->_capacity = 0;
		this->_text = nullptr;
	}
	MyString(const char* text)
	{
		this->_length = strlen(text);
		set_text(text);
	}
	MyString(const MyString& other)
	{
		this->_length = other._length;
		set_text(other._text);
	}
	MyString& operator=(const MyString& other)
	{
		this->_length = other._length;
		set_text(other._text);
		return *this;
	}
	inline char& front()const { return this->_text[0]; }
	inline char& back()const { return this->_text[this->_length]; }
	char& at(size_t index)
	{
		if (index < this->_length)
		{
			return this->_text[index];
		}
		assert(!"Out of length");
	}
	inline size_t capacity()const { return this->_capacity; }
	inline size_t size()const { return this->_length; }
	size_t find(char chr)const
	{
		for (size_t i = 0; i < this->_length; i++)
		{
			if (chr == this->_text[i])
				return i;
		}
		return -1;
	}
	size_t rfind(char chr)const
	{
		for (size_t i = this->_length; i > 0; i--)
		{
			if (chr == this->_text[i])
				return i;
		}
		return -1;
	}
	inline const char* print()const { return this->_text; }
	inline void clear() { this->_text = nullptr; }
	inline void reserve(size_t newCapacity) { this->_capacity = newCapacity; }
	inline void shrink_to_fit() { this->_capacity = this->_length; }
	bool empty() const { return this->_text; }
	void append(const char* text)
	{
		size_t newlen = _length + strlen(text);
		char* newstr = new char[newlen + 1];

		strcpy_s(newstr, newlen, this->_text);
		strcat_s(newstr, newlen, text);

		delete[] newstr;
		_text = newstr;
		_length = newlen;
	}
	int compare(const MyString right)
	{
		int len = strlen(_text);
		int len2 = strlen(right._text);
		if (len == len2) return 0;
		else if (len > len2) return 1;
		else if (len < len2) return -1;
	}
//===============================================================================
	// Own methods
	void replace(char symbol, char changed_symbol)
	{
		for (size_t i = 0; i < _length; i++)
		{
			if (_text[i] == symbol)
			{
				_text[i] = changed_symbol;
				return;
			}
		}
	}
	void reverse()
	{
		int len = strlen(this->_text);
		int temp;
		for (size_t i = 0; i < len / 2; i++)
		{
			temp = _text[i];
			_text[i] = _text[len - i - 1];
			_text[len - i - 1] = temp;
		}

	}
	bool isupper()
	{
		int checker = 0;
		for (size_t i = 0; i < _length; i++)
		{
			if (int(_text[i]) >= 65 && int(_text[i]) <= 90)
			{
				checker++;
			}
		}
		if (checker == _length)
			return true;
		else
			return false;
	}
	bool islower()
	{
		int checker = 0;
		for (size_t i = 0; i < _length; i++)
		{
			if (int(_text[i]) >= 97 && int(_text[i]) <= 122)
			{
				checker++;
			}
		}
		if (checker == _length)
			return true;
		else
			return false;
	}
	MyString upper()
	{
		for (size_t i = 0; i < _length; i++)
			_text[i] -= 32;
		return this->_text;
	}
	MyString lower()
	{
		for (size_t i = 0; i < _length; i++)
			_text[i] += 32;
		return this->_text;
	}
	bool endswith(char symbol)
	{
		if (_text[_length] = symbol)
		{
			return true;
		}
		return false;
	}
	bool startswith(char symbol)
	{
		if (_text[0] = symbol)
		{
			return true;
		}
		return false;
	}
	bool isnumeric()
	{
		int counter = 0;
		for (size_t i = 0; i < _length; i++)
		{
			if (_text[i] >= 49 && _text[i] <= 57)
				counter++;
		}
		if (counter == _length)
			return true;
		else
			return false;
	}


};
