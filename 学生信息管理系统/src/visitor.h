#pragma once

#include <string>
#include "studentlist.h"

class visitor {
private:
	string vaccount;
	string vpassword;
public:
	visitor* next;
	visitor(string Account="",string Password=""):vaccount(Account),vpassword(Password),next(nullptr){}
	//��ȡ����
	string getAccount() { return vaccount; }
	//��ȡ����
	string getPassword() { return vpassword; }
	//�޸�����
	void changePassword(string newPassword) { vpassword = newPassword; }
	//������ʾѧ����Ϣ
	void askToDisplay(studentlist*& stl);
};