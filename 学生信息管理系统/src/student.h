#pragma once
#include <iostream>
#include <string>
using namespace std;
class student {
private:
	string name;//����
	string sex;//�Ա�
	string id;//ѧ��
	string academy;//ѧԺ
	string major;//רҵ
	string classname;//�༶
	string dormitory;//����
	string origin;//����
	string tel;//�绰
public:
	student* next;
	student(string Name = "null", string Sex = "null", string Id = "null", string Academy = "null", string Major = "null", string Classname = "null",
		string Dormitory = "null", string Origin = "null", string Tel = "null",student* Next=nullptr) {
		name = Name;
		sex = Sex;
		id = Id;
		academy = Academy;
		major = Major;
		classname = Classname;
		dormitory = Dormitory;
		origin = Origin;
		tel = Tel;
		next = Next;
	}
	//����id
	string getId() { return id; }
	//��������
	string getName() { return name; }
	//�����Ա�
	string getSex() { return sex; }
	//����ѧԺ
	string getAcademy() { return academy; }
	//����רҵ
	string getMajor() { return major; }
	//���ذ༶
	string getClassname() { return classname; }
	//��������
	string getDormitory() { return dormitory; }
	//���ؼ���
	string getOrigin() { return origin; }
	//���ص绰
	string getTel() { return tel; }
	//��ӡ��ѧ������Ϣ
	void display();
	//�޸�ѧ��
	void changeId(string newId) { id = newId; }
	//�޸�����
	void changeName(string newName) { name = newName; }
	//�޸��Ա�
	void changeSex(string newSex) { sex = newSex; }
	//�޸�ѧԺ
	void changeAcademy(string newAcademy) { academy = newAcademy; }
	//�޸�רҵ
	void changeMajor(string newMajor) { major = newMajor; }
	//�޸İ༶
	void changeClassname(string newClassname) { classname = newClassname; }
	//�޸�����
	void changeDormitory(string newDormitory) { dormitory = newDormitory; }
	//�޸ļ���
	void changeOrigin(string newOrigin) { origin = newOrigin; }
	//�޸ĵ绰
	void changeTel(string newTel) { tel = newTel; }
};