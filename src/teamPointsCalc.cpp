#include <iostream>
#include <cstdlib>
#include "team.h"
#include "pointSystem.h"
using namespace std;

// 6-18-2019
// The scorers are not setting correctly

// 6-20-2019
// The above error has been corrected and
// a new correction method implemented
// beginning on line 150. 
// Ambiguity issue this evening with cout, cin,
// and system. Adding cstdlib fixed this.

// 6-23-2019
// Implemented new classification printing.
// Still has a few bugs while printing. Think
// this in only when printing one team at a time.
// Also, need to put a loop for the classifications
// to keep calculating on same finishing orders.

// 6-24-2019
// Fixed bug pertaining to the individual team printing
// however, when a team doesn't score, printing is wrong. 
// Also, some housekeeping needing to be done on console 
// text. Becoming a bit cluttered.

// 6-25-2019
// Fixed printing error. Clutter still needs cleaned.

// 6-27-2019
// Clutter is cleared. Planning on adding a feature
// which displays the teams in the order they scored
// for the race. I believe my two options for this would
// be to do it with a linked list or vectors.

// 7-1-2019
// Added the foundation for an output which prints each cars 
// points for the stages and then adds them for total points.
// Still need to implement the carDetails function in the 
// main function and adjust the menu to offer extended options.

// 7-3-2019
// Implemented new car point system. The program will now, in
// in addition to giving team classifications, give you car
// classifications. Still need to display the cars and teams 
// in order of points earned.

// 7-15-2019
// Laid foundation with linked lists to print a rank of the teams
// and cars. Still need a way to tie the team name/car number to
// the list entry. Also, need to adjust totalPoints data member of 
// team to only add the stages which were scored in. 

// 7-16-2019
// Implemented a bubble sorting function to rank the teams in order
// of their total race points. Linked lists were not needed and the
// .h and .cpp files for them were removed. There is an issue with 
// with calculating several rankings in the same build. The points
// don't seem to be reseting.

// 7-17-2019
// Fixed bug mentioned above and implemented the sorting algorithm
// for scoring and ranking cars.

// 2-27-20
// Updated Program to fit 2020 classification

void showMenu() {
	cout << "Calculations complete. Choose a number to display the teams classification." << endl;
	cout << "1......Full Race Classification" << endl;
	cout << "2......Car Point Classification" << endl;
	cout << "3......Full Car Point Classification" << endl;
	cout << "4......Team Rankings" << endl;
	cout << "5......Car Rankings" << endl;
}

void showCarMenu() {
	cout << "1........Kurt Busch" << endl;
	cout << "2........Brad Keselowski" << endl;
	cout << "3........Austin Dillon" << endl;
	cout << "4........Kevin Harvick" << endl;
	cout << "5........Ryan Newman" << endl;
	cout << "6........Daniel Hemric" << endl;
	cout << "7........Chase Elliott" << endl;
	cout << "8........Aric Almirola" << endl;
	cout << "9........Denny Hamlin" << endl;
	cout << "10.......Ryan Blaney" << endl;
	cout << "11.......Ty Dillon" << endl;
	cout << "12.......Clint Bowyer" << endl;
	cout << "13.......Ricky Stenhouse Jr." << endl;
	cout << "14.......Kyle Busch" << endl;
	cout << "15.......Martin Truex Jr" << endl;
	cout << "16.......Erik Jones" << endl;
	cout << "17.......Paul Menard" << endl;
	cout << "18.......Joey Logano" << endl;
	cout << "19.......William Byron" << endl;
	cout << "20.......Corey Lajoie" << endl;
	cout << "21.......Michael McDowell" << endl;
	cout << "22.......Matt Tifft" << endl;
	cout << "23.......Chris Buescher" << endl;
	cout << "24.......David Ragen" << endl;
	cout << "25.......Daniel Suarez" << endl;
	cout << "26.......Kyle Larson" << endl;
	cout << "27.......Bubba Wallace Jr." << endl;
	cout << "28.......Ryan Preece" << endl;
	cout << "29.......Jimmie Johnson" << endl;
	cout << "30.......Alex Bowman" << endl;
	cout << "31.......Matt DiBeneditto" << endl;
}

