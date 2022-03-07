#pragma once

struct Car {
	int teamID;
	int carNumber;
	int stage1Points;
	int stage2Points;
	int stage3Points;
	int totalPoints;
};

class Team {
public:
	//Constructors
	Team();

	//Setters
	void setTeamName(std::string name);
	void setTeamSize(int size);
	void sets1Points(int s1p);
	void sets2Points(int s2p);
	void setRPoints(int rP);
	void setTotalPoints(int tP);
	void setTeamID(int id);
	void setScorer(int stage, int carNumber);
	void setDidScore1(bool score1);
	void setDidScore2(bool score2);
	void setDidScore3(bool score3);

	//Getters
	std::string getTeamName();
	int getTeamSize();
	int gets1Points();
	int gets2Points();
	int getRacePoints();
	int getTotalPoints();
	int getTeamID();
	int getScorer(int stage);
	bool Score1();
	bool Score2();
	bool Score3();

	//Printing function
	void printReport();
private:
	std::string teamName;
	int teamSize;
	int teamID;
	int stage1Total;
	int stage2Total;
	int raceTotal;
	int totalPoints;
	bool didScore1;
	bool didScore2;
	bool didScore3;
	int scorers[3];
};