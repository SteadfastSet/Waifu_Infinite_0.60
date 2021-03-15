#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{

	Sleep(250);
	printf("Ready Master!\n");
	printf("Please Press TAB to Begin!\n");

	while (true) {																			//Prepares the macro for use

		Sleep(50);

		INPUT Input_0 = { 0 };																//Variable defining nightmare
		INPUT Input_1 = { 0 };
		INPUT Input_2 = { 0 };
		INPUT Input_3 = { 0 };
		INPUT Input_4 = { 0 };
		INPUT Input_5 = { 0 };
		INPUT Input_6 = { 0 };
		INPUT Input_7 = { 0 };

		Input_0.type = INPUT_KEYBOARD;														//Defining Input Type
		Input_1.type = INPUT_KEYBOARD;
		Input_2.type = INPUT_KEYBOARD;
		Input_3.type = INPUT_KEYBOARD;
		Input_4.type = INPUT_KEYBOARD;
		Input_5.type = INPUT_KEYBOARD;
		Input_6.type = INPUT_KEYBOARD;
		Input_7.type = INPUT_MOUSE;

		if (GetAsyncKeyState(VK_TAB)) {														//Starting the macro

			Sleep(250);
			printf("Ikimashou!\n");

			while (true) {

				if (GetAsyncKeyState(VK_NUMPAD0)) {											//0 is the kill switch

					return 0;

				}

				Input_0.ki.wVk = VkKeyScanA('b');											//Inputting and sending "b.g" in discord
				Input_1.ki.wVk = VkKeyScanA('.');
				Input_2.ki.wVk = VkKeyScanA('g');
				Input_3.ki.wVk = VK_RETURN;

				SendInput(1, &Input_0, sizeof(Input_0));									//Sending defined inputs
				SendInput(1, &Input_1, sizeof(Input_1));
				SendInput(1, &Input_2, sizeof(Input_2));
				SendInput(1, &Input_3, sizeof(Input_3));

				Input_0.ki.dwFlags = KEYEVENTF_KEYUP;										//Lifts up the virtual keys
				Input_1.ki.dwFlags = KEYEVENTF_KEYUP;
				Input_2.ki.dwFlags = KEYEVENTF_KEYUP;
				Input_3.ki.dwFlags = KEYEVENTF_KEYUP;

				SendInput(1, &Input_0, sizeof(Input_0));									//Seemingly needless code that holds this whole operation together
				SendInput(1, &Input_1, sizeof(Input_1));
				SendInput(1, &Input_2, sizeof(Input_2));
				SendInput(1, &Input_3, sizeof(Input_3));

				ZeroMemory(&Input_0, sizeof(Input_0));
				ZeroMemory(&Input_1, sizeof(Input_1));
				ZeroMemory(&Input_2, sizeof(Input_2));
				ZeroMemory(&Input_3, sizeof(Input_3));

				Sleep(3500); // The line Seperating us from disaster

				keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | 0, 0);				//"Borrowed" paste input
				keybd_event('V', 0x2F, KEYEVENTF_EXTENDEDKEY | 0, 0);
				keybd_event('V', 0x2F, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
				keybd_event(VK_CONTROL, 0x1D, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

				Input_6.ki.wVk = VK_RETURN;													//Sends the instant guess paragraph
				SendInput(4, &Input_6, sizeof(Input_6));
				Input_6.ki.dwFlags = KEYEVENTF_KEYUP;
				SendInput(4, &Input_6, sizeof(Input_6));
				ZeroMemory(&Input_6, sizeof(Input_6));

				Sleep(500);

				SetCursorPos(400, 780);														//Resets cursor position

				Input_7.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;									//Reselects the text box
				::SendInput(1, &Input_7, sizeof(INPUT));
				::ZeroMemory(&Input_7, sizeof(INPUT));
				Input_7.type = INPUT_MOUSE;
				Input_7.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				::SendInput(1, &Input_7, sizeof(INPUT));
				::ZeroMemory(&Input_7, sizeof(INPUT));

				Sleep(10000);
			}
		}
	}
}