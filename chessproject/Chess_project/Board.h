#pragma once
#include <map>
#include "Box.h"
#include <string>
#include <vector>
#include <QWidget>

using namespace std;
class Echequier 
{
public:
	Echequier() {
	}
	~Echequier() {};


	void creerEchequier();

	void ajouterPiece(shared_ptr<Piece> piece, pair<int, int> position);

	void detruirePiece(shared_ptr<Piece> piece, pair<int, int> position);

	void deplacerPiece(pair<int, int> posBeginning, pair<int, int> posEnding);

	bool estCaseOccupee(pair<int, int> position);

	shared_ptr<Piece> obtenirPieceAPosition(pair<int, int> pos);

	void initializerEchequier();

	void detruireEchequier();


private:
	static const int LIGNES = 8;
	static const int COLONNES = 8;
	shared_ptr<Box> tebleauEchequier[LIGNES][COLONNES]; 
	int nbRois_ = 0; 
	
};

