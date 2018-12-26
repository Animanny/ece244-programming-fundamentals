#include <galaxy-explorer/GameAI.hpp>
#include <galaxy-explorer/MyAIData.hpp>

#include <SFML/Graphics.hpp>

using namespace std;
#include<iostream>


GameAI::GameAI(const GameInfo& game_info, sf::RenderTarget* debug_rt)
{
	this->debug_rt = debug_rt;
	this->game_info = game_info;
	this->asteroid_observer = AsteroidsObserver(this);
	this->my_game_ai = new MyAIData();

	// customState().debug_on = false;
}

GameAI::~GameAI() {
	delete my_game_ai;
}

SuggestedAction GameAI::suggestAction(const ShipState& ship_state) {
	debug_rt->clear(sf::Color::Transparent);
        float deltaX, deltaY; // difference in location of asteroid and ship
        
        float shipX = ship_state.hitbox.left; // xy coordinate of ship
        float shipY = ship_state.hitbox.top;
        
        float asteroidX, asteroidY; // xy coordinate of asteroid
        
        SuggestedAction move;

	if (customState().debug_on) {
		if (not asteroidsObserver().asteroids().isEmpty()) {
                    for (AsteroidListItem* item = asteroidsObserver().asteroids().begin(); 
                        item != asteroidsObserver().asteroids().end(); 
                        item = item->getNext()) {
//			const sf::IntRect first_ast_hb = asteroidsObserver().asteroids().front().getCurrentHitbox();
                        const sf::IntRect first_ast_hb = item->getData().getCurrentHitbox();
			sf::RectangleShape ast_rect(sf::Vector2f(first_ast_hb.width, first_ast_hb.height));
			ast_rect.setPosition(first_ast_hb.left, first_ast_hb.top);
			ast_rect.setOutlineThickness(33.0f); // if lines are too thin, they won't show up sometimes
			ast_rect.setOutlineColor(sf::Color::Yellow);
			ast_rect.setFillColor(sf::Color::Transparent);
			debug_rt->draw(ast_rect);
                        
                        asteroidY = item->getData().getCurrentHitbox().top;
                        asteroidX = item->getData().getCurrentHitbox().left;
            
//                        cout << "asteroid " << item->getData().getID() << " x: " << asteroidX << endl;
//                        cout << "asteroid " << item->getData().getID() << " y: " << asteroidY << endl;

//                        deltaX = asteroidX - shipX;
//                        deltaY = shipY - asteroidY;
//                        
//                        cout << "deltaX: " << deltaX <<endl;
//                        cout << "deltaY: " << deltaY <<endl;
//                        cout << "asteroid " << item->getData().getID() << " y: " << asteroidY << endl;



//                        if ((deltaY < 2000 && deltaX < 2000) ||  (deltaY < 2000 && deltaX > 0) ) {
//                            return SuggestedAction{ SuggestedAction::YawingClockwise, SuggestedAction::FiringTry };
//
//                        } else if ((deltaY < 2000 && deltaX > -2000 ) ||  (deltaY < 2000 && deltaX < 0) ){
//                            return  SuggestedAction{ SuggestedAction::YawingAntiClockwise, SuggestedAction::FiringTry };
//
//                        }

//                        if ((deltaY < 3500 && deltaX > -2500) || (deltaY < 3500 && deltaX > 0)) { // if coming from the right and above                
////                            cout << " rotate clock wise" << endl;
//                            move = SimpleActions::START_YAWING_CW;
//                        } else if ((deltaY < 3500 && deltaX < 2500) || (deltaY < 3500 && deltaX > 0)){ // if coming from the left and above
////                            cout << "rotate counter clock wise" << endl;
//                            move = SimpleActions::START_YAWING_ACW;
//                        } 
                    }
		}
	}
        
        
	// return SimpleActions::NO_CHANGE;
//	return SimpleActions::START_YAWING_CW;
	// return SimpleActions::START_YAWING_ACW;
	// return SimpleActions::STOP_YAWING_AND_FIRE;
	// return SuggestedAction{ SuggestedAction::YawingClockwise, SuggestedAction::FiringTry };
        

        
//        if (!ship_state.fire_phaser_requested) {
//           return SuggestedAction{ SuggestedAction::YawingClockwise, SuggestedAction::FiringTry };
//           
//        }
        
        if (ship_state.millidegree_rotation < -35) return SuggestedAction{SuggestedAction::YawingAntiClockwise, SuggestedAction::FiringTry};
        if (ship_state.millidegree_rotation > 35) return SuggestedAction{SuggestedAction::YawingClockwise, SuggestedAction::FiringTry};
          
        
            
        
        
       
        
        
         
            
        
       
        
        
}
