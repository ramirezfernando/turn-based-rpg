#include "character.h"
#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include "constants/asset_constants.h"
#include "constants/game_constants.h"
#include "game.h"

Character::~Character() {
  SDL_DestroyTexture(character_texture_);
  std::clog << "Character destroyed" << std::endl;
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

std::string Character::GetCharacterTypeString() const {
  if (dynamic_cast<const FireKnight*>(this)) {
    return constants::FIRE_KNIGHT_CHARACTER_TYPE_STRING;
  } else if (dynamic_cast<const GroundMonk*>(this)) {
    return constants::GROUND_MONK_CHARACTER_TYPE_STRING;
  } else if (dynamic_cast<const WaterPriestess*>(this)) {
    return constants::WATER_PRIESTESS_CHARACTER_TYPE_STRING;
  }
  return "";
}

constants::AttackType Character::GetAiDecision(Character* enemy) {
  CURL* curl = curl_easy_init();
  std::string response_data;
  if (!curl) {
    std::cerr << "Failed to initialize cURL" << std::endl;
    return constants::AttackType::ATTACK1;
  }

  //std::string api_key = "";
  std::string api_key = Util::GetApiKey();

  if (api_key.empty()) {
    std::cerr << "API key is empty. Please set it in api_key.txt." << std::endl;
    return constants::AttackType::ATTACK1;
  }

  std::string prompt =
      "You are an AI controlling a character in a turn-based RPG battle. "
      "This game features three character types: Fire Knight, Ground Monk, "
      "and Water Priestess. Each character has unique attributes and "
      "abilities that affect their combat style and strategy.\n\n"

      "Each character can perform four types of attacks 1 through 4, each with "
      "different damage and energy costs; attack 1 does the least damage "
      "and costs the least energy, while attack 4 does the most damage and "
      "costs the most energy. The game ends when either the player or "
      "the enemy's health reaches zero or their energy is depleted.\n\n"

      "The character types and their attributes are:\n\n"

      "1. Fire Knight:\n"
      "- High damage dealer\n"
      "- High energy cost\n"
      "- Best suited for aggressive play and high damage output\n\n"

      "2. Ground Monk:\n"
      "- Balanced character\n"
      "- Standard energy costs\n"
      "- Well-rounded and adaptable\n\n"

      "3. Water Priestess:\n"
      "- Lower base damage\n"
      "- Efficient energy usage\n"
      "- Excels at sustained combat\n\n"

      "Your task is to choose the most strategic attack based on the current "
      "state of the battle. Consider the following factors:\n";

  if (dynamic_cast<FireKnight*>(this)) {
    prompt += "You are a Fire Knight.\n";
  } else if (dynamic_cast<GroundMonk*>(this)) {
    prompt += "You are a Ground Monk.\n";
  } else if (dynamic_cast<WaterPriestess*>(this)) {
    prompt += "You are a Water Priestess.\n";
  }

  if (dynamic_cast<FireKnight*>(enemy)) {
    prompt += "The enemy is a Fire Knight.\n";
  } else if (dynamic_cast<GroundMonk*>(enemy)) {
    prompt += "The enemy is a Ground Monk.\n";
  } else if (dynamic_cast<WaterPriestess*>(enemy)) {
    prompt += "The enemy is a Water Priestess.\n";
  }

  prompt += "Your character stats:\n";
  prompt += "- Level: " + std::to_string(level_) + "\n";
  prompt += "- Health: " + std::to_string(health_) + "\n";
  prompt += "- Energy: " + std::to_string(energy_) + "\n";

  prompt += "Enemy character stats:\n";
  prompt += "- Level: " + std::to_string(enemy->GetLevel()) + "\n";
  prompt += "- Health: " + std::to_string(enemy->GetHealth()) + "\n";
  prompt += "- Energy: " + std::to_string(enemy->GetEnergy()) + "\n";

  prompt += "\nYour available attacks:\n";
  prompt += "1. Basic Attack: " + std::to_string(attack1_damage_) +
            " damage, costs " + std::to_string(attack1_energy_cost_) +
            " energy\n";
  prompt += "2. Medium Attack: " + std::to_string(attack2_damage_) +
            " damage, costs " + std::to_string(attack2_energy_cost_) +
            " energy\n";
  prompt += "3. Heavy Attack: " + std::to_string(attack3_damage_) +
            " damage, costs " + std::to_string(attack3_energy_cost_) +
            " energy\n";
  prompt += "4. Ultimate Attack: " + std::to_string(attack4_damage_) +
            " damage, costs " + std::to_string(attack4_energy_cost_) +
            " energy\n";

  prompt +=
      "\nBased on your character type, current state, and available attacks, "
      "choose the most strategic attack. Respond with only the number 1-4.";

  std::clog << prompt << std::endl;

  nlohmann::json body = {
      {"model", "gpt-3.5-turbo"},
      {"messages", {{{"role", "user"}, {"content", prompt}}}}};

  struct curl_slist* headers = nullptr;
  headers =
      curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
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

  try {
    auto json = nlohmann::json::parse(response_data);
    std::string choice =
        json["choices"][0]["message"]["content"].get<std::string>();
    // Parse the response and return appropriate attack type.
    if (choice.find("1") != std::string::npos) {
      return constants::AttackType::ATTACK1;
    } else if (choice.find("2") != std::string::npos) {
      return constants::AttackType::ATTACK2;
    } else if (choice.find("3") != std::string::npos) {
      return constants::AttackType::ATTACK3;
    } else if (choice.find("4") != std::string::npos) {
      return constants::AttackType::ATTACK4;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error parsing OpenAI response: " << e.what() << std::endl;
  }

  // Fallback strategy based on energy levels.
  if (energy_ >= attack4_energy_cost_) {
    return constants::AttackType::ATTACK4;
  } else if (energy_ >= attack3_energy_cost_) {
    return constants::AttackType::ATTACK3;
  } else if (energy_ >= attack2_energy_cost_) {
    return constants::AttackType::ATTACK2;
  }
  return constants::AttackType::ATTACK1;
}