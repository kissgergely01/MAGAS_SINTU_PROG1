#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
try
	{

	using namespace Graph_lib;

	Simple_window win{ Point{100,100}, 800, 1000, "Canvas"};

	int x_size = 800;
	int y_size = 1000;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = x_grid; x < x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,800});
	for (int y = y_grid; y <= 800; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});


	Vector_ref<Rectangle> negyzetek;
		for (int i = 0; i <= 8; ++i)
		{
			negyzetek.push_back(new Rectangle{Point{i*100, i*100},100,100});
			negyzetek[i].set_fill_color(Color::red);
			win.attach(negyzetek[i]);
		}

	Image img1 {Point{200,0},"thisisfine.jpeg"};
	Image img2 {Point{0,500},"thisisfine.jpeg"};
	Image img3 {Point{600,200},"thisisfine.jpeg"};

	int x1 = 100; 	int y1 = 0;
	Image troll {Point{x1,y1},"troll.jpeg"};

	win.attach(grid);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
	win.attach(troll);
	win.wait_for_button();

	while (true)
	{

		int randomszam = std::rand() % 4;

		if(randomszam == 0 and x1 >= 100)
			{
				troll.move(-100,0);
				x1 = x1-100;
			}
		else if (randomszam==1 and x1<=700)	
			{
				troll.move(100,0);
				x1 = x1+100;
			}
		else if (randomszam==2 and y1>=100)	
			{
				troll.move(0,-100);
				y1 = y1-100;
			}
		else if (randomszam==3 and y1<=700)
			{
				troll.move(0,100);
				y1 = y1+100;
			}
		win.wait_for_button();
	}
	
	}
	catch (exception& e){
		cout << "Error\n";
		return 1;
	}

	catch(...){
		cout << "Other error\n";
		return 2;
	}

}
