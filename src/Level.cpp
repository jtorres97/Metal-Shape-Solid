#include "Level.h"

Level::Level()
{
	stage = 5;
}

void Level::Init()
{
	walls.clear();
	enemies.clear();
	doors.clear();
	buttons.clear();
	lights.clear();

	if (stage == 0)
	{
		walls = {
			{100, 80, 20, 270},
			{120, 80, 60, 20},
			{120, 330, 60, 20},
			{120, 200, 200, 20},
			{320, 80, 20, 270},
			{260, 80, 60, 20},
			{260, 330, 60, 20},
			{500, 10, 20, 160},
			{500, 250, 20, 160},
			{320, 350, 20, 60}
		};

		doors = {
			{180, 330, 80, 20},
			{320, 10, 20, 70},
			{500, 170, 20, 80}
		};

		buttons = {
			{280, 140, 20, 20},
			{150, 270, 20, 20}
		};
		buttons[0].SetOperation(1, 1);
		buttons[1].SetOperation(0, 1);

		lights = {
			{180, 100, 140, 100},
			{120, 220, 140, 110}
		};

		enemies = {
			{390, 50, {390, 50}, {390, 300}}
		};
		enemies[0].SetPatrolParameters();
	}
	else if (stage == 1)
	{
		lights = {
			{60, 10, 60, 400},
			{180, 10, 60, 400},
			{300, 10, 60, 400},
			{420, 10, 60, 400},
			{540, 10, 60, 400}
		};

		enemies = {
			{589, 180, {590, 180}, {1, 1}}
		};
		enemies[0].SetStandingParameters();
	}
	else if (stage == 2)
	{
		walls = {
			{100, 100, 530, 20},
			{100, 300, 530, 20}
		};

		doors = {
			{120, 120, 20, 18},
			{550, 120, 20, 180}
		};

		buttons = {
			{550, 50, 20, 20},
			{550, 350, 20, 20}
		};
		buttons[0].SetOperation(1, 1);
		buttons[1].SetOperation(0, 1);

		enemies = {
			{395, 120, {470, 120}, {170, 120}},
			{320, 180, {470, 180}, {170, 180}},
			{245, 240, {470, 240}, {170, 240}},
			{170, 25, {170, 25}, {470, 25}},
			{470, 335, {170, 335}, {470, 335}}
		};

		for (auto& enemy : enemies)
		{
			enemy.SetPatrolParameters();
		}
	}
	else if (stage == 3)
	{
		walls = {
			{90, 60, 20, 100},
			{240, 60, 20, 100},
			{390, 60, 20, 100},
			{540, 60, 20, 100},
			{90, 250, 20, 100},
			{240, 250, 20, 100},
			{390, 250, 20, 100},
			{540, 250, 20, 100},
			{10, 140, 90, 20},
			{10, 250, 90, 20},
			{560, 140, 70, 20},
			{560, 250, 70, 20},
			{90, 40, 470, 20},
			{90, 350, 470, 20}
		};

		doors = {
			{110, 140, 130, 20},
			{260, 140, 130, 20},
			{410, 140, 130, 20},
			{110, 250, 130, 20},
			{260, 250, 130, 20},
			{410, 250, 130, 20},
			{240, 160, 20, 90},
			{390, 160, 20, 90},
			{540, 160, 20, 90}
		};

		buttons = {
			{165, 85, 20, 20},
			{315, 85, 20, 20},
			{465, 85, 20, 20},
			{165, 195, 20, 20},
			{315, 195, 20, 20},
			{465, 195, 20, 20},
			{165, 305, 20, 20},
			{315, 305, 20, 20},
			{465, 305, 20, 20}
		};

		buttons[0].SetOperation(0, 0);
		buttons[0].SetOperation(1, 0);
		buttons[0].SetOperation(2, 1);
		buttons[0].SetOperation(3, 0);
		buttons[0].SetOperation(4, 1);
		buttons[0].SetOperation(5, 0);
		buttons[0].SetOperation(6, 1);
		buttons[0].SetOperation(7, 0);
		buttons[0].SetOperation(8, 1);

		buttons[1].SetOperation(0, 1);
		buttons[1].SetOperation(1, 0);
		buttons[1].SetOperation(2, 1);
		buttons[1].SetOperation(3, 1);
		buttons[1].SetOperation(4, 1);
		buttons[1].SetOperation(5, 1);
		buttons[1].SetOperation(6, 3);
		buttons[1].SetOperation(7, 0);
		buttons[1].SetOperation(8, 3);

		buttons[2].SetOperation(0, 0);
		buttons[2].SetOperation(1, 1);
		buttons[2].SetOperation(2, 0);
		buttons[2].SetOperation(3, 1);
		buttons[2].SetOperation(4, 0);
		buttons[2].SetOperation(5, 1);
		buttons[2].SetOperation(6, 0);
		buttons[2].SetOperation(7, 1);
		buttons[2].SetOperation(8, 1);

		buttons[3].SetOperation(0, 1);
		buttons[3].SetOperation(1, 1);
		buttons[3].SetOperation(2, 1);
		buttons[3].SetOperation(3, 1);
		buttons[3].SetOperation(4, 0);
		buttons[3].SetOperation(5, 1);
		buttons[3].SetOperation(6, 2);
		buttons[3].SetOperation(7, 1);
		buttons[3].SetOperation(8, 1);

		buttons[4].SetOperation(0, 1);
		buttons[4].SetOperation(1, 0);
		buttons[4].SetOperation(2, 1);
		buttons[4].SetOperation(3, 1);
		buttons[4].SetOperation(4, 1);
		buttons[4].SetOperation(5, 1);
		buttons[4].SetOperation(6, 0);
		buttons[4].SetOperation(7, 1);
		buttons[4].SetOperation(8, 1);

		buttons[5].SetOperation(0, 1);
		buttons[5].SetOperation(1, 1);
		buttons[5].SetOperation(2, 1);
		buttons[5].SetOperation(3, 0);
		buttons[5].SetOperation(4, 0);
		buttons[5].SetOperation(5, 1);
		buttons[5].SetOperation(6, 1);
		buttons[5].SetOperation(7, 1);
		buttons[5].SetOperation(8, 1);

		buttons[6].SetOperation(0, 1);
		buttons[6].SetOperation(1, 0);
		buttons[6].SetOperation(2, 0);
		buttons[6].SetOperation(3, 0);
		buttons[6].SetOperation(4, 1);
		buttons[6].SetOperation(5, 1);
		buttons[6].SetOperation(6, 1);
		buttons[6].SetOperation(7, 1);
		buttons[6].SetOperation(8, 1);

		buttons[7].SetOperation(0, 3);
		buttons[7].SetOperation(1, 3);
		buttons[7].SetOperation(2, 3);
		buttons[7].SetOperation(3, 3);
		buttons[7].SetOperation(4, 3);
		buttons[7].SetOperation(5, 3);
		buttons[7].SetOperation(6, 2);
		buttons[7].SetOperation(7, 3);
		buttons[7].SetOperation(8, 2);

		buttons[8].SetOperation(0, 3);
		buttons[8].SetOperation(1, 3);
		buttons[8].SetOperation(2, 3);
		buttons[8].SetOperation(3, 3);
		buttons[8].SetOperation(4, 3);
		buttons[8].SetOperation(5, 0);
		buttons[8].SetOperation(6, 2);
		buttons[8].SetOperation(7, 2);
		buttons[8].SetOperation(8, 1);
	}
	else if (stage == 4)
	{
		walls = {
			{10, 250, 90, 20},
			{80, 150, 20, 100},
			{80, 70, 370, 20},
			{170, 90, 20, 100},
			{260, 90, 20, 180},
			{170, 270, 20, 80},
			{80, 330, 270, 20},
			{350, 250, 20, 100},
			{350, 170, 100, 20},
			{450, 330, 80, 20},
			{530, 70, 20, 280}
		};

		doors = {
			{280, 170, 70, 20},
			{260, 10, 20, 60},
			{430, 90, 20, 80},
			{550, 70, 80, 20},
			{550, 130, 80, 20},
			{550, 270, 80, 20},
			{550, 330, 80, 20}
		};

		lights = {
			{205, 90, 40, 40},
			{15, 370, 35, 35},
			{490, 290, 40, 40},
			{280, 90, 40, 40}
		};

		buttons = {
			{215, 100, 20, 20},
			{20, 380, 20, 20},
			{500, 300, 20, 20},
			{290, 100, 20, 20}
		};

		buttons[0].SetOperation(0, 0);
		buttons[0].SetOperation(1, 1);
		buttons[0].SetOperation(2, 1);
		buttons[0].SetOperation(3, 1);
		buttons[0].SetOperation(4, 1);
		buttons[0].SetOperation(5, 1);
		buttons[0].SetOperation(6, 1);

		buttons[1].SetOperation(0, 1);
		buttons[1].SetOperation(1, 0);
		buttons[1].SetOperation(2, 0);
		buttons[1].SetOperation(3, 1);
		buttons[1].SetOperation(4, 1);
		buttons[1].SetOperation(5, 1);
		buttons[1].SetOperation(6, 1);

		buttons[2].SetOperation(0, 1);
		buttons[2].SetOperation(1, 1);
		buttons[2].SetOperation(2, 1);
		buttons[2].SetOperation(3, 0);
		buttons[2].SetOperation(4, 1);
		buttons[2].SetOperation(5, 0);
		buttons[2].SetOperation(6, 1);

		buttons[3].SetOperation(0, 1);
		buttons[3].SetOperation(1, 1);
		buttons[3].SetOperation(2, 1);
		buttons[3].SetOperation(3, 1);
		buttons[3].SetOperation(4, 0);
		buttons[3].SetOperation(5, 1);
		buttons[3].SetOperation(6, 0);

		enemies = {
			{400, 10, {470, 10}, {130, 10}},
			{150, 350, {460, 350}, {20, 350}},
			{90, 100, {90, 100}, {490, 280}}
		};

		for (auto& enemy : enemies)
		{
			enemy.SetPatrolParameters();
		}
	}
	else if (stage == 5)
	{
		lights = {
			{50, 35, 50, 50},
			{50, 135, 50, 50},
			{50, 235, 50, 50},
			{50, 335, 50, 50},
			{100, 85, 50, 50},
			{100, 185, 50, 50},
			{100, 285, 50, 50},
			{150, 35, 50, 50},
			{150, 135, 50, 50},
			{150, 235, 50, 50},
			{150, 335, 50, 50},
			{200, 85, 50, 50},
			{200, 185, 50, 50},
			{200, 285, 50, 50},
			{250, 35, 50, 50},
			{250, 135, 50, 50},
			{250, 235, 50, 50},
			{250, 335, 50, 50},
			{300, 85, 50, 50},
			{300, 185, 50, 50},
			{300, 285, 50, 50},
			{350, 35, 50, 50},
			{350, 135, 50, 50},
			{350, 235, 50, 50},
			{350, 335, 50, 50},
			{400, 85, 50, 50},
			{400, 185, 50, 50},
			{400, 285, 50, 50},
			{450, 35, 50, 50},
			{450, 135, 50, 50},
			{450, 235, 50, 50},
			{450, 335, 50, 50},
			{500, 85, 50, 50},
			{500, 185, 50, 50},
			{500, 285, 50, 50},
			{550, 35, 50, 50},
			{550, 135, 50, 50},
			{550, 235, 50, 50},
			{550, 335, 50, 50}
		};

		enemies = {
			{-60, -60, {-60, -60}, {10, 10}},
			{300, -60, {300, -60}, {10, 10}},
			{600, -60, {600, -60}, {10, 10}},
			{-60, 490, {-60, 490}, {10, 10}},
			{300, 490, {300, 490}, {10, 10}},
			{600, 490, {600, 490}, {10, 10}},
			{660, 190, {660, 190}, {10, 10}},
			{10, 10, {10, 10}, {10, 400}}
		};

		size_t i;
		for (i = 0; i < enemies.size() - 1; i++)
		{
			enemies[i].SetStandingParameters();
		}
		enemies[i].SetPatrolParameters();
	}
	else
	{
		// Blank stage for any number past the created stages
	}
}

void Level::Win()
{
	stage += 1;
}
