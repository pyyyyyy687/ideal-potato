#pragma once
#include "student.h"
#include "studentlist.h"
class manager{
private:
	string maccount;
	string mpassword;
public:
	manager* next;

	//����manager
	manager(string Maccount,string Mpassword, manager* Next = nullptr) : maccount(Maccount),mpassword(Mpassword),next(next){}
	//��������
	string getAccount() { return maccount; }
	//��������
	string getPassword() { return mpassword; }
	//�޸�����
	void changePassword(string newPassword) { mpassword = newPassword; }
	//��
	void madd(studentlist*& stl);
	//ɾ
	void mdelete(studentlist*& stl);
	//��
	void mchange(studentlist*& stl,string id,int n);
	//����ѧ������
	void msortById(studentlist*& stl);
	//����ѧԺ����
	void msortByAcademy(studentlist*& stl);
	//������������
	void msortByDormitory(studentlist*& stl);
};