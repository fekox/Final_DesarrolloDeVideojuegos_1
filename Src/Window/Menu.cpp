#include "Window/Menu.h"

MenuButton play;
MenuButton controlls;
MenuButton rules;
MenuButton credits;
MenuButton quit;
MenuButton returnMenu;

MenuButton ichiolinkF;

void InitMenu()
{
	//Play Button
	play.pos.x = static_cast<float>(GetScreenWidth() / 12);
	play.pos.y = static_cast<float>(GetScreenHeight() / 3.2f);
	play.width = static_cast<float>(GetScreenWidth() / 9);
	play.height = static_cast<float>(GetScreenHeight() / 10);
	play.size = 50;
	play.isActive = false;
	play.repoTexX = 40;
	play.repoTexY = 10;

	play.color = WHITE;

	//Controlls Button
	controlls.pos.x = static_cast<float>(GetScreenWidth() / 20);
	controlls.pos.y = static_cast<float>(GetScreenHeight() / 2.35f);
	controlls.width = static_cast<float>(GetScreenWidth() / 5);
	controlls.height = static_cast<float>(GetScreenHeight() / 10);
	controlls.size = 50;
	controlls.isActive = false;

	controlls.color = WHITE;

	//Rules Button
	rules.pos.x = static_cast<float>(GetScreenWidth() / 12);
	rules.pos.y = static_cast<float>(GetScreenHeight() / 1.84f);
	rules.width = static_cast<float>(GetScreenWidth() / 8);
	rules.height = static_cast<float>(GetScreenHeight() / 10);
	rules.size = 50;
	rules.isActive = false;
	rules.repoTexX = 40;
	rules.repoTexY = 10;

	rules.color = WHITE;

	//Credits Button
	credits.pos.x = static_cast<float>(GetScreenWidth() / 1.5f);
	credits.pos.y = static_cast<float>(GetScreenHeight() / 1.1f);
	credits.width = static_cast<float>(GetScreenWidth() / 3.25f);
	credits.height = static_cast<float>(GetScreenHeight() / 10);
	credits.size = 50;
	credits.isActive = false;
	credits.repoTexX = 30;

	credits.color = WHITE;

	//Quit Button
	quit.pos.x = static_cast<float>(GetScreenWidth() / 12);
	quit.pos.y = static_cast<float>(GetScreenHeight() / 1.53f);
	quit.width = static_cast<float>(GetScreenWidth() / 10);
	quit.height = static_cast<float>(GetScreenHeight() / 10);
	quit.size = 50;
	quit.isActive = false;
	quit.repoTexX = 40;
	quit.repoTexY = 10;

	quit.color = WHITE;

	//ReturnMenu Button
	returnMenu.pos.x = static_cast<float>(GetScreenWidth() / 2.5f);
	returnMenu.pos.y = static_cast<float>(GetScreenHeight() / 1.1f);
	returnMenu.width = static_cast<float>(GetScreenWidth() / 8);
	returnMenu.height = static_cast<float>(GetScreenHeight() / 10);
	returnMenu.size = 50;
	returnMenu.isActive = false;

	returnMenu.color = WHITE;

	//itch.io Link Feko_Games
	ichiolinkF.pos.x = static_cast<float>(GetScreenWidth() / 2.4f);
	ichiolinkF.pos.y = static_cast<float>(GetScreenHeight() / 3.5f);
	ichiolinkF.width = static_cast<float>(GetScreenWidth() / 6);
	ichiolinkF.height = static_cast<float>(GetScreenHeight() / 10);
	ichiolinkF.size = 50;
	ichiolinkF.isActive = false;

	ichiolinkF.color = WHITE;
}

