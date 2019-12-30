// Joshua Bonner
// Creative Project 2
// 23 MAY 16

#include <iostream>
#include <windows.h>
#include <cstring>
#include <string>
#include <iomanip>
#include <cctype>


using namespace std;

double calAvg(double*, int);
void sort(double*, string*, string*, int);
void findHighest(double*, int);
void findLowest(double*, int);

void main()
{
	int choice1;
	int choice2;
	string *ptrFirstName = nullptr;
	string *ptrLastName = nullptr;
	double *ptrTestScores = nullptr;
	double testAvg = 0;
	int numTestScores = 0;
	
	do
	{
		cout << " USER MENU " << endl;
		cout << "-----------" << endl;
		cout << "1. Input Data " << endl;
		cout << "2. Retrieve Data " << endl;
		cout << "3. Process Data " << endl;
		cout << "4. Clear Data " << endl;
		cout << "5. Close Program " << endl << endl;
		cout << "User choice: ";
		cin >> choice1;

		
		switch (choice1)
		{
		case 1:
			{   system("CLS");

				cout << "Number of test scores: ";
				cin >> numTestScores;

				system("CLS");
				
				while(numTestScores <= 0 || cin.fail())
				{	
					if(cin.fail())
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << "Must be a digit" << endl;
						cout << "Please reenter the amount of test scores to store: ";
						cin >> numTestScores;
					}
					else
					{
						cout << "The number of test scores must be a positive integer number." << endl;
						cout << "Please reenter the amount of test scores to store: ";
						cin >> numTestScores;
					}
						system("CLS");
				}
				
				system("CLS");

				ptrFirstName = new string[numTestScores];
				ptrLastName = new string[numTestScores];
				ptrTestScores = new double[numTestScores];
	
				for (int i = 0; i < numTestScores; i++)
				{
					cout << "Enter students first name: ";
					cin >> ptrFirstName[i];
					cout << "Enter students last name: ";
					cin >> ptrLastName[i];
					cout << "Enter test score for "<< *(ptrFirstName + i) << " " << *(ptrLastName + i) << ": ";
					cin >> ptrTestScores[i];
					cout << endl;

					system("CLS");

					while (ptrTestScores[i] < 0 || ptrTestScores[i] > 100)
					{
						cout << "Test scores must be a positive interger number between 0 and 100." << endl;
						cout << "Please enter another test score for " << ptrFirstName[i] << " " << ptrLastName[i] << ": ";
						cin >> ptrTestScores[i];
						system("CLS");
					}
				}	

				cout << "Data stored!" << endl;

				Sleep(750);
				system("CLS");

				break;
			}

		case 2:
			{  system("CLS");

				cout << "TEST SCORES" << endl;
				cout << "-----------" << endl;

				for (int j = 0; j < numTestScores; j++)
				{
					
					cout << "\n" << fixed << setprecision(2);
				    cout << *(ptrFirstName + j) << " " << *(ptrLastName + j) << ": " << *(ptrTestScores + j);	
				}

				cout << endl << endl;
				system("PAUSE");
				system("CLS");

				break;
			}

		case 3:
			{  system("CLS");

			do
			{
				
				cout << endl;
				cout << "PROCESS DATA MENU" << endl;
				cout << "-----------------" << endl;
				cout << "1. Average " << endl;
				cout << "2. Sort " << endl;
				cout << "3. Find Highest " << endl;
				cout << "4. Find Lowest " << endl;
				cout << "5. Exit To Main Menu " << endl << endl;
				cout << "User choice: ";
				cin >> choice2;

				switch (choice2)
				{
				case 1: 
					{  system("CLS");

						testAvg = calAvg(ptrTestScores, numTestScores);
						cout << "The average of these test scores is: " << testAvg << "." << endl << endl;
						system("PAUSE");
						system("CLS");
						break;
					}

				case 2:
					{  system("CLS");

						sort(ptrTestScores, ptrFirstName, ptrLastName, numTestScores);

							for (int j = 0; j < numTestScores; j++)
						{
							cout << "\n" << fixed << setprecision(2); 
						    cout << "Test Score " << ptrFirstName[j] << " " << ptrLastName[j] << ": " << ptrTestScores[j];
						}

						cout << endl << endl;
						system("PAUSE");
						system("CLS");

						break;
					}

				case 3:
					{  system("CLS");

						findHighest(ptrTestScores, numTestScores);

						break;
					}

				case 4:
					{  system("CLS");

						findLowest(ptrTestScores, numTestScores);

						break;
					}

				case 5: 
					{  system("CLS");
						break;
					}

				default : 
					{
						cout << "\nIvalid input, please try again" << endl;
						Sleep(750);
						system("CLS");
					}
				}

			} while(choice2 != 5);
				
			break;

			}

		case 4:
			{  system("CLS");

				
				

				for (int i = 0; i < numTestScores; i++)
				{
					ptrFirstName[i] =  " ";
					ptrLastName[i] = " ";
					ptrTestScores[i] = NULL;
				}

				int numTestScores = 0;

				cout << "Data cleared!" << endl << endl;

				system("PAUSE");
				system("CLS");
				break;

			}

		case 5: exit(0);
			
		default : 
			{
				cout << "\nIvalid input, please try again" << endl;
				Sleep(750);
				system("CLS");
			}
		}

		cout << endl;

	

	} while (choice1 != 5);

	delete [] ptrTestScores;
	delete [] ptrFirstName;
	delete [] ptrLastName;
	ptrTestScores = nullptr;
	ptrFirstName = nullptr;
	ptrLastName = nullptr;
	
	system("PAUSE");
}

double calAvg(double* score, int max)
{
	double total = 0;

	for (int i = 0; i < max; i++)
		total += score[i];

	return (total / max);
}

void sort(double* score, string* FirstName, string* LastName, int size)
{
	int startScan, minIndex; 
	double minValue;
	string minValueFN;
	string minValueLN;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];
		minValueFN = FirstName[startScan];
		minValueLN = LastName[startScan];

		for(int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue)
			{
				minValue = score[index];
				minValueFN = FirstName[index];
				minValueLN = LastName[index];
				minIndex = index;
			}
		}

		score[minIndex] = score[startScan];
		score[startScan] = minValue;
		FirstName[minIndex] = FirstName[startScan];
		FirstName[startScan] = minValueFN;
		LastName[minIndex] = LastName[startScan];
		LastName[startScan] = minValueLN;
	}
}

void findHighest(double* scores, int max)
{
		double highest = 0;
		for (int i = 1; i < max; i++)
		{
			if (scores[i] > highest)
				highest = scores[i];
		}
		cout << "Highest test score: " << highest << endl << endl;

		system("PAUSE");
		system("CLS");
}

void findLowest(double* scores, int max)
{
	double lowest = scores[0];
		for (int i = 1; i < max; i++)
		{
			if (scores[i] < lowest)
				lowest = scores[i];
		}
		cout << "Lowest test score: " << lowest << endl << endl;

		system("PAUSE");
		system("CLS");
}