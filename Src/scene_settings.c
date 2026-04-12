// TODO-HACKATHON 3-9: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_settings.h"
#include "scene_menu_object.h"
#include "scene_menu.h"
// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */
// TODO-IF: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.
static Button check_box;
static Button check_box1;
static ALLEGRO_BITMAP* SETTING_LATARBELAKANG = NULL;
static Button character_naruto;
static Button character_pacman;
static Button character_kakashi;
static int SETTING_LATARBELAKANG_LEBAR;
static int SETTING_LATARBELAKANG_TINGGI;
static int settingTitleW;
static int settingTitleH;

static void init() {

	// TODO-HACKATHON 3-2: Create button to settings
	// Uncomment and fill the code below
	check_box = button_create(450, 100, 50, 50, "Assets/Checkbox.png", "Assets/Checkbox_check.png");
	check_box1 = button_create(450, 150, 50, 50, "Assets/Checkbox.png", "Assets/Checkbox_check.png");
	character_naruto = button_create(100, 150, 50, 50, "Assets/Naruto_settingbox.png", "Assets/Naruto_settingbox_check.png");
	character_pacman = button_create(100, 100, 50, 50, "Assets/Pacman_settingbox.png", "Assets/Pacman_settingbox_check.png");
	character_kakashi = button_create(100, 200, 50, 50, "Assets/Kakashi_setting.png", "Assets/Kakashi_setting_check.png");
	SETTING_LATARBELAKANG = load_bitmap("Assets/game_background.jpg");
	SETTING_LATARBELAKANG_LEBAR = al_get_bitmap_width(SETTING_LATARBELAKANG);
	SETTING_LATARBELAKANG_TINGGI = al_get_bitmap_height(SETTING_LATARBELAKANG);
}

static void draw(void ){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * settingTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * settingTitleH;

	al_draw_scaled_bitmap(
		SETTING_LATARBELAKANG,
		0, 0,
		SETTING_LATARBELAKANG_LEBAR, SETTING_LATARBELAKANG_TINGGI,
		0, 0,
		SCREEN_W, SCREEN_H,
		0
	);
	if (checkCounter)
	{
		click_CheckBox(check_box);
		drawButton(check_box1);
	}
	else if (checkCounter2)
	{
		drawButton(check_box);
		click_CheckBox(check_box1);
	}
	else
	{
		drawButton(check_box);
		drawButton(check_box1);
	}
	if (characterCounter)
	{
		click_CheckBox(character_naruto);
		drawButton(character_pacman);
		drawButton(character_kakashi);
	}
	else if (characterCounter2)
	{
		drawButton(character_naruto);
		click_CheckBox(character_pacman);
		drawButton(character_kakashi);
	}
	else if (characterCounter3)
	{
		drawButton(character_naruto);
		drawButton(character_pacman);
		click_CheckBox(character_kakashi);
	}
	else
	{
		drawButton(character_naruto);
		drawButton(character_pacman);
		drawButton(character_kakashi);
	}
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W - 185,
		SCREEN_H - 688,
		ALLEGRO_ALIGN_CENTER,
		"Pacman BGM"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W - 196,
		SCREEN_H - 638,
		ALLEGRO_ALIGN_CENTER,
		"Naruto BGM"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W - 548,
		SCREEN_H - 688,
		ALLEGRO_ALIGN_CENTER,
		"Pacman"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W - 560,
		SCREEN_H - 638,
		ALLEGRO_ALIGN_CENTER,
		"Naruto"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W - 554,
		SCREEN_H - 588,
		ALLEGRO_ALIGN_CENTER,
		"Kakashi"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W - 205,
		SCREEN_H - 745,
		ALLEGRO_ALIGN_CENTER,
		"<Pick A BGM>"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W - 575,
		SCREEN_H - 745,
		ALLEGRO_ALIGN_CENTER,
		"<Pick A Character>"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W - 625,
		SCREEN_H - 500,
		ALLEGRO_ALIGN_CENTER,
		"Music Vol."
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W - 613,
		SCREEN_H - 450,
		ALLEGRO_ALIGN_CENTER,
		"Effect Vol."
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"<ESCAPE>"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 100,
		ALLEGRO_ALIGN_CENTER,
		"BACK TO MENU"
	);
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	TODO-HACKATHON 3-7: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
	check_box.hovered = buttonHover(check_box, mouse_x, mouse_y);
	check_box1.hovered = buttonHover(check_box1, mouse_x, mouse_y);
	character_naruto.hovered = buttonHover(character_naruto, mouse_x, mouse_y);
	character_pacman.hovered = buttonHover(character_pacman, mouse_x, mouse_y);
	character_kakashi.hovered = buttonHover(character_kakashi, mouse_x, mouse_y);
}


