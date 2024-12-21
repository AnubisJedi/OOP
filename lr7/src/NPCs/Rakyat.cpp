#include "../../include/NPCs/Rakyat.h"

Rakyat::Rakyat (Point<int> pos, std::string name) : NPC(pos, name, NPCType::RakyatType, 5, 5, 'J') {}

bool Rakyat::fight (const Pirate &other) {
    fightNotify(other.getName());
    return true;
}

bool Rakyat::fight (const Privateer &other) {
    return false;
}

bool Rakyat::fight (const Rakyat &other) {
    return false;
}

bool Rakyat::accept (std::shared_ptr<NPC> other) {
    return other->fight(*this);
}

void Rakyat::move (std::size_t mapWidth, std::size_t mapHeight) {
    std::lock_guard<std::shared_mutex> lock(mtx);

    for (std::size_t i = 0; i < getMovePoints(); i++) {
        Point<int> dPos(std::rand() % 3 - 1, std::rand() % 3 - 1);
        position = position + dPos;

        if (position.getX() < 0) position.setX(0); 
        else if (position.getX() >= mapWidth) position.setX(mapWidth - 1); 
        if (position.getY() < 0) position.setY(0); 
        else if (position.getY() >= mapHeight) position.setY(mapHeight - 1); 
    }
}

std::ostream& Rakyat::print (std::ostream &os) {
    os << "Rakyat {" << std::endl;
    os << "\tname: " << getName() << std::endl;
    os << "\tposition: " << getPos() << std::endl;
    os << "}";

    return os;
}

std::ostream& operator<<(std::ostream &os, Rakyat &rakyat) {
    return rakyat.print(os);
}