void MenuCollisions(Mouse& mouse, int& optionSelect)
{
	//Play Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 3.5f), static_cast<float>(play.width), static_cast<float>(play.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		play.color = RED;
	}

	else
	{
		play.color = WHITE;
	}

	//Controlls Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 22), static_cast<float>(GetScreenHeight() / 2.5f), static_cast<float>(controlls.width), static_cast<float>(controlls.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		controlls.color = RED;
	}

	else
	{
		controlls.color = WHITE;
	}

	//Rules Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 1.94f), static_cast<float>(rules.width), static_cast<float>(rules.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		rules.color = RED;
	}

	else
	{
		rules.color = WHITE;
	}

	//Credits Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5f), static_cast<float>(GetScreenHeight() / 1.13f), static_cast<float>(credits.width), static_cast<float>(credits.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		credits.color = RED;
	}

	else
	{
		credits.color = WHITE;
	}

	//itch.io Link Feko_Games
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.5f), static_cast<float>(GetScreenHeight() / 3.8f), static_cast<float>(ichiolinkF.width), static_cast<float>(ichiolinkF.height) }) && optionSelect == 4)
	{
		ichiolinkF.color = RED;
	}

	else
	{
		ichiolinkF.color = WHITE;
	}

	//Quit Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 1.59f), static_cast<float>(quit.width), static_cast<float>(quit.height) }) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
	{
		quit.color = RED;
	}

	else
	{
		quit.color = WHITE;
	}

	//ReturnMenu Button
	if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.6f), static_cast<float>(GetScreenHeight() / 1.12f), static_cast<float>(returnMenu.width), static_cast<float>(returnMenu.height) }) && optionSelect != 1)
	{
		returnMenu.color = RED;
	}

	else
	{
		returnMenu.color = WHITE;
	}
}

void MenuInputs(Mouse& mouse, int& optionSelect, bool& playGame)
{
	if (!playGame)
	{
		//Play Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 3.5f), static_cast<float>(play.width), static_cast<float>(play.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 1;
				play.isActive = true;
				playGame = true;
				HideCursor();
			}
		}

		//Controlls Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 22), static_cast<float>(GetScreenHeight() / 2.5f), static_cast<float>(controlls.width), static_cast<float>(controlls.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 2;
			}
		}

		//Rules Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 1.94f), static_cast<float>(rules.width), static_cast<float>(rules.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 3;
			}
		}

		//Credits Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 1.5f), static_cast<float>(GetScreenHeight() / 1.13f), static_cast<float>(credits.width), static_cast<float>(credits.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 4;
			}
		}

		//itch.io Link Feko_Games
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.5f), static_cast<float>(GetScreenHeight() / 3.8f), static_cast<float>(ichiolinkF.width), static_cast<float>(ichiolinkF.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect == 4)
			{
				OpenURL("https://feco-games.itch.io/");
			}
		}

		//Quit Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 14), static_cast<float>(GetScreenHeight() / 1.59f), static_cast<float>(quit.width), static_cast<float>(quit.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1 && optionSelect != 2 && optionSelect != 3 && optionSelect != 4 && optionSelect != 5)
			{
				optionSelect = 5;
			}
		}

		//ReturnMenu Button
		if (CheckCollisionPointRec(mouse.position, Rectangle{ static_cast<float>(GetScreenWidth() / 2.6f), static_cast<float>(GetScreenHeight() / 1.12f), static_cast<float>(returnMenu.width), static_cast<float>(returnMenu.height) }))
		{
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && optionSelect != 1)
			{
				optionSelect = 0;
				playGame = false;
			}
		}
	}
}

