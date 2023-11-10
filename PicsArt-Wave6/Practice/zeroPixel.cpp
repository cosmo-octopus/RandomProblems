#include <iostream>

struct Pixel
{
	int	x = 0;
	int	y = 0;
};

void	changeValue(Pixel *pixel)
{
	static int	i = 0;

	i++;
	pixel->x = i;
	pixel->y = i;
}

void	changePixels(Pixel pixel[4], void(*change)(Pixel *))
{
	for (int i = 0; i < 4; i++)
	{
		if (pixel[i].x == 0 && pixel[i].y == 0)
			change(&pixel[i]);
	}
}

int	main()
{
	Pixel	arr[4];
	
	for (int i = 0; i < 4; i++)
		std::cout << "x: " << arr[i].x << " y: " << arr[i].y << std::endl;
	
	changePixels(arr, changeValue);

	std::cout << "\nNew Pixels: " << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << "x: " << arr[i].x << " y: " << arr[i].y << std::endl;
}