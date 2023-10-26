#include "card.h"

 Card::Card(int id, string text){
    this->id = id;
    this->text = text;
 }

 int Card::getId(){
    return id;
 }

 string Card::getText(){
    return text;
 }

 PointCard::PointCard(int id, string text, int points):Card(id, text){
    this->points = points;
 }

 void PointCard::cardAction(Player* player, Player* opponent){
    if (points > 0)
    {
        player->addPoints(points);
        opponent->removePoints(points);
    }
    else
    {
        player->removePoints(-points);
        opponent->addPoints(-points);
    }
 }

 MoveCard::MoveCard(int id, string text, MoveType type):Card(id, text){
    this->type = type;
 }

 void MoveCard::cardAction(Player* player, Player* opponent){
    if (type == PlayTwice)
    {
        opponent->missNextTurn();
    }
    else if (type == MissTurn)
    {
        player->missNextTurn();
    }
 }