void DrawMenu(Font gameFont, Texture menuBackground, Texture buttonTex)
{
	ClearBackground(BLACK);

	//Menu Background
	DrawTexture(menuBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "  Pingu ", { static_cast<float>(GetScreenWidth() / 20) , static_cast<float>(GetScreenHeight() / 20) }, 80, 0, GOLD);
	DrawTextEx(gameFont, "Climber", { static_cast<float>(GetScreenWidth() / 20) , static_cast<float>(GetScreenHeight() / 7) }, 80, 0, GOLD);

	//Play Button
	DrawTexture(buttonTex, static_cast<int>(GetScreenWidth() / 14) - play.repoTexX, static_cast<int>(GetScreenHeight() / 3.5f) + play.repoTexY, WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 14), static_cast<int>(GetScreenHeight() / 3.5), static_cast<int>(play.width), static_cast<int>(play.height), BLANK);
	DrawTextEx(gameFont, "PLAY", play.pos, static_cast<float>(play.size), 0, play.color);

	//Controlls Button
	DrawTexture(buttonTex, static_cast<int>(GetScreenWidth() / 22), static_cast<int>(GetScreenHeight() / 2.5), WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 22), static_cast<int>(GetScreenHeight() / 2.5f), static_cast<int>(controlls.width), static_cast<int>(controlls.height), BLANK);
	DrawTextEx(gameFont, "CONTROLLS", controlls.pos, static_cast<float>(controlls.size), 0, controlls.color);

	//Rules Button
	DrawTexture(buttonTex, static_cast<int>(GetScreenWidth() / 14) - rules.repoTexX, static_cast<int>(GetScreenHeight() / 1.94f) + rules.repoTexY, WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 14), static_cast<int>(GetScreenHeight() / 1.94), static_cast<int>(rules.width), static_cast<int>(rules.height), BLANK);
	DrawTextEx(gameFont, "RULES", rules.pos, static_cast<float>(rules.size), 0, rules.color);

	//Credits Button
	DrawTexture(buttonTex, static_cast<int>(GetScreenWidth() / 1.5f) - credits.repoTexX, static_cast<int>(GetScreenHeight() / 1.13f), WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 1.5f), static_cast<int>(GetScreenHeight() / 1.13f), static_cast<int>(credits.width), static_cast<int>(credits.height), BLANK);
	DrawTextEx(gameFont, "CREDITS", credits.pos, static_cast<float>(credits.size), 0, credits.color);

	//Quit Button
	DrawTexture(buttonTex, static_cast<int>(GetScreenWidth() / 14) - quit.repoTexX, static_cast<int>(GetScreenHeight() / 1.59f) + quit.repoTexY, WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 14), static_cast<int>(GetScreenHeight() / 1.59f), static_cast<int>(quit.width), static_cast<int>(quit.height), BLANK);
	DrawTextEx(gameFont, "QUIT", quit.pos, static_cast<float>(quit.size), 0, quit.color);
}

void DrawControlls(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "Controlls", { static_cast<float>(GetScreenWidth() / 2.8f) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	DrawTextEx(gameFont, "PLAYER", { static_cast<float>(GetScreenWidth() / 7) , static_cast<float>(GetScreenHeight() / 5) }, 50, 0, GOLD);

	//Player
	DrawTextEx(gameFont, "move\tA D", { static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 3.5f) }, 50, 0, WHITE);
	DrawTextEx(gameFont, "jump\t  W", { static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 2.8f) }, 50, 0, WHITE);
	DrawTextEx(gameFont, "down\t  S", { static_cast<float>(GetScreenWidth() / 8) , static_cast<float>(GetScreenHeight() / 2.4f) }, 50, 0, WHITE);

	//Pause
	DrawTextEx(gameFont, "PAUSE", { static_cast<float>(GetScreenWidth() / 1.5f) , static_cast<float>(GetScreenHeight() / 5) }, 50, 0, GOLD);
	DrawTextEx(gameFont, "esc or p ", { static_cast<float>(GetScreenWidth() / 1.5f) , static_cast<float>(GetScreenHeight() / 3.5f) }, 50, 0, WHITE);
	DrawTextEx(gameFont, "pause ", { static_cast<float>(GetScreenWidth() / 1.5f) , static_cast<float>(GetScreenHeight() / 2.8f) }, 50, 0, WHITE);
	DrawTextEx(gameFont, "button", { static_cast<float>(GetScreenWidth() / 1.5f) , static_cast<float>(GetScreenHeight() / 2.4f) }, 50, 0, WHITE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.6f), static_cast<int>(GetScreenHeight() / 1.12f), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawRules(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "RULES", { static_cast<float>(GetScreenWidth() / 2.5f) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	DrawTextEx(gameFont, "Help this little penguin to return to his family, if you\ncollide with an enemy or an obstacle you will have\nto start over. To win you must overcome all obstacles,\nclimb the platforms and reach the top of the abyss.\n\nPD: If you step on an enemy you kill him.",
		{ static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 4) }, 50, 0, WHITE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.6f), static_cast<int>(GetScreenHeight() / 1.12f), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}

