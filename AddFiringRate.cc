#include "AddFiringRate.h"
#include "SpaceShip.h"
#include "GameFrame.h"
#include <string>

AddFiringRate::AddFiringRate(
        GameFrame &gameFrame,
        bool allowAnti,
        sf::Time lifeTime,
        sf::Time activeTime)
    : PowerUp(gameFrame, allowAnti, lifeTime, activeTime)
{
    std::string file;
    if (anti)
    {
        file = "Images/PowerUps/RPM-.png";
        firingrate = -DEFAULT_SHIP_FIRE_RATE/1.5;
    }
    else
    {
        file = "Images/PowerUps/RPM+.png";
        firingrate = 10.0f;
    }
    setTexture(gameFrame.textureHandler.getTexture(file));
    setScale(0.5f, 0.5f);
    setRandomPosition();
}

void AddFiringRate::activate(SpaceShip &ship) const
{
    ship.addWeaponAttributes(firingrate, 0.0f);
}

void AddFiringRate::deactivate(SpaceShip &ship) const
{
    ship.addWeaponAttributes(-firingrate, 0.0f);
}
