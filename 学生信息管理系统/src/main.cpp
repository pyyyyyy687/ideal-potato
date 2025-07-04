#include "studentlist.h"
#include "managerlist.h"
#include "visitorlist.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	studentlist* stulist = new studentlist;
	managerlist* manlist = new managerlist;
	visitorlist* vislist = new visitorlist;
	stulist->read();
	manlist->read();
	vislist->read();
	int i = 0, j = 0, k = 0;
	while (i != -1) {
		j = 0;
		cout << "---------------------------------------------------------" << endl;
		cout << "|             欢迎进入学生信息管理系统                  |" << endl;
		cout << "|             1.查询学生信息                            |" << endl;
		cout << "|             2.登录                                    |" << endl;
		cout << "|                                版权所有 侵权必究      |" << endl;
		cout << "|             请选择（1/2,-1为结束）:                   |" << endl;
		cout << "---------------------------------------------------------" << endl;
		do {
			cin >> i;
			if (i != 1 && i != 2 && i != -1) {
				cout << "warning：请输入正确的选项！" << endl;
			}
		} while (i != 1 && i != 2 && i != -1);
		if (i == 1) {
			while (j != -1) {
				k = 0;
				cout << "----------------------学生信息查询-----------------------" << endl;
				cout << "|             1.查询学生个人信息                        |" << endl;
				cout << "|             2.查询学生统计信息                        |" << endl;
				cout << "|             请选择（1/2,-1为返回上一层）:             |" << endl;
				cout << "---------------------------------------------------------" << endl;
				do {
					cin >> j;
					if (j != 1 && j != 2 && j != -1) {
						cout << "warning：请输入正确的选项！" << endl;
					}
				} while (j != 1 && j != 2 && j != -1);
				if (j == 1) {
					while (k != -1) {
						cout << "--------------------学生个人信息查询---------------------" << endl;
						cout << "|             1.根据学号查询                            |" << endl;
						cout << "|             2.根据姓名查询                            |" << endl;
						cout << "|             3.根据学院查询                            |" << endl;
						cout << "|             4.根据系查询                              |" << endl;
						cout << "|             5.根据班级查询                            |" << endl;
						cout << "|             6.根据宿舍查询                            |" << endl;
						cout << "|             7.根据籍贯查询                            |" << endl;
						cout << "|             8.根据电话查询                            |" << endl;
						cout << "|             请选择（1-8,-1为返回上一层）:             |" << endl;
						cout << "---------------------------------------------------------" << endl;
						do {
							cin >> k;
							if ((!(k >= 1 && k <= 8)) && k != -1) {
								cout << "warning：请输入正确的选项！" << endl;
							}
						} while ((!(k >= 1 && k <= 8)) && k != -1);


						if (k == 1) stulist->findWithId();

						else if (k == 2) stulist->findWithName();

						else if (k == 3) stulist->findWithAcademy();

						else if (k == 4) stulist->findWithMajor();

						else if (k == 5) stulist->findWithClassname();

						else if (k == 6) stulist->findWithDormitory();

						else if (k == 7) stulist->findWithOrigin();

						else if (k == 8) stulist->findWithTel();

					}
				}
				else if (j == 2) {
					while (k != -1) {
						cout << "--------------------学生统计信息查询---------------------" << endl;
						cout << "|             1.根据学院统计                            |" << endl;
						cout << "|             2.根据专业统计                            |" << endl;
						cout << "|             3.根据班级统计                            |" << endl;
						cout << "|             4.根据籍贯统计                            |" << endl;
						cout << "|             请选择（1-4,-1为结束）:                   |" << endl;
						cout << "---------------------------------------------------------" << endl;
						do {
							cin >> k;
							if (k != 1 && k != 2 && k != 3 && k != 4 && k != -1) {
								cout << "warning：请输入正确的选项！" << endl;
							}
						} while (k != 1 && k != 2 && k != 3 && k != 4 && k != -1);

						if (k == 1) {
							stulist->countByAcademy();
						}
						else if (k == 2) {
							stulist->countByMajor();
						}
						else if (k == 3) {
							stulist->countByClassname();
						}
						else if (k == 4) {
							stulist->countByOrigin();
						}
					}
				}
			}
		}
		else if (i == 2) {
			while (j != -1) {
				k = 0;
				cout << "--------------------------登录---------------------------" << endl;
				cout << "|             1.学生登录                                |" << endl;
				cout << "|             2.管理员登录                              |" << endl;
				cout << "|             请选择（1/2,-1为返回上一层）:             |" << endl;
				cout << "---------------------------------------------------------" << endl;
				do {
					cin >> j;
					if (j != 1 && j != 2 && j != -1) {
						cout << "warning：请输入正确的选项！" << endl;
					}
				} while (j != 1 && j != 2 && j != -1);
				if (j == 1) {
					int flag = 0;
					do {
						cout << "用户名：(输入-1退出) ";
						string acc;
						cin >> acc;
						if (acc == "-1") { j = 0; break; }//可以输入账号密码的时候退出
						cout << "密码：(输入-1退出) ";
						string pas;
						cin >> pas;
						if (pas == "-1") { j = 0; break; }//可以输入账号密码的时候退出

						visitor example(acc, pas);
						visitor* now;

						if (!vislist->find(example, now)) {
							cout << "用户名或密码错误! 请重新输入" << endl;
						}
						else {
							flag = 1;
							int total = 0;
							while (k != -1) {
								//第一次登陆成功时候显示欢迎语句

								if (total == 0) {
									cout << "登录成功！欢迎你" << example.getAccount() << endl;
									total = 1;
								}

								cout << "------------------------学生登录-------------------------" << endl;
								cout << "|             1.显示学生信息                            |" << endl;
								cout << "|             2.修改密码                                |" << endl;
								cout << "|             请选择（1/2,-1为返回上一层）:             |" << endl;
								cout << "---------------------------------------------------------" << endl;

								do {
									cin >> k;
									if (k != 1 && k != 2 && k != -1) {
										cout << "warning：请输入正确的选项！" << endl;
									}
								} while (k != 1 && k != 2 && k != -1);

								if (k == 1) {
									now->askToDisplay(stulist);
								}
								else if (k == 2) {
									int flag = 0;
									string newpas1, newpas2;
									do {
										cout << "请输入新密码：(输入-1退出) ";
										cin >> newpas1;
										if (newpas1 == "-1") break;

										cout << "请再输入一遍：(输入-1退出) ";
										cin >> newpas2;
										if (newpas1 == "-1") break;

										if (newpas1 != newpas2) {
											cout << "两次输入密码不同！请重新输入" << endl;
										}
										else {
											if (newpas1 == now->getPassword()) {
												cout << "新密码与原密码相同！请重新输入" << endl;
											}
											else {
												now->changePassword(newpas1);
												//cout << "密码修改成功！" << endl;
												vislist->write();
												flag = 1;
											}
										}
									} while (flag == 0);

								}

							}
						}
					} while (flag == 0);

				}

				else if (j == 2) {
					int flag = 0;
					do {
						cout << "用户名：(输入-1退出) ";
						string acc;
						cin >> acc;
						if (acc == "-1") { j = 0; break; }//可以输入账号密码的时候退出
						cout << "密码：(输入-1退出) ";
						string pas;
						cin >> pas;
						if (pas == "-1") { j = 0; break; }//可以输入账号密码的时候退出

						manager* now;
						manager example(acc, pas);
						if (!manlist->find(example, now)) {
							cout << "用户名或密码错误! 请重新输入" << endl;
						}
						else {
							flag = 1;
							int total = 0;
							while (k != -1) {
								//第一次登陆成功时候显示欢迎语句
								if (total == 0) {
									cout << "登录成功！欢迎你" << example.getAccount() << endl;
									total++;
								}

								cout << "-----------------------管理员登录------------------------" << endl;
								cout << "|             1.增加学生信息                            |" << endl;
								cout << "|             2.删除学生信息                            |" << endl;
								cout << "|             3.修改学生信息                            |" << endl;
								cout << "|             4.学生信息排序                            |" << endl;
								cout << "|             5.修改密码                                |" << endl;
								cout << "|             请选择（1-5,-1为返回上一层）:             |" << endl;
								cout << "---------------------------------------------------------" << endl;

								do {
									cin >> k;
									if (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != -1) {
										cout << "warning：请输入正确的选项！" << endl;
									}
								} while (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != -1);

								if (k == 1) {
									now->madd(stulist);
								}
								else if (k == 2) {
									now->mdelete(stulist);
								}
								else if (k == 3) {
									int t = 0;
									while (t != -1) {
										cout << "----------------------学生信息修改-----------------------" << endl;
										cout << "|             1.修改学号                                |" << endl;
										cout << "|             2.修改姓名                                |" << endl;
										cout << "|             3.修改性别                                |" << endl;
										cout << "|             4.修改学院                                |" << endl;
										cout << "|             5.修改专业                                |" << endl;
										cout << "|             6.修改班级                                |" << endl;
										cout << "|             7.修改宿舍                                |" << endl;
										cout << "|             8.修改籍贯                                |" << endl;
										cout << "|             9.修改电话                                |" << endl;
										cout << "|             请选择（1-9,-1为返回上一层）:             |" << endl;
										cout << "---------------------------------------------------------" << endl;

										do {
											cin >> t;
											if ((!(t >= 1 && t <= 9)) && t != -1) {
												cout << "请输入正确的选项！" << endl;
											}
										} while ((!(t >= 1 && t <= 9)) && t != -1);

										if (t == 1) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id;
											now->mchange(stulist, id, 1);
										}
										else if (t == 2) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id;
											now->mchange(stulist, id, 2);
										}
										else if (t == 3) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 3);
										}
										else if (t == 4) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 4);
										}
										else if (t == 5) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 5);
										}
										else if (t == 6) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 6);
										}
										else if (t == 7) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 7);
										}
										else if (t == 8) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 8);
										}
										else if (t == 9) {
											cout << "请输入要修改信息的学生的学号：";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 9);
										}
									}
								}
								else if (k == 4) {
									int t = 0;
									while (t != -1) {
										cout << "----------------------学生信息排序-----------------------" << endl;
										cout << "|             1.按照学号排序                            |" << endl;
										cout << "|             2.按照学院排序                            |" << endl;
										cout << "|             3.按照宿舍排序                            |" << endl;
										cout << "|             请选择（1-9,-1为返回上一层）:             |" << endl;
										cout << "---------------------------------------------------------" << endl;

										do {
											cin >> t;
											if (t != 1 && t != 2 && t != 3 && t != -1) {
												cout << "请输入正确的选项！";
											}
										} while (t != 1 && t != 2 && t != 3 && t != -1);

										if (t == 1) {
											now->msortById(stulist);
										}
										else if (t == 2) {
											now->msortByAcademy(stulist);
										}
										else if (t == 3) {
											now->msortByDormitory(stulist);
										}
										stulist->write();//修改之后的信息写入文件
									}

								}
								else if (k == 5) {
									int flag = 0;
									string newpas1, newpas2;
									do {
										cout << "请输入新密码：(输入-1退出) ";
										cin >> newpas1;
										if (newpas1 == "-1") break;

										cout << "请再输入一遍：(输入-1退出) ";
										cin >> newpas2;
										if (newpas1 == "-1") break;

										if (newpas1 != newpas2) {
											cout << "两次输入密码不同！请重新输入" << endl;
										}
										else {
											if (newpas1 == now->getPassword()) {
												cout << "新密码与原密码相同！请重新输入" << endl;
											}
											else {
												now->changePassword(newpas1);
												//cout << "密码修改成功！" << endl;
												manlist->write();
												flag = 1;
											}
										}
									} while (flag == 0);
								}
							}

						}
					} while (flag == 0);
				}
			}
		}
		else if (i == -1) {
			cout << "------------------------感谢使用-------------------------" << endl;
		}
	}

	stulist->deleteStudentList();
	manlist->deleteManagerList();
	vislist->deleteVisitorList();
	delete stulist;
	delete manlist;
	delete vislist;

	return 0;
}