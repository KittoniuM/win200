#include "Keyp.h"
#include "Cvars.h"
#include "Hookwing.h"

KeyInput gKeyInput;


unsigned void* KeyInput::HookwCursor(unsigned void*)
{
	unsigned int x = m_iCursorPos[0], y = m_iCursorPos[1];
	unsigned int yOut = y + 4;
	unsigned int yNorm = y;

	ESP_Hookwing.FillRGBA(x + 1, y + 14, 14, 1, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 15, 15, 1, COL_WHITE); // First arrow
	ESP_Hookwing.FillRGBA(x + 1, y + 16, 16, 2, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 18, 13, 2, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 20, 10, 2, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 22, 7, 2, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 24, 4, 2, COL_WHITE);
	ESP_Hookwing.FillRGBA(x + 1, y + 26, 1, 2, COL_WHITE);
}


unsigned void* KeyInput::Think(unsigned void*)
{
	// Left click 

	m_iCursorPos[0] = pointCursor.x - rectMain.left;
	m_iCursorPos[1] = pointCursor.y - rectMain.top;
}
