#include <iostream>
#include "raylib.h"




int main() {
    int width = 800;
    int height = 450;
    InitWindow(width, height, "hohoho");
    bool run = true;

    // int circleX = width / 2;
    // int circleY = height / 2;


    int circleX = 200;
    int circleY = 200;
    int circleRadius = 25;




    int axe_x{400};
    int axe_y{0};
    int axe_length{50};


    int l_circle_x{circleX - circleRadius};
    int r_circle_x{circleX + circleRadius};
    int u_circle_y{circleY - circleRadius};
    int b_circle_y{circleY + circleRadius};
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};


    int direction{10};


    SetTargetFPS(60);

    bool collision_with_axe = (
                        u_circle_y <= b_axe_y &&
                        b_circle_y >= u_axe_y &&
                        r_circle_x >= l_axe_x &&
                        l_circle_x <= r_axe_x
                        );


    bool mainMenu = true;
    std::string menuArr[2] {"start", "exit"};
    int menuIndex = 0;

    while (run) {
        BeginDrawing();
        // printf("FPS: %i\n", GetFPS());
        ClearBackground(BLACK);


        if (IsKeyDown(KEY_ESCAPE))
        {
            run = false;
        }
        if (mainMenu || collision_with_axe) {

            if (collision_with_axe) {
                DrawText("Game Over", width/2,height/3,20,RED);
            }
            else
            {
                DrawText("Main Menu", width/2,height/3 ,20,WHITE);
            }
            if (menuIndex == 0) {
                DrawText(menuArr[0].c_str(), width/2,height/3 + 60,20,GREEN);
                DrawText(menuArr[1].c_str(), width/2,height/3  +120,20,RED);
            }
            else
            {
                DrawText(menuArr[0].c_str(), width/2,height/3 + 60,20,RED);
                DrawText(menuArr[1].c_str(), width/2,height/3  +120,20,GREEN);
            }


            if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))&& menuIndex != 0)
            {
                menuIndex--;
            }
            if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) && menuIndex != 1)
            {
                menuIndex++;
            }
            if (IsKeyPressed(KEY_SPACE))
            {
                switch (menuIndex) {
                    case 0:
                        collision_with_axe = false;
                        mainMenu = false;
                        circleX = 200;
                        circleY = 200;
                        break;
                    case 1:
                        run = false;
                    default: ;
                }
            }

        }
        // else if (collision_with_axe)
        // {
        //     DrawText("Game Over", width/2,height/2,20,RED);
        //
        // }
        else
        {

            // update the edges
            l_circle_x = circleX - circleRadius;
            r_circle_x = circleX + circleRadius;
            u_circle_y = circleY - circleRadius;
            b_circle_y = circleY + circleRadius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            //update collision with axe
            collision_with_axe = (
                        u_circle_y <= b_axe_y &&
                        b_circle_y >= u_axe_y &&
                        r_circle_x >= l_axe_x &&
                        l_circle_x <= r_axe_x
                        );


            DrawCircle(circleX,circleY,circleRadius,BLUE);
            DrawRectangle(axe_x,axe_y,axe_length, axe_length,RED);

            // Game logic begins
            // DrawCircle(circleX,circleY,radius,BLUE);

            // move the axe
            axe_y += direction;
            if (axe_y> height - axe_length || axe_y < 0)
            {
                direction = -direction;
            }
            // axe_x += direction;
            // if (axe_x > width - 50 || axe_x < 0)
            // {
            //     direction = -direction;
            // }

            if (IsKeyDown(KEY_D) && circleX < width-circleRadius)
            {
                circleX += 5;
            }
            if (IsKeyDown(KEY_A) && circleX > circleRadius)
            {
                circleX -= 5;
            }
            if (IsKeyDown(KEY_W))
            {
                circleY -= 5;
            }
            if (IsKeyDown(KEY_S))
            {
                circleY += 3;
            }
            if (IsKeyDown(KEY_ESCAPE))
            {
                run = false;
            }





            // const int pressed = GetKeyPressed();

            // switch (pressed)
            // {
            //     case KEY_ESCAPE:
            //         run = false;
            //         break;
            //     case KEY_LEFT:
            //         break;
            //     case KEY_RIGHT:
            //         break;
            //     case KEY_UP:
            //         break;
            //     case KEY_DOWN:
            //         break;
            // }

        }
        // Game logic ends
        EndDrawing();

    }
    return 0;
}
