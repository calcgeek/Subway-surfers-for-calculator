#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gfx/hiiii.h"
#include "gfx/subwaysurf.h"



#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

void drawBackground(void) {
    gfx_SetColor(0);
    gfx_FillScreen(0);
// I think this is were we should put the jake pic//

    // Bright neon sky gradient
    for (int y = 0; y < 100; y++) {
        int color = 128 + (y / 12);
        gfx_SetColor(color);
        gfx_HorizLine(0, y, SCREEN_WIDTH);
    }

    // Dark ground
    gfx_SetColor(16);
    gfx_FillRectangle(0, 100, SCREEN_WIDTH, 140);
}



void drawTitle(void) {
    gfx_SetTextScale(3, 3);
    gfx_SetColor(206);
    gfx_PrintStringXY("SUBWAY", 90, 15);
    gfx_SetColor(141);
    gfx_PrintStringXY("SURFERS", 85, 35);

    gfx_SetTextScale(1, 1);
    gfx_SetColor(226);
    gfx_PrintStringXY(">> CE <<", 135, 55);
}

void drawMenuButton(int x, int y, int width, int height, const char *text, int selected) {
    if (selected) {
        // Selected: bright neon colors
        gfx_SetColor(206);
        gfx_FillRectangle(x - 3, y - 3, width + 6, height + 6);
        gfx_SetColor(141);
        gfx_FillRectangle(x, y, width, height);
        gfx_SetColor(255);
    } else {
        // Unselected: darker colors
        gfx_SetColor(16);
        gfx_FillRectangle(x, y, width, height);
        gfx_SetColor(200);
    }

    gfx_Rectangle(x, y, width, height);

    gfx_SetTextScale(1, 1);
    gfx_PrintStringXY(text, x + 10, y + 8);
}

void drawMenuBackground(void) {
    // Semi-transparent dark overlay - lighter so train shows through
    gfx_SetColor(40);
    for (int i = 0; i < 3; i++) {
        gfx_FillRectangle(0, 130 + (i * 35), SCREEN_WIDTH, 28);
    }
}

int main(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();

    int selected = 0;
    int numOptions = 3;
    //uint8_t prevKeys = 0;//

    while (1) {
        drawBackground();

        drawTitle();
        drawMenuBackground();

        const char *options[] = {"PLAY GAME", "SETTINGS", "EXIT"};

        for (int i = 0; i < numOptions; i++) {
            int y = 140 + (i * 35);
            drawMenuButton(70, y, 180, 28, options[i], (i == selected));
        }

        gfx_SetTextScale(1, 1);
        gfx_SetColor(206);
        gfx_PrintStringXY("UP/DOWN | CLEAR exit", 100, 235);

        gfx_SwapDraw();

        kb_Scan();
        if(kb_IsDown(kb_KeyUp)) {

        if (kb_IsDown(kb_KeyUp)) while(kb_AnyKey())
            if (selected < 0) selected = numOptions - 1;
        }

        if(kb_IsDown(kb_KeyUp)) {
            selected++;
            if (selected >= numOptions) selected = 0;
        }

        if (kb_IsDown(kb_Clear)) while(kb_AnyKey()) {
            break;
        }

        while(kb_AnyKey());
    }

    gfx_End();
    return 0;
}
