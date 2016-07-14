//======================================================================
class BaseMenu
{
public:
	BaseMenu();

	void Think();
	void Paint();

	int m_iBoxHeight = 19;
	int m_iBoxSpacer = 0;
	int m_iPadding = 50;
	bool m_bIsEnabled = false;

	BaseObject* CreateCheck(BaseObject* parent, const char* Name, float* Var, int X, int Y);
	BaseObject* CreateButton(BaseObject* parent, const char* Name, ButtonAction iAction, int X, int Y, int W, int H);
	BaseObject* CreateColorButton(BaseObject* parent, const char* Name, Color* col, int X, int Y, int W, int H);

	std::vector<BaseObject*>* ObjectList = new std::vector < BaseObject* >;
};
//======================================================================

//======================================================================
BaseObject* BaseMenu::CreateCheck(BaseObject* parent, const char* Name, float* Var, int X, int Y)
{
	BaseCheckBox* NewBaseCheckBox = new BaseCheckBox();
	NewBaseCheckBox->SetPos(X, Y);
	NewBaseCheckBox->Text = Name;
	NewBaseCheckBox->Var = Var;
	NewBaseCheckBox->SetParent(parent);
	NewBaseCheckBox->Init(ObjectList);
	return NewBaseCheckBox;
}
//======================================================================

//======================================================================
BaseObject* BaseMenu::CreateButton(BaseObject* parent, const char* Name, ButtonAction iAction, int X, int Y, int W, int H)
{
	BaseButton* NewBaseButton = new BaseButton();
	NewBaseButton->SetSize(W, H);
	NewBaseButton->SetPos(X, Y);
	NewBaseButton->Text = Name;
	NewBaseButton->iAction = iAction;
	NewBaseButton->SetParent(parent);
	NewBaseButton->Init(ObjectList);
	return NewBaseButton;
}
//======================================================================

//======================================================================
BaseObject* BaseMenu::CreateColorButton(BaseObject* parent, const char* Name, Color* col, int X, int Y, int W, int H)
{
	BaseColorButton* NewBaseColorButton = new BaseColorButton();
	NewBaseColorButton->SetParent(parent);
	NewBaseColorButton->SetPos(X, Y);
	NewBaseColorButton->SetSize(W, H);
	NewBaseColorButton->col = col;
	NewBaseColorButton->Text = Name;
	NewBaseColorButton->Init(ObjectList);
	return NewBaseColorButton;
}
//======================================================================

