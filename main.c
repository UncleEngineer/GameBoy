#include <gb/gb.h>
#include <stdio.h>
#include "Loong.c"

void sound() {
	NR10_REG = 0x16;
	NR11_REG = 0x40;
	NR12_REG = 0x73;
	NR13_REG = 0x00;
	NR14_REG = 0xC3;
}

void main(){

	UINT8 spriteindex = 0;

	set_sprite_data(0,2, FaceLoong);
	set_sprite_tile(0,0);
	move_sprite(0,88,78);
	SHOW_SPRITES;

	// Turn On Sound Mode
	NR52_REG = 0x80;
	NR50_REG = 0x77;
	NR51_REG = 0xFF;

	while (1)
	{
		switch (joypad()) {
			case J_LEFT:
				scroll_sprite(0,-10,0);
				sound();
				break;
			case J_RIGHT:
				scroll_sprite(0,10,0);
				sound();
				break;
			case J_UP:
				scroll_sprite(0,0,-10);
				sound();
				break;
			case J_DOWN:
				scroll_sprite(0,0,10);
				sound();
				break;			
		}		
		delay(100);
	}

}