static void on_mouse_down(int btn, int x, int y, int dz) {
	if (check_box.hovered)
	{
		//game_change_scene(scene_settings_create());
		checkCounter = true;
		checkCounter2 = false;
	}
	if (check_box1.hovered)
	{
		//game_change_scene(scene_settings_create());
		checkCounter2 = true;
		checkCounter = false;
	}
	if (character_naruto.hovered)
	{
		//game_change_scene(scene_settings_create());
		characterCounter = true;
		characterCounter2 = false;
		characterCounter3 = false;
		pacmanCounter = 2;
	}
	if (character_pacman.hovered)
	{
	//	game_change_scene(scene_settings_create());
		characterCounter = false;
		characterCounter2 = true;
		characterCounter3 = false;
		pacmanCounter = 1;
	}
	if (character_kakashi.hovered)
	{
		characterCounter = false;
		characterCounter2 = false;
		characterCounter3 = true;
		pacmanCounter = 3;
	}
}

static void on_key_down(int keycode) {
	switch (keycode) {
		case ALLEGRO_KEY_ESCAPE:
			game_change_scene(scene_menu_create());
			break;
		default:
			break;
	}
}

// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;
	// TODO-IF: Register more event callback functions such as keyboard, mouse, ...
	game_log("Settings scene created");
	return scene;
}

static void destroy(void) {
	al_destroy_bitmap(SETTING_LATARBELAKANG);
	al_destroy_bitmap(check_box.default_img);
	al_destroy_bitmap(check_box.hovered_img);
	al_destroy_bitmap(check_box1.default_img);
	al_destroy_bitmap(check_box1.hovered_img);
	al_destroy_bitmap(character_naruto.default_img);
	al_destroy_bitmap(character_naruto.hovered_img);
	al_destroy_bitmap(character_pacman.default_img);
	al_destroy_bitmap(character_pacman.hovered_img);
	al_destroy_bitmap(character_kakashi.default_img);
	al_destroy_bitmap(character_kakashi.hovered_img);
}

// TODO-Graphical_Widget:
// Just suggestions, you can create your own usage.
	// Selecting BGM:
	// 1. Declare global variables for storing the BGM. (see `shared.h`, `shared.c`)
	// 2. Load the BGM in `shared.c`.
	// 3. Create dropdown menu for selecting BGM in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and play the BGM if the corresponding option is selected.

	// Adjusting Volume:
	// 1. Declare global variables for storing the volume. (see `shared.h`, `shared.c`)
	// 2. Create a slider for adjusting volume in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. You may use checkbox to switch between mute and unmute.
	// 3. Adjust the volume and play when the button is pressed.

	// Selecting Map:
	// 1. Preload the map to `shared.c`.
	// 2. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
		// 2.1. For player experience, you may also create another scene between menu scene and game scene for selecting map.
	// 3. Create buttons(or dropdown menu) for selecting map in setting scene, involving `scene_settings.c` and `scene_setting.h.
	// 4. Switch and draw the map if the corresponding option is selected.
		// 4.1. Suggestions: You may use `al_draw_bitmap` to draw the map for previewing. 
							// But the map is too large to be drawn in original size. 
							// You might want to modify the function to allow scaling.