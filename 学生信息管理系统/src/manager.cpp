#include "manager.h"
void manager::madd(studentlist*& stl) {
	string name, sex, id, academy, major, classname, dormitory, origin, tel;
	cout << "������Ҫ���ӵ�ѧ����Ϣ��" << endl;
	cout << "������";
	cin >> name;
	cout << "�Ա�";
	cin >> sex;
	cout << "ѧ�ţ�";
	cin >> id;
	cout << "ѧԺ��";
	cin >> academy;
	cout << "רҵ��";
	cin >> major;
	cout << "�༶��";
	cin >> classname;
	cout << "���᣺";
	cin >> dormitory;
	cout << "���᣺";
	cin >> origin;
	cout << "�绰��";
	cin >> tel;
	student* stu = new student(name, sex, id, academy, major, classname, dormitory, origin, tel);
	cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
	char c;
	cin.get();
	cin.get(c);
	if (c == '1') {
		stl->add(stu);
		stl->write();//�޸�֮�����Ϣд���ļ�
	}
}

void manager::mdelete(studentlist*& stl) {
	string id;
	cout << "������Ҫɾ����ѧ��ѧ�ţ�";
	cin >> id;
	cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
	char c;
	cin.get();
	cin.get(c);
	if (c == '1') {
		stl->deleteById(id);
		stl->write();//�޸�֮�����Ϣд���ļ�
	}
}

void manager::mchange(studentlist*& stl, string id, int n) {
	if (n == 1) {
		cout << "�������µ�ѧ�ţ�";
		string newid;
		cin >> newid;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴�����";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToId(id, newid);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 2) {
		cout << "�������µ�������";
		string newname;
		cin >> newname;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToName(id, newname);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
		
	}
	else if (n == 3) {
		cout << "�������µ��Ա�";
		string newsex;
		cin >> newsex;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToSex(id, newsex);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 4) {
		cout << "�������µ�ѧԺ��";
		string newacademy;
		cin >> newacademy;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToAcademy(id, newacademy);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 5) {
		cout << "�������µ�רҵ��";
		string newmajor;
		cin >> newmajor;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToMajor(id, newmajor);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 6) {
		cout << "�������µİ༶��";
		string newclassname;
		cin >> newclassname;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToClassname(id, newclassname);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 7) {
		cout << "�������µ����᣺";
		string newdormitory;
		cin >> newdormitory;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToDormitory(id, newdormitory);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 8) {
		cout << "�������µļ��᣺";
		string neworigin;
		cin >> neworigin;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToOrigin(id, neworigin);
			stl->write();//�޸�֮�����Ϣд���ļ�
		}
	}
	else if (n == 9) {
		cout << "�������µĵ绰��";
		string newtel;
		cin >> newtel;
		cout << "�Ƿ���Ҫ���棿���밴1�����밴����� ";
		char c;
		cin.get();
		cin.get(c);
		if (c == '1') {
			stl->changeToTel(id, newtel);
			stl->write();//�޸�֮�����Ϣд���ļ�
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