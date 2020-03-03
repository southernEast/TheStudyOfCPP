#include <iostream>
#include <typeinfo>
using namespace std;

/*
	函数int getVertexCount() const用来获得当前图像的顶点个数
	三个函数分别使用一下方法实现：
	（1）使用dynamic_cast实现；
	（2）使用typeid实现；
	（3）将Shape::getVertexCount声明为纯虚函数，在派生类中给出具体实现。
*/

class Shape {
public:
	/*virtual double getArea() const;
	virtual double getPerim() const;*/
	int getVertexCount1();
	int getVertexCount2();
	virtual int getVertexCount3() const = 0;
};
class Rectangle : public Shape {
public:
	Rectangle(double w = 0, double l = 0) : width(w), length(l) {}
	/*virtual double getArea() const override;
	virtual double getPerim() const override;*/
	virtual int getVertexCount3() const override;
private:
	double width, length;
};
class Circle : public Shape {
public:
	Circle(double r = 0) : radius(r) {}
	/*virtual double getArea() const override;
	virtual double getPerim() const override;*/
	virtual int getVertexCount3() const override;
private:
	static double PI;
	double radius;
};

int Shape::getVertexCount1() {
	Rectangle* ptrRec = dynamic_cast<Rectangle*>(this);	// 转换成功则指针不为空
	if (ptrRec)
		return 4;
	Circle* ptrCir = dynamic_cast<Circle*>(this);
	if (ptrCir)
		return 0;
	return 0;
}
int Shape::getVertexCount2() {
	if (typeid(*this) == typeid(Rectangle))
		return 4;
	else if (typeid(*this) == typeid(Circle))
		return 0;
	else
		return 0;
}
int Rectangle::getVertexCount3() const {
	return 4;
}
int Circle::getVertexCount3() const {
	return 0;
}

int main() {
	Shape* ptrShape;
	Rectangle r;
	Circle c;

	ptrShape = &r;
	cout << ptrShape->getVertexCount1() << endl;
	ptrShape = &c;
	cout << ptrShape->getVertexCount1() << endl << endl;

	ptrShape = &r;
	cout << ptrShape->getVertexCount2() << endl;
	ptrShape = &c;
	cout << ptrShape->getVertexCount2() << endl << endl;

	ptrShape = &r;
	cout << ptrShape->getVertexCount3() << endl;
	ptrShape = &c;
	cout << ptrShape->getVertexCount3() << endl << endl;

	return 0;
}