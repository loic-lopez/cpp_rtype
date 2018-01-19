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
        {
            float firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
            float firstYPos = 0;
            this->emptyHeartRef = std::make_shared<t_layer>(path, sf::Vector2f(firstXPos, firstYPos));
            this->fillHeartVector(this->emptyHearts, emptyHeartRef.get());
        }
        else if (path.find("FilledHeart.png") != std::string::npos)
        {
            float firstXPos = (float) WindowProperties::WIN_WIDTH / 100;
            float firstYPos = 0;
            this->filledHeartRef = std::make_shared<t_layer>(path, sf::Vector2f(firstXPos, firstYPos));
            this->fillHeartVector(this->filledHearts, filledHeartRef.get());
        }
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
    this->drawScore(GameHandler::Instance().getPlayer()->getScore(), firstScoreTextNumberPosition);
}

void Hud::fillHeartVector(std::vector<std::shared_ptr<Hud::t_layer>> &vector, t_layer *ref)
{
    float firstXPos = ref->img.getPosition().x;
    float firstYPos = ref->img.getPosition().y;
    int hp = 1;

    t_layer *newRef = new t_layer(ref);
    vector.emplace_back(newRef);
    while (hp < WindowProperties::MAX_PLAYER_HP)
    {
        newRef = new t_layer(ref);
        firstXPos += (float) vector.front()->texture.getSize().x / 2;
        newRef->img.setPosition(firstXPos, firstYPos);
        vector.emplace_back(newRef);
        hp++;
    }
}

void Hud::fillHeartVector(std::vector<std::shared_ptr<Hud::t_layer>> &vector, t_layer *ref, int currentPlayerHp)
{
    float firstXPos = ref->img.getPosition().x;
    float firstYPos = ref->img.getPosition().y;
    int hp = 1;

    t_layer *newRef = new t_layer(ref);
    vector.emplace_back(newRef);
    while (hp < currentPlayerHp)
    {
        newRef = new t_layer(ref);
        firstXPos += (float) vector.front()->texture.getSize().x / 2;
        newRef->img.setPosition(firstXPos, firstYPos);
        vector.emplace_back(newRef);
        hp++;
    }
}

void Hud::takeDamage()
{
    if (!filledHearts.empty())
        filledHearts.pop_back();
}

void Hud::addScoreNumberTexture(const std::string &path)
{
    firstScoreTextNumberPosition.x = scoreText->img.getPosition().x + scoreText->texture.getSize().x * 0.85f;
    firstScoreTextNumberPosition.y =
            this->filledHearts.back()->img.getPosition().y + (scoreText->texture.getSize().y * 0.15f);

    scoreNumbers.emplace_back(new t_layer(path, firstScoreTextNumberPosition));
    sf::Vector2f currentFirstPosition = scoreNumbers.front()->img.getPosition();
    scoreNumbers.front()->img.setPosition(
            sf::Vector2f(currentFirstPosition.x + scoreNumbers.front()->texture.getSize().x, currentFirstPosition.y));
    firstScoreTextNumberPosition.x += scoreNumbers.front()->texture.getSize().x;
}

void Hud::addScoreTexture(const std::string &path)
{
    sf::Vector2f scorePosition;
    scorePosition.x = this->filledHearts.back()->img.getPosition().x + this->filledHearts.back()->texture.getSize().x;
    scorePosition.y = this->filledHearts.back()->img.getPosition().y;

    this->scoreText = std::make_shared<t_layer>(path, scorePosition);
}

void Hud::drawScore(int playerScore, sf::Vector2f position)
{

    if (playerScore < 10)
    {
        scoreNumbers.at(playerScore)->img.setPosition(position);
        WindowProperties::App->draw(scoreNumbers.at(playerScore)->img);
    }
    else if (playerScore >= 10)
    {
        drawScore(playerScore / 10, position);
        position.x += scoreNumbers.front()->texture.getSize().x * [](int digit) -> int
        {
            int ret = -1;
            while (digit > 0)
            {
                digit /= 10;
                ret++;
            }
            return ret;
        }(playerScore);
        scoreNumbers.at(playerScore % 10)->img.setPosition(position);
        WindowProperties::App->draw(scoreNumbers.at(playerScore % 10)->img);
    }
}

void Hud::resetHud()
{
    this->fillHeartVector(this->filledHearts, filledHeartRef.get(), GameHandler::Instance().getPlayer()->getHp());
}

bool Hud::emptyFilledHearthsVector()
{
    if (this->filledHearts.empty())
        return this->filledHearts.empty();
    else
    {
        bool toRet = this->filledHearts.size() != WindowProperties::MAX_PLAYER_HP;
        if (toRet)
            this->filledHearts.clear();
        return toRet;
    }
}

Hud::t_layer::t_layer(const std::string &path, sf::Vector2f position)
{
    texture.loadFromFile(path);
    img.setTexture(texture);
    img.setPosition(position);
}

Hud::t_layer::t_layer(const Hud::t_layer *layer)
{
    this->texture = layer->texture;
    this->img = layer->img;
    this->id = layer->id;
}

