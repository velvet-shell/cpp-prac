class Random {
public:
	virtual int next(int n); //virtual - выбор функции в рантайме
};

class RandomDev : public Random {
public:
	virtual int next(int n) {
	//
	}
};

class RandomRand : public Random {
public:
	virtual int next(int n) {
	//
	}
};

/*new: указатель на виртуальную функцию выделяется перед
вызовом конструктора. vptr инициализируется указателем на
функцию из таблицы виртуальных функций */
Random *rnd_first = new RandomRand();
Random *rnd_second = new RandomDev();
int one = rnd_first->next(10); // RandomRand::next()
int two = rnd_second->next(10); // RandomDev::next()
delete rnd_first;
delete rnd_second;
/*некорректное удаление, так как удалится только базовый
тип. Нужен виртуальный деструктор (нужен везде, где есть
виртуальная функция)*/

struct Base {
	virtual void Func(bool state = true) {}
};

struct Derived : Base {
	virtual void Func(bool state = false) {}
};

//Параметры по умолчанию подставляются на этапе компиляции
Derived d;
d.Func(); //false
Base* b = &d;
b->Func();
/*true, так как на этапе компиляции неизвестен класс
(может зависеть от условий и тд)
!Не делать параметры по умолчанию разными!*/

/*чисто виртуальная функция. Ни один объект данного
типа не может быть произвольно инстанцирован*/
struct Shape {
	virtual void draw() = 0;
}

struct Circle : Shape {
	virtual void draw() {
		//
	}
};
/*можно создать объект производного типа и потом
привести к базовому*/
Circle c;
Shape *ps = &c;
ps->draw();

//
struct Shape {
	virtual void draw() = 0;
	Shape() {
		draw();
	}
};

struct Circle : Shape {
	virtual void draw() {

	}
	Circle() {
		draw();
	}
};

Circle c;
/*ошибка компиляции - вызов чисто виртуальной функции.
Сначала конструируется базовый тип с вызовом draw()*/

/*Для виртуального деструктора нужно всегда реализовывать
тело*/

/*Виртуальных конструкторов с точки зрения языка
не существует*/

class Shape {
public:
	virtual Shape* clone() const = 0;
	virtual Shape* create() const = 0;
};
class Circle : public Shape {
public:
	Circle* clone() const;
	Circle* create() const;
};
Circle* Circle::clone() const { return new Circle(*this); };
Circle* Circle::create() const { return new Circle(); };