#include "BlockedGame.h"
#include "Window.h"
#include "Renderer.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "EventHandler.h"
#include "Maps.h"
#include "Player.h"
#include "LevelManager.h"
#include "ColorPanel.h"
#include "Timer.h"
#include "Gravity.h"

namespace Blocked
{
    bool BlockedGame::isRunning;
    Timer BlockedGame::loopTimer;
    int BlockedGame::deltaTime;

    void BlockedGame::init(const char* _title, const int _SCREEN_WIDTH, const int _SCREEN_HEIGHT)
    {
        BlockedGame::isRunning = Window::init(_title, _SCREEN_WIDTH, _SCREEN_HEIGHT) ? Renderer::init() : false;
    }

    void BlockedGame::gameLoop()
    {
        BlockedGame::init("Blocked", 1200, 800);

        Vec2 size(Window::width/12, Window::height/8);
        Vec2 position(150, 100);
        Player player(size, position, ColorPanel::playerRed);

        while (BlockedGame::isRunning)
        {
            Gravity::setGforce(0, (double)5 * BlockedGame::deltaTime);
            BlockedGame::loopTimer.setLoop();
            LevelManager::drawLevel(player);
            BlockedGame::deltaTime = BlockedGame::loopTimer.getLoopTime() / 10;
        }
        BlockedGame::closeGame();
    }

    void BlockedGame::closeGame()
    {
        Renderer::destroyRenderer();
        Window::destroyWindow();
        SDL_Quit();
    }
}
