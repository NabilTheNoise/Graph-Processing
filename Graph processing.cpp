
#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;





int menu() {
	int task;
	cout << "\n\n\t\t\t*****************************************************";
	cout << "\n\t\t\t*****************************************************";
	cout << "\n\t\t\t\t\t\tHi!";
	cout << "\n\t\t\t\t Welcom to the Graph Solution App!\n\t\t\t\t   press any key to continue...";
	cout << "\n\t\t\t*****************************************************";
	cout << "\n\t\t\t*****************************************************";
	_getch();



	system("cls");
	cout << "\n\n\t\t***************************************************************************";
	cout << "\n\t\t**  \t\t\tSelect What You Want To Do:\t\t\t **\n\t\t** <<The Program Will Automaticly Ask For The Matris In The Next Step!>> **\n";
	cout << "\t\t**-----------------------------------------------------------------------**\n";
	cout << "\t\t**   1.                                                                  **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   2. Hamilton Tour                                                    **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   3. Oyler Tour                                                       **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   4. Kootah tarin masir beyne 2 raas                                  **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   5. Ghotre Graph                                                     **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   6. Hambandi                                                         **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   7. Check if the Graph is a Tree!                                    **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   8. Max and Min P(daraje rouse geraph)                               **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   9. Kamel Boodane Graph                                              **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   10.Andaze Graph                                                     **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t**   11.EXIT                                                             **\n";
	cout << "\t\t**                                                                       **\n";
	cout << "\t\t***************************************************************************\n";
	cin >> task;
	if (task == 11) {
		system("cls");
		cout << "Thanks For Using Our App! :D\n press any key to exit...";
		cin.get();
		cin.get();
		exit(1);
	}
	return task;
}


void inputmatris(int, int**);
void outputmatris(int, int**);
void matris_2(int, int**, int**);
bool check(int, int**);

void task1() {

}

void task2(int p, int i, int j, int**matrischeck, int *A, int counter) {
	counter = 0;
	bool dol = true;
	i = 0;
	j = 0;
	A[0] = 0;
	int counter2 = 0;
	bool sol = true;

	while (counter < p - 1) {
		counter2++;
		if (counter2>p + p) { //for breaking the loop if Hamiltoni Tour/Path didnt exist
			sol = false;
			break;
		}
		j = 0;
		for (; j < p; j++) {
			dol = true;
			if (*(*(matrischeck + i) + j) == 1) {
				for (int g = 0; g <= counter; g++) {
					if (A[g] == j)
						dol = false;
				}
				if (dol) {
					i = j;
					counter++;
					A[counter] = j;
					for (int h = 0; h < p; h++) {
						*(*(matrischeck + h) + j) = 0;
					}
					break;
				}
			}
		}
	}
	if (*(*(matrischeck + i) + A[0]) == 1 && sol == true) {
		cout << "Hamiltoni Tour Exists!\n" << endl;
		counter++;
		A[counter] = A[0];
	}
	else if (sol == false) {
		cout << "Hamilton Path/Tour Dosent Exist!\n\n";
	}

	else
		cout << "Hamilton Path Exists!\n" << endl;


	for (int k = 0; k < counter + 1; k++) {
		cout << A[k] + 1 << " ";
	}


	cout << endl;
}
int task6(int p, int i, int j, int**matrischeck) {
	int counter = 0;
	i = 0;
	while (counter < p*p) {
		j = 0;
		for (; j < p; j++) {
			if (*(*(matrischeck + i) + j) == 1) {
				i = j;
				counter++;
				for (int h = 0; h < p; h++) {
					*(*(matrischeck + h) + j) = 0;
				}
			}
			else
				counter++;
		}
	}
	//outputmatris(p, matrischeck);

	int a = 0;
	for (int i = 0; i < p; i++) {
		for (int j = i + 1; j < p; j++) {
			if (*(*(matrischeck + i) + j) != 0) {
				a++;
				break;
			}
		}
	}
	if (a == 0) {
		cout << "\n\nHamband!!!\n";
		system("pause");
		return 5;
	}
	else if (a != 0) {
		cout << "\n\nNa hamband!!!\n";
		system("pause");
		system("cls");
		return 4;
	}
	else {
		cout << "error!!!";
	}

	return 0;
}
int task7(int p, int q, int **matrischeck) {
	int counter = 0;
	int c = 0;
	while (c <= p) {
		for (int i = 0; i < p; i++) {
			int a = 0;
			int po = 0;
			for (int j = 0; j < p; j++) {
				if (*(*(matrischeck + i) + j) == 1) {
					a++;
					po = j;
				}
			}
			if (a == 1) {
				*(*(matrischeck + i) + po) = 0;
				*(*(matrischeck + po) + i) = 0;
			}
		}
		c++;
	}
	for (int i = 0; i < p; i++) {
		for (int j = i + 1; j < p; j++) {
			if (*(*(matrischeck + i) + j) != 0) {
				cout << "Its Not a Tree!!!\n";
				return 0;
			}
		}
	}
	cout << "Its a Tree!!!\n";
	return 0;
}
void task8(int p, int **matris2) {
	int min, max;
	min = *(*(matris2 + 0) + 0);
	max = min;
	for (int i = 1; i < p; i++) {
		if (*(*(matris2 + i) + i) > max) {
			max = *(*(matris2 + i) + i);
		}
		if (*(*(matris2 + i) + i) < min) {
			min = *(*(matris2 + i) + i);
		}
	}
	cout << "\n\n\t|Max is:" << max;
	cout << "\n\t|Min is:" << min << "\n\n";
}
void task9(int p, int **matrischeck) {
	int a = 0;
	for (int i = 1; i < p; i++)
		for (int j = 1 + i; j < p; j++)
			if (*(*(matrischeck + i) + j) != 1)
				a++;
	if (a == 0) {
		cout << "Graph kamel ast!\n";
	}
	else {
		cout << "Graph kamel nist!\n";
	}
}
int task10(int p, int **matris2) {
	int sum = 0;
	for (int i = 0; i < p; i++) {
		sum += *(*(matris2 + i) + i);
	}
	int q = sum / 2;
	return q;
}
void matrischecktask(int p, int **matris, int **matrischeck) {
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			*(*(matrischeck + i) + j) = *(*(matris + i) + j);
		}
	}
}




