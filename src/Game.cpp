#include "game.h"
#include "background/background.h"
#include "characters/character.h"
#include "characters/fire_knight.h"
#include "constants/game_constants.h"

SDL_Renderer* Game::renderer_ = nullptr;
SDL_Event Game::event_;

Background* forest;
Background* textBox;
Character* player;
Character* enemy;
bool isPlayer1Turn = true;
bool isPlayer2Turn = false;

// Helper functions to handle events based on the text box that is displayed
void handleMenuEvents(SDL_Event &event, Background *textBox);
void handleAttackEvents(SDL_Event &event, Background* textBox, Character *player, Character *enemy);
void handleStatsEvents(SDL_Event &event, Background* textBox, Character *player);
void handleRunEvents(SDL_Event &event, Background* textBox, Game* game);

Game::~Game() {
  // Cleans up SDL
  SDL_DestroyWindow(window_);
  SDL_DestroyRenderer(renderer_);
  SDL_Quit();
  IMG_Quit();
  std::cout << "Game destroyed" << std::endl;
}

void Game::Init(const char* title, int x_pos, int y_pos, int width,
                int height) {
  // Initializing SDL2 window
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window_ = SDL_CreateWindow(title, x_pos, y_pos, width, height, 0);
    if (window_) {
      std::cout << "Window created" << std::endl;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
    if (renderer_) {
      SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
      std::cout << "Renderer created" << std::endl;
    }
    is_running_ = true;
  } else {
    is_running_ = false;
  }

  // Setup stuff
  player = new FireKnight(false, "Player");
  enemy = new FireKnight(true, "Bot");
  forest = new Background("assets/Backgrounds/forest.png", 0, 0, false);
  textBox = new Background("assets/TextBoxes/Main.png", 40, 490, true);
}

void Game::Update() {
  forest->Update();
  textBox->Update();
  player->Update();
  enemy->Update();
}

void Game::Render() {
  SDL_RenderClear(renderer_);
  forest->Render();
  textBox->Render();
  player->Render();
  enemy->Render();
  SDL_RenderPresent(renderer_);  // Double buffering
}

void Game::HandleEvents() {
  SDL_PollEvent(&event_);
  switch (event_.type) {
    case SDL_QUIT:
      is_running_ = false;
      break;
    case SDL_KEYDOWN:
      switch (event_.key.keysym.sym) {
        case SDL_KEYDOWN:
          return;
            if (isPlayer1Turn) {
                cout << "It's Player 1's turn" << endl;
                if (textBox->GetPath() == "assets/TextBoxes/Main.png") {
                    handleMenuEvents(event_, textBox);
                    player->Idle();
                    enemy->Idle();
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Attack.png") {
                    handleAttackEvents(event_, textBox, player, enemy);
                    isPlayer1Turn = false;
                    isPlayer2Turn = true;
                    textBox->SetPath("None");
                    // TODO: add delay before text box is displayed
                    textBox->SetPath("assets/TextBoxes/Main.png");
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") {
                    handleStatsEvents(event_, textBox, player);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Run.png") {
                    handleRunEvents(event_, textBox, this);
                }
                
            }
            
            else if (isPlayer2Turn) {
                cout << "It's Player 2's turn" << endl;
                if (textBox->GetPath() == "assets/TextBoxes/Main.png") {
                    handleMenuEvents(event_, textBox);
                    player->Idle();
                    enemy->Idle();
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Attack.png") {
                    handleAttackEvents(event_, textBox, enemy, player);
                    isPlayer1Turn = true;
                    isPlayer2Turn = false;
                    textBox->SetPath("None");
                    // TODO: add delay before text box is displayed
                    textBox->SetPath("assets/TextBoxes/Main.png");
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Stats.png") {
                    handleStatsEvents(event_, textBox, enemy);
                }
                else if(textBox->GetPath() == "assets/TextBoxes/Run.png") {
                    handleRunEvents(event_, textBox, this);
                }
            }
        default:
          break;
      }
      break;
  }
}

void handleMenuEvents(SDL_Event &event, Background *textBox)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            textBox->SetPath("assets/TextBoxes/Attack.png");
            break;
        case SDLK_2:
            textBox->SetPath("assets/TextBoxes/Stats.png");
            break;
        case SDLK_3:
            textBox->SetPath("assets/TextBoxes/Run.png");
            break;
        case SDLK_4:
            textBox->SetPath("assets/TextBoxes/Save.png");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); 
            break;
    }
}

void handleAttackEvents(SDL_Event &event, Background *textBox, Character *player, Character *enemy)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            player->Attack1();
            enemy->TakeDamage(2 * player->GetLevel()); 

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 1);
            textBox->SetPath("None");

            // Wait for attack and take damage animations to finish before going back to idle
            break;
        case SDLK_2:
            player->Attack2();
            enemy->TakeDamage(4 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 1);
            textBox->SetPath("None");
            break;
        case SDLK_3:
            player->Attack3();
            enemy->TakeDamage(8 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 2);
            player->SetEnergy(player->GetEnergy() - 4);
            textBox->SetPath("None");
            break;
        case SDLK_4:
            player->Attack4();
            enemy->TakeDamage(10 * player->GetLevel());

            if (enemy->GetHealth() <= 0) { 
                enemy->Death(); 
            }
            player->SetLevel(player->GetLevel() + 3);
            player->SetEnergy(player->GetEnergy() - 8);
            textBox->SetPath("None");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
            break;
    }
}
void handleStatsEvents(SDL_Event &event, Background *textBox, Character *player)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            player->PrintStats();
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png");
            break;
    }
}
void handleRunEvents(SDL_Event &event, Background *textBox, Game *game)
{
    switch(event.key.keysym.sym){
        case SDLK_1:
            game->SetIsRunning(false);
            break;
        case SDLK_2:
            textBox->SetPath("assets/TextBoxes/Main.png");
            break;
        default:
            textBox->SetPath("assets/TextBoxes/Main.png"); // if you press any key it will go back to the main text box
            break;
    }
}