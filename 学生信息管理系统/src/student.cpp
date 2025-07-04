#include "student.h"
void student::display() {
	cout << "*********************************************************" << endl;
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "学号：" << id << endl;
	cout << "学院：" << academy << endl;
	cout << "专业：" << major << endl;
	cout << "班级：" << classname << endl;
	cout << "宿舍：" << dormitory << endl;
	cout << "籍贯：" << origin << endl;
	cout << "电话：" << tel << endl;
	cout << "*********************************************************" << endl;
}