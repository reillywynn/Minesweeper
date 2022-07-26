# Minesweeper
Overview
For this project you are going to create a version of the classic game, Minesweeper. Your final version will look like this:

 

If you’ve never played the game before, you can find a number of playable versions of this online.

To create this project you are going to use SFML (the Simple and Fast Multimedia Library) to do the work of drawing images to the screen and getting mouse input, while you will be responsible for everything else.

Description
The rules of the game are as follows:

There exists a board, which contains a grid of spaces. A space could be a mine, or not. The player clicks on a space, and it gets revealed. The goal of the game is to reveal all the spaces that are not mines, while avoiding the spaces that are.

When a space is revealed:

If it’s a mine, the game ends

If it’s not a mine, it shows the number of mines adjacent to that space (anywhere from 0 to 8, with 0 just showing as an empty space)

– If a space has no adjacent mines, all non-mine spaces adjacent to it are also revealed The player uses the numbers as clues to figure out where other mines may be located.

When all of the non-mine spaces have been revealed, the player wins!

Flags: Right-clicking a space puts a flag on that space, marking it as a possible mine. Flagged spaces cannot be revealed (with left-clicks or as a result of adjacent spaces being revealed), but another rightclick will remove the flag.

Mine Counter: to track the number of mines that are on the board. Every time the player places a flag, the counter goes down by one. Every time they remove a flag, the counter goes up by one. The mine counter CAN go negative!

Restart Button: The smiley face centered at the top or bottom of the window lets you restart a new board with everything reset and mines randomized

Debug Button: Clicking this button will toggle the visibility of the mines on the board. Use this to help you test/debug various features of the game. Having to play the game properly each time you want to test something is very time-consuming. Creating these developer shortcuts helps speed up the development process

Test Buttons #1-3: Another development shortcut, clicking on these loads a file with a specific board layout, details on this later.

Those are the features that your game will need to have. The rules are pretty simple, but even simple games like this can be challenging to implement.

Window / Board Setup
Most implementations of this game allow for variability in difficulty, board size, etc, but for this project you are going to use these dimensions and values:

Window Size	800 x 600
Mine count	50 on randomly generated maps, determined by file in other cases (more on this later)
Tile count	25 x 16 (400 tiles total)
SFML
The library that you will be using in this project is SFML—Simple Fast Multimedia Library. The first thing you would need to do is compile an application using this. Building an application using an external library can be a difficult thing, but it’s something that you typically only have to do once at the start of a project, and then you’re good to go until that project is finished.

To get started with SFML, visit this site:

https://www.sfml–dev.org/download/sfml/2.5.1/

You want to download the appropriate version for the IDE/compiler that you are using. If you are using something that isn’t listed there, it is HIGHLY RECOMMENDED that you install and use one of the recommended tools. On Windows that would be Visual Studio, XCode on MacOS, etc. The links on that page are for already-compiled versions of the library which will work “out of the box” with the appropriate compiler.

Installing and compiling your first “Hello World” program can be a bit tricky, especially if you’ve never done it before. There are guides here: https://www.sfml–dev.org/tutorials/2.5/, and certainly elsewhere online, but often the best source is from the developer’s themselves.

There are many guides and tutorials on how to use SFML, but the key features that you will be utilizing for this project are:

sf::Sprite	These objects will let you draw some or all of a texture to the screen, the primary object that you will use to represent all aspects of the game
sf:Texture	These store external images that you program needs
sf:Vector2f/i/u	A 2-dimensional vector (an X and Y position), a location on the screen; the f/i/u at the end indicates the type of data used for storage (float, int, unsigned int)
sf::Mouse	The mouse class, giving you information about where the cursor is located, and whether or not a mouse button is pressed
This document will not replicate the wealth of information already out there about this library. The primary list of examples/tutorials can be found here: https://www.sfml–dev.org/tutorials/2.5/

From that page, a few in particular you will find useful for this project:

