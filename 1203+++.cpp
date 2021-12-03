namespace bit
{
	template<class _Ty>
	class vector
	{
	public:
		typedef _Ty* iterator;
		typedef const _Ty* const_iterator;
		typedef size_t size_type;
	public:
		vector() : _start(nullptr), _finish(nullptr),_end_of_storage(nullptr)
		{}
		vector(int n, const _Ty& value = _Ty())
			: _start(nullptr), _finish(nullptr),
			_end_of_storage(nullptr)
		{
			reserve(n);
			while(n--)
				push_back(value);
		}
		vector(const_iterator first, const_iterator last)
			: _start(nullptr), _finish(nullptr),
			_end_of_storage(nullptr)
		{
			reserve(last - first);
			while(first != last)
				push_back(*first++);
		}
		vector(const vector<_Ty> &v)
			 : _start(nullptr), _finish(nullptr),
			_end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for(int i=0; i<v.size(); ++i)
				_start[i] = v[i];
			_finish = _start + v.size();
		}
		vector<_Ty>& operator=(const vector<_Ty> &v)
		{
			if(this != &v)
			{
				vector<_Ty> tmp = v;
				swap(tmp);
			}
			return *this;
		}
		~vector()
		{
			if(_start)
			{
				delete []_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}
	public:
		void push_back(const _Ty &x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			erase(end()-1);
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
	public:
		_Ty& operator[](size_t pos)
		{
			return _start[pos];
		}
		const _Ty& operator[](size_t pos)const 
		{
			return _start[pos];
		}
		const _Ty& at(size_type pos) const
		{
			assert(pos>=0 && pos<size());
			return _start[pos];
		}
		_Ty& at(size_type pos)
		{
			assert(pos>=0 && pos<size());
			return _start[pos];
		}

	public:
		iterator insert(iterator pos, const _Ty& x)
		{
			if(_finish == _end_of_storage)
			{
				size_t old_n = pos - _start;
				size_t new_sz = capacity()==0 ? 1 : 2*capacity();
				reserve(new_sz);
				//重新更新迭代器 pos
				pos = _start + old_n;
			}

			iterator cur = end();
			while(cur != pos)
			{
				*cur = *(cur-1);
				cur--;
			}
			*cur = x;   //
			_finish++;
			return cur;
		}

		iterator erase(iterator pos)
		{
			assert(pos>=_start && pos<_finish);

			iterator cur = pos;
			while(pos < _finish)
			{
				*pos = *(pos+1);
				pos++;
			}
			--_finish;
			return cur;
		}

		void reserve(size_type n)
		{
			if(n > capacity())
			{
				size_t old_sz = size();
				_Ty *new_start = new _Ty[n];
				//memcpy(new_start, _start, sizeof(_Ty)*old_sz);
				for(int i=0; i<old_sz; ++i)
				{
					new_start[i] = _start[i];
				}
				delete []_start;

				_start = new_start;
				_finish = _start + old_sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const _Ty& value = _Ty())
		{
			if(n <= size())
			{
				_finish = _start + n;
				return;
			}

			if(n > capacity())
			{
				reserve(n);
			}

			size_t offset = n - size();
			while(offset--)
			{
				*_finish++ = value;
			}
		}

	public:
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_storage - _start;
		}
		bool empty()const
		{
			return size() == 0;
		}
	public:
		void swap(vector& str)
		{
			std::swap(_start, str._start);
			std::swap(_finish, str._finish);
			std::swap(_end_of_storage, str._end_of_storage);
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
};
