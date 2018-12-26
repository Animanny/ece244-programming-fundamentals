//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#include <tic-tac-toe/playMove.h>

using namespace std;
using namespace sf;


int main() {

    /************************************************************************************************************/
    /* The following variables define the state of the game                                                     */
    /************************************************************************************************************/

    // You should complete the following declarations
    // Make sure to initalize the variables

    // The game board array
    int gameBoard[3][3] = {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty};

    // An boolean that represents the turn in the game
    bool turn = true;

    // A boolean to represent if the move is valid
    bool is_valid_move = true;

    // A boolean to represent if the game is over
    bool is_game_over = false;

    // An integer that represents the win code
    int win_code = 0;
    /************************************************************************************************************/
    /* Insert code that loads the various images used by the game and creates the sprites                       */
    /* The loading of the X image is shown. Repreat for the rest of the images                                  */
    /************************************************************************************************************/

    // Get the X image
    sf::Texture X_texture;
    if (!X_texture.loadFromFile("X.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite X_sprite(X_texture);

    // Get the O image
    sf::Texture O_texture;
    if (!O_texture.loadFromFile("O.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite O_sprite(O_texture);
    
    // Get the blank image
    sf::Texture blank_texture;
    if (!blank_texture.loadFromFile("blank.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite blank_sprite(blank_texture);
    

    /************************************************************************************************************/
    /* Insert code that creates the window and displays it                                                      */
    /************************************************************************************************************/

    // First, we find the sizes of the images so we can determine the size of the window we must create
    // The images (X, O and Black) are assumed to be square are are all of the same size
    // Thus, we just find the size of one of them

    // The tile size is the size of the images
    const int tileSize = X_texture.getSize().x;

    // The cell borders (thick lines) are rectangles
    // The size of these rectangles is 1/20th of the size of the tile by 3 cell sizes plus 2 barWidth's
    const int barWidth = tileSize/20;
    const int barHeight = boardSize*tileSize + (boardSize-1)*barWidth;

    // The size of the window in pixels can now be calculated
    const int windowSize = boardSize*tileSize + (boardSize-1)*barWidth;

    // Create the main window: it has a title bar and a close button, but is not resizable
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), 
            "ECE244 Tic-Tac-Toe", 
            sf::Style::Titlebar | sf::Style::Close);

    // Set the Icon that appears in the task bar when the window is minimized
    // Insert you code here, see the lab handout
    sf::Image windowIcon;
    if (!windowIcon.loadFromFile("icon.jpg")){
        return EXIT_FAILURE;
    }
    window.setIcon(windowIcon.getSize().x,
            windowIcon.getSize().y,
            windowIcon.getPixelsPtr());

    // Create the horizonal (vertical) borders as rectangles of sizes barWidth and barHeight (berHeight and barWidth)
    // Insert your code here
    //
//    int tile_x = 0;
//    int tile_y= 0;
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            blank_sprite.setPosition(tile_x, tile_y);
//            tile_x = tile_x + barWidth + tileSize;
//            window.draw(blank_sprite);
//        }
//        tile_y = tile_y + barWidth + tileSize;
//        tile_x = 0;
//
//    }
//    window.display();
    

    /************************************************************************************************************/
    /* This is the main event loop of the code                                                                  */
    /************************************************************************************************************/

    // Start the game loop that runs as long as the window is open
    while (window.isOpen()) {
        // The event
        sf::Event event;

        // Process the events
        while (window.pollEvent(event)) {

            // This is the handling of the close window event
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
           
            // Left mouse button pressed: get the click position and play the move
            // is_game_over is a variable you should define above
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // left mouse button is pressed: get the coordinates in pixels
                // Insert your code to get the coordinates here
                int x = event.mouseButton.x; // x-coordinate
                int y = event.mouseButton.y; // y-coordinate
                cout << "x position: " << x << "y position: " << y << endl;

                int row;
                int col;

                // Convert the pixel coordinates into game board rows and columns
                // Just divide by tileSize
                // Observe that the x axis is the rows and the y axis is the columns
                // Also make sure that row and column values are valid
                // Insert your code below
                if (x >= 0 && x < tileSize && y >= 0 && y < tileSize) {
                    cout << "row: 0 col: 0" << endl;
                    cout << "x / doubleTileSize: " <<  x / doubleTileSize << endl;
                    cout << "y / doubleTileSize: " <<  y / doubleTileSize << endl;
                    row = 0;
                    col = 0;
                } else if (x >= tileSize && x < 2 * tileSize && y >= 0 && y < tileSize) {
                    cout << "row: 0 col: 1" << endl;
                    cout << "x / doubleTileSize: " <<  x / doubleTileSize << endl;
                    cout << "y / doubleTileSize: " <<  y / doubleTileSize << endl;
                    row = 0;
                    col = 1;
                } else if (x / doubleTileSize >= 0 && x / doubleTileSize <= 1 + barWidth && y / doubleTileSize > 2 + 2 * barWidth && y / doubleTileSize <= 3 + 2 * barWidth) {
                    cout << "row: 0 col: 2" << endl;
                    cout << "x / doubleTileSize: " <<  x / doubleTileSize << endl;
                    cout << "y / doubleTileSize: " <<  y / doubleTileSize << endl;
                    row = 0;
                    col = 2;
                } else if (x / doubleTileSize > 1 + barWidth && x / doubleTileSize <= 2 + 2 * barWidth && y / doubleTileSize >= 0 && y / doubleTileSize <= 1 + barWidth) {
                    cout << "row: 0 col: 1" << endl;
                    cout << "x / doubleTileSize: " <<  x / doubleTileSize << endl;
                    cout << "y / doubleTileSize: " <<  y / doubleTileSize << endl;
                    row = 0;
                    col = 1;
                }

                // check valid move
//                is_valid_move = isValidMove(gameBoard, row, col);
                // Play the move by calling the playMove function
                // Insert your code below
                playMove (gameBoard, row, col, turn, is_valid_move, is_game_over, win_code);
            }
        }

        // Insert code to draw the tiles using the sprites created earlier
        // You must determine the position of each cell on the grid, taking into account the width of
        // the border and then position the sprite there and draw it.
        // Draw the entire board, cell borders included,
        // reflecting any move that has just happened (check the gameBoard array)
        // Further, if the game is over and one player wins, you must create and draw a rectangle of
        // windowSize width and 10 pixels height to indicate the winning marks
        // The fill of this rectangle should be white

        // Insert your code here
//        window.clear(new Color(0,0,0,0));

        // Display to the window
        int tile_x = 0;
        int tile_y= 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameBoard[i][j] == 1) {
//                    cout << "x at row " << i << "col " << j << endl;
                    X_sprite.setPosition(tile_x, tile_y);
                    window.draw(X_sprite);
                } else if (gameBoard[i][j] == -1) {
//                    cout << "O at row " << i << "col " << j << endl;
                    O_sprite.setPosition(tile_x, tile_y);
                    window.draw(O_sprite);
                } else {
                    blank_sprite.setPosition(tile_x, tile_y);
                    tile_x = tile_x + barWidth + tileSize;
                    window.draw(blank_sprite);
                }
            }
            tile_y = tile_y + barWidth + tileSize;
            tile_x = 0;

        
            
        } 
        window.display();
        
    }

    return EXIT_SUCCESS;
}
