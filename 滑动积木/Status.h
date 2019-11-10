#pragma once
#include<vector>
#include<cmath>
using namespace std;

class Status {
public:
	Status* father;//该状态的父状态，用于得到结果后，倒推A*路径
	int cardBlankPost;//E(空位)所在的位置
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
	vector<Status*> CreatNewCardStatus();//根据已有状态(该状态)产生新的状态

	int GetH(vector<char>&carPost);//获得h值

	void Swap(vector<char>& cardPost, int post1, int post2);//交换两卡牌的位置
};

void DisPlayPath(Status* aim);//显示A*路径

Status* AStar(Status* begin);//A*算法

int IsFindAim(const vector<Status*>&table);//是否已找到目标

void RemoveStaus(vector<Status*>&table, Status* sTemp);//移除表中的该状态

int IsExistInTable(vector<Status*>table, Status* sTemp);//判断该状态是否已存在于该表

Status* GetMinStatus(vector<Status*>table);//获得表中f值最小的状态


