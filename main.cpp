// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <Cmath>

//Make the code easier to type with "using namespace"
using namespace sf;
using namespace std;

// TO DO:
//
// [04-22-25]
// 	- Add font file
// 	- Review code for drawing points
//	- Review code for optional color choice menu
//	- Implement code for calculating midpoints

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

	vector<Vector2f> vertices;
	vector<Vector2f> points;

	// Create text
	Text text;

	// Create and load font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.tff"); // Replace with own font file

	// Load font into text
	text.setFont(font);

	// Assign string to print out instructions
	text.setString("This is a test statement.");

	// Change font size and color
	text.setCharacterSize(50);
	text.setFillColor(Color::White);

	// Position the text (copied off Timber.cpp)
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left +
		textRect.width / 2.0f,
		textRect.top +
		textRect.height / 2.0f);
	text.setPosition(1920 / 2.0f, 1080 / 2.0f);

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				// Quit the game when the window is closed
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					if (vertices.size() < 3)
					{
						vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
					}
					else if (points.size() == 0)
					{
						if (event.type == sf::Event::MouseButtonPressed) ///fourth click (I think this is the code for fourth click? Or maybe if vertices.size() == 4?)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));	///push back to points vector
							}
						}
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		/*
		****************************************
		Update
		****************************************
		*/

		if (points.size() > 0)
		{

			///generate more point(s)
			
			///select random vertex
			///calculate midpoint between random vertex and the last point in the vector
			///push back the newly generated coord.
			/// Vector2f temp = 
			/// for (int i = 0; i < vertices.size(); i++) {
			///		Vector2f temp = srand vertices
			///		Vector2f midpoint = (randVert + last point) / 2
			///		points.push_back(midppoint);
			/// 
			/// }
			/// 
			/// while (points.size() < 100)
			/// {
			///		float randX = rand
			///		float tempX = (points[i] + random*) / 2.0;
			///		float tempY = (points[i] + random*) / 2.0;
			///		Vector2f midpoint(tempX, tempY);
			///		points.push_back(midpoint);
			///		
			/// 
			///		
			//
			/// }
		}

		/*
		****************************************
		Draw
		****************************************
		*/
		window.clear();
		for (int i = 0; i < vertices.size(); i++)
		{
			RectangleShape rect(Vector2f(10, 10));
			rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
			rect.setFillColor(Color::Blue);
			window.draw(rect);
		}
		///TODO:  Draw points
		// ======================== REVIEW ========================
		// for (int i = 0; i < points.size(); i++)
		// {
		// 	CircleShape circle(1);
		//	circle.setRadius(1);
		//	circle.setPosition(Vector2f(points[i].x, points[i].y));
		//	circle.setFillColor(Color::Green);
		//	window.draw(circle);
		// }
		//
		// Optional: (Choose a color?)
		// 
		//	cout << "Choose a color: " << endl;
		//	Color<vector> colorTypes = { Color::Red, Color::Green, Color::Blue, Color::Yellow };
		//	string colorNames[4] = { "Red", "Green", "Blue", "Yellow" };
		//	Color colorChoice;
		//
		//	for (int i = 1; i < colorTypes.size(); i++)
		//	{
		//		cout << i << ". " << colorNames[i - 1] << endl;
		//		// text.setString(colorNames[i - 1];
		//	}
		//	cin >> input;
		//	colorChoice = colorTypes[input - 1];
		//	circle.setFillColor(colorChoice);
		// ==========================================================

		window.display();
	}
}
