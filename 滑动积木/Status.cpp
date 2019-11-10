#include "pch.h"
#include "Status.h"
#include<iostream>
#include<stack>
using namespace std;
vector<Status*>OpenTable;
vector<Status*>CloseTable;

Status* AStar(Status* begin) {//由于本题目默认目标已为WW***,所以无需设置参数vector<int>end
	OpenTable.push_back(begin);//将开始状态放入oepn表
	while (OpenTable.size() != 0) {
		Status* minStatus= GetMinStatus(OpenTable); //获得open表最小值
		RemoveStaus(OpenTable, minStatus);//将最小值从open表移除
		CloseTable.push_back(minStatus);
		vector<Status*> nextStatus = minStatus->CreatNewCardStatus();//根据当前状态生成新的卡牌状态

		for (int i = 0; i < nextStatus.size(); i++) {
			int post = IsExistInTable(OpenTable, nextStatus[i]);//判断是否存在于open表
			if (post != -1) {
				if (nextStatus[i]->g < OpenTable[post]->g) {
					/*更改g和f以及父节点*/
					OpenTable[post]->g = nextStatus[i]->g;
					OpenTable[post]->f = nextStatus[i]->f;
					OpenTable[post]->father = nextStatus[i]->father;
				}
			}
			else {
				OpenTable.push_back(nextStatus[i]);//放入Open表
			}
		}
		int aimPost = IsFindAim(OpenTable);//查找目标状态是否存在于Open表中
		if (aimPost != -1)
			return OpenTable[aimPost];
	}
}

int IsFindAim(const vector<Status*> &table) {

	for (int i = 0; i < table.size(); i++)
	{
		if (table[i]->cardPost[0] == 'W' && table[i]->cardPost[1] =='W') {
			return i;
		}
	}
	return -1;
}

void RemoveStaus(vector<Status*>& table, Status * sTemp) {
	for (int i = 0; i < table.size(); i++)
	{
		if (sTemp->cardPost == table[i]->cardPost) {
			table.erase(table.begin() + i, table.begin() + i + 1);
			return;
		}
	}
}

int IsExistInTable(vector<Status*> table, Status*  sTemp) {

	for (int i = 0; i < table.size(); i++)
	{
		if (sTemp->cardPost == table[i]->cardPost) {
			return i;
		}
	}
	return -1;
}

Status* GetMinStatus(vector<Status*> table) {
	int min = 100;
	int post;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i]->f < min) {
			min = table[i]->f;
			post = i;
		}
	}
	return table[post];
}

void DisPlayPath(Status* aim)
{
	cout << "A*算法所得路径为:" << endl;
	stack<Status*> temp;
	temp.push(aim);
	Status* father = aim->father;
	while (father) {
		temp.push(father);
		father = father->father;
	}

	while (!temp.empty())
	{
		vector<char> cTemp = temp.top()->cardPost;
		temp.pop();
		for (int i = 0; i < cTemp.size(); i++) {
			if (i == 0)
				cout << cTemp[i];
			else
				cout << ' ' << cTemp[i];
		}
		if(!temp.empty())
		cout << "-->";
	}
	cout << endl;
}

Status::Status() {
	h = 0;
	g = 0;
	f = g + h;
	father = NULL;
}

Status::Status(vector<char> cardPost) {
	Status();
	this->cardPost = cardPost;
	for (int i = 0; i < this->cardPost.size(); i++) {
		if (this->cardPost[i] == 'E') {
			cardBlankPost = i;
			break;
		}
	}
}

vector<Status*> Status::CreatNewCardStatus() {
	
	vector<Status*>table;
	for (int i = 0; i < cardPost.size(); i++) {
		Status* newTemp = new Status(cardPost);
		if (abs(cardBlankPost - i) == 1 || abs(cardBlankPost - i) == 2) {
			newTemp->g = g + 1;
			Swap(newTemp->cardPost, i, cardBlankPost);
			newTemp->cardBlankPost = i;
			newTemp->h = GetH(newTemp->cardPost);
			newTemp->f = newTemp->h + newTemp->g;
			newTemp->father = this;
			table.push_back(newTemp);
		}
		if (abs(cardBlankPost - i) == 3) {
			newTemp->g = g + 2;
			Swap(newTemp->cardPost, i, cardBlankPost);
			newTemp->cardBlankPost = i;
			newTemp->h = GetH(newTemp->cardPost);
			newTemp->f = newTemp->h + newTemp->g;
			newTemp->father = this;
			table.push_back(newTemp);
		}
	}
	return table;
}

int Status::GetH(vector<char>& cardPost) {
	int sumH = 0;
	if (cardPost[0] == 'W')sumH++;
	if (cardPost[1] == 'W')sumH++;
	return 2 - sumH;
}

void Status::Swap(vector<char>& cardPost, int post1, int post2) {
	int temp = cardPost[post1];
	cardPost[post1] = cardPost[post2];
	cardPost[post2] = temp;
}


