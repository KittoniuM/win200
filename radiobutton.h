//======================================================================
class BaseRadioButton : public BaseObject
{
public:
	float* Var = false;
	const char* Text = "BaseRadioButton";

	using BaseObject::BaseObject;
	BaseRadioButton();
	virtual void Paint();
	virtual void Tick();

	bool IsEnabled()
	{
		return *this->Var == 1;
	}

	bool bCheckHover = false;
};
//======================================================================

//======================================================================
BaseRadioButton::BaseRadioButton()
{
	w = 5;
	h = 5;
}
//======================================================================

//======================================================================
void BaseRadioButton::Paint()
{
	int X, Y;
	GetPos(&X, &Y);
	if (gCmds.debug_menuoutlines)
		pDrawing.FillRGBAOutlined(X, Y, w, h, COL_RED);

	pDrawing.FillGradientCircle(X + 1, Y + 1, h, GRADIENT_1, GRADIENT_2);
	pDrawing.DrawCircle(X + 1, Y + 1, h, h * M_PI, MENU_OUTLINE);

	//pDrawing.FillRGBA(X + 1, Y + 1, w - 2, h - 2, LMenuBG);

	//pDrawing.Border(X + 1, Y + 1, w - 2, h - 1, MENU_OUTLINE);


	if (IsEnabled())
		pDrawing.FillRGBA(X + 2, Y + 2, w - 4, h - 4, MENU_CHECK_ON);

	if (bCheckHover)
		pDrawing.Border(X - 1, Y - 1, w - 2, h - 1, MENU_BH);

	pDrawing.DrawString(FONT_MENU_NORMAL, WinAlign::NONE, X + w + 5, Y + h / 2 - 5, MENU_CHECK_OFF, this->Text);
}
//======================================================================

//======================================================================
void BaseRadioButton::Tick()
{
	int MouseX, MouseY;
	InputManager.GetMousePos(&MouseX, &MouseY);

	int X, Y;
	GetPos(&X, &Y);

	bCheckHover = false;
	if (MouseX >= X && MouseX <= X + (w + pDrawing.GetTextWide(this->Text) + 5) && MouseY >= Y && MouseY <= Y + h)
		bCheckHover = true;

	if (InputManager.Clicked && bCheckHover)
	{
		if (*this->Var == 1)
			*this->Var = 0;
		else
			*this->Var = 1;
	}
}
//======================================================================