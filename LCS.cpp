#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;
void LCS() {
	string x = "ABCBDAB";
	string y = "BDCABA";
	vector < vector <int> > C(x.size(), vector <int>(y.size())), movement(x.size(), vector <int>(y.size()));
	int m = x.size();
	int n = y.size();

	for (int i = 0; i < m; i++)
		C[i][0] = 0;
	for (int j = 0; j < n; j++)
		C[0][j] = 0;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (x[i] == y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				movement[i][j] = 2; //Recording the movement to backtrack later on
			}
			else {
				if (C[i - 1][j] >= C[i][j - 1]) {
					C[i][j] = C[i - 1][j];
					movement[i][j] = 3; //Recording the movement to backtrack later on
				}
				else {
					C[i][j] = C[i][j - 1];
					movement[i][j] = 1; //Recording the movement to backtrack later on
				}
			}
		}
	}

	for (int i = 0; i < C.size(); i++) {  //displaying the matrix
		for (int j = 0; j < C[i].size(); j++) {
			cout << C[i][j] << " \t";
		}
		cout << endl;
	}

	cout << "\n\n\tLCS result : " << C[m - 1][n - 1] << endl;  //Displaying the bottom right corner value
	vector <char> answer;
	int i = m - 1;
	int j = n - 1;
	bool found = false;

	while (!(i <= 0 && j <=0)) { //Finding out the letters for LCS
		if (found == true)
			break;
		switch (movement[i][j]) {
		case 2:  //2 : left-top corner
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			i = i - 1;
			j = j - 1;
			break;
		case 3: //3 : up
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			i = i - 1;
			break;
		case 1: // 1 : left
			if (x[i] == y[j]) {
				answer.push_back(x[i]);
			}
			j = j - 1;
			break;
		default:
			found = true;
			break;
		}
	}

	cout <<"\tLCS output : ";
	for (auto it = answer.rbegin(); it != answer.rend(); it++) {  // Outputting the vector from reverse to get the correct answer
		cout << *it;
	}
}
int main()
{
	time_t start, end;
	start = clock();
	LCS();
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "\n\tBig O notation :" << "O" <<char(253);
	cout << "\n\tTime taken by program is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl;
}
