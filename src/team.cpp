#include <iostream>
#include <string>
#include "team.h"
using namespace std;

void Team::setTeamName(string name)
{
	this->teamName = name;
}

void Team::setTeamSize(int size)
{
	this->teamSize = size;
}

void Team::sets1Points(int s1p)
{
	this->stage1Total = s1p;
}

void Team::sets2Points(int s2p)
{
	this->stage2Total = s2p;
}

void Team::setRPoints(int rP)
{
	this->raceTotal = rP;
}

void Team::setTotalPoints(int tP){
	this->totalPoints = tP;
}

void Team::setTeamID(int id)
{
	this->teamID = id;
}

void Team::setScorer(int stage, int carNumber)
{
	scorers[stage] = carNumber;
}

void Team::setDidScore1(bool score1)
{
	this->didScore1 = score1;
}

void Team::setDidScore2(bool score2)
{
	this->didScore2 = score2;
}

void Team::setDidScore3(bool score3)
{
	this->didScore3 = score3;
}

string Team::getTeamName()
{
	return this->teamName;
}

int Team::getTeamSize()
{
	return this->teamSize;
}

int Team::gets1Points()
{
	return this->stage1Total;
}

int Team::gets2Points()
{
	return this->stage2Total;
}

int Team::getRacePoints()
{
	return this->raceTotal;
}

int Team::getTotalPoints() {
	return this->totalPoints;
}

int Team::getTeamID()
{
	return this->teamID;
}

int Team::getScorer(int stage)
{
	return scorers[stage - 1];
}

bool Team::Score1()
{
	return this->didScore1;
}

bool Team::Score2()
{
	return this->didScore2;
}

bool Team::Score3()
{
	return this->didScore3;
}

void Team::printReport()
{
	cout << "********Classification for " << this->getTeamName() << "********" << endl;
	cout << endl;
	cout << "Team size: " << this->getTeamSize() << endl;
	cout << endl;
	cout << "*****************************************************************" << endl;
	if (this->didScore1) {
		cout << "Stage 1 points: " << this->gets1Points() << " points scored by " << this->getScorer(1) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 1
	else {
		cout << "Stage 1 points: No score" << endl;
		cout << endl;
	}
	if (this->didScore2) {
		cout << "Stage 2 points: " << this->gets2Points() << " points scored by " << this->getScorer(2) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 2
	else {
		cout << "Stage 2 points: No score" << endl;
		cout << endl;
	}
	if (this->didScore3) {
		cout << "Stage 3 points: " << this->getRacePoints() << " points scored by " << this->getScorer(3) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 3
	else {
		cout << "Stage 3 points: No Score" << endl;
		cout << endl;
	}
	//If the team scored in all three stages
	if (this->didScore1 && this->didScore2 && this->didScore3) {
		cout << "Total Race Points: " << this->gets1Points() + this->gets2Points() + this->getRacePoints() << endl;
	}
	//If the team scored in only stage 1 and 3
	else if (this->didScore1 && !(this->didScore2) && this->didScore3) {
		cout << "Total Race Points: " << this->gets1Points() + this->getRacePoints() << endl;
	}
	//If the team scored in only stage 2 and 3
	else if (!(this->didScore1) && this->didScore2 && this->didScore3) {
		cout << "Total Race Points: " << this->gets2Points() + this->getRacePoints() << endl;
	}
	//If the team didn't score at all
	else if (!(this->didScore1) && !(this->didScore2) && !(this->didScore3)) {
		cout << "Total Race Points: No Score"  << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << endl;
}
