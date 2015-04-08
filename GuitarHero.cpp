/*
  Copyright 2015 Kim Douglas, kdouglas@cs.uml.edu

  based on Princeton's GuitarHeroLite.java
  www.cs.princeton.edu/courses/archive/fall13/cos126/assignments/guitar.html

  extended from Fred Martin's GuitarHeroLite starter code
  www.cs.uml.edu/ecg/index.php/Comp4spr15/PS5b
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamplesFromString(GuitarString& gs) {
	std::vector<sf::Int16> samples;
	gs.pluck();
	int duration = 8;
	int i;

	for (int i = 0; i < SAMPLES_PER_SEC * duration; i++)
	{
		gs.tic();
		samples.push_back(gs.sample());
	}

	return samples;
}

int main(int argc, char* argv[]) {

	sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero");
	sf::Event event;
	
	// reused
	double freq = CONCERT_A;  

	// holds for each tone
	std::vector<std::vector <sf::Int16> > samplevect;
//	std::vector<sf::SoundBuffer> buffervect;
	std::vector<sf::Sound> soundvect;
	std::string keys = "1234567890-qwertyuiopasdfghjklzxcvbnm";

	for (unsigned int i = 0; i < 37; i++)
	{
		GuitarString gstring(freq);
		sf::Sound sound;
		sf::SoundBuffer buffer;

//		gstring = new GuitarString(freq);	
		samplevect.push_back(makeSamplesFromString(gstring));
		
		if (!buffer.loadFromSamples(&samplevect[i][0], samplevect[i].size(), 2, SAMPLES_PER_SEC))
			throw std::runtime_error("sf::SoundBuffer: failed to load samples");
	
		sound.setBuffer(buffer);
//		buffervect.push_back(buffer);
		soundvect.push_back(sound);

		freq = freq * pow(2, 3.0/12.0);
	}


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			
			if (event.type == sf::Event::Closed)
				window.close();

			for (int i = 0; i < 37; i++)
			{
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode == keys[i])
					{
						soundvect[i].play();
					}
				}
			}

			window.clear();
			window.display();
		}
	}

	return 0;

}








































