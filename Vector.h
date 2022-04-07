#pragma once

template<class Telem>
class vector {

	private:
		int len;
		int capacity;

	public:
		Telem* v;
		vector();
		~vector();
		int size() const;
		void push_back(Telem x);
		Telem* begin();
		Telem* end();
		void erase(int poz);
};