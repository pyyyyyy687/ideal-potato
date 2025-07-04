#include "manager.h"
void manager::madd(studentlist*& stl) {
	string name, sex, id, academy, major, classname, dormitory, origin, tel;
	cout << "请输入要增加的学生信息：" << endl;
	cout << "姓名：";
	cin >> name;
	cout << "性别：";
	cin >> sex;
	cout << "学号：";
	cin >> id;
	cout << "学院：";
	cin >> academy;
	cout << "专业：";
	cin >> major;
	cout << "班级：";
	cin >> classname;
	cout << "宿舍：";
	cin >> dormitory;
	cout << "籍贯：";
	cin >> origin;
	cout << "电话：";
	cin >> tel;
	student* stu = new student(name, sex, id, academy, major, classname, dormitory, origin, tel);
	cout << "是否需要保存？是请按1，否请按任意键 ";
	char c;
	cin.get();
	cin.get(c);
	if (c == '1') {
		stl->add(stu);
		stl->write();//修改之后的信息写入文件
	}
}

void manager::mdelete(studentlist*& stl) {
	string id;
	cout << "请输入要删除的学生学号：";
	cin >> id;
	cout << "是否需要保存？是请按1，否请按任意键 ";
	char c;
	cin.get();
	cin.get(c);
	if (c == '1') {
		stl->deleteById(id);
		stl->write();//修改之后的信息写入文件
	}
}

void manager::mchange(studentlist*& stl, string id, int n) {
	if (n == 1) {
		cout << "请输入新的学号：";
		string newid;
		cin >> newid;
		cout << "是否需要保存？是请按1，否请按任意键";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToId(id, newid);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 2) {
		cout << "请输入新的姓名：";
		string newname;
		cin >> newname;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToName(id, newname);
			stl->write();//修改之后的信息写入文件
		}
		
	}
	else if (n == 3) {
		cout << "请输入新的性别：";
		string newsex;
		cin >> newsex;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToSex(id, newsex);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 4) {
		cout << "请输入新的学院：";
		string newacademy;
		cin >> newacademy;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToAcademy(id, newacademy);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 5) {
		cout << "请输入新的专业：";
		string newmajor;
		cin >> newmajor;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToMajor(id, newmajor);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 6) {
		cout << "请输入新的班级：";
		string newclassname;
		cin >> newclassname;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToClassname(id, newclassname);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 7) {
		cout << "请输入新的宿舍：";
		string newdormitory;
		cin >> newdormitory;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToDormitory(id, newdormitory);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 8) {
		cout << "请输入新的籍贯：";
		string neworigin;
		cin >> neworigin;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToOrigin(id, neworigin);
			stl->write();//修改之后的信息写入文件
		}
	}
	else if (n == 9) {
		cout << "请输入新的电话：";
		string newtel;
		cin >> newtel;
		cout << "是否需要保存？是请按1，否请按任意键 ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToTel(id, newtel);
			stl->write();//修改之后的信息写入文件
		}
	}
}
void manager::msortById(studentlist*& stl) {
	stl->sortById();
}
void manager::msortByAcademy(studentlist*& stl) {
	stl->sortByAcademy();
}
void manager::msortByDormitory(studentlist*& stl) {
	stl->sortByDormitory();
}