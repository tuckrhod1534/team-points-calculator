#include <iostream>
#include <string>
#include "team.h"
#include "pointSystem.h"
using namespace std;

// Calculate stage points based on
// the highest finishing car
int stagePoints(int finish) {
	int points = 0;
	switch (finish)
	{
	case 1: points = 10;
		break;
	case 2: points = 9;
		break;
	case 3: points = 8;
		break;
	case 4: points = 7;
		break;
	case 5: points = 6;
		break;
	case 6: points = 5;
		break;
	case 7: points = 4;
		break;
	case 8: points = 3;
		break;
	case 9: points = 2;
		break;
	case 10: points = 1;
		break;
	}

	return points;
}

// Calculate the race points based on
// the highest finishing car
int racePoints(int finish) {
	int points = 0;
	switch (finish)
	{
	case 1: points = 40;
		break;
	case 2: points = 35;
		break;
	case 3: points = 34;
		break;
	case 4: points = 33;
		break;
	case 5: points = 32;
		break;
	case 6: points = 31;
		break;
	case 7: points = 30;
		break;
	case 8: points = 29;
		break;
	case 9: points = 28;
		break;
	case 10: points = 27;
		break;
	case 11: points = 26;
		break;
	case 12: points = 25;
		break;
	case 13: points = 24;
		break;
	case 14: points = 23;
		break;
	case 15: points = 22;
		break;
	case 16: points = 21;
		break;
	case 17: points = 20;
		break;
	case 18: points = 19;
		break;
	case 19: points = 18;
		break;
	case 20: points = 17;
		break;
	case 21: points = 16;
		break;
	case 22: points = 15;
		break;
	case 23: points = 14;
		break;
	case 24: points = 13;
		break;
	case 25: points = 12;
		break;
	case 26: points = 11;
		break;
	case 27: points = 10;
		break;
	case 28: points = 9;
		break;
	case 29: points = 8;
		break;
	case 30: points = 7;
		break;
	case 31: points = 6;
		break;
	case 32: points = 5;
		break;
	case 33: points = 4;
		break;
	case 34: points = 3;
		break;
	case 35: points = 2;
		break;
	case 36: points = 1;
		break;
	case 37: points = 1;
		break;
	case 38: points = 1;
		break;
	case 39: points = 1;
		break;
	case 40: points = 1;
		break;
	}
	return points;
}

template <class T>
void swap(T* xp, T* yp) {
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Sort the Team Roster based on the
// total number of points scored
void bubbleSortT(Team arr[], int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j].getTotalPoints() < arr[j + 1].getTotalPoints()) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) { break; }
	}

}

// Sort the Car Roster based on the 
// total number of points scored
void bubbleSortC(Car arr[], int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j].totalPoints < arr[j + 1].totalPoints) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) { break; }
	}
}