void carDetails(Car c){
	cout << "*********Classification for car " << c.carNumber << "*********" << endl;
	if (c.stage1Points > 0 && c.stage1Points < 11) {
		cout << "Stage 1: " << c.stage1Points << endl;
	}
	else { cout << "Stage 1: No Score" << endl; }
	if (c.stage2Points > 0 && c.stage1Points < 11) {
		cout << "Stage 2: " << c.stage2Points << endl;
	}
	else { cout << "Stage 2: No Score" << endl; }
	cout << "Stage 3: " << c.stage3Points << endl;
	if (c.stage1Points > 0 && c.stage2Points > 0) {
		cout << "Total Points: " << c.stage1Points + c.stage2Points + c.stage3Points << endl;
	}
	else if (c.stage1Points > 0 && c.stage2Points < 0) {
		cout << "Total Points: " << c.stage1Points + c.stage3Points << endl;
	}
	else if (c.stage1Points < 0 && c.stage2Points > 0) {
		cout << "Total Points: " << c.stage2Points + c.stage3Points << endl;
	}
	cout << "*******************************************" << endl;
}


int main() {
	Team JGR, TP, SHR, CGR, HMS, RFR, RCR;
	Team JTG, FRM, GMR, RPM, GFR, WBR, LFR;
	Team SPM, MBM, RWR, GBR, PRM, SCR;
	Car c00, c1, c2, c3, c4, c6, c8, c9, c10, c11, c12, c13, c14, c15, c17;
	Car c18, c19, c20, c21, c22, c24, c27, c32, c34, c36, c37, c38, c41;
	Car c42, c43, c47, c48, c52, c53, c66, c77, c88, c95, c96;

	c42.teamID = c1.teamID = 4;
	c12.teamID = c22.teamID = c2.teamID = 2;
	c8.teamID = c3.teamID = 7;
	c14.teamID = c10.teamID = c41.teamID = c4.teamID = 3;
	c6.teamID = c17.teamID = 6;
	c9.teamID = c24.teamID = c48.teamID = c88.teamID = 5;
	c11.teamID = c18.teamID = c19.teamID = c20.teamID = 1;
	c37.teamID = c47.teamID = 8;
	c34.teamID = c36.teamID = c38.teamID = 9;
	c13.teamID = 10;
	c21.teamID = 13;
	c32.teamID = 12;
	c43.teamID = 11;
	c52.teamID = c53.teamID = 17;
	c66.teamID = 16;
	c77.teamID = 15;
	c95.teamID = 14;
	c96.teamID = 18;
	c00.teamID = 20;
	c27.teamID = 19;
	c00.carNumber = 00;
	c1.carNumber = 1;
	c2.carNumber = 2;
	c3.carNumber = 3;
	c4.carNumber = 4;
	c6.carNumber = 6;
	c8.carNumber = 8;
	c9.carNumber = 9;
	c10.carNumber = 10;
	c11.carNumber = 11;
	c12.carNumber = 12;
	c14.carNumber = 14;
	c17.carNumber = 17;
	c18.carNumber = 18;
	c19.carNumber = 19;
	c20.carNumber = 20;
	c24.carNumber = 24;
	c22.carNumber = 22;
	c27.carNumber = 27;
	c34.carNumber = 34;
	c36.carNumber = 36;
	c37.carNumber = 37;
	c38.carNumber = 38;
	c41.carNumber = 41;
	c42.carNumber = 42;
	c47.carNumber = 47;
	c48.carNumber = 48;
	c52.carNumber = 52;
	c53.carNumber = 53;
	c66.carNumber = 66;
	c88.carNumber = 88;
	c77.carNumber = 77;
	c13.carNumber = 13;
	c21.carNumber = 21;
	c32.carNumber = 32;
	c43.carNumber = 43;
	c95.carNumber = 95;
	c96.carNumber = 96;
	Team teamRoster[20] = { JGR, TP, SHR, CGR, HMS, RFR, RCR,
							JTG, FRM, GMR, RPM, GFR, WBR, LFR,
							SPM, MBM, RWR, GBR, PRM, SCR};
	Car carRoster[39] = { c00, c1, c2, c3, c4, c6, c8, c9, c10, c11, c12, c13, c14, c17,
						c18, c19, c20, c21, c22, c24, c27, c32, c34, c36, c37, c38, c41,
						c42, c43, c47, c48, c52, c53, c66, c77, c88, c95, c96 };
	//set all team IDs
	for (int a = 0; a < 20; a++) {
		teamRoster[a].setTeamID(a + 1);
	}
	//This for loop sets all the team names
	for (int i = 0; i < 20; i++) {
		switch (teamRoster[i].getTeamID()) {
		case 1:
			teamRoster[i].setTeamName("Joe Gibbs Racing");
			break;
		case 2:
			teamRoster[i].setTeamName("Team Penske");
			break;
		case 3:
			teamRoster[i].setTeamName("Stewart-Haas Racing");
			break;
		case 4:
			teamRoster[i].setTeamName("Chip Ganassi Racing");
			break;
		case 5:
			teamRoster[i].setTeamName("Hendrick Motorsports");
			break;
		case 6:
			teamRoster[i].setTeamName("Roush Fenway Racing");
			break;
		case 7:
			teamRoster[i].setTeamName("Richard Childress Racing");
			break;
		case 8:
			teamRoster[i].setTeamName("JTG-Daugherty Racing");
			break;
		case 9:
			teamRoster[i].setTeamName("Front Row Motorsports");
			break;
		case 10:
			teamRoster[i].setTeamName("Germain Racing");
			break;
		case 11:
			teamRoster[i].setTeamName("Richard Petty Motorsports");
			break;
		case 12:
			teamRoster[i].setTeamName("GO FAS Racing");
			break;
		case 13:
			teamRoster[i].setTeamName("Wood Brothers Racing");
			break;
		case 14:
			teamRoster[i].setTeamName("Leavine Family Racing");
			break;
		case 15:
			teamRoster[i].setTeamName("Spire Motorsports");
			break;
		case 16:
			teamRoster[i].setTeamName("Motorsport Business Managment");
			break;
		case 17:
			teamRoster[i].setTeamName("Rick Ware Racing");
			break;
		case 18:
			teamRoster[i].setTeamName("Gaunt Brothers Racing");
			break;
		case 19:
			teamRoster[i].setTeamName("Premium Motorsports");
			break;
		case 20:
			teamRoster[i].setTeamName("Star Com Racing");
			break;
		}
		

	}
	//This loop calculates the team size
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 32; j++) {
			static int size;
			if (j == 0) {
				size = 0;
			}
			if (carRoster[j].teamID == teamRoster[i].getTeamID()) {
				size++;
			}
			if (j == 31) {
				teamRoster[i].setTeamSize(size);
			}
		}
	}

	char answer = 'y';
	while (answer == 'y') {
		int fieldSize;
		int s[10];
		int r[40];

		//initialize all score bools
		for (int a = 0; a < 20; a++) {
			teamRoster[a].setDidScore1(false);
			teamRoster[a].setDidScore2(false);
			teamRoster[a].setDidScore3(false);
		}

		//initialize all team scores to 0
		for (int a = 0; a < 20; a++) {
			teamRoster[a].sets1Points(0);
			teamRoster[a].sets2Points(0);
			teamRoster[a].setRPoints(0);
		}

		//intialize all car scores to 0
		for (int a = 0; a < 39; a++) {
			carRoster[a].stage1Points = 0;
			carRoster[a].stage2Points = 0;
			carRoster[a].stage3Points = 0;
		}

		//how many cars were in the race
		cout << "Please enter the number of cars in the field: ";
		cin >> fieldSize;
		cout << endl;
		system("cls");

		//since the race consists of 3 stages
		//we will want to loop through this
		//section 3 times
		for (int j = 0; j < 3; j++) {
			//enter the finishing results for the stages
			if (j < 2) {
				for (int i = 0; i < 10; i++) {
					cout << "Please enter the number " << i + 1 << " finisher in stage " << j + 1 << ": " << endl;
					cin >> s[i];
					system("cls");
				}
			}
			//if it is stage 3, the whole field is scored
			if (j == 2) {
				for (int h = 0; h < fieldSize; h++) {
					cout << "Please enter the number " << h + 1 << " finisher in stage " << j + 1 << ": " << endl;
					cin >> r[h];
					system("cls");
				}
			}

			//check to see if the finishing order entered 
			//was correct
			char check = 'n';
			while (check == 'n') {
				cout << "Is the following finishing order correct (y or n)?" << endl;
				if (j < 2) {
					for (int i = 0; i < 10; i++) {
						if (i + 1 < 10) {
							cout << i + 1 << "  | " << s[i] << endl;
						}
						else {
							cout << i + 1 << " | " << s[i] << endl;
						}
					}
				}
				if (j == 2) {
					for (int i = 0; i < fieldSize; i++) {
						if (i + 1 < 10) {
							cout << i + 1 << "  | " << r[i] << endl;
						}
						else {
							cout << i + 1 << " | " << r[i] << endl;
						}
					}
				}

				//if the finishing order wasn't correct,
				//here we will fix the erroneous position
				cin >> check;
				while (check == 'n') {
					int position;
					int driver;
					system("cls");
					cout << "What position needs to be changed? " << endl;
					//these two if statements change the 
					//erroneous positions in the corresponding arrays
					if (j < 2) {
						for (int i = 0; i < 10; i++) {
							if (i + 1 < 10) {
								cout << i + 1 << "  | " << s[i] << endl;
							}
							else {
								cout << i + 1 << " | " << s[i] << endl;
							}
						}
					}
					if (j == 2) {
						for (int i = 0; i < fieldSize; i++) {
							if (i + 1 < 10) {
								cout << i + 1 << "  | " << r[i] << endl;
							}
							else {
								cout << i + 1 << " | " << r[i] << endl;
							}
						}
					}
					cin >> position;
					system("cls");

					//here the user will tell what position
					//needs fixed and what the correct car
					//number is
					cout << "Please enter the number " << position << " finisher in stage " << j + 1 << ":" << endl;
					cin >> driver;
					//these if statements read in ints to
					//the proper array
					if (j < 2) {
						s[position - 1] = driver;
					}
					if (j == 2) {
						r[position - 1] = driver;
					}
					cout << "Is the following finishing order correct (y or n)?" << endl;
					//these if statements output the finishing
					//order from the proper array to check 
					//for erroneous orderings
					if (j < 2) {
						for (int i = 0; i < 10; i++) {
							if (i + 1 < 10) {
								cout << i + 1 << "  | " << s[i] << endl;
							}
							else {
								cout << i + 1 << " | " << s[i] << endl;
							}
						}
					}
					if (j == 2) {
						for (int i = 0; i < fieldSize; i++) {
							if (i + 1 < 10) {
								cout << i + 1 << "  | " << r[i] << endl;
							}
							else {
								cout << i + 1 << " | " << r[i] << endl;
							}
						}
					}
					cin >> check;
				}
				system("cls");
			}

			//scoring begins in these code clusters
			if (j == 0) {
				for (int i = 0; i < 10; i++) {
					for (int k = 0; k < 31; k++) {
						if (carRoster[k].carNumber == s[i]) {
							//If team has not scored in stage 1, 
							//this is where scoring begins
							if (!teamRoster[carRoster[k].teamID - 1].Score1()) {
								//Assign stage 1 points
								teamRoster[carRoster[k].teamID - 1].sets1Points(stagePoints(i + 1));
								//Record who scored the points
								teamRoster[carRoster[k].teamID - 1].setScorer(j, carRoster[k].carNumber);
								//Now that the team has scored, 
								//they wont score again in this stage.
								teamRoster[carRoster[k].teamID - 1].setDidScore1(true);
							}
							carRoster[k].stage1Points = stagePoints(i + 1);
							break; 
						}
					}
				}
			}
			if (j == 1) {
				for (int i = 0; i < 10; i++) {
					for (int k = 0; k < 31; k++) {
						if (carRoster[k].carNumber == s[i]) {
							//If team has not scored in stage 2, 
							//this is where scoring begins
							if (!teamRoster[carRoster[k].teamID - 1].Score2()) {
								//Assign stage 2 points
								teamRoster[carRoster[k].teamID - 1].sets2Points(stagePoints(i + 1));
								//Record who scored
								teamRoster[carRoster[k].teamID - 1].setScorer(j, carRoster[k].carNumber);
								//team won't score again this stage
								teamRoster[carRoster[k].teamID - 1].setDidScore2(true);
							}
							carRoster[k].stage2Points = stagePoints(i + 1);
							break;
						}
					}
				}
			}
			if (j == 2) {
				for (int i = 0; i < fieldSize; i++) {
					for (int k = 0; k < 31; k++) {
						if (carRoster[k].carNumber == r[i]) {
							//If team has not scored in stage 3, 
							//this is where scoring begins
							if (!teamRoster[carRoster[k].teamID - 1].Score3()) {
								//Assign race points
								teamRoster[carRoster[k].teamID - 1].setRPoints(racePoints(i + 1));
								//Record who scored for the team
								teamRoster[carRoster[k].teamID - 1].setScorer(j, carRoster[k].carNumber);
								//Only score the highest car
								teamRoster[carRoster[k].teamID - 1].setDidScore3(true);
							}
							carRoster[k].stage3Points = racePoints(i + 1);
							break;
						}
					}
				}
			}
			//total team points are calculated here
			for (int i = 0; i < 20; i++) {
				int x, y, z;
				x = teamRoster[i].gets1Points();
				y = teamRoster[i].gets2Points();
				z = teamRoster[i].getRacePoints();
				teamRoster[i].setTotalPoints(x+y+z);
			}
			//total car points are calculated here
			for (int i = 0; i < 39; i++) {
				int a, b, c;
				a = carRoster[i].stage1Points;
				b = carRoster[i].stage2Points;
				c = carRoster[i].stage3Points;
				carRoster[i].totalPoints = a + b + c;
			}
		}
		char calc = 'y';
		while (calc == 'y') {
			char newRace;
			int teamClass;
			showMenu();
			cin >> teamClass;
			//New print function being utilized. Numbered menu for options.
			if (teamClass == 1) {
				for (int i = 0; i < 20; i++) {
					teamRoster[i].printReport();
				}
			}
			if (teamClass == 2) {
				system("cls");
				int num;
				cout << "Please enter number for classification: " << endl;
				showCarMenu();
				cin >> num;
				carDetails(carRoster[num - 1]);
			}
			if (teamClass == 3) {
				for (int i = 0; i < 39; i++) {
					carDetails(carRoster[i]);
				}
			}
			if (teamClass == 4) {
				Team teamRankings[20];
				for (int j = 0; j < 20; j++) {
					teamRankings[j] = teamRoster[j];
				}
				bubbleSortT(teamRankings, 20);
				cout << "************Team Rankings************" << endl;
				for (int i = 0; i < 20; i++){
					cout << i+1 << ". " << teamRankings[i].getTeamName() << "(" 
						<< teamRankings[i].getTotalPoints() << ")" << endl;
				}
			}
			if (teamClass == 5) {
				Car carRankings[39];
				for (int i = 0; i < 39; i++) {
					carRankings[i] = carRoster[i];
				}
				bubbleSortC(carRankings, 39);
				cout << "************Car Rankings************" << endl;
				for (int i = 0; i < 39; i++) {
					cout << i + 1 << ". " << carRankings[i].carNumber << "(" 
						<< carRankings[i].totalPoints << ")" << endl;
				}
			}
			if (teamClass > 5) { 
				cout << "Choice was invalid. Please enter a valid choice." << endl; 
			}
			cout << "Would you like to calculate another classification (y/n)?" << endl;
			cin >> answer;
			//Check to see if new race data is needed.
			if (answer == 'y') {
				cout << "Is this calculation based on a new race? (y/n)" << endl;
				cin >> newRace;
				system("cls");
				if (newRace == 'y') {
					calc = 'n';
					break;
				}
			}
			else { break; }
		}
		system("cls");
		if (answer == 'n') {
			cout << "Thank you for using this program." << endl;
			system("pause");
		}
	}

	return 0;
}