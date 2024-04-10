#include <utility>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>
#include "Wall.h"

using namespace std;

class Tile{
	/* Represents a regular convevex polygon */


	// --- Attributes --- //

	protected: int id; // to id tiles
	protected: int sides; // number of sides
	protected: int size; // size of tile (center to corner)
	protected: int x; // center of tile on x axis
	protected: int y; // center of tile on y axis
	protected: vector<Tile> neighbours; // adjacent tiles
	protected: vector<Wall> walls; // Walls that are open or closed
	protected: vector<pair<int,int>> corners; // positions of the corners


	// --- Setters --- //

	public: void setID(int id){this->id = id;} // not used
	
	public: void setSides(int n){sides = n;}

	public: void setSize(int n){size = n;}

	public: void setX(int x){this->x = x;}

	public: void setY(int y){this->y = y;}

	public: void setXY(int x, int y){
		this->x = x;
		this->y = y;
	}

	public: void setAllNeighbours(vector<Tile> neighbours){
		if (neighbours.size()!=sides){
			string error = "Set neighbours not right size.\n";
			error.append("Number of neighbours (attribute) :" + sides);
			error.append("\nSize of neigbours (parameter):" + neighbours.size());
			throw runtime_error(error);
		} else {
			this->neighbours = neighbours;
		}
	}

	public: void setNeighbour(Tile neighbour,int n){
		if (n >= sides){
			string error = "Set neighbour index out of range.\n";
			error.append("Number of neighbours :" + sides);
			error.append("\nNeighbour selected :" + n);
			throw runtime_error(error);
		} else {
			neighbours[n] = neighbour;
		}
	}

	public: void setAllWalls(vector<Wall> walls){
		if (walls.size()!=sides){
			string error = "Set walls not right size.\n";
			error.append("Number of walls (attribut) :" + sides);
			error.append("\nSize of walls (parameter):" + walls.size());
			throw runtime_error(error);
		} else {
			this->walls = walls;
		}
	}

	public: void setWall(Wall wall,int n){
		if (n >= sides){
			string error = "Set wall index out of range.\n";
			error.append("Number of walls :" + sides);
			error.append("\nWall selected :" + n);
			throw runtime_error(error);
		} else {
			walls[n] = wall;
		}
	}

	

	// Getters
	public: int getID(){return id;}
	public: int getSides(){return sides;}
	public: int getSize(){return size;}
	public: int getX(){return x;}
	public: int getY(){return y;}
	public: pair<int,int> getXY(){return make_pair(x,y);}
	public: vector<Tile> getNeighbours(){return neighbours;}
	public: vector<Wall> getWalls(){return walls;}
	public: vector<pair<int,int>> getCorners(){return corners;}

	// abstract function
	public: virtual void print(){}
	
	// non virtual functions
	public: void calculateCorners(){
		for (int i=0; i< sides;i++){
			int x_i = x + size * cos(2*M_PI*i/sides);
			int y_i = y + size * sin(2*M_PI*i/sides);
			corners[i]=make_pair(x_i,y_i);
		}
	}

	public: void rotate(int alpha){
		for (pair<int,int>& xy : corners){
			int newX = (xy.first-x)*cos(alpha)-(xy.second-y)*sin(alpha)+x;
			int newY = (xy.first-x)*sin(alpha)+(xy.second-y)*cos(alpha)+y;
			xy = make_pair(newX,newY);
		}
	}

	public: void open(int n){
		
	}
};

class Triangle : Tile{

	// Constructor
	public: Triangle(int id ,int x ,int y, int size){
		sides = 3;
		this->id = id;
		this->size = size;
		this->x = x;
		this->y = y;
		calculateCorners();
	};
};

class Square : Tile{

	// Constructor
	public: Square(int id ,int x ,int y, int size){
		sides = 4;
		this->id = id;
		this->size = size;
		this->x = x;
		this->y = y;
		calculateCorners();
	};
};

class Pentagon : Tile{

	// Constructor
	public: Pentagon(int id ,int x ,int y, int size){
		sides = 5;
		this->id = id;
		this->size = size;
		this->x = x;
		this->y = y;
		calculateCorners();
	};
};

class Hexagon : Tile{

	// Constructor
	public: Hexagon(int id ,int x ,int y, int size){
		sides = 6;
		this->id = id;
		this->size = size;
		this->x = x;
		this->y = y;
		calculateCorners();
	};
};


class Octogon : Tile{

	// Constructor
	public: Octogon(int id ,int x ,int y, int size){
		sides = 8;
		this->id = id;
		this->size = size;
		this->x = x;
		this->y = y;
		calculateCorners();
	};
};