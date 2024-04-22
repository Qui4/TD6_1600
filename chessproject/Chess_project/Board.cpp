#include "Board.h"


void Echequier::creerEchequier() {
	for (int i = 0; i < LIGNES; i++) {
		for (int j = 0; j < COLONNES; j++) {
			tebleauEchequier[i][j] = make_shared<Box>();
		}
	}
}

void Echequier::ajouterPiece(shared_ptr<Piece> piece, pair<int, int> positionPiece) {

	if (positionPiece.first < 0 || positionPiece.first >= LIGNES || positionPiece.second < 0 || positionPiece.second >= COLONNES) {
		throw out_of_range("Outside chessboard");
	}

	tebleauEchequier[positionPiece.first][positionPiece.second]->setPiece(piece);

	if (piece->getType() == Type::KING) {
		nbRois_++;
		if (nbRois_ > 3) {
			throw runtime_error("ERREUR: Le nombre de rois est suppérieur à 3.");
		}
	}
}

void Echequier::detruirePiece(shared_ptr<Piece> piece, pair<int, int> positionPiece) {
	if (positionPiece.first < 0 || positionPiece.first >= LIGNES || positionPiece.second < 0 || positionPiece.second >= COLONNES) {
		throw out_of_range("ERREUR: La piece n'est pas dans l'echequier");
	}

	tebleauEchequier[positionPiece.first][positionPiece.second]->setPiece(nullptr);

	if (piece->getType() == Type::KING) {
		nbRois_--;
	}
}

void Echequier::deplacerPiece(pair<int, int> posBeginning, pair<int, int> posEnding) {
	if (estCaseOccupee(posBeginning) == true) {
		tebleauEchequier[posBeginning.first][posBeginning.second]->getPiece() = tebleauEchequier[posEnding.first][posEnding.second]->getPiece();
		tebleauEchequier[posBeginning.first][posBeginning.second]->getPiece() = nullptr;
	}
}

bool Echequier::estCaseOccupee(pair<int, int> positionPiece) {
	if (tebleauEchequier[positionPiece.first][positionPiece.second]->getPiece() == nullptr) {
		return false;
	}
	else {
		return true;
	}

}



shared_ptr<Piece> Echequier::obtenirPieceAPosition(pair<int, int> positionPiece) {
	if (estCaseOccupee(positionPiece) == true) {
		return tebleauEchequier[positionPiece.first][positionPiece.second]->getPiece();
	}
	else {
		return nullptr;
	}
}

void Echequier::initializerEchequier() {
	map<shared_ptr<Piece>, pair<int, int>> board0 = { { make_shared<Piece>(Color::BLACK, Type::ROOK),make_pair(0,0)},
		{make_shared<Piece>(Color::BLACK, Type::ROOK), make_pair(3,1)}, { make_shared<Piece>(Color::WHITE, Type::KING), make_pair(4,5)}
	};

	for (auto const& [piece, pos] : board0) {
		ajouterPiece(piece, pos);
	}
}

void Echequier::detruireEchequier() {
	for (int i = 0; i < LIGNES; i++) {
		for (int j = 0; j < COLONNES; j++) {
			pair<int, int> pos = make_pair(i, j);
			if (estCaseOccupee(pos)) {
				detruirePiece(obtenirPieceAPosition(pos), pos);
			}
		}
	}
}