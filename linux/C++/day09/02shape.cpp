#include <iostream>
using namespace std;

class Shape{
public:
	Shape(int x,int y):m_x(x),m_y(y){}
	virtual void draw(void) = 0;//纯虚函数
	/*virtual void draw(void){
		cout << "图形:" << m_x << ',' << m_y
			<< endl;
	}*/
protected:
	int m_x;
	int m_y;
};
class Rect:public Shape{
public:
	Rect(int x,int y,int w,int h):
		Shape(x,y),m_w(w),m_h(h){}
	void draw(void){
		cout << "矩形:" << m_x << ',' << m_y
		   << ',' << m_w << ','<< m_h << endl;
	}
private:
	int m_w;
	int m_h;
};
class Circle:public Shape{
public:
	Circle(int x,int y,int r):
		Shape(x,y),m_r(r){}
	void draw(void){
		cout << "圆形:" << m_x << ',' << m_y
			<< ',' << m_r << endl;
	}
private:
	int m_r;
};
class Triangle:public Shape{};

void render(Shape* shapes[]){
	for(int i=0;shapes[i];++i){
		shapes[i]->draw();
	}
}
int main(void)
{
	Shape* shapes[256]={NULL};//指针数组,即数组的每个元素都是指针
	shapes[0]=new Rect(1,2,3,4);
	shapes[1]=new Rect(5,6,7,8);
	shapes[2]=new Circle(10,10,15);
	shapes[3]=new Circle(12,12,5);
	shapes[4]=new Rect(11,12,13,14);
	render(shapes);

	//Shape* p = new Shape(0,0);
	//Triangle t;
	return 0;
}








