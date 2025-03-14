#include <iostream>
#include <conio.h> 
#include <windows.h> 
#include <vector>
#include <cstdlib> 
#include <ctime> 
using namespace std;
const int WIDTH = 20;
const int HEIGHT = 20;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
struct Point {
    int x, y;
};
class SnakeGame {
public:
    SnakeGame() : dir(STOP), score(0), gameOver(false) {
        snake.push_back({ WIDTH / 2, HEIGHT / 2 });
        spawnFood();
        srand(time(0));
    }
    void Run() {
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100); 
        }
        cout << "Game Over! Diem so cua ban: " << score << endl;
    }
private:
    vector<Point> snake;
    Point food;
    Direction dir;
    int score;
    bool gameOver;
    void Draw() {
        system("cls"); 
        for (int i = 0; i < WIDTH + 2; ++i) cout << "#";
        cout << endl;
        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                if (x == 0) cout << "#";
                if (x == food.x && y == food.y) cout << "@";
                else if (isSnake(x, y)) cout << "O";
                else cout << " ";
                if (x == WIDTH - 1) cout << "#";
            }
            cout << endl;
        }
        for (int i = 0; i < WIDTH + 2; ++i) cout << "#";
        cout << endl;
        cout << "Diem: " << score << endl;
    }
    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': if (dir != RIGHT) dir = LEFT; break;
                case 'd': if (dir != LEFT) dir = RIGHT; break;
                case 'w': if (dir != DOWN) dir = UP; break;
                case 's': if (dir != UP) dir = DOWN; break;
                case 'x': gameOver = true; break;
            }
        }
    }
    void Logic() {
        Point prev = snake[0];
        Point prev2;
        Point head = snake[0];
        switch (dir) {
            case LEFT:  head.x--; break;
            case RIGHT: head.x++; break;
            case UP:    head.y--; break;
            case DOWN:  head.y++; break;
            default: break;
        }
        if (head.x >= WIDTH || head.x < 0 || head.y >= HEIGHT || head.y < 0) {
            gameOver = true;
        }
        for (int i = 1; i < snake.size(); ++i) {
            if (snake[i].x == head.x && snake[i].y == head.y) {
                gameOver = true;
            }
        }
        if (head.x == food.x && head.y == food.y) {
            score += 10;
            snake.push_back({ prev.x, prev.y });
            spawnFood();
        }
        for (int i = 1; i < snake.size(); ++i) {
            prev2 = snake[i];
            snake[i] = prev;
            prev = prev2;
        }
        snake[0] = head;
    }
    bool isSnake(int x, int y) {
        for (const auto& s : snake) {
            if (s.x == x && s.y == y) return true;
        }
        return false;
    }
    void spawnFood() {
        food.x = rand() % WIDTH;
        food.y = rand() % HEIGHT;
    }
};
int main() {
    SnakeGame game;
    game.Run();
    return 0;
}
