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
		cout << "|             ��ӭ����ѧ����Ϣ����ϵͳ                  |" << endl;
		cout << "|             1.��ѯѧ����Ϣ                            |" << endl;
		cout << "|             2.��¼                                    |" << endl;
		cout << "|                                ��Ȩ���� ��Ȩ�ؾ�      |" << endl;
		cout << "|             ��ѡ��1/2,-1Ϊ������:                   |" << endl;
		cout << "---------------------------------------------------------" << endl;
		do {
			cin >> i;
			if (i != 1 && i != 2 && i != -1) {
				cout << "warning����������ȷ��ѡ�" << endl;
			}
		} while (i != 1 && i != 2 && i != -1);
		if (i == 1) {
			while (j != -1) {
				k = 0;
				cout << "----------------------ѧ����Ϣ��ѯ-----------------------" << endl;
				cout << "|             1.��ѯѧ��������Ϣ                        |" << endl;
				cout << "|             2.��ѯѧ��ͳ����Ϣ                        |" << endl;
				cout << "|             ��ѡ��1/2,-1Ϊ������һ�㣩:             |" << endl;
				cout << "---------------------------------------------------------" << endl;
				do {
					cin >> j;
					if (j != 1 && j != 2 && j != -1) {
						cout << "warning����������ȷ��ѡ�" << endl;
					}
				} while (j != 1 && j != 2 && j != -1);
				if (j == 1) {
					while (k != -1) {
						cout << "--------------------ѧ��������Ϣ��ѯ---------------------" << endl;
						cout << "|             1.����ѧ�Ų�ѯ                            |" << endl;
						cout << "|             2.����������ѯ                            |" << endl;
						cout << "|             3.����ѧԺ��ѯ                            |" << endl;
						cout << "|             4.����ϵ��ѯ                              |" << endl;
						cout << "|             5.���ݰ༶��ѯ                            |" << endl;
						cout << "|             6.���������ѯ                            |" << endl;
						cout << "|             7.���ݼ����ѯ                            |" << endl;
						cout << "|             8.���ݵ绰��ѯ                            |" << endl;
						cout << "|             ��ѡ��1-8,-1Ϊ������һ�㣩:             |" << endl;
						cout << "---------------------------------------------------------" << endl;
						do {
							cin >> k;
							if ((!(k >= 1 && k <= 8)) && k != -1) {
								cout << "warning����������ȷ��ѡ�" << endl;
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
						cout << "--------------------ѧ��ͳ����Ϣ��ѯ---------------------" << endl;
						cout << "|             1.����ѧԺͳ��                            |" << endl;
						cout << "|             2.����רҵͳ��                            |" << endl;
						cout << "|             3.���ݰ༶ͳ��                            |" << endl;
						cout << "|             4.���ݼ���ͳ��                            |" << endl;
						cout << "|             ��ѡ��1-4,-1Ϊ������:                   |" << endl;
						cout << "---------------------------------------------------------" << endl;
						do {
							cin >> k;
							if (k != 1 && k != 2 && k != 3 && k != 4 && k != -1) {
								cout << "warning����������ȷ��ѡ�" << endl;
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
				cout << "--------------------------��¼---------------------------" << endl;
				cout << "|             1.ѧ����¼                                |" << endl;
				cout << "|             2.����Ա��¼                              |" << endl;
				cout << "|             ��ѡ��1/2,-1Ϊ������һ�㣩:             |" << endl;
				cout << "---------------------------------------------------------" << endl;
				do {
					cin >> j;
					if (j != 1 && j != 2 && j != -1) {
						cout << "warning����������ȷ��ѡ�" << endl;
					}
				} while (j != 1 && j != 2 && j != -1);
				if (j == 1) {
					int flag = 0;
					do {
						cout << "�û�����(����-1�˳�) ";
						string acc;
						cin >> acc;
						if (acc == "-1") { j = 0; break; }//���������˺������ʱ���˳�
						cout << "���룺(����-1�˳�) ";
						string pas;
						cin >> pas;
						if (pas == "-1") { j = 0; break; }//���������˺������ʱ���˳�

						visitor example(acc, pas);
						visitor* now;

						if (!vislist->find(example, now)) {
							cout << "�û������������! ����������" << endl;
						}
						else {
							flag = 1;
							int total = 0;
							while (k != -1) {
								//��һ�ε�½�ɹ�ʱ����ʾ��ӭ���

								if (total == 0) {
									cout << "��¼�ɹ�����ӭ��" << example.getAccount() << endl;
									total = 1;
								}

								cout << "------------------------ѧ����¼-------------------------" << endl;
								cout << "|             1.��ʾѧ����Ϣ                            |" << endl;
								cout << "|             2.�޸�����                                |" << endl;
								cout << "|             ��ѡ��1/2,-1Ϊ������һ�㣩:             |" << endl;
								cout << "---------------------------------------------------------" << endl;

								do {
									cin >> k;
									if (k != 1 && k != 2 && k != -1) {
										cout << "warning����������ȷ��ѡ�" << endl;
									}
								} while (k != 1 && k != 2 && k != -1);

								if (k == 1) {
									now->askToDisplay(stulist);
								}
								else if (k == 2) {
									int flag = 0;
									string newpas1, newpas2;
									do {
										cout << "�����������룺(����-1�˳�) ";
										cin >> newpas1;
										if (newpas1 == "-1") break;

										cout << "��������һ�飺(����-1�˳�) ";
										cin >> newpas2;
										if (newpas1 == "-1") break;

										if (newpas1 != newpas2) {
											cout << "�����������벻ͬ������������" << endl;
										}
										else {
											if (newpas1 == now->getPassword()) {
												cout << "��������ԭ������ͬ������������" << endl;
											}
											else {
												now->changePassword(newpas1);
												//cout << "�����޸ĳɹ���" << endl;
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
						cout << "�û�����(����-1�˳�) ";
						string acc;
						cin >> acc;
						if (acc == "-1") { j = 0; break; }//���������˺������ʱ���˳�
						cout << "���룺(����-1�˳�) ";
						string pas;
						cin >> pas;
						if (pas == "-1") { j = 0; break; }//���������˺������ʱ���˳�

						manager* now;
						manager example(acc, pas);
						if (!manlist->find(example, now)) {
							cout << "�û������������! ����������" << endl;
						}
						else {
							flag = 1;
							int total = 0;
							while (k != -1) {
								//��һ�ε�½�ɹ�ʱ����ʾ��ӭ���
								if (total == 0) {
									cout << "��¼�ɹ�����ӭ��" << example.getAccount() << endl;
									total++;
								}

								cout << "-----------------------����Ա��¼------------------------" << endl;
								cout << "|             1.����ѧ����Ϣ                            |" << endl;
								cout << "|             2.ɾ��ѧ����Ϣ                            |" << endl;
								cout << "|             3.�޸�ѧ����Ϣ                            |" << endl;
								cout << "|             4.ѧ����Ϣ����                            |" << endl;
								cout << "|             5.�޸�����                                |" << endl;
								cout << "|             ��ѡ��1-5,-1Ϊ������һ�㣩:             |" << endl;
								cout << "---------------------------------------------------------" << endl;

								do {
									cin >> k;
									if (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != -1) {
										cout << "warning����������ȷ��ѡ�" << endl;
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
										cout << "----------------------ѧ����Ϣ�޸�-----------------------" << endl;
										cout << "|             1.�޸�ѧ��                                |" << endl;
										cout << "|             2.�޸�����                                |" << endl;
										cout << "|             3.�޸��Ա�                                |" << endl;
										cout << "|             4.�޸�ѧԺ                                |" << endl;
										cout << "|             5.�޸�רҵ                                |" << endl;
										cout << "|             6.�޸İ༶                                |" << endl;
										cout << "|             7.�޸�����                                |" << endl;
										cout << "|             8.�޸ļ���                                |" << endl;
										cout << "|             9.�޸ĵ绰                                |" << endl;
										cout << "|             ��ѡ��1-9,-1Ϊ������һ�㣩:             |" << endl;
										cout << "---------------------------------------------------------" << endl;

										do {
											cin >> t;
											if ((!(t >= 1 && t <= 9)) && t != -1) {
												cout << "��������ȷ��ѡ�" << endl;
											}
										} while ((!(t >= 1 && t <= 9)) && t != -1);

										if (t == 1) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id;
											now->mchange(stulist, id, 1);
										}
										else if (t == 2) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id;
											now->mchange(stulist, id, 2);
										}
										else if (t == 3) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 3);
										}
										else if (t == 4) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 4);
										}
										else if (t == 5) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 5);
										}
										else if (t == 6) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 6);
										}
										else if (t == 7) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 7);
										}
										else if (t == 8) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 8);
										}
										else if (t == 9) {
											cout << "������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
											string id;
											cin >> id; 
											now->mchange(stulist, id, 9);
										}
									}
								}
								else if (k == 4) {
									int t = 0;
									while (t != -1) {
										cout << "----------------------ѧ����Ϣ����-----------------------" << endl;
										cout << "|             1.����ѧ������                            |" << endl;
										cout << "|             2.����ѧԺ����                            |" << endl;
										cout << "|             3.������������                            |" << endl;
										cout << "|             ��ѡ��1-9,-1Ϊ������һ�㣩:             |" << endl;
										cout << "---------------------------------------------------------" << endl;

										do {
											cin >> t;
											if (t != 1 && t != 2 && t != 3 && t != -1) {
												cout << "��������ȷ��ѡ�";
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
										stulist->write();//�޸�֮�����Ϣд���ļ�
									}

								}
								else if (k == 5) {
									int flag = 0;
									string newpas1, newpas2;
									do {
										cout << "�����������룺(����-1�˳�) ";
										cin >> newpas1;
										if (newpas1 == "-1") break;

										cout << "��������һ�飺(����-1�˳�) ";
										cin >> newpas2;
										if (newpas1 == "-1") break;

										if (newpas1 != newpas2) {
											cout << "�����������벻ͬ������������" << endl;
										}
										else {
											if (newpas1 == now->getPassword()) {
												cout << "��������ԭ������ͬ������������" << endl;
											}
											else {
												now->changePassword(newpas1);
												//cout << "�����޸ĳɹ���" << endl;
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
			cout << "------------------------��лʹ��-------------------------" << endl;
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