https://www.sfml–dev.org/tutorials/2.5/window–window.php https://www.sfml–dev.org/tutorials/2.5/window–events.php https://www.sfml–dev.org/tutorials/2.5/graphics–sprite.php

Anything beyond that will not be applicable for this project (networking, audio, etc will NOT be used). Everything you see on the screen (each space, numbers, buttons, etc) will all be created and drawn the same way: load a texture, create one or more sprites from that texture, and then draw them to the screen.

You will have to load and store the images listed in the next section in sf::Texture objects.

Images
For this project you will have a folder, creatively called images, where all of the images for this project will be stored. These images will all be loaded as sf::Texture objects to be used in the creation of sf::Sprite objects.

The images are as follows:

Game Images
mine.png	The star of the game (although if you play properly, you’ll never see one!)
tile_hidden.png	What all tiles look like before they are clicked/revealed
tile_revealed.png	A revealed tile with no adjacent tiles
number_#.png	Tiles with the numbers 1-8 on them (replace # with the appropriate number. Used for tiles that have 1-8 adjacent mines
flag.png	Draw this on top of hidden tiles when they are flagged by the player as possible mines.
UI Images
face_happy.png	Click this button to reset the map. New mines, everything hidden, it’s like you restarted the program.
face_win.png	Victory!
face_lose.png	The opposite of victory! (It’s cool, no smiley faces were harmed during the creation of this project)
digits.png	Used for the digits on the “remaining mines” display. You can use this one texture for all the numbers, and change the “texture rect” of a sprite to draw a different portion of the image.
 

The size of each digit (and the size of the texture rect you should use) is 21 x 32 pixels, and each digit would be offset by 21 (the width) times the digit you wanted.

 

See https://www.sfml–dev.org/tutorials/2.5/graphicssprite.php for more information

debug.png	Used to toggle debug mode
test_1/2/3.png	Used to load test files from which the board will be set
Other Features
A button is really just an image that you can click on to make something happen. A more complex UI system would use an event/messaging system, but on a basic level you just need a sf::Sprite to represent the button, and every time the player clicks on something, you need to check if that mouse click occurred inside the boundaries of the sf::Sprite you’re using as the button.

If you’re drawing a sprite somewhere, you know its position (it’s 0, 0 by default, or whatever you set it to). You can get the width/height of the sprite through its textureRect, and then it’s just a matter of checking if the mouse position is inside that box.

In order to calculate the number of nearby mines, as well as when revealing tiles, each tile should store a list of neighboring tiles. A tile could have UP TO 8 neighbors. An easy way to do this is with pointers. Since the number is a variable, a dynamically sized container would be perfect for this. You could also use a fixed-length array, since no tile will ever have more than 8 neighbors.

vector<Tile *> adjacentTiles; // Store each tile near us, the size() of each vector will vary

Tile* neighbors[8]; // Always 8 pointers, some of which might be nullptr

 

 

When clicking either of these buttons:

 

You should open up one of the three files located in the “boards” folder. For Test #1, you should open “testBoard1.brd”, test #2 is “testBoard2.brd”, etc. These are plain text files, and you can open them in any text editor.

Those files contain a bunch of 0s and 1s to represent the layout of a particular map. Why use these? When developing any project, having some sort of test data, some known value, is essential. How you do you know if hundreds of randomly generated values are correct or not? That’s really difficult. How do you know if your code to set a series of tiles to mines (or not) is working? Try setting to a specific pattern that you created (or someone provided for you).

testBoard	testBoard2
1000000000000000000000000
0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

0000000000000000000000000

 

0000000000000000000000000
0000000000000000000000000

0011111011110111101111100

0000100010000100000010000

0000100011000011000010000

0000100010000000100010000

0000100011110011000010000

0000000000000000000000000

0000011100100010011000000

0000001000101010100100000

0000001000010100100100000

0000001000010100011000000

0000000000000000000000000

1110111010101000110100100

1010100010101000100100100

1110111010101110100100000

