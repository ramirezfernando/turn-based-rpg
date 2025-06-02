#include "character.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include "constants/asset_constants.h"
#include "constants/game_constants.h"

Character::~Character() {
  SDL_DestroyTexture(character_texture_);
  std::cout << "Character destroyed" << std::endl;
}

void Character::Update() {
  src_rect_.h = constants::CHARACTER_HEIGHT;
  src_rect_.w = constants::CHARACTER_WIDTH;
  src_rect_.x = 0;
  src_rect_.y = 0;
  dest_rect_.x = x_pos_;
  dest_rect_.y = y_pos_;
  dest_rect_.h = src_rect_.h * 2;
  dest_rect_.w = src_rect_.w * 2;

  Uint32 current_time = SDL_GetTicks();
  if (current_time > last_frame_time_ + delay_) {
    if (count_ < frames_) {
      std::string filename =
          folder_path_ + "/" + std::to_string(count_) + ".png";
      const char* file = filename.c_str();
      character_texture_ = Util::LoadTexture(file);
      count_++;
    } else {
      // This ensures that the character returns to an idle state after
      // performing an action (attack, defend, etc.) and that the idle animation
      // is played only once after the action is completed. The only exception
      // is when the character is dead, in which case the death animation is
      // kept.
      if (health_ > 0) {
        this->Idle();
        this->Update();
      } else {
        this->Death();
      }
      // Animation is complete
      if (is_attacking_) {
        is_attacking_ = false;  // Reset attack state
      }
    }
    last_frame_time_ = current_time;
  }
}

void Character::Render() {
  if (is_enemy_) {
    Util::RenderInvertedTexture(character_texture_, src_rect_, dest_rect_,
                                SDL_FLIP_HORIZONTAL);
  } else {
    SDL_RenderCopy(Game::renderer_, character_texture_, &src_rect_,
                   &dest_rect_);
  }
}

constants::AttackType Character::GetAiDecision() {
  return constants::AttackType::ATTACK1;
  CURL* curl = curl_easy_init();
  std::string response_data;
  if (curl) {
    std::string api_key = "Bearer ";
    std::string prompt = "Enemy is level " + std::to_string(level_) +
                         " and has " + std::to_string(health_) + " HP and " +
                         std::to_string(energy_) +
                         " energy. "
                         "Choose an action: 'attack', 'defend', or 'heal'.";
    nlohmann::json body = {
        {"model", "gpt-3.5-turbo"},
        {"messages", {{{"role", "user"}, {"content", prompt}}}}};

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("Authorization: " + api_key).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");

    std::string body_str = body.dump();
    curl_easy_setopt(curl, CURLOPT_URL,
                     "https://api.openai.com/v1/chat/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body_str.c_str());

    curl_easy_setopt(
        curl, CURLOPT_WRITEFUNCTION,
        +[](char* ptr, size_t size, size_t nmemb, std::string* data) {
          data->append(ptr, size * nmemb);
          return size * nmemb;
        });
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
  }
  // std::cout << response_data << std::endl;
  // return "attack";

  // // Parse OpenAI response
  // auto json = nlohmann::json::parse(response_data, nullptr, false);
  // if (json.is_discarded())
  //   return "attack";  // fallback

  // try {
  //   return json["choices"][0]["message"]["content"].get<std::string>();
  // } catch (const std::exception& e) {
  //   std::cout << "Error parsing OpenAI response: " << e.what() << std::endl;
  // }
}