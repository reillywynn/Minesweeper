#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "TextureManager.h"
#include "Board.h"
#include "Tile.h"
using namespace std;
using namespace sf;

int main()
{
    Board board;
    bool debugMode = false;
    bool btest1 = false;
    bool btest2 = false;
    bool btest3 = false;

    sf::Sprite backgroundTile(TextureManager::GetTexture("tile_revealed"));
    sf::Sprite coverTile(TextureManager::GetTexture("tile_hidden"));
    sf::Sprite debug(TextureManager::GetTexture("debug"));
    sf::Sprite digits(TextureManager::GetTexture("digits"));
    sf::Sprite happyFace(TextureManager::GetTexture("face_happy"));
    sf::Sprite loseFace(TextureManager::GetTexture("face_lose"));
    sf::Sprite winFace(TextureManager::GetTexture("face_win"));
    sf::Sprite flag(TextureManager::GetTexture("flag"));
    sf::Sprite mine(TextureManager::GetTexture("mine"));
    sf::Sprite num1(TextureManager::GetTexture("number_1"));
    sf::Sprite num2(TextureManager::GetTexture("number_2"));
    sf::Sprite num3(TextureManager::GetTexture("number_3"));
    sf::Sprite num4(TextureManager::GetTexture("number_4"));
    sf::Sprite num5(TextureManager::GetTexture("number_5"));
    sf::Sprite num6(TextureManager::GetTexture("number_6"));
    sf::Sprite num7(TextureManager::GetTexture("number_7"));
    sf::Sprite num8(TextureManager::GetTexture("number_8"));
    sf::Sprite test1(TextureManager::GetTexture("test_1"));
    sf::Sprite test2(TextureManager::GetTexture("test_2"));
    sf::Sprite test3(TextureManager::GetTexture("test_3"));
   
    

    RenderWindow window(sf::VideoMode(800, 600), "MINESWEEPER");
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    
                    if (pos.x >= 0 && pos.x <= 800 && pos.y >= 0 && pos.y <= 512 && board.GetLose() == false) {
                        if (board._board[(int)pos.y / 32][(int)pos.x / 32].GetFlag() == false) {
                            board.uncover((int)pos.y / 32, (int)pos.x / 32);
                        }
                    }
                    if (pos.x >= 544 && pos.x <= 608 && pos.y >= 512 && pos.y <= 544) {
                        debugMode = true;
                    }

                    if (pos.x >= 608 && pos.x <= 672 && pos.y >= 512 && pos.y <= 544) {
                        btest1 = true;
                        btest2 = false;
                        btest3 = false;
                    }

                    if (pos.x >= 672 && pos.x <= 736 && pos.y >= 512 && pos.y <= 544) {
                        btest2 = true;
                        btest1 = false;
                        btest3 = false;
                    }

                    if (pos.x >= 736 && pos.x <= 800 && pos.y >= 512 && pos.y <= 544) {
                        btest3 = true;
                        btest2 = false;
                        btest1 = false;
                    }

                    if (pos.x >= 384 && pos.x <= 448 && pos.y >= 512 && pos.y <= 544) {
                        board.SetLose();
                    }

                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    
                    if (pos.x >= 0 && pos.x <= 800 && pos.y >= 0 && pos.y <= 512 && board.GetLose() == false && board._board[pos.y/32][pos.x/32].GetReveal() == false) {
                        if (board._board[pos.y / 32][pos.x / 32].GetFlag() == false) {
                            board._board[pos.y / 32][pos.x / 32].SetFlag();
                            board.flagCountUp();
                            break;
                        }
                        if (board._board[pos.y / 32][pos.x / 32].GetFlag() == true) {
                            board.flagCountDown();
                            board._board[pos.y / 32][pos.x / 32].SetFlagFalse();
                        }
                    }
                    
                }
            }
        }
        
        window.clear();
        
        
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 25; j++) {
                
                if (board._board[i][j].GetReveal() == true) {
                    
                    backgroundTile.setPosition(32 * j, 32 * i);
                    window.draw(backgroundTile);

                    if (board._board[i][j].GetNum() == 1) {
                        num1.setPosition(32 * j, 32 * i);
                        window.draw(num1);
                    }
                    if (board._board[i][j].GetNum() == 2) {
                        num2.setPosition(32 * j, 32 * i);
                        window.draw(num2);
                    }
                    if (board._board[i][j].GetNum() == 3) {
                        num3.setPosition(32 * j, 32 * i);
                        window.draw(num3);
                    }
                    if (board._board[i][j].GetNum() == 4) {
                        num4.setPosition(32 * j, 32 * i);
                        window.draw(num4);
                    }
                    if (board._board[i][j].GetNum() == 5) {
                        num5.setPosition(32 * j, 32 * i);
                        window.draw(num5);
                    }
                    if (board._board[i][j].GetNum() == 6) {
                        num6.setPosition(32 * j, 32 * i);
                        window.draw(num6);
                    }
                    if (board._board[i][j].GetNum() == 7) {
                        num7.setPosition(32 * j, 32 * i);
                        window.draw(num7);
                    }
                    if (board._board[i][j].GetNum() == 8) {
                        num8.setPosition(32 * j, 32 * i);
                        window.draw(num8);
                    }
                    if (board._board[i][j].GetMine() == true) {
                        mine.setPosition(32 * j, 32 * i);
                        window.draw(mine);
                    }
                    
                }
                else {
                    coverTile.setPosition(32 * j, 32 * i);
                    window.draw(coverTile);
                }
                
                if (board._board[i][j].GetFlag() == true) {
                     coverTile.setPosition(32 * j, 32 * i);
                     window.draw(coverTile);

                     if (board._board[i][j].GetFlag() == true) {
                         flag.setPosition(32 * j, 32 * i);
                         window.draw(flag);
                     }
                }

                
                debug.setPosition(17 * 32, 0 + 32 * (i+1));
                window.draw(debug);

                test1.setPosition(19 * 32, 0 + 32 * (i + 1));
                window.draw(test1);

                test2.setPosition(21 * 32, 0 + 32 * (i + 1));
                window.draw(test2);

                test3.setPosition(736, 0 + 32 * (i + 1));
                window.draw(test3);

                if (board._board[i][j].GetFlag() == true && board._board[i][j].GetMine() == true && (board.GetMineCount() - board.GetFlags()) == 0) {
                    board.SetWin();
                }

                if (board.GetLose() == true) {
                    loseFace.setPosition((25/2) * 32, 32 * (i + 1));
                    window.draw(loseFace);
                }

                if (board.GetRunning() == true && board.GetLose() == false) {
                    happyFace.setPosition((25/2) * 32, 32 * (i + 1));
                    window.draw(happyFace);
                 
                }
                else if (board.GetWin() == true) {
                    winFace.setPosition(13 * 32, 32 * (i + 1));
                    window.draw(winFace);
                }
                
                   
                if (event.mouseButton.x >= 384 && event.mouseButton.x <= 448 && event.mouseButton.y <= 544 && event.mouseButton.y >= 512) {
                    board.SmileyButton();
                    debugMode = false;
                }

                if (debugMode == true) {
                    if (board._board[i][j].GetMine() == true) {
                        backgroundTile.setPosition(32 * j, 32 * i);
                        window.draw(backgroundTile);
                        mine.setPosition(32 * j, 32 * i);
                        window.draw(mine);
                    }
                }

                if (btest1 == true) {
                    string filename = "boards/testboard1.brd";
                    board.loadBoard(filename);
                }
                if (btest2 == true) {
                    string filename = "boards/testboard2.brd";
                    board.loadBoard(filename);
                }
                if (btest3 == true) {
                    string filename = "boards/testboard3.brd";
                    board.loadBoard(filename);
                }

                int minesLeft = board.GetMineCount() - board.GetFlags();
               
                int firstDigit = 0;
                if (minesLeft > 99) {
                    firstDigit = 1;
                }
                if (minesLeft < 0) {
                    firstDigit = 10;
                    minesLeft *= -1;
                }
                int secondDigit = (minesLeft % 100) / 10;
                int thirdDigit = minesLeft % 10;
                
                
                digits.setTextureRect(sf::IntRect(21 * firstDigit, 0, 21, 32));
                digits.setPosition(32 * 1, 0.0f + (32 * (i + 1)));
                window.draw(digits);

                digits.setTextureRect(sf::IntRect(21 * secondDigit, 0, 21, 32));
                digits.setPosition(32 * 1 + 21, 0.0f + (32 * (i + 1)));
                window.draw(digits);

                digits.setTextureRect(sf::IntRect(21 * thirdDigit, 0, 21, 32));
                digits.setPosition(32 * 1 + 21 * 2, 0.0f + (32 * (i + 1)));
                window.draw(digits);
                

                
            }
        }

        

        window.display();
   }
    TextureManager::Clear();
    return 0;
}