testBoard loaded, no revealed tiles	testBoard2 loaded, one tile on the edge revealed (which caused a cascaded of revealed tiles)
 

Code Structure
With larger programs, you can accomplish the goal in any number of ways. There isn’t a single way to write this that works better above all others. From the outside perspective (i.e. that of a player), your application needs to DO various things:

When the player clicks a space, reveal it.
When the player clicks the restart button, reset the board.
If a mine is revealed, end the game. And so on.
HOW you choose to accomplish those things is up to you. If you want to write a single, gigantic main() function, you are free to do so—that approach is not recommended, however. A few suggestions:

A class to represent the board. This represents the core data object in the game.

A class for tiles/spaces. The board is made up of a whole lot of these things. Each one of these can be a mine, have a flag, some number of adjacent tiles/mines, etc.

Many programs (games or otherwise) do the same things over and over again while the application is running. The ability to easily (in code) reset everything is critical. Think about what sorts of helper functions you might want to make that happen. Things like:

Restarting the board

Setting or clearing tiles of flags

Setting or clearing mines (singly or in large quantites)

Recalculating the number of adjacent mines Etc…

Mouse Interactions
The application can really do “nothing” until the user clicks their mouse. Typically games and many other applications are clearing/redrawing the screen on a regular basis (often dozens of times a second).

Once the player has clicked, however (you can check for this in the event loop), you then need to do some checks about that click.

Where did they click?

Is that a valid space on the board anywhere? If so, should you do anything in response to this?

Did the player just click a mine?

Boom, game over!

If not a mine, reveal the tile

Revealing a tile

If the number of adjacent mines is 0, reveal any neighboring tiles as well (as long as they aren’t mines) In revealing those, do the same sort of check for any neighbors to that tile… (sounds a bit like recursion here!)

Storing Resources
While a program is running, it needs RESOURCES to get the job done—things like icons, textures, sound files, etc. Many of the resources need to be stored for long-term use, as they may be called upon time and time again… but you don’t always know when they’ll be needed when you compile your code.

A great storage container for assets that you want to reference by name is the map<>. Storing something that you can access by its name with container[“NameOfAsset”] is vastly preferable to that of dealing with arrays—was “GameOver.png” stored in array[25], or array[26]?

You may find it helpful to create a single storage container for all of the sf::Texture objects, and then pass that around to any class which might need those files.

Using Documentation
Reading through documentation, help files, guides, tutorials, etc is an absolutely critical skill that you must develop. The problem you are currently trying to solve, the exact combination of variables for your scenario might not have existed before now.

The One True Answer to your problem might not be out there on the Internet, in a StackOverflow.com question, or in a video on YouTube. However, the information to help you figure out PARTS of your problem are almost certainly out there. You will have to figure out how to make sense of those smaller bits of information and decide on a proper course of action.

For example, the data referenced sf::Texture objects disappears when the object is deleted, or falls out of scope. You can’t create a sf::Texture inside a function, create a sf::Sprite from that texture, and then use the sprite outside the function. An example of this (and what not to do) in the documentation:

https://www.sfml–dev.org/tutorials/2.5/graphics–sprite.php#the–white–square–problem

Tips
Any libraries or APIs that you work with will have some sort of documentation. READ IT! You absolutely MUST get used to being able to sift through information to find the answers that you are looking for.

Don’t be afraid to experiment! When getting access to new code, you have to figure out how it works. Documentation is all fine and good, but at some point you have to actually DO IT yourself. Learning by doing is the most effective way. Write some code, screw it up, fix that code, do it all over again.

Don’t try to write the entire program all at once. Hard-code test values if you need to. Try to get one single tile working on a basic level (position, responding to mouse clicks, etc) before creating dozens/hundreds of them.

Think about what types of classes or functions you might want to have for this project. There is a board, a board has tiles, tiles have various properties or states… How do you want to store that data? An array? A vector<>? A 2-dimensional array?

You’re the one writing the code! Write it in a way that makes sense to you. Everyone tackles problems a bit differently, find an approach that works for you. 
