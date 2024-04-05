#include <utility>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

class Tile{

	// Attributes :
	private: int id;
	private: int sides;
	private: int x ;
	private: int y;
	private: vector<Tile> neighbours ;

	// Setters :
	// public: void setX(int id){this->id = id;}
	
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
	public: int getSides(){return sides;}
	public: int getX(){return x;}
	public: int getY(){return y;}
	public: pair<int,int> getXY(){return make_pair(x,y);}

};

class Square : Tile{

};
