//this code is written and Run in Turbo C 
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

// Function to draw mountains
void drawMountains(int midy) {
    int peak1_x = getmaxx() / 4;
    int peak2_x = 3 * getmaxx() / 4;
    int base_y = midy - 1;

    // Set the color for the mountains
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);

    // First mountain coordinates
    int triangle1[] = {0, base_y, peak1_x, midy - 200, getmaxx() / 2, base_y};

    // Second mountain coordinates
    int triangle2[] = {getmaxx() / 2, base_y, peak2_x, midy - 200, getmaxx(), base_y};

    // Draw and fill first mountain
    fillpoly(3, triangle1);

    // Draw and fill second mountain
    fillpoly(3, triangle2);
}

// Function to draw the sun
void drawSun() {
    setcolor(YELLOW);  // Use yellow color for the sun
    circle(getmaxx() - 100, 100, 50);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(getmaxx() - 100, 100, YELLOW);
}

// Function to draw the house in the center
void drawHouse(int midx, int base_y) {
    int house_width = 100;
    int house_height = 100;
    int roof_height = 50;

    // House coordinates
    int left = midx - house_width / 2;
    int right = midx + house_width / 2;
    int bottom = base_y;
    int top = bottom - house_height;

    // Draw the house rectangle
    setcolor(WHITE);
    rectangle(left, top, right, bottom);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    floodfill(left + 1, top + 1, WHITE);

    // Draw the roof
    int roof[] = {left, top, right, top, midx, top - roof_height};
    setcolor(RED);
    fillpoly(3, roof);
    setfillstyle(SOLID_FILL, RED);
    floodfill(midx, top - roof_height + 1, RED);

    // Draw the door
    int door_left = midx - house_width / 8;
    int door_right = midx + house_width / 8;
    int door_bottom = bottom;
    int door_top = bottom - house_height / 3;
    setcolor(BROWN);
    rectangle(door_left, door_top, door_right, door_bottom);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(door_left + 1, door_top + 1, BROWN);

    // Draw windows
    int window_size = house_width / 5;
    int left_window_left = left + window_size;
    int left_window_top = top + window_size;
    int left_window_right = left + 2 * window_size;
    int left_window_bottom = top + 2 * window_size;
    setcolor(LIGHTGRAY);
    rectangle(left_window_left, left_window_top, left_window_right, left_window_bottom);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(left_window_left + 1, left_window_top + 1, LIGHTGRAY);

    int right_window_left = right - 2 * window_size;
    int right_window_top = top + window_size;
    int right_window_right = right - window_size;
    int right_window_bottom = top + 2 * window_size;
    rectangle(right_window_left, right_window_top, right_window_right, right_window_bottom);
    floodfill(right_window_left + 1, right_window_top + 1, LIGHTGRAY);
}

