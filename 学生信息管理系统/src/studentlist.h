#pragma once
#include "student.h"
#include <string>
#include <iomanip>

class studentlist {
private:
	static int size;//学生总人数
	student* firstStu;//头一个学生保存位置
public:
	//初次构造一个学生链表
	studentlist() :firstStu(nullptr) {}

	//学生链表加学生
	void add(student*& newStu);

	//删除指定学号的学生
	void deleteById(string target);

	//学生链表按照学号排序
	void sortById();
	//学生链表按照学院排序
	void sortByAcademy();
	//学生链表按照宿舍排序
	void sortByDormitory();

	//修改指定学号学生的学号
	void changeToId(string id, string newid);
	//修改指定学号学生的姓名
	void changeToName(string id, string newname);
	//修改指定学号学生的性别
	void changeToSex(string id, string newsex);
	//修改指定学号学生的学院
	void changeToAcademy(string id, string newacademy);
	//修改指定学号学生的专业
	void changeToMajor(string id, string newmajor);
	//修改指定学号学生的班级
	void changeToClassname(string id, string newclassname);
	//修改指定学号学生的宿舍
	void changeToDormitory(string id, string newdormitory);
	//修改指定学号学生的籍贯
	void changeToOrigin(string id, string neworigin);
	//修改指定学号学生的电话
	void changeToTel(string id, string newtel);

	//获取第一个学生的位置
	student* getFirst() { return firstStu; }

	//删除整个学生链表
	 void deleteStudentList();

	//从student.txt读取信息
	void read();

	//将链表写入student.txt
	void write();

	//交换两个位置学生的信息
	void change(student*& stu1, student*& stu2);

	//根据学号查找
	student* findWithId();

	//根据姓名查找
	student* findWithName();

	//根据学院查找
	student* findWithAcademy();

	//根据系查找
	student* findWithMajor();

	//根据班级查找
	student* findWithClassname();

	//根据宿舍查找
	student* findWithDormitory();

	//根据籍贯查找
	student* findWithOrigin();

	//根据电话查找
	student* findWithTel();

	//根据学院统计
	void countByAcademy();

	//根据系统计
	void countByMajor();

	//根据班级统计
	void countByClassname();

	//根据班级统计
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
		cout << setw(20) << left << content << right << setw(5) << num << "人" << endl;
	}
};