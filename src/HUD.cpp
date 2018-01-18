//
// Created by Loic Dupil on 09/01/2018.
//

#include <HUD.h>
#include <Handler/GameHandler.h>


Hud::Hud()
{

}

Hud::~Hud()
{

}

void Hud::initHud(const std::string &path)
{
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i)
    {
        (void) i;

        if (path.find("EmptyHeart.png") != std::string::npos)
            this->fillHeartVector(path, this->emptyHearts);
        else if (path.find("FilledHeart.png") != std::string::npos)
            this->fillHeartVector(path, this->filledHearts);
        else if (path.find("score.png") != std::string::npos)
            this->addScoreTexture(path);
        else
            this->addScoreNumberTexture(path);

    });
}

void Hud::drawHud(sf::RenderWindow &App)
{
    for (const auto &emptyHeart : emptyHearts)
        App.draw(emptyHeart->img);

    for (const auto &filledHeart : filledHearts)
        App.draw(filledHeart->img);

    App.draw(scoreText->img);
    this->drawScore(10, firtScoreTextNumberPosition);
}

void Hud::fillHeartVector(const std::string &path, std::vector<std::shared_ptr<Hud::t_layer>> &vector)
{
    float firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
    float firstYPos = 0;
    int hp = 0;

    vector.emplace_back(new t_layer(path, sf::Vector2f(firstXPos, firstYPos)));
    hp++;
    while (hp < WindowProperties::MAX_PLAYER_HP)
    {
        firstXPos += (float) vector.front()->texture.getSize().x / 2;
        vector.emplace_back(new t_layer(path, sf::Vector2f(firstXPos, firstYPos)));
        hp++;
    }

}

void Hud::takeDamage()
{
    filledHearts.pop_back();
}

void Hud::addScoreNumberTexture(const std::string &path)
{
    firtScoreTextNumberPosition.x = scoreText->img.getPosition().x + scoreText->texture.getSize().x;
    firtScoreTextNumberPosition.y = this->filledHearts.back()->img.getPosition().y;

    scoreNumbers.emplace_back(new t_layer(path, firtScoreTextNumberPosition));
    firtScoreTextNumberPosition.x += scoreNumbers.front()->texture.getSize().x / 2;
}

void Hud::addScoreTexture(const std::string &path)
{
    sf::Vector2f scorePosition;
    scorePosition.x = this->filledHearts.back()->img.getPosition().x +  this->filledHearts.back()->texture.getSize().x;
    scorePosition.y = this->filledHearts.back()->img.getPosition().y;

    std::cout << scorePosition.x << std::endl;
    this->scoreText = std::shared_ptr<t_layer>(new t_layer(path, scorePosition));
}

void Hud::drawScore(int playerScore, sf::Vector2f position)
{
    if (playerScore < 10)
    {
        scoreNumbers.at(playerScore)->img.setPosition(position);
        WindowProperties::App->draw(scoreNumbers.at(playerScore)->img);
    }
    else
    {
        drawScore(playerScore / 10, position);
        position.x += scoreNumbers.front()->texture.getSize().x / 2;
        scoreNumbers.at(playerScore % 10)->img.setPosition(position);
        WindowProperties::App->draw(scoreNumbers.at(playerScore % 10)->img);
    }
}

Hud::t_layer::t_layer(const std::string &path, sf::Vector2f position)
{
    texture.loadFromFile(path);
    img.setTexture(texture);
    img.setPosition(position);
}
