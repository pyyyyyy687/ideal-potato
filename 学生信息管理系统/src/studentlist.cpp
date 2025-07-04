#include "studentlist.h"
#include <fstream>
#include <string>
int studentlist::size = 0;

void studentlist::add(student*& newStu) {
	if (firstStu == nullptr) {
		firstStu = newStu;
	}
	else {
		student* p = firstStu;
		while (p->next)p = p->next;
		p->next = newStu;
	}
	size++;
}
void studentlist::deleteById(string target) {
	student* p = firstStu;
	student* pre = nullptr;
	while (p) {
		if (p->getId() == target && pre==nullptr) {
			firstStu = firstStu->next;
			delete p;
			break;
		}
		else if (p->getId() == target && pre!=nullptr) {
			pre->next = p->next;
			delete p;
			break;
		}
		pre = p;
		p = p->next;
	}
	size--;
}

//修改指定学号学生的学号
void studentlist::changeToId(string id, string newid) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeId(newid);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的姓名
void studentlist::changeToName(string id, string newname) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeName(newname);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的性别
void studentlist::changeToSex(string id, string newsex) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeSex(newsex);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的学院
void studentlist::changeToAcademy(string id, string newacademy) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeAcademy(newacademy);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的专业
void studentlist::changeToMajor(string id, string newmajor) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeMajor(newmajor);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的班级
void studentlist::changeToClassname(string id, string newclassname) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeClassname(newclassname);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的宿舍
void studentlist::changeToDormitory(string id, string newdormitory) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeDormitory(newdormitory);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的籍贯
void studentlist::changeToOrigin(string id, string neworigin) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeOrigin(neworigin);
			break;
		}
		p = p->next;
	}
}
//修改指定学号学生的电话
void studentlist::changeToTel(string id, string newtel) {
	student* p = firstStu;
	while (p) {
		if (p->getId() == id) {
			p->changeTel(newtel);
			break;
		}
		p = p->next;
	}
}
void studentlist::change(student*& stu1, student*& stu2) {
	string temp;
	temp = stu1->getId();
	stu1->changeId(stu2->getId());
	stu2->changeId(temp);

	temp = stu1->getName();
	stu1->changeName(stu2->getName());
	stu2->changeName(temp);

	temp = stu1->getSex();
	stu1->changeSex(stu2->getSex());
	stu2->changeSex(temp);

	temp = stu1->getAcademy();
	stu1->changeAcademy(stu2->getAcademy());
	stu2->changeAcademy(temp);

	temp = stu1->getMajor();
	stu1->changeMajor(stu2->getMajor());
	stu2->changeMajor(temp);

	temp = stu1->getClassname();
	stu1->changeClassname(stu2->getClassname());
	stu2->changeClassname(temp);

	temp = stu1->getDormitory();
	stu1->changeDormitory(stu2->getDormitory());
	stu2->changeDormitory(temp);

	temp = stu1->getOrigin();
	stu1->changeOrigin(stu2->getOrigin());
	stu2->changeOrigin(temp);

	temp = stu1->getTel();
	stu1->changeTel(stu2->getTel());
	stu2->changeTel(temp);
}
//学生链表按照学号排序
void studentlist::sortById() {
	student* p = firstStu;
	while (p) {
		student* q = p;
		student* min = p;
		while (q) {
			if (q->getId() < min->getId()) min = q;
			q = q->next;
		}
		change(p, min);
		p = p->next;
	}
}

//学生链表按照学院排序
void studentlist::sortByAcademy() {
	student* p = firstStu;
	while (p) {
		student* q = p;
		student* min = p;
		while (q) {
			if (q->getAcademy() < min->getAcademy()) min = q;
			q = q->next;
		}
		change(p, min);
		p = p->next;
	}
}

//学生链表按照宿舍排序
void studentlist::sortByDormitory() {
	student* p = firstStu;
	while (p) {
		student* q = p;
		student* min = p;
		while (q) {
			if (q->getDormitory() < min->getDormitory()) min = q;
			q = q->next;
		}
		change(p, min);
		p = p->next;
	}
}

void studentlist::deleteStudentList() {
	student* p = firstStu;
	while (firstStu) {
		firstStu = firstStu->next;
		delete p;
		p = firstStu;
	}
	size = 0;
}
void studentlist::read() {
	ifstream instudent("../test/data/student.txt", ios::in);
	string name, sex, id, academy, major, classname, dormitory, origin, tel;
	if (firstStu != nullptr) deleteStudentList();
	while (instudent >> name >> sex >> id >> academy >> major >> classname >> dormitory >> origin >> tel) {
		student* stu = new student(name, sex, id, academy, major, classname, dormitory, origin, tel);
		add(stu);
	}
}

void studentlist::write() {
	ofstream outfile("../test/data/student.txt", ios::out);
	student* p = firstStu;
	while (p) {
		outfile << p->getName() << ' ' << p->getSex() << ' ' << p->getId() << ' ' << p->getAcademy() << ' ' << p->getMajor()
			<< ' ' << p->getClassname() << ' ' << p->getDormitory() << ' ' << p->getOrigin() << ' ' << p->getTel() << endl;
		p = p->next;
	}
	cin.get();
	cout << "保存成功！请按任意键退出" << endl;
	cin.get();
}


