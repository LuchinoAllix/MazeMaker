#include <utility>
#include "Tile.h"
#include "vector"

using namespace std;


class Wall{

	// Attributes //
	protected: bool isOpen;
	protected: vector<pair<int,int>> coords;

	// Setters //
	public: void open(){isOpen=true;}
	public: void close(){isOpen=false;}
	public: void set(bool open){isOpen=open;}
	public: void setAllCoords(vector<pair<int,int>> coords){
		if (coords.size()!=4){
			string error = "Set coords not right size.\n";
			error.append("Number of coords needed: 4\n");
			error.append("Size of coords provided:" + coords.size());
			throw runtime_error(error);
		} else {
			this->coords = coords;
		}
	}

	//Getters //
	public: bool getIsOpen(){return isOpen;}
	public: vector<pair<int,int>> getCoords(){return coords;}

};

class InnerWall : Wall{
	protected: pair<Tile,Tile> cells;

	public: void setCells(Tile t1,Tile t2){cells = make_pair(t1,t2);}

	public: pair<Tile,Tile> getCells(){return cells;}

	public: InnerWall(pair<Tile,Tile> cells,  vector<pair<int,int>> coords){
		this->isOpen = false;
		this->coords = coords;
		this->cells = cells;
	}

	public: InnerWall(pair<Tile,Tile> cells){
		this->isOpen = true;
		this->cells = cells;
	}
};

class OuterWall : Wall{

	// --- Attributs
	protected: Tile cell;
	protected: vector<pair<int,int>> outerCoords;

	public: void setCell(Tile t1){cell = t1;}
	public: void setAllOuterCoords(vector<pair<int,int>> outerCoords){
		if (outerCoords.size()!=4){
			string error = "Set outercoords not right size.\n";
			error.append("Number of outerCoords needed: 4\n");
			error.append("Size of outerCoords provided:" + coords.size());
			throw runtime_error(error);
		} else {
			this->outerCoords = outerCoords;
		}
	}


	// --- Getters --- //
	public: Tile getCell(){return cell;}
	public: vector<pair<int,int>> getOuterCoords(){return outerCoords;}


	// --- Constructor --- //
	public: OuterWall(Tile cell,  vector<pair<int,int>> Coords, vector<pair<int,int>> outerCoords){
		this->isOpen = false;
		this->coords = coords;
		this->outerCoords = outerCoords;
	}

};