void DrawCredits(Font gameFont, Texture subMenusBackground)
{
	ClearBackground(BLACK);

	//Sub Menu Background
	DrawTexture(subMenusBackground, 0, 0, WHITE);

	DrawTextEx(gameFont, "CREDITS", { static_cast<float>(GetScreenWidth() / 2.5f) , static_cast<float>(GetScreenHeight() / 15) }, 60, 0, GOLD);

	//itch.io Link Feko_Games
	DrawText("Facundo Santos", static_cast<int>(GetScreenWidth() / 3.5f), static_cast<int>(GetScreenHeight() / 5.5f), 50, WHITE);
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.5f), static_cast<int>(GetScreenHeight() / 3.8f), static_cast<int>(ichiolinkF.width), static_cast<int>(ichiolinkF.height), BLANK);
	DrawTextEx(gameFont, "ITCH.IO", ichiolinkF.pos, static_cast<float>(ichiolinkF.size), 0, ichiolinkF.color);

	DrawTextEx(gameFont, "FONT", { static_cast<float>(GetScreenWidth() / 6.5f) , static_cast<float>(GetScreenHeight() / 2.6f) }, 30, 0, GOLD);

	DrawTextEx(gameFont, "https://www.dafont.com/es/rocket-vintage.font", { static_cast<float>(GetScreenWidth() / 12) , static_cast<float>(GetScreenHeight() / 2.3f) }, 20, 0, WHITE);

	DrawTextEx(gameFont, "SPRITES", { static_cast<float>(GetScreenWidth() / 1.3f) , static_cast<float>(GetScreenHeight() / 2.6f) }, 30, 0, GOLD);

	DrawTextEx(gameFont, "https://www.pinterest.cl/pin/725149977490142903/", { static_cast<float>(GetScreenWidth() / 1.6f) , static_cast<float>(GetScreenHeight() / 2.3f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://ar.pinterest.com/pin/640637115762309743/", { static_cast<float>(GetScreenWidth() / 1.6f) , static_cast<float>(GetScreenHeight() / 2.15f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://spelunky.fyi/mods/m/penguin-skin-sprite-sheet/", { static_cast<float>(GetScreenWidth() / 1.6f), static_cast<float>(GetScreenHeight() / 2) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://forums.rpgmakerweb.com/index.php?threads/looking-for-sea-mammal-sprites.67753/#post-644773", { static_cast<float>(GetScreenWidth() / 3.5f) , static_cast<float>(GetScreenHeight() / 1.9f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://www.deviantart.com/redballbomb/art/Giga-water-ice-effects-sprite-sheet-788776529", { static_cast<float>(GetScreenWidth() / 3.5f) , static_cast<float>(GetScreenHeight() / 1.8f) }, 20, 0, WHITE);

	DrawTextEx(gameFont, "MUSIC", { static_cast<float>(GetScreenWidth() / 2.4f) , static_cast<float>(GetScreenHeight() / 1.5f) }, 30, 0, GOLD);
	DrawTextEx(gameFont, "https://pixabay.com/music/christmas-sleigh-ride-snowflake-swing-10951/", { static_cast<float>(GetScreenWidth() / 4.5f) , static_cast<float>(GetScreenHeight() / 1.4f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://www.youtube.com/watch?v=MFw3E6X5aoA", { static_cast<float>(GetScreenWidth() / 3.5f) , static_cast<float>(GetScreenHeight() / 1.35f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://pixabay.com/sound-effects/cartoon-jump-6462/", { static_cast<float>(GetScreenWidth() / 3.4f) , static_cast<float>(GetScreenHeight() / 1.3f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://pixabay.com/sound-effects/wrong-answer-126515/", { static_cast<float>(GetScreenWidth() / 3.4f) , static_cast<float>(GetScreenHeight() / 1.25f) }, 20, 0, WHITE);
	DrawTextEx(gameFont, "https://pixabay.com/sound-effects/punch-2-37333/", { static_cast<float>(GetScreenWidth() / 3.4f) , static_cast<float>(GetScreenHeight() / 1.2f) }, 20, 0, WHITE);

	//ReturnMenu Button
	DrawRectangle(static_cast<int>(GetScreenWidth() / 2.6f), static_cast<int>(GetScreenHeight() / 1.12f), static_cast<int>(returnMenu.width), static_cast<int>(returnMenu.height), BLANK);
	DrawTextEx(gameFont, "MENU", returnMenu.pos, static_cast<float>(returnMenu.size), 0, returnMenu.color);
}