int main() {

	int task, q = 0;
	task = menu();
	system("cls");
	cout << "Graph chand raas darad?\n";
	int p;
	cin >> p;
	int *A = new int[p + 1];
	int **matris = new int *[p];
	for (int i = 0; i < p; i++) {
		matris[i] = new int[p];
	}
	int **matris2 = new int *[p];
	for (int i = 0; i < p; i++) {
		matris2[i] = new int[p];
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			*(*(matris2 + i) + j) = 0;
		}
	}




	inputmatris(p, matris);
	if (check(p, matris)) {
		cout << "This is wrong! \nDo you want to try again? (Y/N)";
		switch (_getch()) {
		case 'y':
			system("cls");
			main();
			break;
		case 'n':
			system("cls");
			cout << "Thanks For Using Our App! :D\n press any key to exit...";
			cin.get();
			cin.get();
			exit(1);
			break;
		}
	}




	int **matrischeck = new int *[p];
	for (int i = 0; i < p; i++) {
		matrischeck[i] = new int[p];
	}
	//int s, e, z;
	matrischecktask(p, matris, matrischeck);
	int x2 = 0;
	int counter = 0;
	int i1 = 0, j1 = 0;
	matris_2(p, matris, matris2);
	switch (task) {

	case 2:
		i1 = 0;
		//  matrischecktask(p,matris, matrischeck);
		//	x2=task6(p,i1,j1,matrischeck);
		//	if (x2==5){
		matrischecktask(p, matris, matrischeck);
		task2(p, i1, j1, matrischeck, A, counter);
		//	    }
		//  else 
		//   	   cout<<"ERROR a0001xd\nMatris Cannot be checked for Hamilton Tour/Path!\n ";
		break;
	case 6:
		task6(p, i1, j1, matrischeck);
		break;
	case 7:
		q = task10(p, matris2);
		matrischecktask(p, matris, matrischeck);
		task7(p, q, matrischeck);
		break;
	case 8:
		task8(p, matris2);
		break;
	case 9:
		matrischecktask(p, matris, matrischeck);
		task9(p, matrischeck);
		break;
	case 10:
		q = task10(p, matris2);
		cout << "Andaze Graph: " << 2 * q << endl;
		break;
	}

	outputmatris(p, matris);
	cout << "\n\n\t\t\t\t";
	system("pause");
	for (int del=0; del<p; del++) {
		delete[] matrischeck[del];
		delete[] matris[del];
		delete[] matris2[del];
	}
	delete matrischeck;
	delete matris;
	delete matris2;
	delete A;
}





void inputmatris(int p, int**matris) {
	cout << "enter your matris:\n";
	for (int i = 0; i < p; i++) {
		cout << "colum " << i + 1 << endl;
		for (int j = 0; j < p; j++) {
			cin >> *(*(matris + i) + j);
		}
		system("cls");
	}
	system("cls");
}
void outputmatris(int p, int**matris) {
	cout << "your matris is:\n\n";


	cout << "   ";
	int counter = 0;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		counter++;
		if (counter <= p)
			cout << ch << " ";
		else {
			cout << endl;
			counter = 0;
			break;
		}
	}


	char ch = 'a';


	for (int i = 0; i < p; i++) {
		counter++;
		if (counter <= p) {
			cout << ch;
		}
		ch++;
		cout << "| ";
		for (int j = 0; j < p; j++) {

			cout << *(*(matris + i) + j) << " ";
		}
		cout << "|";
		cout << endl;
	}
}
void matris_2(int p, int **matris, int **matris2) {
	int m = 0, n = 0, x, y;
	for (int m = 0; m < p; m++)
		for (int n = 0; n < p; n++)
			for (int i = 0; i < p; i++) {
				x = *(*(matris + m) + i);
				y = *(*(matris + i) + n);
				*(*(matris2 + m) + n) += x * y;
			}
}
bool check(int p, int **matris) {
	int a, b;
	for (int i = 0; i < p; i++) {
		if (*(*(matris + i) + i) != 0) {
			return true;
		}
		for (int j = 0; j < p; j++) {
			a = *(*(matris + i) + j);
			b = *(*(matris + j) + i);
			if (a != b) {
				return true;
			}
		}
	}
	return false;
}