student* studentlist::findWithId() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的学号：(输入-1退出) ";
		string id;
		cin >> id;
		cin.get();
		if (id == "-1") return nullptr;

		while (p) {
			if (p->getId().find(id) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithName() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的姓名：(输入-1退出) ";
		string name;
		cin >> name;
		cin.get();
		if (name == "-1") return nullptr;

		while (p) {
			if (p->getName().find(name) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithAcademy() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的学院：(输入-1退出) ";
		string academy;
		cin >> academy;
		cin.get();
		if (academy == "-1") return nullptr;

		while (p) {
			/*cout << findString(academy, p->getAcademy());*/
			if (p->getAcademy().find(academy) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithMajor() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的专业：(输入-1退出) ";
		string major;
		cin >> major;
		cin.get();
		if (major == "-1") return nullptr;

		while (p) {
			if (p->getMajor().find(major) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithClassname() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的班级：(输入-1退出) ";
		string classname;
		cin >> classname;
		cin.get();
		if (classname == "-1") return nullptr;

		while (p) {
			if (p->getClassname().find(classname) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithDormitory() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的宿舍：(输入-1退出) ";
		string dormitory;
		cin >> dormitory;
		cin.get();
		if (dormitory == "-1") return nullptr;

		while (p) {
			if (p->getDormitory().find(dormitory) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

student* studentlist::findWithOrigin() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的籍贯：(输入-1退出) ";
		string origin;
		cin >> origin;
		cin.get();
		if (origin == "-1") return nullptr;

		while (p) {
			if (p->getOrigin().find(origin) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}
student* studentlist::findWithTel() {
	int flag = 0;
	student* p = firstStu;
	do {
		cout << "请输入要查询的学生的电话：(输入-1退出) ";
		string tel;
		cin >> tel;
		cin.get();
		if (tel == "-1") return nullptr;

		while (p) {
			if (p->getTel().find(tel) != string::npos) {
				p->display();
				flag = 1;
			}
			p = p->next;
		}
		if (flag == 0 && p == nullptr) {
			cout << "不存在该学生！请重新输入" << endl;
		}
	} while (flag == 0);

	cout << "按任意键返回" << endl;
	cin.get();
	return p;
}

void studentlist::countByAcademy() {
	int len = 0;
	countStudent array[200];
	student* p = firstStu;
	int i;
	while (p) {
		for (i = 0; i < len; i++) {
			if (p->getAcademy() == array[i].getContent()) {
				array[i].changeNum();
				break;
			}
		}
		if (i == len) {
			array[len].changeContent(p->getAcademy());
			array[len].changeNum();
			len++;
		}
		p = p->next;
	}
	cout << "*********************************************************" << endl;
	for (int i = 0; i < len; i++) {
		array[i].displayCount();
	}
	cout << "*********************************************************" << endl;
	cin.get();
	cout << "请输入任意键退出" << endl;
	cin.get();
}

void studentlist::countByMajor() {
	int len = 0;
	countStudent array[200];
	student* p = firstStu;
	while (p) {
		int i;
		for (i = 0; i < len; i++) {
			if (p->getMajor() == array[i].getContent()) {
				array[i].changeNum();
				break;
			}
		}
		if (i == len) {
			array[len].changeContent(p->getMajor());
			array[len].changeNum();
			len++;
		}
		p = p->next;
	}
	cout << "*********************************************************" << endl;
	for (int i = 0; i < len; i++) {
		array[i].displayCount();
	}
	cout << "*********************************************************" << endl;
	cin.get();
	cout << "请输入任意键退出" << endl;
	cin.get();
}

void studentlist::countByClassname() {
	int len = 0;
	countStudent array[200];
	student* p = firstStu;
	while (p) {
		int i;
		for (i = 0; i < len; i++) {
			if (p->getClassname() == array[i].getContent()) {
				array[i].changeNum();
				break;
			}
		}
		if (i == len) {
			array[len].changeContent(p->getClassname());
			array[len].changeNum();
			len++;
		}
		p = p->next;
	}
	cout << "*********************************************************" << endl;
	for (int i = 0; i < len; i++) {
		array[i].displayCount();
	}
	cout << "*********************************************************" << endl;
	cin.get();
	cout << "请输入任意键退出" << endl;
	cin.get();
}

void studentlist::countByOrigin() {
	int len = 0;
	countStudent array[200];
	student* p = firstStu;
	while (p) {
		int i;
		for (i = 0; i < len; i++) {
			if (p->getOrigin() == array[i].getContent()) {
				array[i].changeNum();
				break;
			}
		}
		if (i == len) {
			array[len].changeContent(p->getOrigin());
			array[len].changeNum();
			len++;
		}
		p = p->next;
	}
	cout << "*********************************************************" << endl;
	for (int i = 0; i < len; i++) {
		array[i].displayCount();
	}
	cout << "*********************************************************" << endl;
	cin.get();
	cout << "请输入任意键退出" << endl;
	cin.get();
}