// Function to draw stickman
void drawStickMan(int x, int y, int radius, int midy, int pos, int hasUmbrella) {
    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 1, 3);
    line(0, midy, getmaxx(), midy);  // Road for stickman
    circle(x, y, radius);            // Head
    line(x, y + radius, x, y + radius + 50); // Body

    if (hasUmbrella) {
        // Draw umbrella near the hand
        line(x, y + radius + 10, x - 30, y - 20);
        pieslice(x - 30, y - 20, 0, 180, 30);
    }

    if (pos == 1) {
        // First position
        line(x, y + radius + 50, x - 10, midy);
        line(x, y + radius + 50, x + 10, midy - 30);
        line(x + 10, midy - 30, x + 10, midy);
        line(x, y + radius + 10, x - 15, y + radius + 30);
        line(x - 15, y + radius + 30, x + 15, y + radius + 40);
    } else if (pos == 2) {
        // Second position
        line(x, y + radius + 50, x - 15, midy);
        line(x, y + radius + 50, x + 10, midy - 30);
        line(x + 10, midy - 30, x + 10, midy);
        line(x, y + radius + 5, x - 10, y + radius + 20);
        line(x - 10, y + radius + 20, x - 10, y + radius + 45);
        line(x, y + radius + 5, x + 5, y + radius + 25);
        line(x + 5, y + radius + 25, x + 15, y + radius + 45);
    } else if (pos == 3) {
        // Third position
        line(x, y + radius + 50, x - 20, midy);
        line(x, y + radius + 50, x + 20, midy);
        line(x, y + radius + 5, x - 20, y + radius + 20);
        line(x - 20, y + radius + 20, x - 20, y + radius + 30);
        line(x, y + radius + 5, x + 20, y + radius + 25);
        line(x + 20, y + radius + 25, x + 30, y + radius + 30);
    } else if (pos == 4) {
        // Fourth position
        line(x, y + radius + 50, x - 8, midy - 30);
        line(x - 8, midy - 30, x - 25, midy);
        line(x, y + radius + 50, x + 10, midy - 30);
        line(x + 10, midy - 30, x + 12, midy);
        line(x, y + radius + 5, x - 10, y + radius + 10);
        line(x - 10, y + radius + 10, x - 10, y + radius + 30);
        line(x, y + radius + 5, x + 15, y + radius + 20);
        line(x + 15, y + radius + 20, x + 30, y + radius + 20);
    } else if (pos == 5) {
        // Fifth position
        line(x, y + radius + 50, x + 3, midy);
        line(x, y + radius + 50, x + 8, midy - 30);
        line(x + 8, midy - 30, x - 20, midy);
        line(x, y + radius + 5, x - 15, y + radius + 10);
        line(x - 15, y + radius + 10, x - 8, y + radius + 25);
        line(x, y + radius + 5, x + 15, y + radius + 20);
        line(x + 15, y + radius + 20, x + 30, y + radius + 20);
    }
}

// Function to draw rain
void drawRain() {
    int i;
    for (i = 0; i < 100; i++) {
        int rx = rand() % getmaxx();
        int ry = rand() % getmaxy();
        setcolor(WHITE);
        line(rx, ry, rx, ry + 5);
    }
}

int main() {
    /* request auto detection */
    int gdriver = DETECT, gmode, err;
    int radius = 10, x, y, midx, midy;

    /* initialize graphic mode */
    initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
    err = graphresult();

    if (err != grOk) {
        /* error occurred */
        printf("Graphics Error: %s\n", grapherrormsg(err));
        return 0;
    }

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    x = 50;
    y = midy - 100;

    /* used 5 stickman (still/image) positions to get walking animation */
    while (x < getmaxx() - 25) {
        cleardevice();

        // Draw background elements
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        int hasUmbrella = (x > getmaxx() / 2); // Add umbrella when stickman reaches middle

        if (hasUmbrella) {
            drawRain();
        }

        drawStickMan(x, y, radius, midy, 1, hasUmbrella);
        delay(150);
        cleardevice();

        // Draw background elements again after clearing device
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        x++;

        if (hasUmbrella) {
            drawRain();
        }

        drawStickMan(x, y, radius, midy, 2, hasUmbrella);
        delay(100);
        cleardevice();

        // Draw background elements again after clearing device
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        x++;

        if (hasUmbrella) {
            drawRain();
        }

        drawStickMan(x, y, radius, midy, 3, hasUmbrella);
        delay(150);
        cleardevice();

        // Draw background elements again after clearing device
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        x++;

        if (hasUmbrella) {
            drawRain();
        }

        drawStickMan(x, y, radius, midy, 4, hasUmbrella);
        delay(100);
        cleardevice();

        // Draw background elements again after clearing device
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        x++;

        if (hasUmbrella) {
            drawRain();
        }

        drawStickMan(x, y, radius, midy, 5, hasUmbrella);
        delay(150);
        cleardevice();

        // Draw background elements again after clearing device
        drawMountains(midy);
        if (x <= getmaxx() / 2) {
            drawSun();  // Draw sun only if not raining
        }
        drawHouse(midx, midy);

        x++;
    }

    getch();

    /* deallocate memory allocated for graphic screen */
    closegraph();

    return 0;
}