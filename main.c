#include <tice.h>
#include <graphx.h>
#include <keypadc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/getcsc.h>
#include "gfx/gfx.h"
#include "gfx/hiiii.h"
#include "gfx/subwaysurf.h"

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240





void drawBackground(void) {
    gfx_SetColor(31);
    gfx_FillScreen(255);
gfx_FillRectangle(0,0,SCREEN_WIDTH,12);
gfx_SetColor(63);
gfx_FillRectangle(0,12,SCREEN_WIDTH,12);
gfx_SetColor(95);
gfx_FillRectangle(0,24,SCREEN_WIDTH,12);
gfx_SetColor(127);
gfx_FillRectangle(0,36,SCREEN_WIDTH,12);
gfx_SetColor(159);
gfx_FillRectangle(0,48,SCREEN_WIDTH,12);
gfx_SetColor(191);
gfx_FillRectangle(0,60,SCREEN_WIDTH,12);
gfx_SetColor(223);
gfx_FillRectangle(0,72,SCREEN_WIDTH,12);
}

void drawTitle(void) {
    gfx_SetTextScale(3, 3);
    gfx_SetColor(206);
    gfx_PrintStringXY("SUBWAY", 90, 1);
    gfx_SetColor(141);
    gfx_PrintStringXY("SURFERS", 85, 23);

    gfx_SetTextScale(2, 1);
    gfx_SetColor(226);
    gfx_PrintStringXY(">> CE <<", 117, 50);
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


int main(void) {
    gfx_Begin();
    gfx_SetDrawBuffer();

    int selected = 0;
    int numOptions = 3;
    //uint8_t prevKeys = 0;//

   // while (1)// {
        drawBackground();
         gfx_SetPalette(global_palette, sizeof_global_palette, 0);
        //bottom right
      gfx_ScaledTransparentSprite_NoClip(tree, 240, 150, 2,2);
        //botton left tree
      gfx_ScaledTransparentSprite_NoClip(tree, -10, 150, 2,2);

      gfx_ScaledTransparentSprite_NoClip(hiiii, -13, 0, 5, 5);

    drawTitle();
/*gfx_SetTransparentColor(whatever index your color white is);
    gfx_TransparentSprite(sprite, x, y);*/

        const char *options[] = {"PLAY GAME", "MORE OPTIONS", "EXIT"};

        for (int i = 0; i < numOptions; i++) {
            int y = 130 + (i * 35);
            drawMenuButton(70, y, 180, 28, options[i], (i == selected));
        }

        gfx_SetTextScale(1, 1);
        gfx_SetColor(206);
        gfx_PrintStringXY("UP/DOWN | CLEAR exit", 100, 230);
 ;

        gfx_SwapDraw();



   /* Waits for a key */
    while(!os_GetCSC()){};

    /* End graphics drawing */
    gfx_End();

    return 0 ;
}