//======================================================================
BaseMenu::BaseMenu()
{
	int MenuW = 640;
	int MenuH = 560;

	BaseWindow* MainWindow = new BaseWindow();
	MainWindow->SetSize(MenuW, MenuH);
	MainWindow->SetPos(200, 200);
	MainWindow->SetTitle("Win200 :: Soon to be a pCheat!");

	BaseTabPanel* TabProperty = new BaseTabPanel();
	TabProperty->SetParent(MainWindow);
	TabProperty->SetPos(5, 35);
	TabProperty->SetSize(MenuW - 25, MenuH - 70);

	BaseObject* AimbotTab = TabProperty->AddTab("Aimboat");
	BaseObject* ESP2DTab = TabProperty->AddTab("2D ESP");
	BaseObject* ESP3DTab = TabProperty->AddTab("3D ESP");
	BaseObject* FrameTab = TabProperty->AddTab("Frame");
	BaseObject* RemovalsTab = TabProperty->AddTab("Vis Rem");
	BaseObject* MiscTab = TabProperty->AddTab("Misc");
	BaseObject* HVHTab = TabProperty->AddTab("Adv");
	BaseObject* FilterTab = TabProperty->AddTab("Filter");

	CreateButton(MainWindow, "+", BB_CLOSEMENU, MenuW - 16, 0, 16, 18);
	CreateButton(MainWindow, "Save", BB_SAVE, 5, MenuH - MenuBar - 25, 100, 20);
	CreateButton(MainWindow, "Load", BB_LOAD, MenuW - 105, MenuH - MenuBar - 25, 100, 20);

	/* Aimbot */
	BaseTabSpace* SmoothAimSpace = new BaseTabSpace();
	SmoothAimSpace->SetParent(AimbotTab);
	SmoothAimSpace->bDrawName = false;
	SmoothAimSpace->SetSize(250, m_iBoxSpacer + m_iBoxHeight * 2);
	SmoothAimSpace->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(SmoothAimSpace, "Smooth Aim", &gCmds.aimbot_smoothaim, 0, -5);
	BaseSlider* SmoothAimSlider = new BaseSlider();
	SmoothAimSlider->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 1);
	SmoothAimSlider->SetWidth(230);
	SmoothAimSlider->SetParent(SmoothAimSpace);
	SmoothAimSlider->SetRange(1, 10);
	SmoothAimSlider->Var = &gCmds.aimbot_smoothaim_speed;

	BaseTabSpace* TargettingSpace = new BaseTabSpace();
	TargettingSpace->SetParent(AimbotTab);
	TargettingSpace->bDrawName = true;
	TargettingSpace->Text = "Aim Method";
	TargettingSpace->SetSize(250, m_iBoxSpacer + m_iBoxHeight * 6);
	TargettingSpace->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 5);
	BaseTabSpace* TargettingFOVSpace = new BaseTabSpace();
	TargettingFOVSpace->SetParent(TargettingSpace);
	TargettingFOVSpace->bDrawName = true;
	TargettingFOVSpace->Text = "FOV";
	TargettingFOVSpace->SetSize(225, m_iBoxSpacer + m_iBoxHeight * 1);
	TargettingFOVSpace->SetPos(10, 15);
	BaseSlider* FOVSlider = new BaseSlider();
	FOVSlider->SetPos(10, 11);
	FOVSlider->SetWidth(205);
	FOVSlider->SetParent(TargettingFOVSpace);
	FOVSlider->SetRange(1, 360);
	FOVSlider->Var = &gCmds.aimbot_fov;

	BaseTabSpace* AIMKEYSPACE = new BaseTabSpace();
	AIMKEYSPACE->SetParent(TargettingSpace);
	AIMKEYSPACE->bDrawName = true;
	AIMKEYSPACE->Text = "Aim Key";
	AIMKEYSPACE->SetSize(225, m_iBoxSpacer + m_iBoxHeight * 1);
	AIMKEYSPACE->SetPos(10, 50);
	BaseSlider* AIMKEYSLIDER = new BaseSlider();
	AIMKEYSLIDER->SetPos(10, 11);
	AIMKEYSLIDER->SetWidth(205);
	AIMKEYSLIDER->SetParent(AIMKEYSPACE);
	AIMKEYSLIDER->SetRange(1, 5);
	AIMKEYSLIDER->Var = &gCmds.aimbot_key;


	LComboBox* TargetType = new LComboBox();
	TargetType->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 4.3);
	TargetType->SetSize(230, 20);
	TargetType->SetParent(TargettingSpace);
	TargetType->Text = "Method";
	TargetType->SetVar(&gCmds.aimbot_targetting);
	TargetType->AddOption("Distance", 1.0f);
	TargetType->AddOption("FOV", 2);

	BaseTabSpace* WeaponMods = new BaseTabSpace();
	WeaponMods->SetParent(AimbotTab);
	WeaponMods->bDrawName = true;
	WeaponMods->Text = "Weapon Mods";
	WeaponMods->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 4);
	WeaponMods->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 12);
	CreateCheck(WeaponMods, "No Recoil", &gCmds.aimbot_norecoil, 10, 15);
	CreateCheck(WeaponMods, "No Spread", &gCmds.aimbot_spread_comp, 10, 30);
	CreateCheck(WeaponMods, "Adaptive Recoil", &gCmds.aimbot_norecoil_adaptive, 10, 45);
	CreateCheck(WeaponMods, "Adaptive Spread", &gCmds.aimbot_nospread_adaptive, 10, 60);



	BaseTabSpace* AimSpaceSettings = new BaseTabSpace();
	AimSpaceSettings->SetParent(AimbotTab);
	AimSpaceSettings->bDrawName = true;
	AimSpaceSettings->Text = "Options";
	AimSpaceSettings->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 14);
	AimSpaceSettings->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(AimSpaceSettings, "Anti-Untrusted (Angle Clamping)", &gCmds.aimbot_fixangles, 10, 15);
	CreateCheck(AimSpaceSettings, "Silent Aim", &gCmds.aimbot_silent, 10, 30);
	CreateCheck(AimSpaceSettings, "Fix Movement", &gCmds.aimbot_fixmovement, 10, 45);
	CreateCheck(AimSpaceSettings, "Auto Shoot", &gCmds.aimbot_autoshoot, 10, 60);
	CreateCheck(AimSpaceSettings, "Auto Duck", &gCmds.aimbot_autoduck, 10, 75);
	CreateCheck(AimSpaceSettings, "Auto Aim", &gCmds.aimbot_auto, 10, 90);
	CreateCheck(AimSpaceSettings, "Auto Backstab", &gCmds.aimbot_triggerbackstab, 10, 105);
	CreateCheck(AimSpaceSettings, "Hit Scan", &gCmds.aimbot_hitscan, 10, 120);
	CreateCheck(AimSpaceSettings, "Aim at Bones", &gCmds.aimbot_bone, 10, 135);
	CreateCheck(AimSpaceSettings, "Auto Wall", &gCmds.aimbot_autowall, 10, 150);
	CreateCheck(AimSpaceSettings, "Gravity Prediction", &gCmds.aimbot_prediction_gravity, 10, 165);
	CreateCheck(AimSpaceSettings, "Engine Prediction", &gCmds.aimbot_prediction_engine, 10, 180);
	CreateCheck(AimSpaceSettings, "Eye Prediction", &gCmds.aimbot_prediction_eye, 10, 195);
	CreateCheck(AimSpaceSettings, "HVH Hitboxes", &gCmds.hvh_boxfix, 10, m_iBoxSpacer + 210);
	CreateCheck(AimSpaceSettings, "Projectile Prediction", &gCmds.aimbot_projectile_prediction, 10, m_iBoxSpacer + 225);
	CreateCheck(AimSpaceSettings, "Moving Accuracy", &gCmds.aimbot_moveaccuracy, 10, m_iBoxSpacer + 240);

	BaseTabSpace* TriggerSpace = new BaseTabSpace();
	TriggerSpace->SetParent(AimbotTab);
	TriggerSpace->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 4);
	TriggerSpace->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 15);
	CreateCheck(TriggerSpace, "Triggerbot", &gCmds.aimbot_triggerbot, 0, -5);
	BaseTabSpace* TriggerSpaceA = new BaseTabSpace();
	TriggerSpaceA->bDrawName = true;
	TriggerSpaceA->Text = "1 Hitscan, 2 Chest, 3 Head";
	TriggerSpaceA->SetParent(TriggerSpace);
	TriggerSpaceA->SetSize(180, m_iBoxSpacer + m_iBoxHeight * 1);
	TriggerSpaceA->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 1);
	BaseSlider* TriggerSpotSlider = new BaseSlider();
	TriggerSpotSlider->SetPos(10, 11);
	TriggerSpotSlider->SetWidth(160);
	TriggerSpotSlider->SetParent(TriggerSpaceA);
	TriggerSpotSlider->SetRange(1, 3);
	TriggerSpotSlider->Var = &gCmds.aimbot_trigger_spot;
	CreateCheck(TriggerSpace, "Recoil", &gCmds.aimbot_trigger_recoil, 10, 45);
	CreateCheck(TriggerSpace, "Spread", &gCmds.aimbot_trigger_spread, 10, 60);
	/* 2D ESP */
	BaseTabSpace* ESP2DOptions = new BaseTabSpace();
	ESP2DOptions->SetParent(ESP2DTab);
	ESP2DOptions->bDrawName = true;
	ESP2DOptions->Text = "Options";
	ESP2DOptions->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 6);
	ESP2DOptions->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(ESP2DOptions, "Crosshair", &gCmds.crosshair, 10, 15); CreateCheck(ESP2DOptions, "Recoil", &gCmds.ESP2D_recoilcross, 75, 15);
	CreateCheck(ESP2DOptions, "Hitmarker", &gCmds.ESP2D_hitmarker, 10, 30);
	CreateCheck(ESP2DOptions, "Hitsounds", &gCmds.ESP2D_hitsounds, 10, 45);
	CreateCheck(ESP2DOptions, "Accoldes", &gCmds.ESP2D_accoldes, 10, 60);
	CreateCheck(ESP2DOptions, "Killstreak Sounds", &gCmds.misc_killstreak_sounds, 10, 75);

	BaseTabSpace* ESP2DRightSideFIRST = new BaseTabSpace();
	ESP2DRightSideFIRST->SetParent(ESP2DTab);
	ESP2DRightSideFIRST->bDrawName = true;
	ESP2DRightSideFIRST->Text = "Tips";
	ESP2DRightSideFIRST->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 6);
	ESP2DRightSideFIRST->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(ESP2DRightSideFIRST, "Aiming Info Box", &gCmds.ESP2D_aiminginfobox, 10, 15);
	CreateCheck(ESP2DRightSideFIRST, "Local Stats Box", &gCmds.ESP2D_localstatbox, 10, 30);
	CreateCheck(ESP2DRightSideFIRST, "Spectator Box", &gCmds.ESP2D_spectatorlist, 10, 45);
	CreateCheck(ESP2DRightSideFIRST, "Warning for Explosives", &gCmds.ESP2D_explosiveswarning, 10, 60);
	CreateCheck(ESP2DRightSideFIRST, "Warning for Aimers", &gCmds.ESP2D_aimingatyouwarning, 10, 75);
	CreateCheck(ESP2DRightSideFIRST, "Warning for Jews", &gCmds.ESP2D_jewwarning, 10, 90);

	BaseTabSpace* ESP2DRightMiddle = new BaseTabSpace();
	ESP2DRightMiddle->SetParent(ESP2DTab);
	ESP2DRightMiddle->bDrawName = false;
	ESP2DRightMiddle->SetSize(150, m_iBoxSpacer + m_iBoxHeight * 2);
	ESP2DRightMiddle->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 8);
	CreateCheck(ESP2DRightMiddle, "Radar", &gCmds.ESP2D_radar, 0, -5);
	BaseSlider* ESP2DRadarSizeSlider = new BaseSlider();
	ESP2DRadarSizeSlider->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 1);
	ESP2DRadarSizeSlider->SetWidth(130);
	ESP2DRadarSizeSlider->SetParent(ESP2DRightMiddle);
	ESP2DRadarSizeSlider->SetRange(1, 250);
	ESP2DRadarSizeSlider->Var = &gCmds.radar_size;

	/* 3D ESP */
	BaseTabSpace* ExtrasTabOptions = new BaseTabSpace();
	ExtrasTabOptions->SetParent(ESP3DTab);
	ExtrasTabOptions->bDrawName = true;
	ExtrasTabOptions->Text = "ESP Extras";
	ExtrasTabOptions->SetSize(220, m_iBoxSpacer + m_iBoxHeight * 18);
	ExtrasTabOptions->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(ExtrasTabOptions, "Outline Boxes", &gCmds.esp_extra_outlinedbox, 10, 15);
	CreateCheck(ExtrasTabOptions, "Filled Boxes", &gCmds.esp_2dbox_fill, 10, 30);

	BaseTabSpace* HealthbarSpace = new BaseTabSpace();
	HealthbarSpace->SetParent(ExtrasTabOptions);
	HealthbarSpace->bDrawName = true;
	HealthbarSpace->Text = "Healthbars";
	HealthbarSpace->SetSize(150, m_iBoxSpacer + m_iBoxHeight * 6);
	HealthbarSpace->SetPos(10, 55);
	CreateCheck(HealthbarSpace, "Side", &gCmds.esp_extra_healthbarsside, 10, 15);
	CreateCheck(HealthbarSpace, "Vertical", &gCmds.esp_extra_verticalbars, 10, 30);
	CreateCheck(HealthbarSpace, "Outlined", &gCmds.esp_extra_outlinedhbars, 10, 45);
	CreateCheck(HealthbarSpace, "DrUnKeN ChEeTaH Style", &gCmds.esp_extra_gahealthbars, 10, 60);
	BaseTabSpace* Healthbarwidthspace = new BaseTabSpace();
	Healthbarwidthspace->SetParent(HealthbarSpace);
	Healthbarwidthspace->bDrawName = false;
	Healthbarwidthspace->SetSize(130, m_iBoxSpacer + m_iBoxHeight * 1);
	Healthbarwidthspace->SetPos(10, 80);
	BaseSlider* WidthSlider = new BaseSlider();
	WidthSlider->SetPos(10, 11);
	WidthSlider->SetWidth(110);
	WidthSlider->SetParent(Healthbarwidthspace);
	WidthSlider->SetRange(5, 100);
	WidthSlider->Var = &gCmds.esp_healthbar_width;

	CreateCheck(ExtrasTabOptions, "Local DLight", &gCmds.ESP3D_localdlight, 10, 175);
	CreateCheck(ExtrasTabOptions, "Team Color", &gCmds.esp_extra_teamcolors, 10, 190);
	CreateCheck(ExtrasTabOptions, "Side Text", &gCmds.esp_extra_sidetext, 10, 210);
	CreateCheck(ExtrasTabOptions, "Detailed Sentries, etc", &gCmds.esp_detailedobjects, 10, 225);
	CreateCheck(ExtrasTabOptions, "Skeleton Team Color", &gCmds.esp_skeleton_teamcolor, 10, 240);
	CreateCheck(ExtrasTabOptions, "Cornered Box", &gCmds.esp_extra_cornerbox, 10, 255);
	CreateCheck(ExtrasTabOptions, "Skinny Box", &gCmds.esp_extra_classicbox_skinny, 10, 270);
	CreateCheck(ExtrasTabOptions, "Zeals Box", &gCmds.esp_extra_zealsbox, 10, 285);
	BaseTabSpace* FontSpace = new BaseTabSpace();
	FontSpace->SetParent(ExtrasTabOptions);
	FontSpace->bDrawName = true;
	FontSpace->Text = "Font";
	FontSpace->SetSize(100, m_iBoxSpacer + m_iBoxHeight * 1);
	FontSpace->SetPos(10, 315);
	BaseSlider* FontSlider = new BaseSlider();
	FontSlider->SetPos(10, 11);
	FontSlider->SetWidth(80);
	FontSlider->SetParent(FontSpace);
	FontSlider->SetRange(0, 4);
	FontSlider->Var = &gCmds.esp_font;



	BaseTabSpace* ESP3DOptions = new BaseTabSpace();
	ESP3DOptions->SetParent(ESP3DTab);
	ESP3DOptions->bDrawName = true;
	ESP3DOptions->Text = "Options";
	ESP3DOptions->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 21);
	ESP3DOptions->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(ESP3DOptions, "Name Tags", &gCmds.esp_nametags, 10, 15);
	CreateCheck(ESP3DOptions, "Distance", &gCmds.ESP3D_distance, 10, 30);
	CreateCheck(ESP3DOptions, "Weapon", &gCmds.esp_weapon, 10, 45);
	CreateCheck(ESP3DOptions, "Health", &gCmds.esp_healthbar, 10, 60); CreateCheck(ESP3DOptions, "Text", &gCmds.esp_healthtext, 70, 60);
	CreateCheck(ESP3DOptions, "Armor", &gCmds.esp_armorbar, 10, 75); CreateCheck(ESP3DOptions, "Text", &gCmds.esp_armortext, 70, 75);
	CreateCheck(ESP3DOptions, "Skeleton", &gCmds.esp_skeleton, 10, 90);
	CreateColorButton(ESP3DOptions, "Bone Color", &gCmds.colBones, 35, 105, 100, 20);
	CreateCheck(ESP3DOptions, "2D Box", &gCmds.esp_box, 10, 135); CreateCheck(ESP3DOptions, "Draw Lines", &gCmds.esp_lines, 85, 135);
	CreateColorButton(ESP3DOptions, "Team", &gCmds.colTeam, 20, 150, 70, 20);
	CreateColorButton(ESP3DOptions, "Enemy", &gCmds.colEnemy, 20, 180, 70, 20);
	CreateCheck(ESP3DOptions, "Money", &gCmds.esp_money, 10, 210);
	CreateCheck(ESP3DOptions, "Is Defusing", &gCmds.esp_defusing, 10, 225);
	CreateCheck(ESP3DOptions, "SteamID", &gCmds.esp_steamid, 10, 240);
	CreateCheck(ESP3DOptions, "Aimbot Target", &gCmds.esp_aimspot, 10, 255);
	CreateCheck(ESP3DOptions, "Class", &gCmds.esp_class, 10, 270);
	CreateCheck(ESP3DOptions, "Cloaked & Disguised", &gCmds.esp_spy, 10, 285);
	CreateCheck(ESP3DOptions, "Conditions", &gCmds.esp_condition, 10, 300);
	CreateCheck(ESP3DOptions, "Traitor/Murder Finder", &gCmds.esp_baddiedetector, 10, 315);
	CreateCheck(ESP3DOptions, "Gun Barrel", &gCmds.ESP3D_gunbarrel, 10, 330);
	CreateCheck(ESP3DOptions, "Neon Player", &gCmds.ESP3D_neonplayer, 10, 345); CreateCheck(ESP3DOptions, "ELight", &gCmds.ESP3D_neonplayer_elight, 100, 345);
	BaseTabSpace* ESP3D_neonplayerSpace = new BaseTabSpace();
	ESP3D_neonplayerSpace->SetParent(ESP3DOptions);
	ESP3D_neonplayerSpace->bDrawName = true;
	ESP3D_neonplayerSpace->Text = "Radius";
	ESP3D_neonplayerSpace->SetSize(100, m_iBoxSpacer + m_iBoxHeight * 1);
	ESP3D_neonplayerSpace->SetPos(10, 365);
	BaseSlider* ESP3D_neonplayerSlider = new BaseSlider();
	ESP3D_neonplayerSlider->SetPos(10, 11);
	ESP3D_neonplayerSlider->SetWidth(80);
	ESP3D_neonplayerSlider->SetParent(ESP3D_neonplayerSpace);
	ESP3D_neonplayerSlider->SetRange(10, 110);
	ESP3D_neonplayerSlider->Var = &gCmds.ESP3D_neonplayer_radius;
	/* Frame */
	BaseTabSpace* FrameOptions = new BaseTabSpace();
	FrameOptions->SetParent(FrameTab);
	FrameOptions->bDrawName = true;
	FrameOptions->Text = "Options";
	FrameOptions->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 3);
	FrameOptions->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(FrameOptions, "Clock", &gCmds.clock, 10, 15); 	CreateCheck(FrameOptions, "Auto-Center", &gCmds.clock_autocenter, 55, 15);
	CreateCheck(FrameOptions, "Filter Steam Screenshots [F12]", &gCmds.misc_antiscreenshot, 10, 30);

	/* Vis Rem */
	BaseTabSpace* VisRemOptions = new BaseTabSpace();
	VisRemOptions->SetParent(RemovalsTab);
	VisRemOptions->bDrawName = true;
	VisRemOptions->Text = "Options";
	VisRemOptions->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 7);
	VisRemOptions->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(VisRemOptions, "No Hands", &gCmds.esp_nohands, 10, 15);
	CreateCheck(VisRemOptions, "No Fog", &gCmds.esp_nofog, 10, 30);
	CreateCheck(VisRemOptions, "No Flash", &gCmds.esp_noflash, 10, 45);
	CreateCheck(VisRemOptions, "No Smoke", &gCmds.esp_nosmoke, 10, 60);
	CreateCheck(VisRemOptions, "No Visual Recoil", &gCmds.aimbot_novisrecoil, 10, 75);
	CreateCheck(VisRemOptions, "Anti Disguise", &gCmds.esp_anti_disguise, 10, 90);
	CreateCheck(VisRemOptions, "Anti Cloak", &gCmds.esp_anti_cloak, 10, 105);
	CreateCheck(VisRemOptions, "No Weapon", &gCmds.esp_noweapon, 10, 120);
	/* Misc */
	BaseTabSpace* MiscTabOptionsRightBottom = new BaseTabSpace();
	MiscTabOptionsRightBottom->SetParent(MiscTab);
	MiscTabOptionsRightBottom->bDrawName = true;
	MiscTabOptionsRightBottom->Text = "Rage";
	MiscTabOptionsRightBottom->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 8);
	MiscTabOptionsRightBottom->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(MiscTabOptionsRightBottom, "Round Say", &gCmds.misc_roundsay, 10, 15);
	CreateCheck(MiscTabOptionsRightBottom, "Rage Quit Notice", &gCmds.misc_ragequitnotice, 10, 30);
	CreateCheck(MiscTabOptionsRightBottom, "Killstreak Say", &gCmds.misc_killstreak, 10, 45);
	BaseTabSpace* MiscTabOptionsRightSpamSide = new BaseTabSpace();
	MiscTabOptionsRightSpamSide->SetParent(MiscTabOptionsRightBottom);
	MiscTabOptionsRightSpamSide->bDrawName = true;
	MiscTabOptionsRightSpamSide->Text = "Spam";
	MiscTabOptionsRightSpamSide->SetSize(180, m_iBoxSpacer + m_iBoxHeight * 4);
	MiscTabOptionsRightSpamSide->SetPos(10, 70);
	CreateCheck(MiscTabOptionsRightSpamSide, "Normal", &gCmds.misc_chatspam_normal, 10, 15);
	CreateCheck(MiscTabOptionsRightSpamSide, "OOC", &gCmds.misc_chatspam_ooc, 10, 30);
	CreateCheck(MiscTabOptionsRightSpamSide, "Advert", &gCmds.misc_chatspam_advert, 10, 45);
	CreateCheck(MiscTabOptionsRightSpamSide, "PSAY/ASAY", &gCmds.misc_chatspam_ulx, 10, 60);



	BaseTabSpace* MiscTabOptions = new BaseTabSpace();
	MiscTabOptions->SetParent(MiscTab);
	MiscTabOptions->bDrawName = true;
	MiscTabOptions->Text = "Options";
	MiscTabOptions->SetSize(200, m_iBoxSpacer + m_iBoxHeight * 8);
	MiscTabOptions->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(MiscTabOptions, "Bunny Hop", &gCmds.misc_bhop, 10, 15);					CreateCheck(MiscTabOptions, "Duck", &gCmds.misc_bhopducker, 100, 15);
	CreateCheck(MiscTabOptions, "Auto Strafer", &gCmds.misc_bhop_autostrafe, 10, 30);	CreateCheck(MiscTabOptions, "Angle", &gCmds.misc_bhop_autostrafe_fast, 100, 30);
	CreateCheck(MiscTabOptions, "Auto Pistol", &gCmds.misc_autopistol, 10, 45);
	CreateCheck(MiscTabOptions, "Auto Flashlight", &gCmds.misc_flashlightspam, 10, 60);
	CreateCheck(MiscTabOptions, "Rapid +USE", &gCmds.misc_IN_USE_spam, 10, 75);
	CreateCheck(MiscTabOptions, "Auto Crosshair Commands", &gCmds.misc_thinkcrosshair, 10, 90);
	CreateCheck(MiscTabOptions, "Auto Clear Decals", &gCmds.misc_decalthinker, 10, 105);
	CreateButton(MiscTabOptions, "Disconnect", BB_DISCONNECT, 10, 120, 180, 14);
	/* Adv */
	BaseTabSpace* SpeedSpace = new BaseTabSpace();
	SpeedSpace->SetParent(HVHTab);
	SpeedSpace->bDrawName = false;
	SpeedSpace->SetSize(250, m_iBoxSpacer + m_iBoxHeight * 3 + 25);
	SpeedSpace->SetPos(285, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(SpeedSpace, "Speedhack", &gCmds.hvh_pspeed, 0, -5);
	CreateCheck(SpeedSpace, "Constant", &gCmds.hvh_pspeed_constant, 10, 15);
	CreateCheck(SpeedSpace, "Light Speed", &gCmds.hvh_telespeed, 10, 30);
	BaseTabSpace* SpeedSlideSpace = new BaseTabSpace();
	SpeedSlideSpace->SetParent(SpeedSpace);
	SpeedSlideSpace->bDrawName = true;
	SpeedSlideSpace->Text = "Speed";
	SpeedSlideSpace->SetSize(230, m_iBoxSpacer + m_iBoxHeight * 1);
	SpeedSlideSpace->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 1 + 35);
	BaseSlider* SpeedSlider = new BaseSlider();
	SpeedSlider->SetPos(10, 11);
	SpeedSlider->SetWidth(205);
	SpeedSlider->SetParent(SpeedSlideSpace);
	SpeedSlider->SetRange(2, 45);
	SpeedSlider->Var = &gCmds.aimbot_pspeed_speed;



	BaseTabSpace* HVHSpace = new BaseTabSpace();
	HVHSpace->SetParent(HVHTab);
	HVHSpace->bDrawName = false;
	HVHSpace->SetSize(125, m_iBoxSpacer + m_iBoxHeight * 3.5);
	HVHSpace->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(HVHSpace, "Hack vs Hack", &gCmds.hvh_enabled, 0, -5);
	CreateCheck(HVHSpace, "Fake Lag", &gCmds.hvh_fakelag, 10, 15);
	LComboBox* AntiAimTYPE = new LComboBox();
	AntiAimTYPE->SetParent(HVHSpace);
	AntiAimTYPE->SetPos(10, m_iBoxSpacer + m_iBoxHeight * 2);
	AntiAimTYPE->SetSize(105, 20);
	AntiAimTYPE->Text = "Anti Aim";
	AntiAimTYPE->SetVar(&gCmds.hvh_antiaim);
	AntiAimTYPE->AddOption("Jitter", 1);
	AntiAimTYPE->AddOption("Fake Jitter", 2);
	AntiAimTYPE->AddOption("Right", 3);
	AntiAimTYPE->AddOption("Fake Ang", 4);
	AntiAimTYPE->AddOption("Custom", 5);
	AntiAimTYPE->AddOption("KAA", 6);
	AntiAimTYPE->AddOption("Spinner", 7);
	/* Filter */
	BaseTabSpace* FilterTabAimbot = new BaseTabSpace();
	FilterTabAimbot->SetParent(FilterTab);
	FilterTabAimbot->SetSize(170, m_iBoxSpacer + m_iBoxHeight * 11);
	FilterTabAimbot->SetPos(m_iPadding, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(FilterTabAimbot, "Aimboat", &gCmds.Win200_AimbotLoop, 0, -5);
	CreateCheck(FilterTabAimbot, "Aim at NPCS", &gCmds.aimbot_aim_npc, 10, 15);
	CreateCheck(FilterTabAimbot, "Aim at Players", &gCmds.aimbot_aim_player, 10, 30);
	CreateCheck(FilterTabAimbot, "Aim at Buildings", &gCmds.filter_aimbot_buildings, 10, 45);
	CreateCheck(FilterTabAimbot, "Aim at Only Friends", &gCmds.aimbot_onlyfriends, 10, 60);
	CreateCheck(FilterTabAimbot, "Aim at Only Bots", &gCmds.aimbot_onlybots, 10, 75);
	CreateCheck(FilterTabAimbot, "Ignore Team", &gCmds.aimbot_ignoreteam, 10, 90);
	CreateCheck(FilterTabAimbot, "Ignore Enemies [TTT]", &gCmds.aimbot_onlyteam, 10, 105);
	CreateCheck(FilterTabAimbot, "Ignore Friends", &gCmds.aimbot_ignorefriends, 10, 120);
	CreateCheck(FilterTabAimbot, "Ignore Non-Visibles", &gCmds.aimbot_visibilitycheck, 10, 135);
	CreateCheck(FilterTabAimbot, "Ignore SpawnProtected", &gCmds.aimbot_ignorecolor, 10, 150);
	CreateCheck(FilterTabAimbot, "Aim Chicken", &gCmds.filter_aimbot_chicken, 10, 165);

	BaseTabSpace* FilterTabESP = new BaseTabSpace();
	FilterTabESP->SetParent(FilterTab);
	FilterTabESP->SetSize(300, m_iBoxSpacer + m_iBoxHeight * 14);
	FilterTabESP->SetPos(m_iPadding * 5, m_iBoxSpacer + m_iBoxHeight * 1);
	CreateCheck(FilterTabESP, "ESP", &gCmds.Win200_ESPLoop, 0, -5);
	CreateCheck(FilterTabESP, "Draw NPCS", &gCmds.filter_esp_npc, 10, 15);
	CreateCheck(FilterTabESP, "Draw Players", &gCmds.filter_esp_player, 10, 30);
	CreateCheck(FilterTabESP, "Draw Buildings", &gCmds.filter_esp_buildings, 10, 45);
	CreateCheck(FilterTabESP, "Draw Entities", &gCmds.esp_ents, 10, 60);
	CreateCheck(FilterTabESP, "Draw RP Money", &gCmds.esp_money, 10, 75);
	CreateCheck(FilterTabESP, "Draw Printers", &gCmds.esp_printer, 10, 90);
	CreateCheck(FilterTabESP, "Draw Dropped Weapons", &gCmds.filter_esp_droppedweapon, 10, 105);
	CreateCheck(FilterTabESP, "Draw Team", &gCmds.filter_esp_drawteam, 10, 120);
	CreateCheck(FilterTabESP, "Draw Dormant", &gCmds.filter_esp_drawdormant, 10, 135);
	CreateCheck(FilterTabESP, "Only Draw Friends", &gCmds.filter_esp_drawonlyfriends, 10, 150);
	CreateCheck(FilterTabESP, "Only Draw Aimbot Target", &gCmds.filter_esp_aimtargetonly, 10, 165);
	CreateCheck(FilterTabESP, "Draw World Ammo", &gCmds.filter_esp_ammo, 10, 180);
	CreateCheck(FilterTabESP, "Draw World Health/Med Kits", &gCmds.filter_esp_medkits, 10, 195);
	CreateCheck(FilterTabESP, "Draw World Printers/Money/Gifts", &gCmds.filter_esp_misc, 10, 210);
	CreateCheck(FilterTabESP, "Draw Chicken", &gCmds.filter_esp_chicken, 10, 225);

	BaseTabSpace* FilterTabESP2D = new BaseTabSpace();
	FilterTabESP2D->SetParent(FilterTab);
	FilterTabESP2D->SetSize(140, m_iBoxSpacer + m_iBoxHeight * 5);
	FilterTabESP2D->SetPos(m_iPadding * 8, m_iBoxSpacer + m_iBoxHeight * 1 + 20);
	CreateCheck(FilterTabESP2D, "Radar", &gCmds.ESP2D_radar, 0, -5);
	CreateCheck(FilterTabESP2D, "Draw NPC", &gCmds.radar_filter_radar_npcs, 10, 15);
	CreateCheck(FilterTabESP2D, "Draw Players", &gCmds.radar_filter_radar_players, 10, 30);
	CreateCheck(FilterTabESP2D, "Draw Projectiles", &gCmds.radar_filter_radar_projectiles, 10, 45);
	CreateCheck(FilterTabESP2D, "Draw Medkit", &gCmds.radar_filter_radar_health, 10, 60);
	CreateCheck(FilterTabESP2D, "Draw Chicken", &gCmds.radar_filter_radar_chicken, 10, 75);

	TabProperty->SetCurrentTab(0);

} BaseMenu *Menu = new BaseMenu();
//======================================================================

//======================================================================
void BaseMenu::Think()
{
	for (BaseObject* Object : *ObjectList)
		Object->Tick();
}
//======================================================================

//======================================================================
void BaseMenu::Paint()
{
	for (BaseObject* Object : *ObjectList)
		Object->Paint();
}
//======================================================================