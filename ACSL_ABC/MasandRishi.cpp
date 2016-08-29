#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {

	for (int m = 0; m < 5; m++) {

		string inputString;
		getline(cin, inputString);

		vector<string> allInputs;

		stringstream inputStream(inputString);

		string s;

		char grid[6][6];

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				grid[i][j] = '0';
			}
		}

		while (inputStream >> s)
		{
			int pos = s.find(',');
			if (pos >= 0) {
				s.erase(pos, pos);
			}

			allInputs.push_back(s);

			if (inputStream.peek() == ',' || inputStream.peek() == ' ') {
				inputStream.ignore();
			}
		}

		for (int i = 0; i < allInputs.size(); i++) {
			if (i >= 0 && i <= 3) {
				int gridPos = stoi(allInputs.at(i));
				int gridRow = gridPos / 6;
				int gridCol = gridPos % 6 - 1;
				grid[gridRow][gridCol] = 'X';
			}
			else if (i == 4) {
				int numChars = stoi(allInputs.at(i));
				for (int q = 0; q < numChars; q++) {
					int gridPos = stoi(allInputs.at(i + (2 * q) + 2));
					int gridRow = gridPos / 6;
					int gridCol = gridPos % 6 - 1;
					/*if (gridCol == -1) {
						gridCol = 5;
					}*/
					grid[gridRow][gridCol] = allInputs.at(i + (2 * q) + 1)[0];

					if (gridCol == 0) {
						if (grid[gridRow][gridCol + 1] == 'X') {
							grid[gridRow][gridCol + 2] = allInputs.at(i + (2 * q) + 1)[0];
						}
						else {
							grid[gridRow][gridCol + 1] = allInputs.at(i + (2 * q) + 1)[0];
						}

					}
					else if (gridCol == -1) {
						if (grid[gridRow][gridCol - 1] == 'X') {
							grid[gridRow][gridCol - 2] = allInputs.at(i + (2 * q) + 1)[0];
						}
						else {
							grid[gridRow][gridCol - 1] = allInputs.at(i + (2 * q) + 1)[0];
						}
					}
					else {
						if (gridRow == 5) {
							if (grid[gridRow - 1][gridCol] == 'X') {
								grid[gridRow - 2][gridCol] = allInputs.at(i + (2 * q) + 1)[0];
							}
							else {
								grid[gridRow - 1][gridCol] = allInputs.at(i + (2 * q) + 1)[0];
							}
						}
						else {
							if (grid[gridRow + 1][gridCol] == 'X') {
								grid[gridRow + 2][gridCol] = allInputs.at(i + (2 * q) + 1)[0];
							}
							else {
								grid[gridRow + 1][gridCol] = allInputs.at(i + (2 * q) + 1)[0];
							}
						}
					}

				}

				i += (numChars * 2);
			}
			else {

				//time to solve

				for (int u = 0; u < 104; u++) {

					for (int y = 1; y < 5; y++) {
						for (int z = 1; z < 5; z++) {
							if (grid[y][z] == 'A') {
								for (int w = 1; w < 5; w++) {
									for (int x = 1; x < 5; x++) {
										if (grid[w][x] == 'B') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'C';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'C';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'C';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'C';
												}
											}
										}
										else if (grid[w][x] == 'C') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'B';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'B';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'B';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'B';
												}
											}
										}
									}
								}
							}
							else if (grid[y][z] == 'B') {
								for (int w = 1; w < 5; w++) {
									for (int x = 1; x < 5; x++) {
										if (grid[w][x] == 'A') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'C';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'C';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'C';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'C';
												}
											}
										}
										else if (grid[w][x] == 'C') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'A';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'A';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'A';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'A';
												}
											}
										}
									}
								}
							}
							else if (grid[y][z] == 'C') {
								for (int w = 1; w < 5; w++) {
									for (int x = 1; x < 5; x++) {
										if (grid[w][x] == 'B') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'A';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'A';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'A';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'A';
												}
											}
										}
										else if (grid[w][x] == 'A') {
											if (w == y) {
												for (int d = 1; d < 5; d++) {
													if (grid[w][d] == '0') {
														grid[w][d] = 'B';
													}
												}
											}
											else if (x == z) {
												for (int d = 1; d < 5; d++) {
													if (grid[d][x] == '0') {
														grid[d][x] = 'B';
													}
												}
											}
											else {
												if (grid[y][x] == '0') {
													grid[y][x] = 'B';
												}
												if (grid[w][z] == '0') {
													grid[w][z] = 'B';
												}
											}
										}
									}
								}
							}
						}
					}
				}

				int gridPos = stoi(allInputs.at(i));
				int gridRow = gridPos / 6;
				int gridCol = gridPos % 6 - 1;

				cout << grid[gridRow][gridCol] << endl;

			}
		}

		//for (int i = 0; i < 6; i++) {
		//	for (int j = 0; j < 6; j++) {
		//		cout << grid[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		//cout << endl << endl;

		//for (int i = 1; i < 5; i++) {
		//	for (int j = 1; j < 5; j++) {
		//		cout << grid[i][j] << " ";
		//	}
		//	cout << endl;
		//}

	}

	return 0;
}