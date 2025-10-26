#include "iostream"
#include<Windows.h>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;
wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;
int nScreenWidth = 80;
int nScreenHeight = 30;
unsigned char* pField = nullptr;
int Rotate(int px, int py, int r) {
	switch (r % 4) 
	{
	case 0: return py * 4 + px;
	case 1: return 12 + py - (px * 4);
	case 2: return 15 - (py * 4)-px;
	case 3: return 3 - py + (px * 4);
		}
	return 0;
}
bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY) {
	for (int px = 0; px < 4; px++) {
		for (int py = 0; py < 4; py++) {
			int pi = Rotate(px, py, nRotation);
			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);
		
		if (nPosX + px >= 0 && nPosX + px < nFieldWidth) {
			if (nPosY + py >= 0 && nPosY + py < nFieldHeight) {
				if (tetromino[nTetromino][pi] == L'x' && pField[fi] != 0)
					return false;
			}
		}
	
		}
	}
	return true;
}
int main() {
	tetromino[0].append(L"..x.");
	tetromino[0].append(L"..x.");
	tetromino[0].append(L"..x.");
	tetromino[0].append(L"..x.");

	tetromino[1].append(L"..x.");
	tetromino[1].append(L".xx.");
	tetromino[1].append(L".x..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".x..");
	tetromino[2].append(L".xx.");
	tetromino[2].append(L"..x.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".xx.");
	tetromino[3].append(L".xx.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..x.");
	tetromino[4].append(L".xx.");
	tetromino[4].append(L"..x.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".xx.");
	tetromino[5].append(L"..x.");
	tetromino[5].append(L"..x.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".xx.");
	tetromino[6].append(L".x..");
	tetromino[6].append(L".x..");
	pField = new unsigned char[nFieldWidth * nFieldHeight];
	for (int x = 0; x < nFieldWidth; x++)
	{
		for (int y = 0; y < nFieldHeight; y++) {
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
		}
	}
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++)
		screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	bool bGameOver = false;
	//test
	int nCurrentPiece = 1;
	int nCurrentRotation = 0;
	int nCurrentX = nFieldWidth / 2;
	int nCurrentY = 0;
	bool bKey[4];
	bool bRotateHold = false;
	int nSpeed = 20;
	int nSpeedCounter = 0;
	bool bForceDown = false;
	int nPieceCount = 0;
	int nScore = 0;
	vector<int> vline;
	while (!bGameOver) {
		//
		this_thread::sleep_for(50ms);
		nSpeedCounter++;
		bForceDown = (nSpeedCounter == nSpeed);
		//
		for (int k = 0; k < 4; k++) {
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;
		}

		//
		nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
		nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;
		nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;
		if (bKey[3]) {
			nCurrentRotation += (!bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
			bRotateHold = true;
		}
		else bRotateHold = false;
		if (bForceDown) {
			if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) {
				nCurrentY++;
			}
			else {
				for (int px = 0; px < 4; px++) {
					for (int py = 0; py < 4; py++) {
						if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'x')
							pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
					}
				}
				nPieceCount++;
				if (nPieceCount % 10 == 0)
					if (nSpeed >= 10)nSpeed--;
				for (int py = 0; py < 4; py++) {
					if (nCurrentY + py < nFieldHeight - 1) {
						bool bline = true;
						for (int px = 1; px < nFieldWidth - 1; px++) {
							bline &= (pField[(nCurrentY + py) * nFieldWidth + px] != 0);
						}
						if (bline) {
							for (int px = 1; px < nFieldWidth - 1; px++) 
								pField[(nCurrentY + py) * nFieldWidth + px] = 8;
								vline.push_back(nCurrentY + py);
						}
					}
				}
				nScore += 25;
				if (!vline.empty())nScore += (1 << vline.size()) * 100;
				nCurrentX = nFieldWidth / 2;
				nCurrentY = 0;
				nCurrentRotation = 0;
				nCurrentPiece = rand() % 7;
				bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
			}
			nSpeedCounter = 0;
		}
		//





		for (int x = 0; x < nFieldWidth; x++) {
			for (int y = 0; y < nFieldHeight; y++) {
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
			}
		}
		//test
		for (int px = 0; px < 4; px++) {
			for (int py = 0; py < 4; py++) {
				if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'x')
					screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
			}
		}
		swprintf_s(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE:%8d", nScore);
		if (!vline.empty()) {
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
			this_thread::sleep_for(400ms);
			for (auto &v : vline) 
				for (int px = 1; px <nFieldWidth-1; px++) {
					for (int py = v; py > 0; py--)
						pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
					pField[px] = 0;
					
				}
				vline.clear();
		}
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}	
	CloseHandle(hConsole);
	cout << "Game Over!! Score:" << nScore << endl;
	system("pause");
	return 0;
}