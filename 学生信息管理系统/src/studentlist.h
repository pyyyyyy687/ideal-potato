#pragma once
#include "student.h"
#include <string>
#include <iomanip>

class studentlist {
private:
	static int size;//ѧ��������
	student* firstStu;//ͷһ��ѧ������λ��
public:
	//���ι���һ��ѧ������
	studentlist() :firstStu(nullptr) {}

	//ѧ�������ѧ��
	void add(student*& newStu);

	//ɾ��ָ��ѧ�ŵ�ѧ��
	void deleteById(string target);

	//ѧ��������ѧ������
	void sortById();
	//ѧ��������ѧԺ����
	void sortByAcademy();
	//ѧ����������������
	void sortByDormitory();

	//�޸�ָ��ѧ��ѧ����ѧ��
	void changeToId(string id, string newid);
	//�޸�ָ��ѧ��ѧ��������
	void changeToName(string id, string newname);
	//�޸�ָ��ѧ��ѧ�����Ա�
	void changeToSex(string id, string newsex);
	//�޸�ָ��ѧ��ѧ����ѧԺ
	void changeToAcademy(string id, string newacademy);
	//�޸�ָ��ѧ��ѧ����רҵ
	void changeToMajor(string id, string newmajor);
	//�޸�ָ��ѧ��ѧ���İ༶
	void changeToClassname(string id, string newclassname);
	//�޸�ָ��ѧ��ѧ��������
	void changeToDormitory(string id, string newdormitory);
	//�޸�ָ��ѧ��ѧ���ļ���
	void changeToOrigin(string id, string neworigin);
	//�޸�ָ��ѧ��ѧ���ĵ绰
	void changeToTel(string id, string newtel);

	//��ȡ��һ��ѧ����λ��
	student* getFirst() { return firstStu; }

	//ɾ������ѧ������
	 void deleteStudentList();

	//��student.txt��ȡ��Ϣ
	void read();

	//������д��student.txt
	void write();

	//��������λ��ѧ������Ϣ
	void change(student*& stu1, student*& stu2);

	//����ѧ�Ų���
	student* findWithId();

	//������������
	student* findWithName();

	//����ѧԺ����
	student* findWithAcademy();

	//����ϵ����
	student* findWithMajor();

	//���ݰ༶����
	student* findWithClassname();

	//�����������
	student* findWithDormitory();

	//���ݼ������
	student* findWithOrigin();

	//���ݵ绰����
	student* findWithTel();

	//����ѧԺͳ��
	void countByAcademy();

	//����ϵͳ��
	void countByMajor();

	//���ݰ༶ͳ��
	void countByClassname();

	//���ݰ༶ͳ��
	void countByOrigin();
};

class countStudent {
private:
	string content;
	int num;
public:
	countStudent(string Content="", int n = 0) :content(Content), num(n) {}
	void changeContent(string input) { content = input; }
	void changeNum() { num++; }
	string getContent() { return content; }
	void displayCount() {
		cout << setw(20) << left << content << right << setw(5) << num << "��" << endl;
	}
};