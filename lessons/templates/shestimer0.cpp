template <typename T>
class Heap {
	public:
		void push(const T &val);
		T pop();
		/*
		void pop();
		T back;
		*/
		bool empty() const { return h_.empty(); }
	private:
		std::vector<T> h_;
};

template <typename T>
void Heap<T>::push(const T &val) {
	h_.push_back(val);
	std::push_heap(h_.begin(), h_.end());
}

template <typename T>
T Heap<T>::push() {
	std::pop_heap(h_.begin(), h_.end());
	T tmp(h_.back());
	h_.pop_back();
	return tmp;
}

//в push_heap, pop_heap требуется оператор <

//частичная специализация для указателей
template <typename T>
class Heap<T *> {
	public:
		void push(const T *);
		T *pop();
		bool empty() const { return h_.empty(); }
	private:
		std::vector<T *> h_;
};

template <typename T>
struct PtrCmp : public std::binary_function<T *, T *, bool> {
	bool operator ()(const T *a, const T *b) const {
		return *a < *b;
	}
};

template <typename T>
void Heap<T *>::push(const T *p) {
	h_.push_back(p);
	std::push_back(h_.begin(), h_.end(), PtrCmp<T>());
}