#include <iostream>
#include <string>
#include "team.h"

using std::cout;
using std::endl;
using std::string;

Team::Team() : teamSize(0), teamID(0), stage1Total(0), stage2Total(0), raceTotal(0), totalPoints(0), didScore1(0), didScore2(0), didScore3(0), scorers{} {}

void Team::setTeamName(string name)
{
	teamName = name;
}

void Team::setTeamSize(int size)
{
	teamSize = size;
}

void Team::sets1Points(int s1p)
{
	stage1Total = s1p;
}

void Team::sets2Points(int s2p)
{
	stage2Total = s2p;
}

void Team::setRPoints(int rP)
{
	raceTotal = rP;
}

void Team::setTotalPoints(int tP){
	totalPoints = tP;
}

void Team::setTeamID(int id)
{
	teamID = id;
}

void Team::setScorer(int stage, int carNumber)
{
	scorers[stage] = carNumber;
}

void Team::setDidScore1(bool score1)
{
	didScore1 = score1;
}

void Team::setDidScore2(bool score2)
{
	didScore2 = score2;
}

void Team::setDidScore3(bool score3)
{
	didScore3 = score3;
}

string Team::getTeamName()
{
	return teamName;
}

int Team::getTeamSize()
{
	return teamSize;
}

int Team::gets1Points()
{
	return stage1Total;
}

int Team::gets2Points()
{
	return stage2Total;
}

int Team::getRacePoints()
{
	return raceTotal;
}

int Team::getTotalPoints() {
	return totalPoints;
}

int Team::getTeamID()
{
	return teamID;
}

int Team::getScorer(int stage)
{
	return scorers[stage - 1];
}

bool Team::Score1()
{
	return didScore1;
}

bool Team::Score2()
{
	return didScore2;
}

bool Team::Score3()
{
	return didScore3;
}

void Team::printReport()
{
	cout << "********Classification for " << getTeamName() << "********" << endl;
	cout << endl;
	cout << "Team size: " << getTeamSize() << endl;
	cout << endl;
	cout << "*****************************************************************" << endl;
	if (didScore1) {
		cout << "Stage 1 points: " << gets1Points() << " points scored by " << getScorer(1) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 1
	else {
		cout << "Stage 1 points: No score" << endl;
		cout << endl;
	}
	if (didScore2) {
		cout << "Stage 2 points: " << gets2Points() << " points scored by " << getScorer(2) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 2
	else {
		cout << "Stage 2 points: No score" << endl;
		cout << endl;
	}
	if (didScore3) {
		cout << "Stage 3 points: " << getRacePoints() << " points scored by " << getScorer(3) << endl;
		cout << endl;
	}
	//If the team didn't score in stage 3
	else {
		cout << "Stage 3 points: No Score" << endl;
		cout << endl;
	}
	//If the team scored in all three stages
	if (didScore1 && didScore2 && didScore3) {
		cout << "Total Race Points: " << gets1Points() + gets2Points() + getRacePoints() << endl;
	}
	//If the team scored in only stage 1 and 3
	else if (didScore1 && !(didScore2) && didScore3) {
		cout << "Total Race Points: " << gets1Points() + getRacePoints() << endl;
	}
	//If the team scored in only stage 2 and 3
	else if (!(didScore1) && didScore2 && didScore3) {
		cout << "Total Race Points: " << gets2Points() + getRacePoints() << endl;
	}
	//If the team didn't score at all
	else if (!(didScore1) && !(didScore2) && !(didScore3)) {
		cout << "Total Race Points: No Score"  << endl;
	}
	cout << "*****************************************************************" << endl;
	cout << endl;
}
