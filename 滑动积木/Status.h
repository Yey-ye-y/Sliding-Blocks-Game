#pragma once
#include<vector>
#include<cmath>
using namespace std;

class Status {
public:
	Status* father;//��״̬�ĸ�״̬�����ڵõ�����󣬵���A*·��
	int cardBlankPost;//E(��λ)���ڵ�λ��
	int h;//H(n)
	int g;//G(n)
	int f;//F(n)
	vector<char> cardPost;
	Status();
	Status(vector<char>cardPost);
	Status(const Status& temp) {
		cardBlankPost = temp.cardBlankPost;
		h = temp.h;
		g = temp.g;
		f = temp.f;
		father = temp.father;
		cardPost = temp.cardPost;
	}
	vector<Status*> CreatNewCardStatus();//��������״̬(��״̬)�����µ�״̬

	int GetH(vector<char>&carPost);//���hֵ

	void Swap(vector<char>& cardPost, int post1, int post2);//���������Ƶ�λ��
};

void DisPlayPath(Status* aim);//��ʾA*·��

Status* AStar(Status* begin);//A*�㷨

int IsFindAim(const vector<Status*>&table);//�Ƿ����ҵ�Ŀ��

void RemoveStaus(vector<Status*>&table, Status* sTemp);//�Ƴ����еĸ�״̬

int IsExistInTable(vector<Status*>table, Status* sTemp);//�жϸ�״̬�Ƿ��Ѵ����ڸñ�

Status* GetMinStatus(vector<Status*>table);//��ñ���fֵ��С��״̬


