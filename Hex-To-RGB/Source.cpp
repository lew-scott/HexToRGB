#include <sstream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <conio.h>


struct RGB
{
	int r, g, b;
};

std::vector<RGB> colours;

void makeRGB(std::string colour)
{
	int r, g, b;

	std::stringstream sr(colour.substr(4, 2));
	sr >> std::hex >> r;
	std::stringstream sg(colour.substr(6, 2));
	sg >> std::hex >> g;
	std::stringstream sb(colour.substr(8, 2));
	sb >> std::hex >> b;

	colours.push_back({ r,g,b });
}

int main() {

	std::string line;
	std::ifstream file("Tile.txt");
	std::string colour;
	std::stringstream ss;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			std::stringstream ss(line);
			while (getline(ss, colour, ','))
			{
				if (colour.size() == 1)
				{
					continue;
				}

				if (colour[0] == ' ')
				{
					colour.erase(0, 1);
				}
				makeRGB(colour);
				std::cout << colour << "\n";
			}

		}
	file.close();
	}

	int width = 50; 
	int height = 50;

	std::ofstream outfile;
	outfile.open("output.txt");

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			std::cout << "gfx.putpixel(x + " << i << ", y + " << j << ", " << colours[j * width + i].r << ", " << colours[j * width + i].g << ", " << colours[j * width + i].b << "); \n";
			outfile << "gfx.putpixel(x + " << i << ", y + " << j << ", " << colours[j * width + i].r << ", " << colours[j * width + i].g << ", " << colours[j * width + i].b << "); \n";
		}
	}

	outfile.close();

	while(!_kbhit());
	return 0;


	/*
	unsigned int x;
	std::stringstream ss;
	ss << std::hex << "3d";
	ss >> x;
	// output it as a signed type
	std::cout << static_cast<int>(x) << std::endl;
	*/
}