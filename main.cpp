#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Fractal: public olc::PixelGameEngine {
public:

    void recurse_circle(int x, int y, int radius){
        DrawCircle(x,y, radius);
        if (radius > 2) {
            radius = radius * 0.95f;
            recurse_circle(x, y, radius);
        }
    }

    // TODO: has some glitches ; fix it soon
    void recurse_rect(int x, int y, int height, int width) {
        DrawRect(x, y, height, width);

        if (height > 4 && width > 4) {
            x += 4;
            y += 4;
            height = height * 0.95f;
            width = width * 0.95f;
            recurse_rect(x, y, height, width);
        }
    }

    void koch_curve(int start_x, int start_y, int end_x, int end_y){
        // steps:
        // 1. Draw a line
        //DrawLine(start_x,start_y, end_x,end_y);
        // 2. Divide the line into 3 equal parts
        float mid_point_main_line_x = (start_x + end_x) / 2.0f;
        float mid_point_main_line_y = (start_y + end_y) / 2.0f;

        int mid_point_left_line_x = (start_x + mid_point_main_line_x) / 2;
        int mid_point_left_line_y = (start_y + mid_point_main_line_y) / 2;

        int mid_point_right_line_x = (end_x + mid_point_main_line_x) / 2;
        int mid_point_right_line_y = (end_y + mid_point_main_line_y) / 2;

        int height = mid_point_main_line_x - mid_point_left_line_x;

        // 4. remove the line segment

        Clear(olc::BLACK);

        DrawLine(start_x, start_y, mid_point_left_line_x, mid_point_left_line_y);
        DrawLine(mid_point_right_line_x, mid_point_right_line_y, end_x, end_y);


        // 3. Draw an equilateral triangle from those points

        DrawLine(mid_point_left_line_x, mid_point_left_line_y, mid_point_main_line_x, height);
        DrawLine(mid_point_main_line_x, height, mid_point_right_line_x, mid_point_main_line_y);

        // 5. repeat 2-3
        /*
        if(mid_point_main_line_x > 5 && mid_point_main_line_y > 5){
            koch_curve(mid_point_left_line_x, mid_point_right_line_x, mid_point_main_line_x, height);
            koch_curve(mid_point_main_line_x, height, mid_point_right_line_x, mid_point_main_line_y);
        }
        */
    }

    bool OnUserCreate() override{
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {

        //recurse_circle(190,150, 100);
        //recurse_rect(5,5 , 150, 150);
        int start_x = 5;
        int start_y = 5;
        int end_x   = 400;
        int end_y   = 50;
        koch_curve(start_x, start_y, end_x, end_y);
        return true;
    }
};

int main() {
    Fractal my_fractal;
    if(my_fractal.Construct(450, 340, 4, 4))
        my_fractal.Start();
}
