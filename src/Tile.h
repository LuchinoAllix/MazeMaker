#include <utility>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

class Tile{

	// Attributes :
	protected: int id;
	protected: int sides;
	protected: int x;
	protected: int y;
	protected: vector<Tile> neighbours;
	protected: vector<bool> walls;
	protected: vector<pair<int,int>> corners;

	// Setters :
	public: void setID(int id){this->id = id;} // not used
	
	public: void setSides(int n){sides = n;}

	public: void setX(int x){this->x = x;}

	public: void setY(int y){this->y = y;}

	public: void setXY(int x, int y){
		this->x = x;
		this->y = y;
	}

	public: void setAllNeighbours(vector<Tile> neighbours){
		if (neighbours.size()!=sides){
			string error = "Set neighbours not right size.\n";
			error.append("Size of sides :" + sides);
			error.append("Size of neigbours :" + neighbours.size());
			throw runtime_error(error);
		} else {
			this->neighbours = neighbours;
		}
	}

	// Getters
	public: int getID(){return id;}
	public: int getSides(){return sides;}
	public: int getX(){return x;}
	public: int getY(){return y;}
	public: pair<int,int> getXY(){return make_pair(x,y);}
	public: vector<Tile> getNeighbours(){return neighbours;}

	// abstract function
	public: virtual void print(){};
	public: virtual void calculateCorners(){};

};

class Triangle : Tile{

	// Constructors
	public: Triangle(int id ,int x ,int y){
		sides = 3;
		this->id = id;
		this->x = x;
		this->y = y;
		this->walls = vector<bool>(sides, true);
	};

	public: Triangle(int id ,int x ,int y, vector<Tile> neighbours){
		sides = 3;
		this->id = id;
		this->x = x;
		this->y = y;
		this->setAllNeighbours(neighbours);
		this->walls = vector<bool>(sides, true);
	};

};

class Square : Tile{

	// Constructors
	public: Square(int id ,int x ,int y){
		sides = 4;
		this->id = id;
		this->x = x;
		this->y = y;
		this->walls = vector<bool>(sides, true);
	};

	public: Square(int id ,int x ,int y, vector<Tile> neighbours){
		sides = 4;
		this->id = id;
		this->x = x;
		this->y = y;
		this->setAllNeighbours(neighbours);
		this->walls = vector<bool>(sides, true);
	};

};

class Pentagon : Tile{

	// Constructors
	public: Pentagon(int id ,int x ,int y){
		sides = 5;
		this->id = id;
		this->x = x;
		this->y = y;
		this->walls = vector<bool>(sides, true);
	};

	public: Pentagon(int id ,int x ,int y, vector<Tile> neighbours){
		sides = 5;
		this->id = id;
		this->x = x;
		this->y = y;
		this->setAllNeighbours(neighbours);
		this->walls = vector<bool>(sides, true);
	};

};

class Hexagon : Tile{

	// Constructors
	public: Hexagon(int id ,int x ,int y){
		sides = 6;
		this->id = id;
		this->x = x;
		this->y = y;
		this->walls = vector<bool>(sides, true);
	};

	public: Hexagon(int id ,int x ,int y, vector<Tile> neighbours){
		sides = 6;
		this->id = id;
		this->x = x;
		this->y = y;
		this->setAllNeighbours(neighbours);
		this->walls = vector<bool>(sides, true);
	};

};


class Octogon : Tile{

	// Constructors
	public: Octogon(int id ,int x ,int y){
		sides = 8;
		this->id = id;
		this->x = x;
		this->y = y;
		this->walls = vector<bool>(sides, true);
	};

	public: Octogon(int id ,int x ,int y, vector<Tile> neighbours){
		sides = 8;
		this->id = id;
		this->x = x;
		this->y = y;
		this->setAllNeighbours(neighbours);
		this->walls = vector<bool>(sides, true);
	};

};